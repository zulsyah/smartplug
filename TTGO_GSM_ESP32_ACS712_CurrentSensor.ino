#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define BLYNK_PRINT Serial
#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>
#include <BlynkSimpleTinyGSM.h>
#include <ACS712.h>

// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

#define SerialAT Serial1
#define SIM800L_RX     27
#define SIM800L_TX     26
#define SIM800L_PWRKEY 4
#define SIM800L_RST    5
#define SIM800L_POWER  23
#define LED_BLUE  13

BlynkTimer timer;

#define currentSensor 39
#define relay1Pin 33
#define relay2Pin 14
int mVperAmp = 100; // use 185 for 5A Module, 100 for 20A Module and 66 for 30A Module

double Voltage = 0;
double ACVoltage = 248;
double VRMS = 0;
double AmpsRMS = 0;
double analogBit = 4096.0;
int vin = 5;
int offsetWattRMS = 15;
String customerName= "AZ Putra";

char auth[] = "Your Blynk Auth Token";

// Your GPRS credentials
// Leave empty, if missing user or pass
char apn[]  = "Your APN"; //Celcom Malaysia APN
char user[] = "";
char pass[] = "";

String WiFiSSID = "Celcom";

bool result;
bool s1;
bool s2;

Adafruit_SH110X display = Adafruit_SH110X(64, 128, &Wire);
ACS712  ACS(currentSensor, 3.3, 4095, 100);
TinyGsm modem(SerialAT);

void setup(){
  pinMode(currentSensor, INPUT);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  pinMode(SIM800L_PWRKEY, OUTPUT);
  pinMode(SIM800L_RST, OUTPUT);
  pinMode(SIM800L_POWER, OUTPUT);

  digitalWrite(SIM800L_PWRKEY, LOW);
  digitalWrite(SIM800L_RST, HIGH);
  digitalWrite(SIM800L_POWER, HIGH);

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
  // Set GSM module baud rate
  SerialAT.begin(115200, SERIAL_8N1, SIM800L_TX, SIM800L_RX);
  delay(3000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  Serial.println("Initializing modem...");
  modem.restart();

  String modemInfo = modem.getModemInfo();
  Serial.print("Modem: ");
  Serial.println(modemInfo);

  // Unlock your SIM card with a PIN
  //modem.simUnlock("1234");

  Blynk.begin(auth, modem, apn, user, pass);
  digitalWrite(LED_BLUE, HIGH);
  
  result = Blynk.connected();

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
    display.println("Connected to GPRS");
  } else {
    display.println("Not connected to GPRS");
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
    display.println("Connected to GPRS");
  } else {
    display.println("Not connected to GPRS");  
    display.println("");
    display.println("Trying to connect...");
    display.println("");
    display.print("Telco : ");
    display.print(WiFiSSID);
  }
  display.display();
}
