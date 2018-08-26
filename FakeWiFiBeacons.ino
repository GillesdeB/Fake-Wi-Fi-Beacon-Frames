/* FakeBeaconESP8266.ino
 *    Fake beacon frames on ESP8266 using the Arduino IDE
 *  
 *  Functions:
 *  - Blink the onboard blue LED on the ESP-01 module as proof of life beacon (connected to GPIO1 = D10)
 *  - Press the push button to select a different jam behavior (type of SSIDs generated)
 *  - Light an external LED connected to D1 when the button is pushed
 *
 * Based on:
 *  - http://nomartini-noparty.blogspot.com/2016/07/esp8266-and-beacon-frames.html
 *  - https://github.com/kripthor/WiFiBeaconJam)
 *  - 802.11 mngmt: Beacon Frame https://mrncciew.com/2014/10/08/802-11-mgmt-beacon-frame/
 *  - Declaration of Independence of Cyberspace as SSIDs https://pastebin.com/dffvBMwC
 *  
 *  ToDo: 
 *    Move interesting code from Fake_Beacon_Original.ino and erase
 *    Add more poetry
 *  
 *  Updated: 2018-08-25 Gilles de Bordeaux
 */

#include <ESP8266WiFi.h>
#include "BeaconPackets.h"
#include "DevTools.h"
#include "SSIDs.h"

extern "C" {
  #include "user_interface.h"
}

#define ButtonPushed HIGH                         // To ground = LOW, to 5V = HIGH

// ----- Timer
unsigned long previousMillis_LED = 0;
unsigned long nextInterval = 0;
unsigned long delayBetweenPacketBroadcasts = 1;   // milliseconds
unsigned long delayFailedPacketBroadcast = 2000;  // milliseconds

const uint32_t attackTimeInMs = 0;              // Repeat beacon spam attack every x ms
uint32_t currentTime = 0;
uint32_t attackTime = 0;

// ----- LED's
const int LED_1 = LED_BUILTIN;
const int LED_2 = D2;
const long LED_flashInterval = 5000;
const long LED_flashDuration = 50;
enum ledStates{lightOn, lightOff};    
int led_State = LOW;     

// ----- Push button
const int pushButton = D1;
int pushButtonbuttonAuthorized = true;

// -----Jam behavior
enum jamBehaviors { _RickRoll, _ssidWifiAndBroadband, _SsidFunny, _ssidNamesToAvoid, _sendBeacon, _sendRandomBeacon,_sendFuzzedBeacon, _declarationOfIndependance };
int jamBehavior = _RickRoll;

// ----- Change behavioral state if pushbutton pressed
void checkPushButton () {
  unsigned int _delay = 200;
  unsigned long lastMillis = 0;
  
  lastMillis = millis();
  while (digitalRead(pushButton) == ButtonPushed && pushButtonbuttonAuthorized == true)
   {
      ledState(LED_2, lightOn, true);
      if((millis() - lastMillis) > _delay)
      {
          //Serial.print("Button Pressed: ");
          incrementJamBehavior();
          Serial.print("Behavior="); Serial.println(jamBehavior);
          while(digitalRead(pushButton) == ButtonPushed);
      }
   }
   ledState(LED_2, lightOff, true);
}

// ----- Set next behavioral state
void incrementJamBehavior() {
  if (++jamBehavior > _declarationOfIndependance) {
    jamBehavior = 0;
  }
}

// ----- Flash the internal blue LED as proof of life
void flashProofOfLifeLed () {
  unsigned long currentMillis = millis();
  if((currentMillis - previousMillis_LED) >= nextInterval) {
    previousMillis_LED = currentMillis;   
    if (led_State == LOW) {
      led_State = HIGH;
      ledState(LED_1, lightOn, false);
      nextInterval = LED_flashDuration;
    }
    else {
      led_State = LOW;
      ledState(LED_1, lightOff, false);
      nextInterval = LED_flashInterval;
    }
  }
}

// ----- Switch LED on or off
void ledState(int LED, ledStates state, bool reversed) {
  if (reversed==false){
    if (state == lightOn) digitalWrite(LED, LOW); else digitalWrite(LED, HIGH);
  }
  else{
    if (state == lightOn) digitalWrite(LED, HIGH); else digitalWrite(LED, LOW);
  }
  //char temp[80];
  //snprintf ( temp, 80, "LED port:%02d, state:%01d, reversed:%01d", LED, state, reversed);
  //Serial.println(temp);
}

// ----- Behavior - SSID = random text
void sendRandomBeacon(int len) {
  char ssid[len+1];                     // +1 char for the 0x00 end of string char
  randomSSID(len, ssid);
  sendBeacon(ssid);
}

