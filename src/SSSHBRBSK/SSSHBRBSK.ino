#include <Arduboy2.h>
#include "ShipModel.h"

// Milestone 1: fixed-grid ship editor; no economy, salvage or persistence.
Arduboy2 arduboy;
using namespace ShipModel;
constexpr uint8_t FrameRate = 30;
constexpr uint8_t GridX = 14, GridY = 15, CellW = 10, CellH = 10;
enum Screen : uint8_t { Title, Editor, Picker, Help };
Screen screen = Title;
Ship ship = {};
uint8_t cursorX = 4, cursorY = 1;
uint8_t selected = Hull;
uint8_t pickerSelection = Hull;
bool helpFromEditor = false;

// PROGMEM string literals via F() avoid RAM consumption.
void partName(uint8_t part) {
  switch (part) {
    case Cockpit: arduboy.print(F("COCKPIT")); break;
    case Hull: arduboy.print(F("HULL")); break;
    case Engine: arduboy.print(F("ENGINE")); break;
    case Fin: arduboy.print(F("FIN")); break;
    case Weapon: arduboy.print(F("WEAPON")); break;
    case Shield: arduboy.print(F("SHIELD")); break;
    default: arduboy.print(F("REMOVE")); break;
  }
}

// Each shape is a native monochrome drawing inside a 10x10 grid cell.
void drawPart(uint8_t part, int16_t x, int16_t y) {
  switch (part) {
    case Cockpit:
      arduboy.fillRect(x + 1, y + 3, 6, 5, WHITE);
      arduboy.drawPixel(x + 7, y + 4, WHITE);
      arduboy.fillRect(x + 4, y + 4, 2, 2, BLACK);
      break;
    case Hull:
      arduboy.fillRect(x + 1, y + 2, 8, 6, WHITE);
      arduboy.drawFastHLine(x + 3, y + 4, 4, BLACK);
      break;
    case Engine:
      arduboy.fillRect(x + 3, y + 2, 6, 6, WHITE);
      arduboy.fillRect(x + 1, y + 3, 2, 4, WHITE);
      arduboy.drawPixel(x, y + 5, WHITE);
      break;
    case Fin:
      arduboy.fillTriangle(x + 1, y + 7, x + 7, y + 1, x + 8, y + 7, WHITE);
      break;
    case Weapon:
      arduboy.fillRect(x + 1, y + 4, 8, 3, WHITE);
      arduboy.drawFastVLine(x + 3, y + 2, 6, WHITE);
      break;
    case Shield:
      arduboy.drawCircle(x + 5, y + 5, 4, WHITE);
      arduboy.drawFastVLine(x + 5, y + 3, 5, WHITE);
      break;
  }
}
void drawShip(const Ship &model, uint8_t x0, uint8_t y0) {
  for (uint8_t y = 0; y < Rows; ++y)
    for (uint8_t x = 0; x < Columns; ++x)
      drawPart(get(model, x, y), x0 + x * CellW, y0 + y * CellH);
}
void heading(const __FlashStringHelper *name) {
  arduboy.setCursor(0, 0);
  arduboy.print(name);
  arduboy.drawFastHLine(0, 10, WIDTH, WHITE);
}
void drawTitle() {
  heading(F("S.S.S.H.B.R.B.S.K."));
  arduboy.setCursor(18, 16); arduboy.print(F("SALVAGE YARD"));
  arduboy.setCursor(19, 28); arduboy.print(F("SHIP EDITOR"));
  arduboy.setCursor(10, 46); arduboy.print(F("A:BUILD  B:HELP"));
  arduboy.setCursor(9, 56); arduboy.print(F("M1 PROTOTYPE"));
}
void drawEditor() {
  heading(F("BUILD  A:SET B:PART"));
  // Outlined workspace with a subtle central axis.
  arduboy.drawRect(GridX - 1, GridY - 1, Columns * CellW + 2,
                   Rows * CellH + 2, WHITE);
  arduboy.drawFastHLine(GridX, GridY + 2 * CellH - 1,
                        Columns * CellW, WHITE);
  drawShip(ship, GridX, GridY);
  uint8_t cx = GridX + cursorX * CellW;
  uint8_t cy = GridY + cursorY * CellH;
  arduboy.drawRect(cx, cy, CellW, CellH, WHITE);
  // Corner ticks make the selection visible even over a filled part.
  arduboy.fillRect(cx, cy, 2, 2, WHITE);
  arduboy.fillRect(cx + CellW - 2, cy + CellH - 2, 2, 2, WHITE);
  arduboy.setCursor(0, 56); partName(selected);
  arduboy.setCursor(89, 56);
  arduboy.print(count(ship)); arduboy.print(F("/40"));
}
void drawPicker() {
  heading(F("PARTS  A:OK B:BACK"));
  arduboy.setCursor(0, 14); arduboy.print(F("<"));
  arduboy.setCursor(13, 14); partName(pickerSelection);
  arduboy.setCursor(119, 14); arduboy.print(F(">"));
  if (pickerSelection != Empty)
    drawPart(pickerSelection, 58, 32);
  else {
    arduboy.drawRect(58, 32, 10, 10, WHITE);
    arduboy.drawLine(59, 40, 66, 33, WHITE);
  }
  arduboy.setCursor(7, 48); arduboy.print(F("L/R:CHOOSE"));
  arduboy.setCursor(7, 56); arduboy.print(F("REMOVE = ERASE"));
}
void drawHelp() {
  heading(F("HOW TO BUILD"));
  arduboy.setCursor(0, 13); arduboy.print(F("D-PAD : MOVE CURSOR"));
  arduboy.setCursor(0, 23); arduboy.print(F("A     : PLACE PART"));
  arduboy.setCursor(0, 33); arduboy.print(F("B     : PART PICKER"));
  arduboy.setCursor(0, 43); arduboy.print(F("PICK  : REMOVE"));
  arduboy.setCursor(0, 56); arduboy.print(F("A/B   : RETURN"));
}
void handleInput() {
  if (screen == Title) {
    if (arduboy.justPressed(A_BUTTON)) screen = Editor;
    else if (arduboy.justPressed(B_BUTTON)) {
      helpFromEditor = false; screen = Help;
    }
  } else if (screen == Help) {
    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON))
      screen = helpFromEditor ? Editor : Title;
  } else if (screen == Editor) {
    if (arduboy.justPressed(LEFT_BUTTON) && cursorX) --cursorX;
    if (arduboy.justPressed(RIGHT_BUTTON) && cursorX + 1 < Columns) ++cursorX;
    if (arduboy.justPressed(UP_BUTTON) && cursorY) --cursorY;
    if (arduboy.justPressed(DOWN_BUTTON) && cursorY + 1 < Rows) ++cursorY;
    if (arduboy.justPressed(A_BUTTON)) set(ship, cursorX, cursorY, selected);
    if (arduboy.justPressed(B_BUTTON)) {
      pickerSelection = selected; screen = Picker;
    }
  } else if (screen == Picker) {
    // Seven choices, including Empty = REMOVE. Wrap in both directions.
    if (arduboy.justPressed(LEFT_BUTTON))
      pickerSelection = (pickerSelection == 0) ? Shield : pickerSelection - 1;
    if (arduboy.justPressed(RIGHT_BUTTON))
      pickerSelection = (pickerSelection == Shield) ? Empty : pickerSelection + 1;
    if (arduboy.justPressed(A_BUTTON)) {
      selected = pickerSelection;
      screen = Editor;
    }
    if (arduboy.justPressed(B_BUTTON)) screen = Editor;
  }
}
void setup() {
  arduboy.begin();
  arduboy.setFrameRate(FrameRate);
  clear(ship);
}
void loop() {
  if (!arduboy.nextFrame()) return;
  arduboy.pollButtons();
  handleInput();
  arduboy.clear();
  switch (screen) {
    case Title: drawTitle(); break;
    case Editor: drawEditor(); break;
    case Picker: drawPicker(); break;
    case Help: drawHelp(); break;
  }
  arduboy.display();
}
