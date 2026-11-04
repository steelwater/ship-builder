# Milestone 1 — Simulator acceptance checklist

**Status:** awaiting CI and project owner ProjectABE / Ardens testing. Do not mark Milestone 1 complete on compilation alone.

## Setup

1. Download the latest `ssshbrbsk-arduboy-hex` artifact from the Milestone 1 PR's GitHub Actions build (or compile locally using the README).
2. Open the HEX in ProjectABE or Ardens, 128×64 native mode.
3. Use Arduboy D-pad, A, B; no keyboard-only shortcuts are required.

## Verify (check each)

- [ ] Title displays fully on-screen; **A** opens editor; **B** opens help and returns.
- [ ] Editor grid, ship drawing, cursor and footer are legible at 128×64.
- [ ] D-pad reaches each edge without moving the cursor off-grid.
- [ ] **B** opens picker; left/right cycle all six parts and REMOVE; **A** selects, **B** cancels.
- [ ] **A** places selected part, replaces existing part, and updates occupied count.
- [ ] Selecting REMOVE then pressing **A** on an occupied cell clears it.
- [ ] Build three different ship silhouettes: long, tall, asymmetrical. No clipping or visual artifacts.
- [ ] Use repeated input on corners/edges; no crash, hang or input bleed between screens.
- [ ] Reset device: editor starts empty (expected RAM-only behavior).
- [ ] CI compilation succeeds and reports flash/SRAM usage; HEX artifact is downloadable.
- [ ] Note any simulator-specific issues or controls that feel awkward.

## Scope boundaries

The ship may be any arrangement of components; topology/validity rules and any economy are deferred. Little Mule purchase, dismantling, restoration and salvage logs are **not** part of Milestone 1.

## Reviewer notes

Record ProjectABE screenshots, flash and SRAM report, issues and pass/fail in the PR before merging.
