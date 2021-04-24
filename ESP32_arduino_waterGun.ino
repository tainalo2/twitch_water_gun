//--déclaration des bibliothèque--
//--Libraries declaration--
#include <WiFi.h>
#include <WebServer.h>
//----
//--déclaration des variables globales--
//--global variables declaration--
//infos pour connexion wifi (STA)
//WiFi connection info
const char* ssid = "Your_SSID";
const char* password = "Your_WiFi_password";

//webserver port
WebServer server(80);

//variable du GPIO pour controler le relai
//GPIO variable to control relay
const int relay = 26;
//----



//--Fonction de boot de l'ESP--
//--ESP boot function--
void setup() {
  //Fréquence de l'ESP32 pour téléverser correctement le code (unité : bauds)
  //ESP32 frequency to communicate with the PC (in baud)
  Serial.begin(115200);
  Serial.println("start");
  //On indique que la GPIO 26 va servir pour émettre un signal et non pour en recevoir.
  //Indicate to the relay GPIO will emit (and not receive) a signal.
  pinMode(relay, OUTPUT);
  //On indique que la GPIO 26 n'émet pas de signal
  //Indicate to the relay GPIO to emit nothing by default
  digitalWrite(relay, LOW);

  //Connexion au WIFI configuré et affiche l'IP distribuée dans la console
  //Connect to wifi and display the IP used by ESP32
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
    Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
}

  //On indique au serveur web de déclencher la fonction "handle_waterGun" dés qu'il recoit un requête sur l'URI "/waterGun"
  //When receive a HTTP request on "/waterGun" URI launch the function "handle_waterGun"
  server.on("/waterGun", handle_waterGun);
  //initialise le serveur web
  server.begin();
}
//----

//--Boucle d'exécution principale--
//--Principal loop once boot is finished--
void loop()
{
    //boucle principale (infini) du serveur web
    //infinite loop for webserver
    server.handleClient();
}
//----

//--Autre fonction appelée depuis le boot ou la boucle principale--
//--Other functions called from the principal loop--
void handle_waterGun() {
    //émet un signal sur le GPIO 26
    //Emit signal on relay GPIO (26)
    digitalWrite(relay, HIGH);
    //attend 0.5 secondes avant de passer à la suite
    //waiting 0.5 seconds
    delay(500);
    //stop l'émission sur le GPIO 26
    //Stop to emit signal on relay GPIO (26)
    digitalWrite(relay, LOW);
    server.send(200, "text/plain", "Requête bien reçu!");
}
//----
