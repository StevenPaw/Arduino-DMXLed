#include <FastLED.h>
#include <DMXSerial.h>

#define LED_PIN 6
#define NUM_LEDS 256

CRGB leds[NUM_LEDS];

int delayval = 100;
const int ledPin = 7; // the pin that the LED is attached to

void setup()
{
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    DMXSerial.init(DMXReceiver);
}

// the loop function runs over and over again forever
void loop()
{
    // Read the value of the first channel
    for (int l = 0; l < NUM_LEDS; l++)
    {
        int dmxstart = l * 3;
        int red = DMXSerial.read(dmxstart + 1);
        int green = DMXSerial.read(dmxstart + 2);
        int blue = DMXSerial.read(dmxstart + 3);
        // Set the color of the LED
        leds[l] = CRGB(red, green, blue);
    }

    FastLED.show();
    delay(50);
}
