#include "Particle.h"
#include "tca9535.h"

/* Function prototypes -------------------------------------------------------*/

SYSTEM_MODE(SEMI_AUTOMATIC);

TCA9535 portExpander;

#define PE_PIN_PS_IRQ0_ISO      (0)    // Port 1 = Pin 0-7
#define PE_PIN_PS_HEARTBEAT     (13)   // Port 2 = Pin 8-15

bool initialize = false;

/* This function is called once at start up ----------------------------------*/
void setup()
{
    Serial.begin(9600);

    if (false == portExpander.begin())
    {
        // Debug - for production we probably want to send an event to the
        //   cloud that this device hardware is bad then reboot to try again
        // NOTE: Persist the event for X time so it does not spam the cloud
        Serial.println("Failed to communicate with I2C port expander");
    }

    // Sets the I/O
    portExpander.pinMode(PE_PIN_PS_IRQ0_ISO, INPUT);
    portExpander.pinMode(PE_PIN_PS_HEARTBEAT, OUTPUT);

    // Read pin state from IRQ0 pin
    // Set the heartbeat pin
    bool value;
    portExpander.digitalRead(PE_PIN_PS_IRQ0_ISO, &value);
    portExpander.digitalWrite(PE_PIN_PS_HEARTBEAT, value);
}

/* This function loops forever --------------------------------------------*/
void loop()
{
    //Serial.print(".");
}
