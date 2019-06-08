/*
//=======================================================================
           _   __                  _                  
          | | / /                 | |                 
          | |/ /   __ _  ___  ___ | | __  ___   _ __  
          |    \  / _` |/ __|/ __|| |/ / / _ \ | '_ \ 
          | |\  \| (_| |\__ \\__ \|   < | (_) || | | |
          \_| \_/ \__,_||___/|___/|_|\_\ \___/ |_| |_|
                                                        
//=======================================================================
  transmit_to_server.cpp - Library for transmition of data to a server.
   june 8, 2019.
*/

#include "Arduino.h"
#include "transmit_to_server.h"
#include <ESP8266WiFi.h>

transmit_to_server::transmit_to_server(IPAddress IP , int port)
{
  WiFi.mode(WIFI_STA);
  _port = port;
  _IP = IP;
  WiFiClient client;

}

void transmit_to_server::transmit(String arg, String data)
{
  if (!client.connect(_IP, _port)) {
    Serial.println("connection failed");
    return;
  }
  //ip/data/?arg=data
  String url = "/data/";
  url += "?" + arg + "=";
  url += data;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + _IP + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}

void transmit_to_server::server_commands(String url)
{
  if (!client.connect(_IP, _port)) {
    Serial.println("connection failed");
    return;
  }


  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + _IP + "\r\n" +
               "Connection: close\r\n\r\n");
  while (client.connected() || client.available())
  {
    if (client.available())
    {
      String line = client.readStringUntil('\n');
      Serial.println(line);
    }
  }

}


void transmit_to_server::connect_to_server()
{
  if (!client.connect(_IP, _port)) {
    Serial.println("connection failed");
    return;
  }
}

void transmit_to_server::change_ip(IPAddress new_ip)
{
  _IP = new_ip;
}


void transmit_to_server::change_port(int new_port)
{
  _port = new_port;
}