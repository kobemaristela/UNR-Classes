#include "secrets.h" //Imports certificates to connect to AWS | WIFI SSID and Password 
#include <WiFiClientSecure.h> // Library used to support secure connections using TLS(SSL) for the ESP32. It helps authenicate the server and negotiates an encrypted connection between the server and ESP
#include <MQTTClient.h> //Library used as a messaging protocal for IOT devices that runs an MQTT library and connects to an MQTT broker over a network
#include <ArduinoJson.h> //JSON library for embedded C++ code that supports serialization, deserialization, message packs, fixed allocation, etc.
#include "WiFi.h" //Library that allows the ESP 32 to connect to wifi/internet
#include "analogWrite.h"// Library that allows for you convert the value of the voltage on an analog input pin and return the digital value tha can be used for an output

//These must be GPIO Pins
//Speed pins must be PWMed to control turns

//------------------------------------------------
//Setting up the motors speed and rotational values
int LeftMotorSpeedPin1 =  21;
int LeftMotorRotationPin1 = 23;
int LeftMotorRotationPin2 = 22;

int RightMotorSpeedPin1 = 19;
int RightMotorRotationPin1 = 17;
int RightMotorRotationPin2 = 16;
//------------------------------------------------

/// Initialize topics
#define AWS_IOT_PUBLISH_TOPIC   "KAR-pi/action" // The MQTT topics that this device should publish/subscribe
#define AWS_IOT_SUBSCRIBE_TOPIC "KAR-pi/action" // The name for the topics are "KAR-pi/action"

WiFiClientSecure net = WiFiClientSecure(); //Creates a new Wifi client that handles TLS encrypted WiFi connections to a remote server or client
MQTTClient client = MQTTClient(256); //Used to changed the maximum size for packets being published and received to 256 bytes from 128

//------------------------------------------------
//function to connect ESP 32 to the AWS Iot
void connectAWS()
{
  WiFi.mode(WIFI_STA);//Changes the WiFi mode to Station(STA), which is used to get the ESP module connected to a WiFi network established by an access point
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //Connecting to WiFi network using the SSID and password

  Serial.println("Connecting to Wi-Fi"); //Prints to the serial monitor that the ESP is connecting to the WiFi

  while (WiFi.status() != WL_CONNECTED){//function that confirms if the device connected to the WiFi
    delay(500);
    Serial.print(".");
  }

  //Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  //Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  //Create a message handler
  client.onMessage(messageHandler);

  Serial.println("Connecting to AWS IOT");

  while (!client.connect(THINGNAME)) {// checks to see if the ESP 32 is connected or not
    Serial.print(".");
    delay(100);
  }

  if(!client.connected()){
    Serial.println("AWS IoT Timeout!");
    return;
  }

  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
  Serial.println("AWS IoT Connected!");
}
//------------------------------------------------


void messageHandler(String &topic, String &payload) {

  //Strips payload for comparison - could be optimized using Regex
  char str_array[payload.length()];
  payload.toCharArray(str_array, payload.length());


  //example of a right turn with pwm after recieveing mqtt right
  //these two sets of pins control direction that motors spin
  //https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/
  //see truth table in above link to see what outputs match which directions
  //both pins set to all high or all low will turn it off

  // Pin1: LOW | Pin2: HIGH --> Forward
  if (strstr(str_array, "right") != NULL)
  {
  str_array[strlen(str_array) - 1]  = '\0';
  Serial.println(strstr(str_array, "right"));


  //runs left wheel at half speed to turn right
  analogWrite(LeftMotorSpeedPin1, 50);
  analogWrite(RightMotorSpeedPin1, 200);

  //Right Motor - Spin Forward
  digitalWrite(RightMotorRotationPin1, HIGH);
  digitalWrite(RightMotorRotationPin2, LOW);

  //Left Motor - Spin Backwards
  digitalWrite(LeftMotorRotationPin1, LOW);
  digitalWrite(LeftMotorRotationPin2, HIGH);
  }

  if (strstr(str_array, "left") != NULL)
    {
    //Parsed string payload for keyword 'forward'
    str_array[strlen(str_array) - 1]  = '\0';
    Serial.println(strstr(str_array, "left"));


    //runs right wheel at half speed to turn left
    analogWrite(LeftMotorSpeedPin1, 200);
    analogWrite(RightMotorSpeedPin1, 50);

    //Right Motor - Spin Backwards
    digitalWrite(RightMotorRotationPin1, LOW);
    digitalWrite(RightMotorRotationPin2, HIGH);

    //Left Motor - Spin Forward
    digitalWrite(LeftMotorRotationPin1, HIGH);
    digitalWrite(LeftMotorRotationPin2, LOW);
    }

  if (strstr(str_array, "forward") != NULL)
    {
    //Parsed string payload for keyword 'forward'
    str_array[strlen(str_array) - 1]  = '\0';
    Serial.println(strstr(str_array, "forward"));


    //Sets motor speed to max
    digitalWrite(LeftMotorSpeedPin1, HIGH);
    digitalWrite(RightMotorSpeedPin1, HIGH);

    //Right Motor - Spin Forward
    digitalWrite(RightMotorRotationPin1, LOW);
    digitalWrite(RightMotorRotationPin2, HIGH);

    //Left Motor - Spin Forward
    digitalWrite(LeftMotorRotationPin1, LOW);
    digitalWrite(LeftMotorRotationPin2, HIGH);
    }

    if (strstr(str_array, "backwards") != NULL)
    {
    //Parsed string payload for keyword 'backwards'
    str_array[strlen(str_array) - 1]  = '\0';
    Serial.println(strstr(str_array, "backwards"));


    //Sets motor speed to max
    digitalWrite(LeftMotorSpeedPin1, HIGH);
    digitalWrite(RightMotorSpeedPin1, HIGH);

    //Right Motor - Spin Backwards
    digitalWrite(RightMotorRotationPin1, HIGH);
    digitalWrite(RightMotorRotationPin2, LOW);forward

    //Left Motor - Spin Backwards
    digitalWrite(LeftMotorRotationPin1, HIGH);
    digitalWrite(LeftMotorRotationPin2, LOW);
    }


  // Turn off motor after .5 sec delay
  delay(500);
  digitalWrite(RightMotorRotationPin1, LOW);
  digitalWrite(RightMotorRotationPin2, LOW);
  
  digitalWrite(LeftMotorRotationPin1, LOW);
  digitalWrite(LeftMotorRotationPin2, LOW);

  *str_array = NULL;

}

// Initialize variables
void setup() {
  Serial.begin(9600);//Sets the date rate of baud to 9600 bits per second for serial data transmission
  connectAWS(); //calls function to connect to AWS and WiFi

  //  Initialize Motors
  pinMode(LeftMotorSpeedPin1, OUTPUT);
  pinMode(LeftMotorRotationPin1, OUTPUT);
  pinMode(LeftMotorRotationPin2, OUTPUT);

  pinMode(RightMotorSpeedPin1, OUTPUT);
  pinMode(RightMotorRotationPin1, OUTPUT);
  pinMode(RightMotorRotationPin2, OUTPUT);

}

void loop() {
  client.loop();

}
