/*
 Joystick Shield Sample Sketch
 
 Reads the buttons and joystick position of SparkFun's Arduino
 Joystick Shield. The Joystick Shield is available from SparkFun's
 website:
 
 http://www.sparkfun.com/commerce/product_info.php?products_id=9490 
 
 created Nov. 23, 2009
 by Ryan Owens
*/

#include <Ethernet.h>
#include <SPI.h>
#include <ArdOSC.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 0, 0, 18 };

OSCServer server;
int serverPort = 12345;

OSCClient client;
int destPort = 12345;
byte destIP[4] =  { 10, 0, 0, 4 } ;


//Create variables for each button on the Joystick Shield to assign the pin numbers
char button0=3, button1=4, button2=5, button3=6;
char sel=2;
int incomingByte = 0;   // for incoming serial data

//create new osc message
OSCMessage global_mes;

byte sourceIp[]  = { 
  192, 168, 0, 4 };
  
  
void setup(void)
{
  pinMode(sel, INPUT);      //Set the Joystick 'Select'button as an input
  digitalWrite(sel, HIGH);  //Enable the pull-up resistor on the select button
  
  pinMode(button0, INPUT);      //Set the Joystick button 0 as an input
  digitalWrite(button0, HIGH);  //Enable the pull-up resistor on button 0

  pinMode(button1, INPUT);      //Set the Joystick button 1 as an input
  digitalWrite(button1, HIGH);  //Enable the pull-up resistor on button 1
  
  pinMode(button2, INPUT);      //Set the Joystick button 2 as an input
  digitalWrite(button2, HIGH);  //Enable the pull-up resistor on button 2

  pinMode(button3, INPUT);      //Set the Joystick button 3 as an input
  digitalWrite(button3, HIGH);  //Enable the pull-up resistor on button 3
  
  
  Ethernet.begin(mac, ip);
  server.begin(serverPort);
}

void loop(void)
{
    // read the incoming byte:
    incomingByte = analogRead(0);
  /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/x");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
 
     // read the incoming byte:
    incomingByte = analogRead(1);
  /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/y");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
    
    
        // read the incoming byte:
    incomingByte = digitalRead(sel);
  /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/select");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
    
        // read the incoming byte:
    incomingByte = digitalRead(button1);
  /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/up");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
    
        // read the incoming byte:
    incomingByte = digitalRead(button2);
    /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/down");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
    
        // read the incoming byte:
    incomingByte = digitalRead(button3);
    /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/left");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
    
        // read the incoming byte:
    incomingByte = digitalRead(button0);
    /************* // Send Serial messages to OSC ****************/
    global_mes.setAddress(destIP,destPort);
    global_mes.beginMessage("/joystick/right");
    global_mes.addArgInt32(incomingByte);
    client.send(&global_mes);
    global_mes.flush(); //object data clear
}


