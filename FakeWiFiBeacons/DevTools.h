#ifndef DevTools_h
#define DevTools_h

/*
   This file contains developer tools and utilities.
 */

#include "Arduino.h"

extern "C" {
#include "user_interface.h"
}

/*-----------constants-----------*/

/*--------data structures--------*/
  
/*- Print buffer content to serial monitor -*/
void printBufferToConsole(String title, char buffer[], size_t length) {
  char printString[500];
  
  sprintf(printString, "\n--> Start dump: %s <--", title.c_str());
  Serial.println(printString);
  
  size_t len = strlen(buffer);
  if (length < 1) { length = len; };

  sprintf(printString, "[Buffer size requested: %d] [sizeof(buffer): %d]", length, sizeof((char *)buffer));
  Serial.println(printString);

  for (int i=0; i<length; i++) {
    sprintf(printString, "%d: %02X ", i, buffer[i]);
    Serial.println(printString);
  }
  
  sprintf(printString, "--> End dump: %s <--", title.c_str());
  Serial.println(printString);
  delay(1000);                             //*** REMOVE
}

#endif // ifndef DevTools_h
