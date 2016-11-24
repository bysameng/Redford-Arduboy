#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include <menu.h>

Arduboy2 arduboy;


typedef void (*FunctionPointer) ();
const FunctionPointer PROGMEM  mainGameLoop[] =
{
  stateMenuIntro,
  stateMenuMain,
  stateDrawing,
};

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(15);
}


void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;
  // first we clear our screen to black
  arduboy.clear();

  bool button = arduboy.pressed(A_BUTTON);
  if (button){
    render();
  }

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}


void render(){

  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  arduboy.setCursor(4, 9);

  // then we print to screen what is in the Quotation marks ""
  arduboy.print(F("Hello, world!"));

}
