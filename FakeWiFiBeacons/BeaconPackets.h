#ifndef BEACON_PACKETS_h
#define BEACON_PACKETS_h

/*
   This file contains the beacon packets.

   See: https://mrncciew.com/2014/10/08/802-11-mgmt-beacon-frame/
 */

extern "C" {
#include "user_interface.h"
}

/*-----------constants-----------*/
const bool spamWPA = false;                   // broadcast WPA(2) protected networks

/*--------data structures--------*/
uint8_t _packet[128];
int _packetSize = 0;

uint8_t packetBegin[36] = {                   /* Beacon Frame  structure*/
	/* MAC Header */
	/*00*/  0x80, 0x00,                         //Frame Control
	/*02*/  0x00, 0x00,                         //Beacon duration
	/*04*/  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //DA - Destination address = broadcast
	/*10*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //SA - Source address - overwritten later
	/*16*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //BSSID - overwritten to the same as SA
	/*22*/  0xc0, 0x6c,                         //Seq-ctl
 
	/* Frame body starts here */
	/*24*/  0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, // Timestamp - # microseconds AP has been active
	/*32*/  0xff, 0x00,                         // Beacon interval in Time Units: (2 bytes)
	                                            // (0x64, 0x00 = 100 TU = 102.4 ms)
                                              // (0xff, 0x00 = 255 TU = 261.12 ms)
                                              // (0xe8, 0x03 = 1000 TU = 1 sec)
	/*34*/  0x01, 0x04                          //Capability info
 
  /* SSID starts here */
  /*36*/  /*, 0x00, */                        //SSID element ID
  /*37*/  /*, 0x04, */                        //Length
	/*38*/  /*  0x72, 0x72, 0x72, 0x72 */       //SSID name
 
	/* Beacon Packet end */
};

uint8_t packetEnd[13] = {
	/* Post-SSID */
  0x01,       // Supported Rates elementID
  0x08,       // Length (variable size)
  0x82,       // 1(B)
  0x84,       // 2(B)
  0x8b,       // 5.5(B)
  0x96,       // 11(B)
  0x24,       // 18
  0x30,       // 24
  0x48,       // 36
  0x6c,       // 54
  
  0x03,       // Channel elementID
  0x01,       // Length
  0x03        // Current Channel
};

uint8_t wpa2tag[26] = {
  0x30,                   //RSN (Robust Secure Network) element ID
  0x18,                   //tag length
  0x01, 0x00,             //RSN version
  0x00, 0x0f, 0xac, 0x02, //cipher (TKIP)
  0x02, 0x00,             //pair cipher
  0x00, 0x0f, 0xac, 0x04, //cipher (AES)
  //0x00, 0x0f, 0xac, 0x02, //cipher (TKIP)
  0x0f, 0xac, 0x04,       /*Fix: changed 0x02(TKIP) to 0x04(CCMP) is default. 
                            WPA2 with TKIP not supported by many devices*/
  0x01, 0x00,             //AKM count
  0x00, 0x0f, 0xac, 0x02, //PSK
  0x00, 0x00              //RSN capabilities
};

#endif // ifndef BEACON_PACKETS_h
