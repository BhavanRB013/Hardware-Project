#include<ESP32_MailClient.h>
// #include<WiFi.h>

const char* ssid = "CIT-Campus";
const char* password = "citchennai";

#define emailSenderAccount "bhavanrb81@gmail.com"
#define emailSenderPassword "yztd ajqa glug vimc"
#define emailRecipient "bhavanrb567@gmail.com"
#define smptServer "smtp.gmail.com"
#define smtpServerPort 465
#define emailSubject "ESP32 Testing Email"

SMTPData smtpData;

int touchValue=0;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

    while(WiFi.status()!=WL_CONNECTED){
      Serial.print("*");
      delay(500);
    }

    Serial.println("Connected Successfully");
    // smtpData.setLogin(smptServer,smtpServerPort,emailSenderAccount,emailSenderPassword);
    // smtpData.setSender("ESP32 SENDER",emailSenderAccount);
    // smtpData.setPriority("HIGH");
    // smtpData.setSubject(emailSubject);
    

    // smtpData.addRecipient(emailRecipient);

    // if(!MailClient.sendMail(smtpData))
    //   Serial.println("ERROR in sending email "+MailClient.smtpErrorReason());
      
    //   smtpData.empty();
    
}

void loop() {

  
  smtpData.setLogin(smptServer,smtpServerPort,emailSenderAccount,emailSenderPassword);
  smtpData.setSender("ESP32 SENDER",emailSenderAccount);
  smtpData.setPriority("HIGH");
  smtpData.setSubject(emailSubject);

  touchValue = touchRead(4);
  Serial.print("The touch sensor value is: ");
  Serial.println(touchValue);

  if(touchValue < 90){
    smtpData.setMessage("The touch sensor value is below 90",false);
    smtpData.addRecipient(emailRecipient);
    
    if(!MailClient.sendMail(smtpData))
      Serial.println("ERROR in sending email "+MailClient.smtpErrorReason());
      smtpData.empty();
    
  }
  delay(10000);

}

void sendCallBack(SendStatus message){
  Serial.println(message.info());

  if(message.success()){
    Serial.print("+++++++++++++++++++++++");
  }
}
