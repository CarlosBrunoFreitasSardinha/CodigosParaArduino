#include <spi.h>    //Carregamos a livraria SPI incluida no IDE de Arduino
#include <RC522_RFID.h>   //Carregamos a livraria RC522_RFID de Paul Kourany
 
#include <SPI.h>
//Carregamos a livraria SPI incluida no IDE de Arduino
  //Carregamos a livraria RC522_RFID de Paul Kourany
 
#define SS_PIN 10   // Declaramos o pino SDA do Arduino
#define RST_PIN 9   // Declaramos o pino RST do Arduino
RFID rfid(SS_PIN, RST_PIN);   //Iniciamos o objeto RFID
 
String cardID;      //Declaramos uma variável de tipo string
                    //para armazenar o valor dos dados obtidos da
                    // etiqueta RFID
 
void setup() {
  Serial.begin(9600); //Iniciamos a comunicação serie para ler as respostas do módulo
  SPI.begin();        //Iniciamos a comunicação SPI
  rfid.init();        //Iniciamos o objeto RFID
}
 
void loop() {
  check_for_card();   //Comprovamos em laço se há um cartão perto do leitor chamando a função check_for_card()
}
 
void check_for_card()
{
 if (rfid.isCard()) {   //Se há um cartão perto do leitor...
   Serial.println("Se há um cartão perto do leitor"); //Mostramos uma mensagem pelo monitor serie
   if (rfid.readCardSerial()) {     //Lemos a ID do cartão
      cardID = String(rfid.serNum[0]) + String(rfid.serNum[1]) + String(rfid.serNum[2]) + String(rfid.serNum[3]) + String(rfid.serNum[4]);  //Le damos una formato de cadena de carácteres
      Serial.println(cardID);  //Mostramos no monitor série
      if (cardID == "4272516342312" || cardID == "4426315511437"){   //Se a ID é alguma detas 2...
        Serial.println("O cartão é válido");  //O cartão é válido!
        }else{   //Em caso contrario...
        Serial.println("O cartão é inválido"); //O cartão não é válido!
        }
       rfid.halt();  //Finalizamos o objeto RFID
       delay(1000);  //Pausa de 1 segundo para dar tempo a finalizar todas as ordens
     }
  }
}