void randomSSID(int len, char* ssid) {
  String alfa = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ _-@#$&*";
  const int alfaSize = sizeof(alfa);
  
  for(int i = 0; i < len; i++) {
    ssid[i] = alfa[random(alfaSize)];
  }
  ssid[len] = 0x00;                     // End of string
}

// ----- Behavior - SSID = text passed+random text
void sendFuzzedBeacon(char* baseSsid, int len, int howMany) {
  char ssidBuffer[33];
  int baseLength = strlen(baseSsid);
  int restLength = 32 - baseLength;
  char randomSsid[33];
                                        // Set leading character of SSID
  memcpy((char*)ssidBuffer, (char*)baseSsid, baseLength);
 
  for(int i=0; i < howMany; i++) {      // Number of SSIDs to generate
    randomSSID(restLength, randomSsid);    // Random characters after the base
    memcpy((char*)ssidBuffer[baseLength], (char*)randomSSID, restLength);
    ssidBuffer[len] = 0x00;
    Serial.print("New SSID: "); Serial.println(ssidBuffer[0]);
    
    sendBeacon(ssidBufferSsid);
  }
}

// ----- Behavior - SSID = each line of the Declaration Of Independance In Cyberspace
void sendDeclarationOfIndependance() {
  for(int i=0; i<ssidsDoIoCSize; i++){
    buildPacket(ssidsDoIoC[i], ssids[i]);
    wifi_set_channel(ssids[i].channel);
    _sendPacket(_packet, _packetSize);
  }
}

// ----- Behavior - SSID = each line of the Rick Roll song
void sendRickRoll() {
  for(int i=0; i<ssidRickRollSize; i++){
    buildPacket(ssidRickRoll[i], ssids[i]);
    wifi_set_channel(ssids[i].channel);
    _sendPacket(_packet, _packetSize);
  }
}

// ----- Behavior - SSID = Wi-fi and Broadband poem
void sendWifiAndBroadband() {
  for(int i=0; i<ssidWifiAndBroadbandSize; i++){
    buildPacket(ssidWifiAndBroadband[i], ssids[i]);
    wifi_set_channel(ssids[i].channel);
    _sendPacket(_packet, _packetSize);
  }
}

// ----- Behavior - SSID = SSID names to avoid
void sendNamesToAvoid() {
  for(int i=0; i<ssidNamesToAvoidSize; i++){
    buildPacket(ssidNamesToAvoid[i], ssids[i]);
    wifi_set_channel(ssids[i].channel);
    _sendPacket(_packet, _packetSize);
  }
}

// ----- Behavior - SSID = each line of the Rick Roll song
void sendSsidFunny() {
  for(int i=0; i<ssidFunnySize; i++){
    buildPacket(ssidFunny[i], ssids[i]);
    wifi_set_channel(ssids[i].channel);
    _sendPacket(_packet, _packetSize);
  }
}

// ----- Send a beacon frame
void sendBeacon(char* ssid) {                                     
    //wifi_set_channel(channel);         /* Channel */
                                        /* Beacon Packet buffer */
    uint8_t packet[128] = { 0x80, 0x00, //Frame Control 
                    /*2*/   0x00, 0x00, //Duration
                    /*4*/   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //Destination address 
                    /*10*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //Source address - overwritten later
                    /*16*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //BSSID - overwritten to the same as the source address
                    /*22*/  0xc0, 0x6c, //Seq-ctl
                                        /* Frame body starts here */
                    /*24*/  0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, //timestamp - # microseconds AP has been active
                    /*32*/  0xFF, 0x00, //Beacon interval // 0x64, 0x00,
                    /*34*/  0x01, 0x04, //Capability info                                       
                    /*36*/  0x00        /* SSID */
    };
                                        // Randomize source MAC address and BSSID
    packet[10] = packet[16] = random(256);
    packet[11] = packet[17] = random(256);
    packet[12] = packet[18] = random(256);
    packet[13] = packet[19] = random(256);
    packet[14] = packet[20] = random(256);
    packet[15] = packet[21] = random(256);
                    /*37*/              // SSID length
    int ssidLen = strlen(ssid);
    packet[37] = ssidLen;
                    /*38*/              // SSID
    for(int i = 0; i < ssidLen; i++) {
      packet[38+i] = ssid[i];
    }
                                         
    uint8_t postSSID[] = {0x01, 0x08,   // Supported rate
                          0x82, 0x84, 0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c,
                          0x03, 0x01    // Channel
    };
                                        /* DSSS (Current Channel) */
    for(int i = 0; i < sizeof(postSSID); i++) {
      packet[38 + ssidLen + i] = postSSID[i];
    }
                                        // Channel
    packet[50 + ssidLen] = channel;
    int packetSize = 51 + ssidLen;

    _sendPacket(packet, packetSize);    // Broadcast the packet
}

