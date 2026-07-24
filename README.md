# Voyager Dev-ES firmware

A radical ZSA Voyager layout designed from scratch for:

- English and Spanish prose
- TypeScript development
- macOS
- minimal movement away from the home row

## Important assumption

The Spanish macros target the macOS **ABC** or **U.S.** input source. They use native macOS dead-key sequences, so no Unicode Hex Input source or extra software is required.

## Thumb keys

| Physical key | Tap | Hold |
|---|---|---|
| Left upper | Backspace | Number layer |
| Left lower | Space | Navigation layer |
| Right lower | Tab | Shift |
| Right upper | Enter | Code layer |

## Base layer

```text
CapsWord F1 F2 F3 F4 F5          F6 F7 F8 F9 F10 Delete
Esc      Q  J  Y  ,  .           B  H  D  M  P   \
Spanish  A  E⌃ O⌥ I⌘ U           N  S⌘ T⌥ R⌃ L   '
Hyper    Z  X  C  G  -           K  W  F  V  /   Enter

             Bsp/Num  Spc/Nav   Tab/Shift  Enter/Code
```

## Code layer

```text
=== !== ??  ?.  ... =>           && || <= >= += -=
Esc `   <   >   @   #            &  |  ?  :  ;  \
[   {   (   )   }   ]            => =  +  -  *  /
_   "   '   $   %   ^            !  ~  \  .  ,  ;
```

## Navigation layer

The left half remains transparent, preserving the home-row modifiers. The right half provides application/tab controls, document and word movement, arrows, and clipboard operations.

## Number layer

Digits are on the home row, their shifted symbols are directly above, and F1–F12 occupy the physical top row.

## Spanish layer

Tap the Spanish one-shot key, then:

- `A E O I U` → `á é ó í ú`
- `N` → `ñ`
- physical `W` → `ü`
- left outer keys → `¡`
- right slash/outer keys → `¿`
- hold the Shift thumb while selecting a letter for uppercase
- top-right key enters the bootloader for flashing/recovery

## Build locally

```bash
qmk setup zsa/qmk_firmware -b firmware25
cp -R keymap ~/qmk_firmware/keyboards/voyager/keymaps/dev_es
cd ~/qmk_firmware
qmk compile -kb voyager -km dev_es
```

The output is normally a `.bin` file in the QMK root.

## Build with GitHub Actions

Push this directory to a GitHub repository. The included workflow checks out ZSA's `firmware25` branch, compiles the keymap, and publishes the flashable file as a workflow artifact.

## Flash

Open ZSA Keymapp, choose **Flash**, select the compiled firmware file, and press the Voyager reset button when prompted.

## First tuning targets

- Default tapping term: `220 ms`
- Home-row modifiers: `225 ms`
- Thumb tap-holds: `205 ms`
- Permissive Hold and Chordal Hold are enabled

These values are deliberately conservative for the first week. Adjust them only after the alpha layout starts to feel familiar.
