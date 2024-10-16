#include "Display.h"

// Constructor
Display::Display() {
    // Initialization can be done in init()
}

// Initialization
void Display::init() {
    matrix.begin();
    matrix.textFont(Font_5x7);   // Set font size
    matrix.textScrollSpeed(100); // Adjust scrolling speed as needed
    matrix.stroke(0xFF, 0, 0);   // Set text color (e.g., red)
}

// Show status
void Display::showStatus(const char* status) {
    matrix.clear();  // Clear the display before showing new text
    matrix.beginText(4, 1, 0xFF, 0, 0); // Start position (adjust as needed)
    matrix.print(status);               // Display the status text
    matrix.endText();
}
