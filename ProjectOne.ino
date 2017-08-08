#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();

void setup()
{
  b.begin();
  Particle.subscribe("hook-response/timeEvent", myHandler, MY_DEVICES);
  Particle.subscribe("hook-error/timeEvent", myErrorHandler, MY_DEVICES);
}

void loop()
{
  if (b.buttonOn(1)){
    showButtonLights(1,255,255,255,250);
    Particle.publish("timeEvent", "1", PRIVATE);
  } else if (b.buttonOn(2)){
    showButtonLights(2,255,255,255,250);
    Particle.publish("timeEvent", "2", PRIVATE);
  } else if (b.buttonOn(3)){
    showButtonLights(3,255,255,255,250);
    Particle.publish("timeEvent", "3", PRIVATE);
  } else if (b.buttonOn(4)){
    showButtonLights(4,255,255,255,250);
    Particle.publish("timeEvent", "4", PRIVATE);
  }
}

void myHandler(const char *event, const char *data){
  String str = String(data);
  int red = 0;
  int green = 0;
  int blue = 0;
  int button = 0;

  if(str.startsWith("error")){
    red = 255;
  } else if (str.startsWith("opened")){
    green=255;
  } else if (str.startsWith("closed")){
    blue=255;
  }

  if(str.endsWith("1")){
    button = 1;
  } else if(str.endsWith("2")){
    button = 2;
  } else if(str.endsWith("3")){
    button = 3;
  } else if(str.endsWith("4")){
    button = 4;
  }

  showButtonLights(button, red, green, blue, 250);

}

void myErrorHandler(const char *event, const char *data){
  b.allLedsOn(255,0,0);
  delay(250);
  b.allLedsOff();
}

void showButtonLights(int button, int red, int green, int blue, int wait){
  if (button==1){
    b.ledOn(11, red, green, blue);
    b.ledOn(1, red, green, blue);
    delay(wait);
    b.allLedsOff();
  } else if (button==2){
    b.ledOn(2, red, green, blue);
    b.ledOn(3, red, green, blue);
    b.ledOn(4, red, green, blue);
    delay(wait);
    b.allLedsOff();
  } else if (button==3){
    b.ledOn(5, red, green, blue);
    b.ledOn(6, red, green, blue);
    b.ledOn(7, red, green, blue);
    delay(wait);
    b.allLedsOff();
  } else if (button==4){
    b.ledOn(8, red, green, blue);
    b.ledOn(9, red, green, blue);
    b.ledOn(10, red, green, blue);
    delay(wait);
    b.allLedsOff();
  } else {
    b.allLedsOn(red,green,blue);
    delay(wait);
    b.allLedsOff();
  }
}
