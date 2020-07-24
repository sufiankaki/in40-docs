#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor

#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 2

DHT dht(dht_dpin, DHTTYPE); 

const char* WiFi_ssid = "IN4.0 Talent Academy";
const char* WiFi_password = "password";

const char* mqtt_server = "mqtt.iot.atria.edu";
int mqtt_port = 1883;
const char* mqtt_username = "in40talent";
const char* mqtt_password = "password";

const char* subtopic = "subscribe";
const char* pubtopic = "publish";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  pinMode(2, OUTPUT);     // Initialize the 2 pin as an output
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  dht.begin();
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(WiFi_ssid, WiFi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(subtopic);
  Serial.print("] ");
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32", mqtt_username, mqtt_password)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(pubtopic, "hello world");
      // ... and resubscribe
      client.subscribe(subtopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

    float h = dht.readHumidity();
    float t = dht.readTemperature();         

    snprintf (msg, 20, "Temperature: %.2f", t);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(pubtopic, msg);

    snprintf (msg, 20, "Humidity: %.2f", h);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(pubtopic, msg);
    

    delay(5000);
}
