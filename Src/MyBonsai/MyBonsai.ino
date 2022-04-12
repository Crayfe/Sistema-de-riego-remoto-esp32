/*PROGRAMA PARA CONTROLAR EL RIEGO DE UN BONSAI REMOTAMENTE CON UN NODE-MCU
* POR: @Crayfe
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "page.h" //Pagina HTML con javascript
#define RL 16  //Puerto del relé para endender y apagar la bomba de agua 

const char* ssid = "nombreWiFi";//Aquí va el nombre de la conexión wifi
const char* password = "contraseñaWiFi";//Aquí va la contraseña del wifi
String state = "Regar bonsái";
ESP8266WebServer server(80); //El puerto del servidor será el de por defecto


void handlePage() {
 String s = MAIN_page; //se carga la página html cargada en el archivo page.h
 server.send(200, "text/html", s);
}

void handleState() {
    server.send(200, "text/plane", state); 
}

void handleRelay() {
 String delayRelay = server.arg("Relay"); 
 digitalWrite(RL,LOW); //Relé ON
 server.send(200, "text/plane", "Regando...");
 delay(delayRelay.toInt());
 digitalWrite(RL,HIGH); //Relé off
 state = "Regar bonsái";
}
void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);     //Se conecta al WiFi introducido antes
  Serial.println("");
  pinMode(RL,OUTPUT);
  digitalWrite(RL, HIGH);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(""); 
  Serial.print("Connected to ");  
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //A priori no se sabe cual es su IP asignada, de modo que se envia por comunicación serial para saber cuál es
 
  server.on("/", handlePage);      
  server.on("/setRelay", handleRelay);
  server.on("/readState", handleState);
  server.begin();                  
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();          //En bucle se ejecuta el manejador de peticiones
}
