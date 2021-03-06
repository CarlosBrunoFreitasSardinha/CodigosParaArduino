#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "Rocha Sardinha";
const char* password = "vida2017";

IPAddress ip(10, 0, 1, 57); //IP do ESP (para voce acessar pelo browser)
IPAddress gateway(10, 0, 1, 1); //IP do gateway da sua rede wifi
IPAddress subnet(255, 255, 255, 0); //Mascara de rede da sua rede wifi
WiFiServer server(80); //Servidor web na porta 80

void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(D4, 1);
  digitalWrite(D3, 1);
  digitalWrite(D2, 1); //Preparando o GPI, que esta lidago ao RELE
  WiFi.config(ip, gateway, subnet); //Conectando
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  server.begin();  //Iniciando o servidor Web
}

void loop() {
  WiFiClient client = server.available();  //Verificando se o servidor esta pronto.
  if (!client) { return;}
  while (!client.available()) { delay(1); }//Verificando se o servidor recebeu alguma requisicao
  String req = client.readStringUntil('\r');   //Obtendo a requisicao vinda do browser
  client.flush();
  String buf = "";   //Iniciando o buffer que ira conter a pagina HTML que sera enviada para o browser.
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  buf += "<h3>Utilizando o NODEMCU com Rele</h3>";
  buf += "<p>RELE 4<a href=\"?function=RELE4_on\"><button>LIGA</button></a><a href=\"?function=RELE4_off\"><button>DESLIGA</button></a></p>";
  buf += "<p>RELE 3<a href=\"?function=RELE3_on\"><button>LIGA</button></a><a href=\"?function=RELE3_off\"><button>DESLIGA</button></a></p>";
  buf += "<p>RELE 2<a href=\"?function=RELE2_on\"><button>LIGA</button></a><a href=\"?function=RELE2_off\"><button>DESLIGA</button></a></p>";
  buf += "</html>\n";
  client.print(buf);  //Enviando para o browser a 'pagina' criada.
  client.flush();

  if (req.indexOf("RELE4_on") != -1){
      digitalWrite(D4, 0);
   }
    else if (req.indexOf("RELE4_off") != -1){
          digitalWrite(D4, 1);
       }
  if (req.indexOf("RELE3_on") != -1){
      digitalWrite(D3, 0);}
  else if (req.indexOf("RELE3_off") != -1){
      digitalWrite(D3, 1);}
  if (req.indexOf("RELE2_on") != -1){
      digitalWrite(D2, 0);}
  else if (req.indexOf("RELE2_off") != -1){
    digitalWrite(D2, 1);}
  
  
  else {client.stop();}
}

