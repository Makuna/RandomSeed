// RandomBlink
// This demonstrates how use the RandomSeed to initialize random
// and blink an LED with the results

#include <RandomSeed.h>

// Pin 13 has an LED connected on most Arduino boards.
int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  randomSeed( GenerateRandomSeed() );
}

void loop()
{
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(random(500, 3000));   // wait for a random period between 0.5 seconds and 3 seconds
  digitalWrite(ledPin, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                // wait for a second
}