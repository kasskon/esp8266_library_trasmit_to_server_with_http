# esp8266 library trasmit to server with http
```
//=======================================================================
           _   __                  _                  
          | | / /                 | |                 
          | |/ /   __ _  ___  ___ | | __  ___   _ __  
          |    \  / _` |/ __|/ __|| |/ / / _ \ | '_ \ 
          | |\  \| (_| |\__ \\__ \|   < | (_) || | | |
          \_| \_/ \__,_||___/|___/|_|\_\ \___/ |_| |_|
                                                        
//=======================================================================
```

## the library has the fuctions 

```

  transmit_to_server(IPAddress IP ,int port);
  void transmit(String arg,String data);
  void change_ip(IPAddress new_ip);
  void change_port(int new_port);
  void connect_to_server();
  void server_commands(String url);
  
```

The trasmit_to_server can be implemented like: 

```
trasmit_to_server(ip,port) server;    //initialize the library
```

The the functions can be implemented like: 

```
server.connect_to_server();   // starts the connection to the server
server.transmit(arg,data);    //trasmit data to the server with http get request  //http//ip/data/?arg=data
server.change_ip(ip);         // change ip
server.change_port(port);     //change port
server.server_commands(url);  //reads data from the server with http get request

```

example


```
IPAddress ip=http://192.168.1.1
int port=80;
String arg="test"
String data="123t"

trasmit_to_server(ip,port) server;

server.connect_to_server();

server.transmit(arg,data);  //make a request http//ip/data/?test=123t


```
