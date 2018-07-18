#include <Arduino.h>
#include "fuseegelee.h"
#include "hekate_ctcaer_3.2.h" // Contains fuseeBin and FUSEE_BIN_SIZE

void deepSleep(int errorCode) 
{
  // Turn off all LEDs and go to sleep. To launch another payload, press the reset button on the device.
  //delay(100);
  digitalWrite(PIN_LED_RXL, HIGH);
  digitalWrite(PIN_LED_TXL, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  switch(errorCode) 
  {
    case 0: setLedColor(GREEN); break;
    case 1: setLedColor(BLUE); break;
    default: setLedColor(RED); break;
  }
  delay(LED_CONFIRM_TIME_MS);
  setLedColor(BLACK); //led to off
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* Enable deepsleep */
  __DSB(); /* Ensure effect of last store takes effect */
  __WFI(); /* Enter sleep mode */
}


void setup() 
{
  ledInit();
  
  if (usbInit() == -1) deepSleep(1); // BLUE error code
  if (!waitForTegraDevice()) deepSleep(-1); // RED error code
  
  setupTegraDevice();
  sendPayload(fuseeBin, FUSEE_BIN_SIZE);
  launchPayload();

  deepSleep(0);
}

void loop(){}
