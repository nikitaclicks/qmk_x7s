# X.Tips X7S / IQX7S / XTips X7 Mechanical Keyboard with QMK and VIAL Support, colemak-dh and miryoku

The keyboard works out of the box with **VIA** using the `via-x7.json` file. The QMK files in this repository were provided by the vendor, and you can use them to customize the keyboard via **QMK**.

You can also use **VIAL** to easily reflash and configure the keyboard without recompiling the firmware, while taking advantage of features like tap dance, chords, auto-shift, and other QMK functionalities.

### How to Use and flash:
1. pull qmk or vial-qmk
2. `qmk compile -kb x7s -km miryoku`
3. Connect the keyboard in bootloader mode, see below
4. `qmk flash x7s_miryoku.bin`
5. Repeat 3,4 for the second keyboard part

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
