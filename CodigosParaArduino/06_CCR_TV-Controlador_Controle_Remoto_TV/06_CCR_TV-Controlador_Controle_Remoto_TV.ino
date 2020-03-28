#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRtimer.h>
#include <IRutils.h>
#include <ir_Argo.h>
#include <ir_Daikin.h>
#include <ir_Fujitsu.h>
#include <ir_Gree.h>
#include <ir_Haier.h>
#include <ir_Kelvinator.h>
#include <ir_LG.h>
#include <ir_Magiquest.h>
#include <ir_Midea.h>
#include <ir_Mitsubishi.h>
#include <ir_Toshiba.h>
#include <ir_Trotec.h>

#include <IRremoteESP8266.h> //INCLUSÃO DE BIBLIOTECA
 
IRsend irsend(D5); //FUNÇÃO RESPONSÁVEL PELO MÉTODO DE ENVIO DO SINAL IR / UTILIZA O GPIO14(D5)
 
int tamanho = 68; //TAMANHO DA LINHA RAW(68 BLOCOS)
int frequencia = 32; //FREQUÊNCIA DO SINAL IR(32KHz)
 
// BOTÃO DESLIGA
unsigned int DL[100] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO LIGA 
unsigned int LA[100] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO EJECT
//unsigned int EJ[68] = {}; //UTILIZADO PARA APARELHOS DE SOM
// BOTÃO MUTE
unsigned int MT[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO PLAY / PAUSE
unsigned int PP[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO VOLTAR
unsigned int VT[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO ADIANTAR
unsigned int AT[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO UM
unsigned int UM[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO DOIS
unsigned int DOIS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO TRES
unsigned int TRES[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO QUATRO
unsigned int QUATRO[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO CINCO
unsigned int CINCO[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO SEIS
unsigned int SEIS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO SETE
unsigned int SETE[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO OITO
unsigned int OITO[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO NOVE
unsigned int NOVE[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO AUMENTAR VOLUME
unsigned int VMAIS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO ZERO
unsigned int ZERO[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO AVANÇAR CANAIS
unsigned int CMAIS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO ENTRADAS
unsigned int ENTRADAS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO DIMINUIR VOLUME
unsigned int VMENOS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO OK
unsigned int BOTAOOK[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
// BOTÃO VOLTAR CANAIS
unsigned int CMENOS[68] = {}; //COLE A LINHA RAW CORRESPONDENTE DENTRO DAS CHAVES
 
void setup(){
  irsend.begin(); //INICIALIZA A FUNÇÃO
  Serial.begin(115200); //INICIALIZA A PORTA SERIAL
}
void loop(){
    
    char c = Serial.read(); //VARIÁVEL RESPONSÁVEL POR RECEBER O CARACTER DIGITADO NA JANELA SERIAL
    
    if (c == 'a'){ //SE CARACTER DIGITADO FOR IGUAL A "a", FAZ
        irsend.sendRaw(LD,tamanho,frequencia);  // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Liga / Desliga");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'b'){ //SE CARACTER DIGITADO FOR IGUAL A "b", FAZ
        irsend.sendRaw(MT,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Mute");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'c'){ //SE CARACTER DIGITADO FOR IGUAL A "c", FAZ
        irsend.sendRaw(PP,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Play / Pause");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'd'){ //SE CARACTER DIGITADO FOR IGUAL A "d", FAZ
        irsend.sendRaw(VT,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Faixa Anterior");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'e'){ //SE CARACTER DIGITADO FOR IGUAL A "e", FAZ
        irsend.sendRaw(AT,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Proxima Faixa");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'f'){ //SE CARACTER DIGITADO FOR IGUAL A "f", FAZ
        irsend.sendRaw(UM,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Um");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'g'){ //SE CARACTER DIGITADO FOR IGUAL A "g", FAZ
        irsend.sendRaw(DOIS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Dois");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'h'){ //SE CARACTER DIGITADO FOR IGUAL A "h", FAZ
        irsend.sendRaw(TRES,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Tres");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'i'){ //SE CARACTER DIGITADO FOR IGUAL A "i", FAZ
        irsend.sendRaw(QUATRO,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Quatro");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'j'){ //SE CARACTER DIGITADO FOR IGUAL A "j", FAZ
        irsend.sendRaw(CINCO,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Cinco");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'k'){ //SE CARACTER DIGITADO FOR IGUAL A "k", FAZ
        irsend.sendRaw(SEIS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Seis");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'l'){ //SE CARACTER DIGITADO FOR IGUAL A "l", FAZ
        irsend.sendRaw(SETE,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Sete");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'm'){ //SE CARACTER DIGITADO FOR IGUAL A "m", FAZ
        irsend.sendRaw(OITO,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Oito");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'n'){ //SE CARACTER DIGITADO FOR IGUAL A "n", FAZ
        irsend.sendRaw(NOVE,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Nove");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'o'){ //SE CARACTER DIGITADO FOR IGUAL A "o", FAZ
        irsend.sendRaw(VMAIS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Aumentar Volume");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'p'){ //SE CARACTER DIGITADO FOR IGUAL A "p", FAZ
        irsend.sendRaw(ZERO,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Diminuir Volume");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'q'){ //SE CARACTER DIGITADO FOR IGUAL A "q", FAZ
        irsend.sendRaw(CMAIS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Proximo Canal");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'r'){ //SE CARACTER DIGITADO FOR IGUAL A "r", FAZ
        irsend.sendRaw(ENTRADAS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Mudar Entrada");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 's'){ //SE CARACTER DIGITADO FOR IGUAL A "s", FAZ
        irsend.sendRaw(VMENOS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Diminuir Volume");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 't'){ //SE CARACTER DIGITADO FOR IGUAL A "t", FAZ
        irsend.sendRaw(BOTAOOK,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: OK");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
    if (c == 'u'){ //SE CARACTER DIGITADO FOR IGUAL A "u", FAZ
        irsend.sendRaw(CMENOS,tamanho,frequencia); // PARÂMETROS NECESSÁRIOS PARA ENVIO DO SINAL IR
        Serial.println("Comando enviado: Canal Anterior");
        delay(50); // TEMPO(EM MILISEGUNDOS) DE INTERVALO ENTRE UM COMANDO E OUTRO
    }
}

