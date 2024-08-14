# 1 "C:\\wamp64\\www\\Arduino-DMXLed\\Arduino-DMXLed.ino"
# 2 "C:\\wamp64\\www\\Arduino-DMXLed\\Arduino-DMXLed.ino" 2
# 3 "C:\\wamp64\\www\\Arduino-DMXLed\\Arduino-DMXLed.ino" 2




CRGB leds[256];

int delayval = 100;
const int ledPin = 7; // the pin that the LED is attached to

void setup()
{
    FastLED.addLeds<WS2812, 6, GRB>(leds, 256);
    DMXSerial.init(DMXReceiver);
}

// the loop function runs over and over again forever
void loop()
{
    // Read the value of the first channel
    for (int l = 0; l < 256; l++)
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
