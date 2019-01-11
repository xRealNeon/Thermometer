#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#include "Config.h"

OneWire oneWire_in(inpin);
OneWire oneWire_out(outpin);

DallasTemperature sensor_inhouse(&oneWire_in);
DallasTemperature sensor_outhouse(&oneWire_out);

ESP8266WebServer server(80);

const int led = statusled;

String main = "<!DOCTYPE html><html><head>    <meta charset='utf-8'>    <meta name='author' content='NeoCode.'>    <meta name='description' content='A standalone web based Thermometer'>    <meta name='apple-mobile-web-app-capable' content='yes'>    <meta name='apple-mobile-web-app-status-bar-style' content='black'>    <meta name='apple-mobile-web-app-title' content='Thermometer'>    <meta name='mobile-web-app-capable' content='yes'>    <link href='https://fonts.googleapis.com/css?family=Roboto' rel='stylesheet'>    <link rel='stylesheet' href='style.css'>    <link rel='shortcut icon' type='image/png' href='https://xrealneon.github.io/Thermometer/web/icon.png'>    <script>        var version = 1.0;        var ip = '%URL%;        var key = '%KEY%';    </script>    <script src='main.js'></script>    <link rel='stylesheet' href='http://github.hubspot.com/odometer/themes/odometer-theme-default.css' />    <script src='http://github.hubspot.com/odometer/odometer.js'></script>    <title>Thermometer</title></head><body onload='init()'>    <table cellpadding='0' cellspacing='0' style='height:100%; width: 100%;'>        <tr>            <td><span class='odometer' id='upg'>0</span>°C</td>        </tr>        <tr>            <td><span class='odometer' id='downg'>0</span>°C</td>        </tr>    </table></body></html>";

void handleRoot() {
  if (server.arg("k") == key) {
    if (status_light) {
      digitalWrite(led, 1);
    }
    sensor_inhouse.requestTemperatures();
    sensor_outhouse.requestTemperatures();
    server.send(200, "text/html", main);
    if (status_light) {
      digitalWrite(led, 0);
    }
  } else {
    server.send(200, "text/plain", "Accsess denied!");
  }

}

void handleJson() {
  if (server.arg("k") == key) {
    if (status_light) {
      digitalWrite(led, 1);
    }
    sensor_inhouse.requestTemperatures();
    sensor_outhouse.requestTemperatures();
    server.send(200, "application/json", "{\"out\":" + String(sensor_outhouse.getTempCByIndex(0)) + ",\"in\":" + String(sensor_inhouse.getTempCByIndex(0)) + "}");
    if (status_light) {
      digitalWrite(led, 0);
    }
  } else {
    server.send(200, "text/plain", "Accsess denied!");
  }
}

void handleNotFound() {
  if (status_light) {
    digitalWrite(led, 1);
  }
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  if (status_light) {
    digitalWrite(led, 0);
  }
}

void setup(void) {
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("Thermometer")) {
    Serial.println("MDNS responder started");
  }

  sensor_inhouse.begin();
  sensor_outhouse.begin();

  server.on("/", handleRoot);
  server.on("/json", handleJson);

  server.begin();

  main.replace("%URL%", url);
  main.replace("%KEY%", key);

  if (status_light) {
    digitalWrite(led, 0);
  }
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
