#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6PxdYDaNO"
#define BLYNK_TEMPLATE_NAME "Test esp8266"
#define BLYNK_AUTH_TOKEN "F-ad5ugsG1Efr_paUECOZUXN-Zom1d5Z"
#define LINE_TOKEN  "CjVvvm4MlDmQNTZXxyKZzGTtYJ954MAytb76ObrL8kU"

int SensorPin = A0;
int SensorValue = 0;

#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "Tonnam"; // WiFi 2.4
char pass[] = "f18bcd9d7a45"; // WiFi password

int relay1 = 5;  // D5
int relay2 = 4;  // D4
int relay3 = 14; // D14
int relay4 = 12; // D12

int stateRelay1 = LOW;
int stateRelay2 = LOW;
int stateRelay3 = LOW;
int stateRelay4 = LOW;

#define DHTPIN 2      // D2 for the DHT22 sensor
#define DHTTYPE DHT22 // DHT22 (AM2302) sensor type
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void ControlRelay() {
  // Your control logic goes here
}

void sendSensorData();

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, stateRelay1);
  digitalWrite(relay2, stateRelay2);
  digitalWrite(relay3, stateRelay3);
  digitalWrite(relay4, stateRelay4);
  Serial.println(LINE.getVersion());
  WiFi.begin(ssid, pass);
  Serial.printf("WiFi connecting to %s\n", ssid);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }

  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);

  dht.begin();

  // Setup a timer to send sensor data every 10 seconds (adjust as needed)
  timer.setInterval(10000L, sendSensorData);
}

void loop() {
  SensorValue = analogRead(SensorPin);
  Serial.print("ค่าตรวจจับแก๊ส:   ");
  Serial.println(SensorValue);

  // ให้ระบบรอน้อยลงก่อนที่จะตรวจสอบอีกครั้ง
  delay(200);

  if (SensorValue >= 800) {
    Serial.println("Line");
    LINE.notify("ระดับเกินแก๊สกำหนดแล้ว");

    // รอจนกว่าค่า SensorValue จะต่ำกว่า 800
    while (SensorValue >= 800) {
      SensorValue = analogRead(SensorPin);
      delay(100);
    }
  }
  Blynk.run();
  timer.run();
}
