# S.S.S.H.B.R.B.S.K.

**Space Ship Salvage Haul Break Restore Build Sell Keep**

An open-source 1-bit, 128 x 64 spaceship salvage and construction game for original Arduboy and Arduboy FX (ATmega32u4). The repository retains its original `ship-builder` name.

## Development status

- **Milestone 0 — Complete:** toolchain, CI, HEX artifact and ProjectABE simulator smoke test.
- **Milestone 1 — In progress / awaiting simulator acceptance:** native ship editor and shared fixed-size ship model.
- **Milestone 2 (planned):** buy the first damaged tugboat *Little Mule*, dismantle it one part at a time and restore salvaged components instantly.
- Later milestones add credits, rebuilding, hauling, backstories, provenance and discoveries.

See the [roadmap](https://docs.google.com/document/d/1H23HJkdBqy4uwCIjhhreuiGjYhKyxR59JeFosFODVF0/edit) and [changelog](CHANGELOG.md). The roadmap's **2026-11-02 salvage-economy revision supersedes its original milestone order**.

## Build locally

Install [Arduino CLI](https://docs.arduino.cc/arduino-cli/installation). On macOS: `brew install arduino-cli`.

```bash
arduino-cli core update-index
arduino-cli core install arduino:avr@1.8.6
arduino-cli lib update-index
arduino-cli lib install Arduboy2@6.0.0
mkdir -p dist
arduino-cli compile --fqbn arduino:avr:leonardo --output-dir dist src/SSSHBRBSK
```

Load `dist/SSSHBRBSK.ino.hex` into [Ardens](https://tiberiusbrown.github.io/Ardens/player.html) or ProjectABE. Pull request builds also produce the `ssshbrbsk-arduboy-hex` GitHub Actions artifact. See [development setup](docs/development-setup.md) for troubleshooting.

## Milestone 1 controls

| Screen | Input | Action |
| --- | --- | --- |
| Title | A | Open ship editor |
| Title | B | Show controls |
| Editor | D-pad | Move the grid cursor (10 columns × 4 rows) |
| Editor | A | Place/replace the selected part in the current cell |
| Editor | B | Open parts picker |
| Picker | Left / Right | Cycle cockpit, hull, engine, fin, weapon, shield, remove |
| Picker | A | Equip selected part (remove selects the eraser) |
| Picker | B | Return without changing the selection |
| Help | A / B | Return to title |

**Tip:** Select **REMOVE** in the parts picker, then press A on any occupied cell to erase it. Choose a different part to continue building. All changes are held in RAM only; switching off or resetting clears the ship. Economy, inventory, salvage logs and EEPROM saving are future milestones.

## Repository

- `src/SSSHBRBSK/SSSHBRBSK.ino` — editor UI and Arduboy drawing/inputs.
- `src/SSSHBRBSK/ShipModel.h` — canonical 10×4 fixed-array model and part IDs.
- `docs/milestone-1-testing.md` — simulator acceptance checklist.
- `docs/development-setup.md` — toolchain and emulator setup.
- `.github/workflows/arduboy.yml` — compile and HEX artifact.
- `CHANGELOG.md` — dated, milestone-specific implementation history.

No heap allocation or EEPROM writes. Six part types plus an empty cell use one byte each; the ship occupies 40 bytes. The same model is intended for dismantling, restoration, and flight.

## Development and license

Work is reviewed via feature branch and pull request; a passing CI build does not by itself complete a milestone. Simulator acceptance by the project owner is required before marking Milestone 1 done.

MIT — see [LICENSE](LICENSE).
