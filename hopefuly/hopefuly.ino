#include <DallasTemperature.h>
#include <OneWire.h>

#define ONEWIRE 7
#define aref_voltage 3.3

OneWire oneWire(ONEWIRE);
DallasTemperature sensors(&oneWire);

int led1 = 13;
int led2 = 12;
float previous;

void setup(void) {
  // put your setup code here, to run once:
  Serial.print("Booting...");
  sensors.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);   
  Serial.begin(115200);
}
  
  void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(0);
  float voltage = reading * 5.0;
  voltage /= 1024;
  
  Serial.print(voltage);
  Serial.print(" Volts     ");
  
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  Serial.print(" *C     ");
  
  float temperatureF = (temperatureC * (9.0/5.0)) + 32;
  Serial.print(temperatureF);
  Serial.print(" *F     ");
  
  float change = temperatureF - previous;
  
  Serial.println(change);
  
  if(change > 0)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  if(change < 0)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }

  
  previous = temperatureF;
  
  delay(1000);
  //delay(500);
  //digitalWrite(led1, HIGH);
  //delay(500);
  //digitalWrite(led2, HIGH);
  //delay(500);
  //digitalWrite(led1, LOW);
  //delay(500);
  //digitalWrite(led2, LOW);
}  
