# Developer Setup — macOS, Arduino CLI and Arduboy Simulator

## Requirements

- Mac (including Apple Silicon), macOS Terminal, Git and Homebrew.
- Arduino CLI and an internet connection for the first AVR core/library install.
- For simulator testing: Ardens web player in a recent desktop browser.
- An actual Arduboy is optional until hardware validation.

The `arduino:avr:leonardo` profile is a standard, compatible target for original Arduboy hardware, and it avoids conflicts with the alternate homemade-board package.

## Install once

```bash
brew install arduino-cli
arduino-cli version
arduino-cli core update-index
arduino-cli core install arduino:avr@1.8.6
arduino-cli lib update-index
arduino-cli lib install Arduboy2@6.0.0
```

Do not install the homemade-board package alongside this baseline expecting identical library behavior; it may bundle its own Arduboy2 and create conflicts.

## Compile/export HEX

```bash
git clone https://github.com/steelwater/ship-builder.git
cd ship-builder
# If testing the milestone before merge, switch to its PR/feature branch.
mkdir -p dist
arduino-cli compile --fqbn arduino:avr:leonardo --warnings all --output-dir dist src/SSSHBRBSK
ls -lh dist/SSSHBRBSK.ino.hex
```

The `.ino` folder and filename intentionally match (`SSSHBRBSK`). The compiler's final output prints flash usage and global/dynamic memory usage. Keep this output as acceptance evidence.

The equivalent Arduino IDE method is: install **Arduboy2** via Library Manager, select **Arduino Leonardo**, open `src/SSSHBRBSK/SSSHBRBSK.ino`, then **Sketch > Verify/Compile** or **Sketch > Export Compiled Binary**.

## Run in Ardens

1. Open https://tiberiusbrown.github.io/Ardens/player.html on desktop.
2. Drag and drop `dist/SSSHBRBSK.ino.hex` onto the player (or use its file picker).
3. Start/resume simulation if paused and verify the title, tugboat, controls and 128x64 display.
4. Press **A**: the exhaust light and status text toggle ON/OFF.
5. Press **B**: light resets to ON. Repeat to catch input glitches.
6. Capture a screenshot for the milestone PR.

Alternative: https://felipemanga.github.io/ProjectABE/ — load the same HEX. Browser simulators do not need a USB-connected Arduboy.

## Optional hardware test

Connect the Arduboy by USB; find the serial port with `arduino-cli board list`, then upload using the correct port:

```bash
arduino-cli upload --fqbn arduino:avr:leonardo -p /dev/cu.usbmodemXXXX -i dist/SSSHBRBSK.ino.hex
```

Replace `/dev/cu.usbmodemXXXX` with the detected port; **never** use this sample port unchanged.

## Troubleshooting

- **arduino-cli not found:** check Homebrew installation and `brew shellenv` in your shell setup (on Apple Silicon the default Homebrew prefix is often `/opt/homebrew`).
- **Platform missing / FQBN unknown:** rerun `arduino-cli core update-index` then install `arduino:avr@1.8.6`.
- **Arduboy2.h not found:** run `arduino-cli lib update-index` and `arduino-cli lib install Arduboy2@6.0.0`; check `arduino-cli lib list`.
- **Multiple Arduboy libraries detected:** remove extra conflicting local copies; avoid mixing custom board-package bundles with stock Arduboy2.
- **No HEX:** check compilation output before opening the emulator. The output path is `dist/SSSHBRBSK.ino.hex`.
- **Emulator black screen:** confirm the HEX was loaded (not the `.ino`), start the virtual Arduboy, and inspect the emulator's pause/reset state.
- **Upload fails / port missing:** use a data-capable USB cable, check the board is powered and `arduino-cli board list`. Reset to bootloader if the app has locked USB.
- **Emulator and hardware differ:** M0 acceptance is simulator-first; record the discrepancy as a follow-up rather than claiming hardware compatibility.

## References

- https://www.arduboy.com/quick-start/
- https://docs.arduino.cc/arduino-cli/commands-reference/arduino-cli_compile
- https://github.com/MLXXXp/Arduboy2
- https://github.com/tiberiusbrown/Ardens
