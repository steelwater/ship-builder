# Changelog

Notable work in S.S.S.H.B.R.B.S.K. (Space Ship Salvage Haul Break Restore Build Sell Keep). Milestone work is logged here; the README stays focused on current use and setup.

## Unreleased — Milestone 1 (2026-11-04; acceptance pending)

### Added
- Native 128×64 title screen, contextual help and interactive 10×4 ship editor.
- Six editable ship components: cockpit, hull, engine, fin, weapon and shield, plus REMOVE.
- Single canonical fixed-size ship model, shared by ship rendering and editor.
- Parts picker, cursor movement, replacement/removal and part count.
- Milestone 1 simulator checklist and documented controls.

### Notes
- Ship data is RAM-only; no EEPROM, economy, salvage inventory or credits in this milestone.
- Requires CI compilation and user simulator review before milestone closure.

## Milestone 0 — Completed (2026-11-04)

- Arduino CLI/Arduboy2 build bootstrap and GitHub Actions HEX artifact.
- Original shipyard test screen and development setup documentation.
- CI build verified; ProjectABE visible screen accepted by project owner.
