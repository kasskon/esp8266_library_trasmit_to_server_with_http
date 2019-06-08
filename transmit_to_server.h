/*
//=======================================================================
           _   __                  _                  
          | | / /                 | |                 
          | |/ /   __ _  ___  ___ | | __  ___   _ __  
          |    \  / _` |/ __|/ __|| |/ / / _ \ | '_ \ 
          | |\  \| (_| |\__ \\__ \|   < | (_) || | | |
          \_| \_/ \__,_||___/|___/|_|\_\ \___/ |_| |_|
                                                        
//=======================================================================
  transmit_to_server.h - Library for transmition of data to a server.
  june 8, 2019.
*/
#ifndef transmit_to_server_h
#define transmit_to_server_h
#endif

#include "Arduino.h"
#include <ESP8266WiFi.h>

class transmit_to_server
{
  public:
  transmit_to_server(IPAddress IP ,int port);
  void transmit(String arg,String data);
	void change_ip(IPAddress new_ip);
	void change_port(int new_port);
  void connect_to_server();
  void server_commands(String url);
      private:
        WiFiClient client;
        int _port;
        int _IP;
};

