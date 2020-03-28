
int microfone = D0;// pino 8 digital para o microfone
int relay1 = D1;//pino do relay
void setup() {                
  Serial.begin(9600);
  pinMode(microfone, INPUT);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
}
 
//0 sensor ativado

void loop() {
  
  Serial.println( digitalRead(microfone) );
  delay(500);
 
}
