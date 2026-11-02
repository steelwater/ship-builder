# S.S.S.H.B.R.B.S.K.

**Space Ship Salvage Haul Break Restore Build Sell Keep**

A 1-bit, 128 x 64 spaceship salvage and construction game for the original Arduboy / Arduboy FX (ATmega32u4). This project was previously called **Ship Builder**; the existing GitHub repository retains its `ship-builder` name.

## Status

**Milestone 0 in progress:** bootstrap sketch, compiler setup, simulator instructions, and GitHub Actions build. This is a hardware/simulator test screen, **not yet the salvage game**.

The approved game loop is: buy damaged ships, dismantle parts, restore them, build new ships, keep or sell, and haul more salvage. The first purchasable wreck will be the small tugboat *Little Mule*. Read the [development roadmap](https://docs.google.com/document/d/1H23HJkdBqy4uwCIjhhreuiGjYhKyxR59JeFosFODVF0/edit) for the sequence and emphasis on salvage logs and part provenance.

## Quick build (macOS or Linux)

Install [Arduino CLI](https://docs.arduino.cc/arduino-cli/installation) first. On macOS:

```bash
brew install arduino-cli
```

Then run from the repository root:

```bash
arduino-cli core update-index
arduino-cli core install arduino:avr@1.8.6
arduino-cli lib update-index
arduino-cli lib install Arduboy2@6.0.0
mkdir -p dist
arduino-cli compile --fqbn arduino:avr:leonardo --output-dir dist src/SSSHBRBSK
```

Expected file: `dist/SSSHBRBSK.ino.hex`. The compilation output should also report program storage and dynamic memory use.

## See it in an emulator

Open the [Ardens web player](https://tiberiusbrown.github.io/Ardens/player.html), load `dist/SSSHBRBSK.ino.hex` by dragging it onto the page, and start the simulation.

The screen should display `S.S.S.H.B.R.B.S.K.`, a shipyard test rig, and a small side-facing tugboat. **A** toggles its thruster light and **B** restores the default light state. There is no gameplay or save data in this milestone.

See [Development setup](docs/development-setup.md) for Arduino IDE/macOS setup, simulator steps and troubleshooting, and [Milestone 0 test checklist](docs/milestone-0-testing.md) for acceptance criteria.

## Repository

- `src/SSSHBRBSK/SSSHBRBSK.ino`: Arduboy-compatible sketch.
- `docs/milestone-0-crew-brief.md`: implementation brief and boundaries.
- `docs/development-setup.md`: local builds and emulator.
- `docs/milestone-0-testing.md`: manual simulator/hardware acceptance.
- `.github/workflows/arduboy.yml`: build and downloadable HEX artifact on each push/PR.

We use fixed-size state and the Arduboy2 framebuffer; no dynamic allocation. Future editor and flight screens must share a canonical ship representation.

## License

MIT — see [LICENSE](LICENSE).

## Development workflow

Implement milestones on feature branches. GitHub Actions builds a HEX for review. Review and merge only after simulator acceptance testing; do not treat a successful compile alone as a completed milestone.
