#include "Display.h"

Display display;

void setup() {
    display.init();
}

void loop() {
    display.showStatus("l"); // Show left back
    delay(1000);

    display.showStatus("r"); // Show right back
    delay(1000);

    display.showStatus("L"); // Show left
    delay(1000);

    display.showStatus("R"); // Show right
    delay(1000);
}