// ----- Build a beacon packet
void buildPacket(char ssidName[], SSID targetSSID){
  int ssidLen = targetSSID.nameSize;

  for(int i=0; i<sizeof(packetBegin); i++) 
  {
    _packet[i] = packetBegin[i];
  }
  _packetSize = sizeof(packetBegin);  
                                        // MAC addresse and BSSID
  for(int i=0; i<6; i++) {
    _packet[10+i] = _packet[16+i] = targetSSID.sourceMACaddress[i];
    _packet[16+i] = targetSSID.BSSID[i];
  }
                                        // SSID
  _packet[_packetSize] = 0x00;
  _packet[_packetSize+1] = ssidLen;
  _packetSize += 2;
  for(int i=0; i<ssidLen; i++) { 
    _packet[_packetSize+i] = ssidName[i];
  }
  _packetSize += ssidLen;
                                        // DSSS (Current Channel)
  for(int i=0; i<sizeof(packetEnd); i++) {
    _packet[_packetSize+i] = packetEnd[i];
  }
  _packetSize += sizeof(packetEnd);
                                        // Copy channel
  _packet[_packetSize-1] = targetSSID.channel;
                                        // Add WPA if necessary
  /*if(spamWPA){
    for(int i=0; i<sizeof(wpa2tag); i++) _packet[_packetSize+i] = wpa2tag[i];
    _packetSize += sizeof(wpa2tag);
  }*/
}

// ----- Send a beacon packet
bool _sendPacket(uint8_t buf[], int len){
  bool result = false;
  
  // Print the packet
  //printBufferToConsole("_sendPacket() ", (char *) buf, len);

  if(wifi_send_pkt_freedom(buf, len, 0) != -1) { result = true; }
  if(wifi_send_pkt_freedom(buf, len, 0) != -1) { result = true; }
  if(wifi_send_pkt_freedom(buf, len, 0) != -1) { result = true; }

  delay(delayBetweenPacketBroadcasts);
  return result;
}

// ----- Setup
void setup() {
  delay(500);
  
  Serial.begin(115200);               // Serial link for debugging
  while(!Serial);
  Serial.println("FakeBeaconESP8266.ino");
  
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1);
  
  pinMode(LED_1, OUTPUT);             // Internal LED
  pinMode(LED_2, OUTPUT);             // External LED
  pinMode(pushButton, INPUT_PULLUP);  // Push button
  
  randomSeed(os_random());            // Make random more random
                                      // Setup the ssids structure
  for(int i=0; i<maxListSize; i++){
    ssids[i].nameSize = 32;           //*** SET THE RIGHT SIZE AFTER CHANGING BEHAVIOR *** START WITH FIRST BEHAVIOR SIZE
                                      
    if(randomChannel) {               // Channel
      ssids[i].channel = random(1,11);
    }
    else {
      ssids[i].channel = channel;
    }
    
    for (int j=0; j<6; j++)           // Random source MAC address
    {
      ssids[i].sourceMACaddress[j] = random(256);
    }
    
    for (int j=0; j<6; j++)           // Random BSSID MAC address
    {
      ssids[i].BSSID[j] = random(256);
    }
  }

  // Print the beginning of the ssids structure
  //printBufferToConsole("First 3 entries of SSID structure", (char *) ssids, sizeof(SSID)*3);

  Serial.println("starting...");
}

// ----- Loop
void loop() {
  flashProofOfLifeLed();              // Flash internal LED as proof of life

  checkPushButton();                  // Change state if pushbutton pressed

  currentTime = millis();             // Send out SSIDs at regular intervals
  if ((currentTime - attackTime) > attackTimeInMs) {
    attackTime = currentTime;

    switch (jamBehavior) {
      case _SsidFunny:
        sendSsidFunny();                 // Funny SSIDs
        break;
      case _RickRoll:
        sendRickRoll();                 // 1987 Rick Astley song "Never Gonna Give You Up"
        break;
      case _ssidWifiAndBroadband:
        sendWifiAndBroadband();         // Poem at http://forums.familyfriendpoems.com/topic.asp?TOPIC_ID=108497
        break;
      case _ssidNamesToAvoid:
        sendNamesToAvoid();             // SSID names to avoid. They may break some devices
        break;        
      case _sendBeacon:
        sendBeacon((char*)"test");      // Send beacon frames with the SSID 'test'
        break;
      case _sendRandomBeacon:
        sendRandomBeacon(10);           // Send beacon frames with 10 character long random SSID
        break;
      case _sendFuzzedBeacon:           // Send beacon frames: 5 SSIDs starting with 'test-', ending with whitespaces
        sendFuzzedBeacon((char*)"test-", 12, 5);
        break;
      case _declarationOfIndependance:  // Declaration of Independence of Cyberspace
        sendDeclarationOfIndependance();
        break;
      default:
        Serial.println("WARNING: behavior not recognized");
        break;
      }
  }
}
