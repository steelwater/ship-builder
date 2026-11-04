#pragma once
#include <stdint.h>

// The single ship representation used by editor, future salvage and flight.
// Fixed storage: 10 x 4 bytes; no heap or EEPROM writes.
namespace ShipModel {
constexpr uint8_t Columns = 10;
constexpr uint8_t Rows = 4;
constexpr uint8_t CellCount = Columns * Rows;
enum Part : uint8_t {
  Empty = 0, Cockpit = 1, Hull = 2, Engine = 3,
  Fin = 4, Weapon = 5, Shield = 6, PartCount = 7
};
struct Ship {
  uint8_t cells[CellCount];
};
inline bool inBounds(uint8_t x, uint8_t y) {
  return x < Columns && y < Rows;
}
inline uint8_t index(uint8_t x, uint8_t y) {
  return static_cast<uint8_t>(y * Columns + x);
}
inline uint8_t get(const Ship &ship, uint8_t x, uint8_t y) {
  return inBounds(x, y) ? ship.cells[index(x, y)] : Empty;
}
inline bool set(Ship &ship, uint8_t x, uint8_t y, uint8_t part) {
  if (!inBounds(x, y) || part >= PartCount) return false;
  ship.cells[index(x, y)] = part;
  return true;
}
inline void clear(Ship &ship) {
  for (uint8_t i = 0; i < CellCount; ++i) ship.cells[i] = Empty;
}
inline uint8_t count(const Ship &ship) {
  uint8_t total = 0;
  for (uint8_t i = 0; i < CellCount; ++i)
    if (ship.cells[i] != Empty) ++total;
  return total;
}
} // namespace ShipModel
