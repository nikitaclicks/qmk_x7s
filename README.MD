# X.Tips X7S / IQX7S / XTips X7 Mechanical Keyboard
## With QMK and VIAL Support
### Miryoku, colemak-dh base layer

The keyboard works out of the box with **VIA** using the `via-x7.json` file. The QMK files in this repository were provided by the vendor, and you can use them to customize the keyboard via **QMK**.

You can also use **VIAL** to easily reflash and configure the keyboard without recompiling the firmware, while taking advantage of features like tap dance, chords, auto-shift, and other QMK functionalities.

### How to Use and flash:
1. pull qmk or vial-qmk (I prefer this)
2. clone the repo into `keyboards` folder
3. `qmk compile -kb x7s -km miryoku`
4. Connect the keyboard in bootloader mode, see below
5. `qmk flash x7s_miryoku.bin`
6. If using vial: Go to https://vial.rocks/ -> QMK Settings -> Tap Hold -> Enable Permissive Hold, Ignore Mod Tap interrupt
7. Repeat 3,4,6 for the second keyboard part

### How to Enter Bootloader Mode:

A) Connect the keyboard holding the top left or top right button (didn't work for me out of the box)

B) Unscrew the lower plate and connect the RESET pins when connecting (https://i.imgur.com/mNZDhzU.png)


After this custom firmware is flashed, bootloader mode can be entered by 

C) holding the top middle button when connecting the keyboard

### Additional info about the process and restoring the keyboard
Reddit thread: https://www.reddit.com/r/ErgoMechKeyboards/comments/1ezndeh/any_users_of_xtips_x7s_keyboard_here_anyone_got/

### keywords:
- IQX7S mechanical keyboard
- X.Tips X7 mechanical keyboard
- QMK firmware for IQX7S
- VIAL firmware support for IQX7S
- VIA setup for IQX7S keyboard
- Custom mechanical keyboard IQX7S
- Bootloader mode for IQX7S keyboard
- X.Tips X7 keyboard QMK
