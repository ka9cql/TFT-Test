# TFT Hello World - Arduino IDE Quick Start

This folder contains the Arduino IDE sketch for testing your XIAO ESP32S3 with a 2.8" ILI9341 TFT display.

## Quick Setup (Arduino IDE 2.3.7)

### Step 1: Install ESP32 Board Support

1. Open **File → Preferences**
2. Add to "Additional Board Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Open **Tools → Board → Boards Manager**
4. Search "**esp32**" and install "**esp32 by Espressif Systems**"

### Step 2: Install TFT_eSPI Library

1. Open **Tools → Manage Libraries**
2. Search "**TFT_eSPI**"
3. Install "**TFT_eSPI by Bodmer**" (v2.5.43+)

### Step 3: Configure TFT_eSPI

**IMPORTANT:** Copy the `User_Setup.h` file from this folder to:

- **Windows**: `Documents\Arduino\libraries\TFT_eSPI\User_Setup.h`
- **Mac**: `~/Documents/Arduino/libraries/TFT_eSPI/User_Setup.h`
- **Linux**: `~/Arduino/libraries/TFT_eSPI/User_Setup.h`

**Backup the original file first!** Rename it to `User_Setup_BACKUP.h`

### Step 4: Upload the Sketch

1. Open `TFT_Hello_World.ino` in Arduino IDE
2. Select **Tools → Board → ESP32 Arduino → XIAO_ESP32S3**
3. Select **Tools → Port → (your COM port)**
4. Click **Upload** (→ button)
5. Hold **BOOT** button if upload fails

### Step 5: Open Serial Monitor

1. Click **Tools → Serial Monitor**
2. Set baud rate to **115200**
3. Press **RESET** button on XIAO
4. You should see initialization messages

## Pin Connections

| Function | XIAO GPIO | TFT Pin | Description |
|----------|-----------|---------|-------------|
| MISO | GPIO 8 | SDO | SPI Data Out |
| MOSI | GPIO 9 | SDI | SPI Data In |
| SCLK | GPIO 7 | SCK | SPI Clock |
| CS | GPIO 3 | CS | Chip Select |
| DC | GPIO 6 | DC/RS | Data/Command |
| RST | GPIO 2 | RESET | Reset |
| LED | GPIO 5 | LED/BL | Backlight |
| BUZZER | GPIO 1 | - | Audio (Optional) |

**Power:** VCC → 3.3V or 5V, GND → GND

## What You Should See

1. **Display shows "Hello World!"** with device info (3 seconds)
2. **Color bars** appear (Red, Green, Blue, Yellow, Magenta, Cyan, White)
3. **Serial monitor** shows initialization messages
4. **Buzzer beeps** twice (if connected)

## Troubleshooting

### Blank Display
- Check all pin connections carefully
- Verify power (VCC and GND)
- Ensure backlight is connected to GPIO 5
- Try lowering SPI speed in `User_Setup.h` (change 40MHz to 20MHz)

### Upload Fails
- Press and hold **BOOT** button during upload
- Check USB cable (must support data, not just charging)
- Verify correct port selected in Tools → Port

### Wrong Colors or Garbled Display
- Double-check MOSI (GPIO 9) and MISO (GPIO 8) are not swapped
- Ensure good GND connection
- Verify display is ILI9341 driver

### Serial Monitor Shows Nothing
- Set baud rate to **115200**
- Press **RESET** button after upload
- Check USB connection

## Need More Help?

See the main [README.md](../README.md) in the parent folder for complete documentation, including:
- Detailed hardware setup
- Advanced configuration options
- PlatformIO alternative
- Feature extension ideas

## Files in This Folder

- **TFT_Hello_World.ino** - Main Arduino sketch
- **User_Setup.h** - TFT_eSPI pin configuration (copy to library folder)
- **README_ARDUINO.md** - This file

---

**Tested with:**
- Arduino IDE 2.3.7
- ESP32 Board Package 2.x
- TFT_eSPI 2.5.43
- XIAO ESP32S3
- 2.8" ILI9341 240x320 TFT Display
