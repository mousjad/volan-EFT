int rpm2led(float rpm, int dernier) {

  int maxi = 4000; int led_maxi = 22;
  int roug = 3500; int led_roug = 19;
  int jaun = 3000; int led_jaun = 16;
  int mini = 700;  int led_mini = 0;
  int dernierled; int led;

  if (rpm < mini) {
    FastLED.clear();
  } else {

    dernierled = (rpm - mini) / (maxi - mini) * (led_maxi - led_mini);
    if (dernierled != dernier) {
      FastLED.clear();
      FastLED.show();
    }

    for (led = led_mini; led < dernierled; led++) {
      leds[led] = CRGB::Green;
    }
  }
  if (dernierled > led_jaun) {
    for (led = led_jaun; led < dernierled; led++) {
      leds[led] = CRGB::Yellow;
    }
  }
  if (dernierled > led_roug) {
    for (led = led_roug; led < dernierled; led++) {
      leds[led] = CRGB::Red;
    }
  }
  if (dernierled > led_maxi) {
    for (led = led_mini;  led < dernierled; led++) {
      leds[led] = CRGB::Red;
    }
  }
  FastLED.show();
  return dernierled;
}
