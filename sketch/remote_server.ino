#include <Keyboard.h>
#include <Mouse.h>
#include <MemoryFree.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

int status = WL_IDLE_STATUS;
char SSID[] = "SSID";
char PASS[] = 'WPA KEY';
IPAddress server_ip(192,168,100,50);
IPAddress server_subnet(255,255,255,0);
IPAddress server_dns(8,8,8,8);
IPAddress server_gateway(192,168,100,1);

WiFiServer server(2290);

void setup(){
    Serial.begin(9600);
    delay(10000);
    wifi_setup();
    Keyboard.begin();
}

void wifi_setup(){
    WiFi.config(server_ip, server_dns, server_gateway, server_dns);
    while (status != WL_CONNECTED){
        status = WiFi.begin(SSID, PASS);
        delay(10000);
    }
    server.begin();
}

String string_split(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void in_parser(String receive){
    char payload[250];
    receive.toCharArray(payload, 250);
    String dump;
    ptr = strtok(payload, ",");
    while (ptr != NULL){
      if (ptr != "K"){
          String target_key = string_split(ptr, '.', 0);
          String target_delay = string_split(ptr, '.', 1);
          Keyboard.write(target_key.toInt());
          delay(target_delay.toInt());
        }
      ptr = strtok(NULL, ",");
   }
}

void loop(){
    client = server.available();
    if (client){
        String client_rec = "";
        while (client.connected()){
            if (client.available()){
                char _rec = client.read();
                client_rec += _rec;
            }
        }
        client.stop();
        in_parser(client_rec);
        client_rec = "";
    }
}