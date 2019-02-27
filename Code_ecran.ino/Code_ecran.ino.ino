#include "Nextion.h"


//Partie pour les LED

#include <FastLED.h>

#define LED_PIN     13
#define NUM_LEDS    22
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 30

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


//Partie pour l'écran

int num_mode = 0;
//Liste des mode

char *modeliste[] = {"Mode 1", "Mode 2", "Mode 3",
                     "Mode 4", "Mode 5", "Mode 6",
                     "Mode 7", "Mode 8"
                    };

// Declare your Nextion objects - Example (page id = 0, component id = 1, component name = "b0")


//Selection des modes
NexButton Mode_Prec = NexButton(0, 3, "Mode_Prec");
NexButton Mode_suiv = NexButton(0, 4, "Mode_suiv");
NexButton Mode_1 = NexButton(1, 1, "Mode_1");
NexButton Mode_2 = NexButton(1, 5, "Mode_2");
NexButton Mode_3 = NexButton(1, 6, "Mode_3");
NexButton Mode_4 = NexButton(1, 4, "Mode_4");
NexButton Mode_5 = NexButton(2, 1, "Mode_5");
NexButton Mode_6 = NexButton(2, 5, "Mode_6");
NexButton Mode_7 = NexButton(2, 4, "Mode_7");
NexButton Mode_8 = NexButton(2, 6, "Mode_8");

NexButton annulerp1 = NexButton(1, 3, "annulerp1");
NexButton annulerp2 = NexButton(2, 3, "annulerp2");
NexButton annulerp3 = NexButton(3, 1, "annulerp3");


//Selection des pages
NexPage page0 = NexPage(0, 0, "Princ");  // Page added as a touch event
NexPage page1 = NexPage(1, 0, "slct_mode");  // Page added as a touch event
NexPage page2 = NexPage(2, 0, "slct_mode2");  // Page added as a touch event
NexPage page3 = NexPage(3, 0, "opt");

// Register a button object to the touch event list.
NexTouch *nex_listen_list[] = {
  &Mode_Prec, &Mode_suiv,
  &Mode_1, &Mode_2,
  &Mode_3, &Mode_4,
  &Mode_5, &Mode_6,
  &Mode_7, &Mode_8,
  &annulerp1, &annulerp2,
  &annulerp3,
  NULL
};

void setup(void) {
//Partie pour les LED

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;


//Partie pour l'écran

  Serial.begin(9600);  // Start serial comunication at baud=9600
  // I am going to change the Serial baud to a faster rate.
  // The reason is that the slider have a glitch when we try to read it's value.
  // One way to solve it was to increase the speed of the serial port.
  delay(500);  // This dalay is just in case the nextion display didn't start yet, to be sure it will receive the following command.
  Serial.print("baud=115200");  // Set new baud rate of nextion to 115200, but it's temporal. Next time nextion is power on,
  // it will retore to default baud of 9600.
  // To take effect, make sure to reboot the arduino (reseting arduino is not enough).
  // If you want to change the default baud, send the command as "bauds=115200", instead of "baud=115200".
  // If you change the default baud, everytime the nextion is power ON is going to have that baud rate, and
  // would not be necessery to set the baud on the setup anymore.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to nextion.
  Serial.write(0xff);
  Serial.write(0xff);

  Serial.end();  // End the serial comunication of baud=9600

  nexInit();
  Mode_Prec.attachPush(Mode_PrecPushCallback);
  Mode_suiv.attachPush(Mode_suivPushCallback);
  Mode_1.attachPush(Mode_1PushCallback);
  Mode_2.attachPush(Mode_2PushCallback);
  Mode_3.attachPush(Mode_3PushCallback);
  Mode_4.attachPush(Mode_4PushCallback);
  Mode_5.attachPush(Mode_5PushCallback);
  Mode_6.attachPush(Mode_6PushCallback);
  Mode_7.attachPush(Mode_7PushCallback);
  Mode_8.attachPush(Mode_8PushCallback);
  annulerp1.attachPush(annulerp1PushCallback);
  annulerp2.attachPush(annulerp2PushCallback);
  annulerp3.attachPush(annulerp3PushCallback);

}

int rpm = 700;
int dernier = 0;

void loop()
{
  //Partie de test
  rpm++;
  if(rpm>2500){rpm=1500;}
  //Partie pour les DEL
  dernier=rpm2led(rpm,dernier);


  //Partie pour l'écran
  writerpm(rpm);
  nexLoop(nex_listen_list); //Check for any touch event
  delay(20);
}



