#include <Wire.h>

int sensor = D0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly}
 
  int est;
  est = digitalRead(sensor);
  if (est == 0){
      Serial.println("Objeto Detectado!!!");
      delay(2000);
  }else{
      Serial.println("Objeto LONGE!!!");
      delay(2000);
  }

}
