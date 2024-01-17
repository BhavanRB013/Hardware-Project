#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

// classes that assist in obtaining and managing authentication tokens required for Firebase operations.
#include "addons/TokenHelper.h"
//include functions for reading, writing, and monitoring data in the Realtime Database.
#include "addons/RTDBHelper.h"

//For internet connectivity
#define WIFI_SSID "NIGGA 1"
#define WIFI_PASSWORD "11111111"


#define API_KEY "AIzaSyDOll-P5A1-Uo-OXm5Zk0Le7byUQW2xESM"


#define DATABASE_URL "https://fir-with-esp32-27de8-default-rtdb.asia-southeast1.firebasedatabase.app/" 


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


  config.api_key = API_KEY;


  config.database_url = DATABASE_URL;

//for anonymus user the last 2 arguments should be empty
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

//this include token refreshes, reauthentication, or other relevant tasks.
  config.token_status_callback = tokenStatusCallback; 
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop(){
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

    if (Firebase.RTDB.setInt(&fbdo, "test/int", count)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    count++;
    

    if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0,100))){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
}