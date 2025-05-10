#include <WiFi.h>
#include <WebServer.h>


const char* user = "hytalo";
const char* password = "lionel16";

int ledPinVerde = 18;
int ledPinVermelho = 5;

int ledVerdeState = 0;
int ledVermelhoState = 0;


WebServer server(80);

  void retornaHtml(){
   String html = "<html><body><h1>Painel de controle</h1><p>liga o led <a href='/vermelho'> vermelho </a></p><p>liga o led <a href='/verde'> verde </a></p></body><html>";    
   server.send(200,"text/html",html);   
  }
  void gerenciaLedVerde(){
    if(ledVerdeState == 0){
      digitalWrite(ledPinVerde,1);
      ledVerdeState = 1;     
    }else{
    digitalWrite(ledPinVerde,0);
    ledVerdeState = 0;
    }
    retornaHtml();
  }
  void gerenciaLedVermelho(){    
    if(ledVermelhoState == 0){
      digitalWrite(ledPinVermelho,1);
      ledVermelhoState = 1;
    }else{
      digitalWrite(ledPinVermelho,0);
      ledVermelhoState = 0;
    }
    retornaHtml();
  }
void setup() {
  Serial.begin(115200);
  pinMode(ledPinVermelho, OUTPUT);
  digitalWrite(ledPinVermelho, 0);
  pinMode(ledPinVerde, OUTPUT);
  digitalWrite(18, 0);
  WiFi.begin(user,password);
  Serial.println("Conectando ao WiFi");
  while(WiFi.status() != WL_CONNECTED ){
    delay(1000);
    Serial.print(".");  
  }  
    
  Serial.print("Endereço IP:");  
  Serial.println(WiFi.localIP());

  server.on("/",HTTP_GET, retornaHtml);
  server.on("/vermelho",HTTP_GET,gerenciaLedVermelho);
  server.on("/verde",HTTP_GET,gerenciaLedVerde);
  server.begin();
}

void loop() {
  server.handleClient();  
}
