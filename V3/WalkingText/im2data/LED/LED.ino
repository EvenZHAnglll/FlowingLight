// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <avr/pgmspace.h>
#include "ImgConst.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__ 
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      60
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
//const char img[NUMPIXELS][lengthOfImg][3];



int frame[NUMPIXELS][3];
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
 
  pixels.begin(); // This initializes the NeoPixel library.
}

void displayFrame( int frame[NUMPIXELS][3] ){
  char ledAddress = 0;
  for(int i=0;i<NUMPIXELS;i++){
    
    ledAddress = i/2;
    pixels.setPixelColor(ledAddress, pixels.Color(frame[i][2],frame[i][1],frame[i][0])); // Moderately bright green color.
    i++;
    ledAddress=59-ledAddress;
    pixels.setPixelColor(ledAddress, pixels.Color(frame[i][2],frame[i][1],frame[i][0])); // Moderately bright green color.
    //Serial.println(frame[i][0]);
    //pixels.show();
  }
  for(int i=30;i<NUMPIXELS;i++){
    //Serial.println(frame[i][0]);
    //pixels.show();
  }
  
  pixels.show();  
}

//void copyRGB(char A[3], char B[3]){
//  for(int i=0;i<3;i++){
//    A[i]=B[i];
//  }
//}
void loop() {
//Serial.println("iiii");
//Serial.println(img[0][0][0]);

//for (int i=0;i<26;i++){
//    Serial.print("i = ");
//    Serial.println(i);
//
////    for(int u=0;u<52;u++){
////        Serial.print(";u = ");
////        Serial.print(u);
//
////        for(int rgb=0;rgb<3;rgb++){
////          Serial.print(";rgb = ");
////          Serial.println(rgb);
////          frame[u][rgb]=img[i][u][rgb];
//          Serial.println(img[1][1][1]);
//          Serial.println(pgm_read_byte(&(img[i][1][1])));
//
//          delay(1000);
////        }
////      copyRGB(frame[u],img[u][i]);
////    }
//}

  for (int i=0;i<lengthOfImg;i++){
//    Serial.print("i = ");
//    Serial.print(i);

    for(int u=0;u<NUMPIXELS;u++){
//        Serial.print(";u = ");
//        Serial.print(u);

        for(int rgb=0;rgb<3;rgb++){
//          Serial.print(";rgb = ");
//          Serial.println(rgb);
          frame[u][rgb]=pgm_read_byte(&(img[u][i][rgb]));
//          Serial.println(img[1][0][0]);
//          Serial.println(pgm_read_byte(&(img[u][i][rgb])));
//          Serial.println(frame[u][rgb]);
//          delay(1000);
        }
//      copyRGB(frame[u],img[u][i]);
    }
    displayFrame(frame); 
    delay(delayval);
  }

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(5000);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
//
//  for(int i=0;i<NUMPIXELS;i++){
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(10,25,25)); // Moderately bright green color.
//    
//    pixels.show(); // This sends the updated pixel color to the hardware.
//
//    delay(delayval); // Delay for a period of time (in milliseconds).
//    pixels.setPixelColor(i, pixels.Color(0,2,2));
//
//  }
//    for(int i=NUMPIXELS-1;i>0;i--){
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(10,25,25)); // Moderately bright green color.
//
//    pixels.show(); // This sends the updated pixel color to the hardware.
//
//    delay(delayval); // Delay for a period of time (in milliseconds).
//    pixels.setPixelColor(i, pixels.Color(0,0,0));
//    
//
//  }
}
