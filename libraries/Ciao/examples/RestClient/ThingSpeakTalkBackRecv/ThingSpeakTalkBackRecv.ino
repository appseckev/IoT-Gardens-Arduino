#include <Wire.h>
#include <Ciao.h>

/* 

This example show the interaction between the Ciao Library and the Thingspeak Cloud. 
To run the example you need to register an account on thingspeak.com.
After that, you need to create a new channel and a new talkback app.
To create a new channel click the "Channels" section in the website (Channels -> My Channels -> New Channel).
To create a new talkback click the "Apps" section in the website (Apps -> TalkBack -> New TalkBack). 
Replace the APIKEY_TALKBACK and ID_TALKBACK values with the values reported in the API section of the site. 

*/

#define CONNECTOR     "rest" 
#define SERVER_ADDR   "api.thingspeak.com"

#define APIKEY_TALKBACK    "XXXXXXXXXXXXX"
#define ID_TALKBACK      "XXXX"


void setup() {

  Ciao.begin(); // CIAO INIT

}

void loop() {
  

      String request = "/talkbacks/";  
          request +=  ID_TALKBACK;
          request +=  "/commands/execute?api_key=";
          request +=  APIKEY_TALKBACK;
    
      Ciao.println("Read cmd from TalkBack Queue"); 
      CiaoData data = Ciao.read(CONNECTOR, SERVER_ADDR, request);
 
      String state = data.get(1);
      String response = data.get(2);
      
      if (!data.isEmpty()){
          Ciao.println( "State: " + String (data.get(1)) );
          Ciao.println( "Response: " + String (data.get(2)) );
        }
        else{ 
          Ciao.println ("Read Error OR EmptyQueue");
        }
 
  delay(30000); // Thinkspeak policy

}  
    
