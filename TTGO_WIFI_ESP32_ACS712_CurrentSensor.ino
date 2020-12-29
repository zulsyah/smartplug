#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ACS712.h>

BlynkTimer timer;

#define currentSensor 39
#define relay1Pin 33
#define relay2Pin 14
#define LED_BLUE 13
#define BLYNK_PRINT Serial

int mVperAmp = 100; // use 185 for 5A Module, 100 for 20A Module and 66 for 30A Module

//double Voltage = 0;
double ACVoltage = 248;
//double VRMS = 0;
//double AmpsRMS = 0;
double analogBit = 1024.0;
//int offsetWattRMS = 25;
String customerName= "AZ Putra";

char auth[] = "Your Blynk Auth Token";

String WiFiSSID = "Your SSID";
char ssid[] = "Your SSID";
char pass[] = "Your WiFi password";

bool result;
bool s1;
bool s2;

Adafruit_SH110X display = Adafruit_SH110X(64, 128, &Wire);
ACS712  ACS(currentSensor, 3.3, 4096, 100);

void setup(){
  pinMode(currentSensor, INPUT);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
  Serial.begin(115200);

  display.begin(0x3C, true); // Address 0x3C default
  
  display.display();
  delay(1000);
  // Clear the buffer.
  display.clearDisplay();
  display.display();
  
  displayOLEDStartup();
  Blynk.begin(auth, ssid, pass);
  
  result = Blynk.connected();
  digitalWrite(LED_BLUE, HIGH);

  timer.setInterval(500L, sendPowerData);
  timer.setInterval(500L, sendCurrentData);
  timer.setInterval(250L, displayOLEDStatus);
}

void loop(){
  
  Blynk.run();
  timer.run();
}

float getVPP(){
  float result;
  
  int readValue; //value read from the sensor
  int maxValue = 0; // store max value here
  int minValue = analogBit; // store min value here
  
  uint32_t start_time = millis();
  
  while((millis()-start_time) < 250) //sample for 1 Sec
  {
  readValue = analogRead(currentSensor);
  //Serial.println(readValue);
  // see if you have a new maxValue
  if (readValue > maxValue)
  {
  /*record the maximum sensor value*/
  maxValue = readValue;
  }
  if (readValue < minValue)
  {
  /*record the maximum sensor value*/
  minValue = readValue;
  }
  }
  
  // Subtract min from max
  result = ((maxValue - minValue) * 5)/analogBit;
  
  return result;
}

void sendPowerData(){
  
//  Voltage = getVPP();
//  VRMS = (Voltage/2.0) *0.707; // sq root
//  AmpsRMS = (VRMS * 1000)/mVperAmp;
//  float Wattage = (ACVoltage*AmpsRMS)-offsetWattRMS; //Observed 18-20 Watt when no load was connected, so substracting offset value to get real consumption.
//  if (Wattage < 0){
//    Wattage = 0;
//  }

  double mA = ACS.mA_AC();
  Blynk.virtualWrite(V20, mA/1000 * ACVoltage);
}

void sendCurrentData(){

//  Voltage = getVPP();
//  VRMS = (Voltage/2.0) *0.707; // sq root
//  AmpsRMS = (VRMS * 1000)/mVperAmp;

  double mA = ACS.mA_AC();
  Blynk.virtualWrite(V21, mA/1000);
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
//  Serial.println(pinValue);
  if (pinValue == 1){
    digitalWrite(relay1Pin, LOW);
    s1 = true;
  } else {
    digitalWrite(relay1Pin, HIGH);
    s1 = false;
  }
  
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
  if (pinValue == 1){
    digitalWrite(relay2Pin, LOW);
    s2 = true;
  } else {
    digitalWrite(relay2Pin, HIGH);
    s2 = false;
  }
  
}

void displayOLEDStatus(){
  
//  Voltage = getVPP();
//  VRMS = (Voltage/2.0) *0.707; // sq root
//  AmpsRMS = (VRMS * 1000)/mVperAmp;
//  float Wattage = (ACVoltage*AmpsRMS)-offsetWattRMS; //Observed 18-20 Watt when no load was connected, so substracting offset value to get real consumption.
//
//  if (Wattage < 0){
//    Wattage = 0;
//  }
//  Serial.print(AmpsRMS);
//  Serial.println(" Amps RMS ");
//  Serial.print(Wattage);
//  Serial.println(" Watt ");
  display.clearDisplay();
  // Code for OLED Screen
  display.setRotation(1);
  display.setTextSize(1.5);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.println("Hi " + customerName);

  if (result){
    display.println("Connected to WiFI");
  } else {
    display.println("Not connected to WiFI");
  }

  double mA = ACS.mA_AC();
  Serial.print("Current : ");
  Serial.print(mA/1000);
  Serial.print("A | Power : ");
  Serial.print(mA/1000 * ACVoltage);
  Serial.println(" watts");
  
//  display.println("");
//  display.print("Current : ");
//  display.print(AmpsRMS);
//  display.println("A");
//  display.print("Power : ");
//  display.print(Wattage);
//  display.println(" watts");
//  display.println("");
//  display.print("S1 : ");

  display.println("");
  display.print("Current : ");
  display.print(mA/1000);
  display.println("A");
  display.print("Power : ");
  display.print(mA/1000 * ACVoltage);
  display.println(" watts");
  display.println("");
  display.print("S1 : ");
  
  if (s1){
    display.print("On | S2 : ");
  } else {
    display.print("Off | S2 : ");
  }

  if (s2){
    display.println("On");
  } else {
    display.println("Off");
  }
  
  display.println("Total usage: RM20");
  display.display(); // actually display all of the above
}

void displayOLEDStartup(){

  display.clearDisplay();
  // Code for OLED Screen
  display.setRotation(1);
  display.setTextSize(1.5);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.println("Hi " + customerName);

  if (result){
    display.println("Connected to WiFI");
  } else {
    display.println("Not connected to WiFI");  
    display.println("");
    display.println("Trying to connect...");
    display.println("");
    display.print("SSID: ");
    display.print(WiFiSSID);
  }
  display.display();
}
