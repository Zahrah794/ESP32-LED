#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String url = "https://s-m.com.sa/s.html";
String payload = "";
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");

  


}

void loop() {
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println();
    Serial.println(payload);
    if( payload == "forward"){
      digitalWrite(33, HIGH);
    }
    else if(payload == "backward"){
      digitalWrite(32, HIGH);
    }
    else if(payload == "right"){
      digitalWrite(21, HIGH);

    }
    else if(payload == "left"){
      digitalWrite(19, HIGH);
    }
    else if(payload == "stop"){
      digitalWrite(33, LOW);
      digitalWrite(32, LOW);
      digitalWrite(21, LOW);
      digitalWrite(19, LOW);

    }
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }
  
}
