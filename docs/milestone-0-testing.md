# Milestone 0 — Verification Record

Use this document for simulator acceptance; a compile-only pass is insufficient.

| Check | Expected behavior | Result |
| --- | --- | --- |
| Build / local | Fresh checkout produces `dist/SSSHBRBSK.ino.hex` | PENDING |
| CI | Push/PR builds and uploads HEX artifact | PASS — push build run #1 |
| Title | `S.S.S.H.B.R.B.S.K.` readable within 128x64 | PENDING |
| Tugboat | A recognizable right-facing ship is visible | PENDING |
| A button | Thruster light and ON/OFF text toggle with each press | PENDING |
| B button | Thruster light resets ON without unintended mode change | PENDING |
| Repetition | 20 A/B presses work without freeze or display clipping | PENDING |
| Resources | Compiler flash/SRAM figures recorded below | PASS — compile log recorded |
| Screenshot | Screenshot attached to PR | PENDING |
| User acceptance | Reviewed in simulator before merge | PENDING |

## Build and simulator evidence

- Arduino CLI version: see workflow run (not separately recorded)
- AVR core: `arduino:avr@1.8.6` (requested)
- Arduboy2 library: `6.0.0` (requested)
- FQBN: `arduino:avr:leonardo`
- Flash: **7,094 bytes (24%) of 28,672-byte sketch limit**
- SRAM: **1,201 bytes (46%) of 2,560-byte limit**; 1,359 bytes remaining for stack/local variables
- CI evidence: https://github.com/steelwater/ship-builder/actions/runs/41436043004 (success; HEX artifact `ssshbrbsk-arduboy-hex`)\n- Simulator and version: not yet exercised
- Screenshot/recording: not yet attached

## Notes

Milestone 0 is deliberately a visual/input smoke test, not a finished or even partially playable ship-builder. CI may supply compile evidence; manual Ardens testing and user acceptance remain necessary before closing the milestone.
