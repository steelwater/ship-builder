# S.S.S.H.B.R.B.S.K. — Milestone 0 Crew Brief

**Status:** In progress; pending verified CI build and simulator acceptance  
**Repository:** https://github.com/steelwater/ship-builder  
**Roadmap:** https://docs.google.com/document/d/1H23HJkdBqy4uwCIjhhreuiGjYhKyxR59JeFosFODVF0/edit  
**Target:** Original Arduboy / FX, 128 x 64 monochrome; ATmega32u4  
**Feature branch:** `milestone-0-arduboy-toolchain`

## Mission

Prepare a reproducible native Arduboy development baseline. Deliver a visible HEX smoke-test sketch, working automated build, documentation for an Apple Silicon macOS development machine, and an emulator smoke-test procedure. Do not implement ship-editor gameplay yet.

## Implementation deliverables

1. Establish the canonical title **S.S.S.H.B.R.B.S.K.** (Space Ship Salvage Haul Break Restore Build Sell Keep), while retaining the existing repository path.
2. Create a minimal `src/SSSHBRBSK/SSSHBRBSK.ino` using Arduboy2, the AVR Leonardo target, and a 128x64 monochrome test screen.
3. Include native A/B input feedback, a right-facing 1-bit tugboat illustration, and an unambiguous title so simulator behavior is observable.
4. Document Arduino CLI / optional Arduino IDE setup for macOS (including Apple Silicon), compile/export steps, Ardens web player load steps, controls, known fixes.
5. Add a CI job that installs pinned AVR/Arduboy2 dependencies, compiles, and uploads a nonempty `.hex` artifact; collect flash/SRAM output.
6. Establish README, MIT license, .gitignore and a human simulator test checklist.

## Acceptance checklist

- [ ] Fresh clone builds on macOS following only the README/setup instructions.
- [ ] GitHub Actions build completes and exposes a downloadable HEX artifact.
- [ ] The HEX boots in Ardens (or ProjectABE) to a readable 128x64 monochrome test screen.
- [ ] Pressing **A** visibly toggles the thruster light; **B** resets it.
- [ ] No clipping, truncated labels, accidental simultaneous-button actions or static-memory budget concerns.
- [ ] Record compilation flash and SRAM usage; attach simulator screenshot to the pull request.
- [ ] User performs acceptance and merges the PR. Do not mark M0 complete earlier.

## Guardrails

- Use Arduino Leonardo compatibility (`arduino:avr:leonardo`) and Arduboy2; avoid custom board packages and FX-specific dependencies at M0.
- Keep bitmaps, ship state and inventory data for later milestones. Prefer fixed arrays and flash-stored strings as features are added.
- No salvage economy, Little Mule acquisition, dismantling, editor, sale, EEPROM persistence, or secret discoveries yet.
- Preserve the revised roadmap ordering: M1 editor/model, M2 purchase/dismantling/restoration, M3 ship/economy, M4 haul, M5 logs/provenance.
- This brief is a work order, not acceptance evidence.
