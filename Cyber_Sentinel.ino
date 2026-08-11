#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define BUZZER 25
#define RED_LED 18
#define GREEN_LED 19

void setup() {

  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("OLED Failed");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(1000);

  display.println("Cyber-Sentinel");
  display.println("Initializing...");
  display.display();

  delay(2000);
}

void loop() {

  display.clearDisplay();
  display.setCursor(0,0);

  display.println("Scanning...");
  display.display();

  int n = WiFi.scanNetworks();

  int threats = 0;

  Serial.println("--------------------------------");

  for(int i=0;i<n;i++){

      String ssid1 = WiFi.SSID(i);
      String mac1  = WiFi.BSSIDstr(i);

      Serial.print(ssid1);
      Serial.print("  ");
      Serial.print(mac1);
      Serial.print("  ");
      Serial.println(WiFi.RSSI(i));

      for(int j=i+1;j<n;j++){

          String ssid2 = WiFi.SSID(j);
          String mac2  = WiFi.BSSIDstr(j);

          if(ssid1==ssid2 && mac1!=mac2){

              threats++;

              Serial.println("***** POSSIBLE ROGUE AP *****");
              Serial.println(ssid1);

              digitalWrite(RED_LED,HIGH);
              digitalWrite(GREEN_LED,LOW);

              tone(BUZZER,2000);
              delay(300);
              noTone(BUZZER);

          }

      }

  }

  if(threats==0){

      digitalWrite(RED_LED,LOW);
      digitalWrite(GREEN_LED,HIGH);

  }

  display.clearDisplay();

  display.setCursor(0,0);
  display.println("Cyber Sentinel");
  display.println();

  display.print("WiFi : ");
  display.println(n);

  display.print("Threats : ");
  display.println(threats);

  if(threats>0)
      display.println("Status: ALERT");
  else
      display.println("Status: SAFE");

  display.display();

  delay(10000);

}
