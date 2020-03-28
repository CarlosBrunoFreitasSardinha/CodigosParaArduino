int relay = D0;
int LUZ = D2;
 
void setup() {
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(LUZ, INPUT); 
}
 
void loop() {
  delay(500);
  if(!digitalRead(LUZ))digitalWrite(relay, HIGH);
  else digitalWrite(relay, LOW);
}
