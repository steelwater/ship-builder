# Milestone 0 — Verification Record

Use this document for simulator acceptance; a compile-only pass is insufficient.

| Check | Expected behavior | Result |
| --- | --- | --- |
| Build / local | Fresh checkout produces `dist/SSSHBRBSK.ino.hex` | PENDING |
| CI | Push/PR builds and uploads HEX artifact | PENDING |
| Title | `S.S.S.H.B.R.B.S.K.` readable within 128x64 | PENDING |
| Tugboat | A recognizable right-facing ship is visible | PENDING |
| A button | Thruster light and ON/OFF text toggle with each press | PENDING |
| B button | Thruster light resets ON without unintended mode change | PENDING |
| Repetition | 20 A/B presses work without freeze or display clipping | PENDING |
| Resources | Compiler flash/SRAM figures recorded below | PENDING |
| Screenshot | Screenshot attached to PR | PENDING |
| User acceptance | Reviewed in simulator before merge | PENDING |

## Build and simulator evidence

- Arduino CLI version: not yet recorded
- AVR core: `arduino:avr@1.8.6` (requested)
- Arduboy2 library: `6.0.0` (requested)
- FQBN: `arduino:avr:leonardo`
- Flash: not yet measured
- SRAM: not yet measured
- Simulator and version: not yet exercised
- Screenshot/recording: not yet attached

## Notes

Milestone 0 is deliberately a visual/input smoke test, not a finished or even partially playable ship-builder. CI may supply compile evidence; manual Ardens testing and user acceptance remain necessary before closing the milestone.
