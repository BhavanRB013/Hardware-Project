#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Akhileash's Galaxy S20 FE 5G";
const char* password = "iszs8637";
const char* apiKey = "815036a6ce6c133139d384f6011040b4";
const char* city = "Kundrathur";
const char* firebaseHost = "espparameters-default-rtdb.firebaseio.com/";
const char* firebaseSecret = "AIzaSyCZn0X-7dNRteuaGpmBnTkSYNH6XcOxihQ";
const char* firebasePath = "/weather_data.json"; // Adjust the path as needed

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Fetch weather data and update Firebase
  getWeatherData();
    // Fetch weather data every 10 minutes (adjust as needed)
  delay(660000); // 10 minutes delay
}

void getWeatherData() {
  // Make the HTTP request to OpenWeatherMap
  String url = "http://api.openweathermap.org/data/2.5/weather?q=" + String(city) + "&appid=" + apiKey;
  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    String payload = http.getString();

    // Parse JSON
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);

    // Extract weather information
    float temperature = doc["main"]["temp"];
    temperature -= 273;
    float humidity = doc["main"]["humidity"];
    float windSpeed = doc["wind"]["speed"];
    String countryCode = doc["sys"]["country"];
    float latitude = doc["coord"]["lat"];
    float longitude = doc["coord"]["lon"];

    // Display on Serial Monitor
    Serial.println("Temperature: " + String(temperature) + " °C");
    Serial.println("Humidity: " + String(humidity) + " %");
    Serial.println("Wind Speed: " + String(windSpeed) + " m/s");
    Serial.println("Country Code: " + countryCode);
    Serial.println("Latitude: " + String(latitude));
    Serial.println("Longitude: " + String(longitude));

    // Upload data to Firebase
    uploadToFirebase(temperature, humidity, windSpeed, countryCode, latitude, longitude);
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();
}

void uploadToFirebase(float temperature, float humidity, float windSpeed, String countryCode, float latitude, float longitude) {
  // Create JSON payload for Firebase
  String firebaseData = "{\"temperature\":" + String(temperature) +
                        ",\"humidity\":" + String(humidity) +
                        ",\"wind_speed\":" + String(windSpeed) +
                        ",\"country_code\":\"" + countryCode + "\"" +
                        ",\"latitude\":" + String(latitude) +
                        ",\"longitude\":" + String(longitude) +
                        "}";

  // Make the HTTP request to update Firebase
  String firebaseUrl = "https://" + String(firebaseHost) + String(firebasePath) + "?auth=" + String(firebaseSecret);
  HTTPClient http;
  http.begin(firebaseUrl);
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.PUT(firebaseData);
  if (httpResponseCode == HTTP_CODE_OK) {
    Serial.println("Data uploaded to Firebase successfully");
  } else {
    Serial.println("Error uploading data to Firebase");
  }

  http.end();
}
