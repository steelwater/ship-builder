#include <Arduboy2.h>

// Milestone 0: visible hardware and simulator smoke test.
// No ship inventory, economy, EEPROM writes, or gameplay yet.
Arduboy2 arduboy;

constexpr uint8_t kFrameRate = 30;
bool thrusterLight = true;

void drawTugboat() {
  // Small 1-bit right-facing tugboat, entirely inside the 128x64 screen.
  // Engine and exhaust at left; cockpit and bow at right.
  arduboy.fillRect(27, 40, 65, 11, WHITE);  // main hull
  arduboy.drawFastHLine(32, 52, 56, WHITE); // keel
  arduboy.fillRect(46, 31, 24, 9, WHITE);   // bridge
  arduboy.fillRect(51, 33, 11, 4, BLACK);   // bridge window
  arduboy.drawRect(92, 42, 10, 7, WHITE);  // bow fitting
  arduboy.fillRect(19, 42, 8, 8, WHITE);   // rear thruster
  arduboy.fillRect(14, 44, 5, 4, thrusterLight ? WHITE : BLACK);
  arduboy.drawPixel(106, 38, WHITE);
  arduboy.drawPixel(9, 35, WHITE);
}

void drawTestScreen() {
  arduboy.clear();
  arduboy.setCursor(10, 1);
  arduboy.print(F("S.S.S.H.B.R.B.S.K."));
  arduboy.drawFastHLine(0, 12, WIDTH, WHITE);
  arduboy.setCursor(10, 17);
  arduboy.print(F("SHIPYARD TEST RIG"));
  drawTugboat();
  arduboy.setCursor(0, 56);
  arduboy.print(F("A:LIGHT B:RESET"));
  arduboy.setCursor(97, 56);
  arduboy.print(thrusterLight ? F("ON") : F("OFF"));
  arduboy.display();
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(kFrameRate);
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }

  arduboy.pollButtons();
  if (arduboy.justPressed(A_BUTTON)) {
    thrusterLight = !thrusterLight;
  }
  if (arduboy.justPressed(B_BUTTON)) {
    thrusterLight = true;
  }
  drawTestScreen();
}
