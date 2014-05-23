#include <Adafruit_NeoPixel.h>

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
int globalLevel = 0;
int numDelay = 2000;
int blinkDelay = 300;
//not useduint8_t randomLevel;

int lSwitchPin = 5; //input left switch
int rSwitchPin = 4; //input right switch
int brakePin = 2; //input from brake
uint32_t color = 0;
long previousTime =0;

void setup() {
  //Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(lSwitchPin, INPUT);   //switch for pin input
  pinMode(rSwitchPin, INPUT);   //switch for pin input
  pinMode(brakePin, INPUT);  
  // Serial.begin(9600);           // set up Serial library at 9600 bps

//long previousTime = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

//   colorWipe(strip.Color(22, 175, 255), 50); // Blue
  //strip.setPixelColor(0, strip.Color(255, 0, 0));
  //strip.show();
  //life();
//uint8_t blinker = 0;
//bool brake = false;  
}

void loop() {

// check to see if it's time to blink the LED; that is, if the 
// difference between the current time and last time you blinked 
// the LED is bigger than the interval at which you want to 
// blink the LED.
long currentTime = millis();

  

boolean brakeEngaged = false;
   //If the right side is switched on, blink the left mothafuckin blinker
if (digitalRead(lSwitchPin) == 1){
   leftBlinker(currentTime);}
   //If the right side is switched on, blink the right mothafuckin blinker
if (digitalRead(rSwitchPin) == 1){
   rightBlinker(currentTime);}
   //if both pins are not active, make sure the yellows are cleared)
if ((digitalRead(rSwitchPin) == 0) && (digitalRead(lSwitchPin) == 0)){
   clearBlinker();}
if (digitalRead(brakePin) == 0){
   brakeEngaged = true;}
  
  runnigLights(brakeEngaged); //this is badly named :(
  //blinkers(blinkPattern);


//  Serial.println(digitalRead(brakePin));    // Read the pin and display the value. 1 is not switched, 0 is 
  //Serial.println(digitalRead(lSwitchPin));    // Read the pin and display the value
  //  Serial.println(digitalRead(rSwitchPin));
  //delay(500);
}
  
  


//these are dim red lights that are constantly on
//when switched, the light becomes brighter
void runnigLights(bool brake){
  if (!brake){
  strip.setPixelColor(3, strip.Color(50, 0, 0));
  strip.setPixelColor(4, strip.Color(50, 0, 0));
  strip.setPixelColor(5, strip.Color(50, 0, 0));
  strip.show();}
  else {
  strip.setPixelColor(3, strip.Color(255, 0, 0));
  strip.setPixelColor(4, strip.Color(255, 0, 0));
  strip.setPixelColor(5, strip.Color(255, 0, 0));
  strip.show();}
    
    
  
}


void rightBlinker(unsigned long time){
  
  //or if time is < blinkDelay
  if(time - previousTime > blinkDelay)
  {
    previousTime = time;
    if (strip.getPixelColor(0) == 0)
    {
    strip.setPixelColor(0, strip.Color(255, 153, 0));
    strip.setPixelColor(1, strip.Color(255, 153, 0));
    strip.setPixelColor(2, strip.Color(255, 153, 0)); 
    strip.show();
    }//end if
    else
    {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.setPixelColor(1, strip.Color(0, 0, 0));
    strip.setPixelColor(2, strip.Color(0, 0, 0));
    strip.show();
    }
  }
 
  
  

}

void leftBlinker(unsigned long time){

  if(time - previousTime > blinkDelay)
  {
    previousTime = time;
    if (strip.getPixelColor(6) == 0)
    {
    strip.setPixelColor(6, strip.Color(255, 153, 0));
    strip.setPixelColor(7, strip.Color(255, 153, 0));
    strip.setPixelColor(8, strip.Color(255, 153, 0));
    strip.show();
    }
    else
    {
    strip.setPixelColor(6, strip.Color(0, 0, 0));
    strip.setPixelColor(7, strip.Color(0, 0, 0));
    strip.setPixelColor(8, strip.Color(0, 0, 0));
    strip.show();
    }
  }
}

//just in case 
void clearBlinker(){
  
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.setPixelColor(1, strip.Color(0, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 0, 0));
  strip.setPixelColor(6, strip.Color(0, 0, 0));
  strip.setPixelColor(7, strip.Color(0, 0, 0));
  strip.setPixelColor(8, strip.Color(0, 0, 0));
  strip.show();  
}




