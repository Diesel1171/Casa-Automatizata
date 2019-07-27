
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>;
#include <DHT.h>

Servo Servo1;
Servo Servo2;

char auth[] = "e705b7d0ff96418a899769faa1c177de";

char ssid[] = "Diesel";
char pass[] = "Carbon14";

#define DHTPIN 1         // TX
#define DHTTYPE DHT11    // DHT 11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Blynk.virtualWrite(V3, h);
  Blynk.virtualWrite(V4, t);

  const int  SenzorUmiditateSol = A0;
  int valoareSenzor = 0;
  int SM = 0; 
  valoareSenzor = analogRead(SenzorUmiditateSol);
  delay(50);
  SM = map(valoareSenzor, 850, 450, 0, 100); 
  
  Blynk.virtualWrite(V5, SM);

  const int SenzorGaz = 3;
  int ValoareSenzor = 0;
  
  ValoareSenzor = digitalRead(SenzorGaz);
  if(ValoareSenzor == 1)
   {
     Blynk.virtualWrite(V6, 1);
   }
    else
     {
       Blynk.virtualWrite(V6, 0);
     }
  
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  dht.begin();

  timer.setInterval(1000L, sendSensor);

    Servo1.attach(15); // NodeMCU D8 pin
    Servo2.attach(13); // NodeMCU D7 pin
}

void loop()
{
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V1)
{
   Servo1.write(param.asInt());
}

BLYNK_WRITE(V2)
{
   Servo2.write(param.asInt());
}
