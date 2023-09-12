/*
 * Project GX-FW
 * Description: industrial Robot FW
 * Author: David Salihu
 * Date: 12 September'23
 * Last Editted: 12th september, 2023
 */

#include "main.h"


PRODUCT_ID(12616);  // Electron product ID

PRODUCT_VERSION(16);

SYSTEM_MODE(MANUAL);    // setting system mode to manual turns of cellular at startup

// Define the pin number for the LED
int ledPin = D7;

// Define the initial state of the LED
bool ledState = false;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  delay(1000);
  Log.print("Setup\n");
  delay(1000);
  // You can also use Particle functions or variables setup here
  // For example, Particle.function() to call functions remotely
  // or Particle.variable() to expose variables to the Particle Cloud
}

void loop() {
  // Toggle the LED state
  ledState = !ledState;

  // Set the LED state
  digitalWrite(ledPin, ledState);
  Log.print("Blink!\n");
  // Wait for 1 second (1000 milliseconds)
  delay(2000);
}

