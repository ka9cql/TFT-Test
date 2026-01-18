# TFT Display Test - Hello World

A simple test program to verify proper connection between a **Seeed XIAO ESP32S3** and a **2.8" ILI9341 TFT Display**.

## Hardware Components

- **Microcontroller**: Seeed XIAO ESP32S3
- **Display**: 2.8" ILI9341 TFT Display (240x320 pixels)
- **Optional**: Buzzer for audio feedback

## Pin Mapping

| Function | XIAO ESP32S3 GPIO | TFT Display Pin | Description          |
|----------|-------------------|-----------------|----------------------|
| MISO     | GPIO 8            | SDO (MISO)      | SPI Data Out         |
| MOSI     | GPIO 9            | SDI (MOSI)      | SPI Data In          |
| SCLK     | GPIO 7            | SCK             | SPI Clock            |
| CS       | GPIO 3            | CS              | Chip Select          |
| DC       | GPIO 6            | DC/RS           | Data/Command Select  |
| RST      | GPIO 2            | RESET           | Reset                |
| LED      | GPIO 5            | LED/BL          | Backlight Control    |
| BUZZER   | GPIO 1            | N/A             | Audio Alert (Optional) |

## Power Connections

- **VCC**: Connect to 3.3V or 5V (check your display specs)
- **GND**: Connect to GND

## Features

This test program demonstrates:

1. **Display Initialization** - Proper setup of SPI communication
2. **Hello World Message** - Large text display
3. **Board Information** - Display device details
4. **Color Test** - RGB color bars to verify color accuracy
5. **Backlight Control** - Demonstrates backlight functionality
6. **Audio Feedback** - Optional buzzer beeps on successful initialization

## Display Output

The program displays two screens:

### Screen 1: Hello World (3 seconds)
```
┌─────────────────────────┐
│   TFT Display Test      │
├─────────────────────────┤
│                         │
│    Hello World!         │
│                         │
│   XIAO ESP32S3          │
│   2.8" ILI9341          │
│   240x320 Display       │
│                         │
│   Connected!            │
│                         │
└─────────────────────────┘
```

### Screen 2: Color Test
Displays 7 color bars (Red, Green, Blue, Yellow, Magenta, Cyan, White) to verify color output.

## Getting Started

This project supports both **Arduino IDE 2.3.7+** and **PlatformIO**. Choose the method that works best for you.

---

## Option 1: Arduino IDE 2.3.7 (Recommended for Beginners)

### Prerequisites

- [Arduino IDE 2.3.7+](https://www.arduino.cc/en/software) installed
- USB cable to connect XIAO ESP32S3 to your computer

### Installation Steps

#### 1. Install ESP32 Board Support

1. Open Arduino IDE 2.3.7
2. Go to **File → Preferences**
3. In "Additional Board Manager URLs", add:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Click **OK**
5. Go to **Tools → Board → Boards Manager**
6. Search for "**esp32**"
7. Install "**esp32 by Espressif Systems**" (latest version)

#### 2. Install TFT_eSPI Library

1. Go to **Tools → Manage Libraries** (or **Sketch → Include Library → Manage Libraries**)
2. Search for "**TFT_eSPI**"
3. Install "**TFT_eSPI by Bodmer**" (v2.5.43 or later)

#### 3. Configure TFT_eSPI for XIAO ESP32S3

This is the most important step! The library needs to know which pins to use.

**Method A: Copy User_Setup.h (Recommended)**

1. Locate your Arduino libraries folder:
   - **Windows**: `Documents\Arduino\libraries\TFT_eSPI\`
   - **Mac**: `~/Documents/Arduino/libraries/TFT_eSPI/`
   - **Linux**: `~/Arduino/libraries/TFT_eSPI/`

2. **Backup the original** `User_Setup.h` file (rename it to `User_Setup_BACKUP.h`)

3. Copy the `User_Setup.h` file from this repository's `TFT_Hello_World/` folder to the TFT_eSPI library folder, replacing the existing file

**Method B: Edit User_Setup.h Manually**

1. Open `Arduino/libraries/TFT_eSPI/User_Setup.h`
2. Find and uncomment (or add) these lines:
   ```cpp
   #define ILI9341_DRIVER
   #define TFT_MISO 8
   #define TFT_MOSI 9
   #define TFT_SCLK 7
   #define TFT_CS   3
   #define TFT_DC   6
   #define TFT_RST  2
   #define TFT_BL   5
   ```

#### 4. Open and Upload the Sketch

1. Open the sketch file: `TFT_Hello_World/TFT_Hello_World.ino`
2. Select your board:
   - **Tools → Board → ESP32 Arduino → XIAO_ESP32S3**
3. Select your port:
   - **Tools → Port → (select the COM port or /dev/tty* for your board)**
4. Click **Upload** button (→)
5. If upload fails, press and hold the **BOOT** button on the XIAO while uploading

#### 5. View Serial Monitor

1. Click **Tools → Serial Monitor** (or the icon in the top right)
2. Set baud rate to **115200**
3. Press the **RESET** button on the XIAO
4. You should see the initialization messages

---

## Option 2: PlatformIO

### Prerequisites

- [PlatformIO](https://platformio.org/) installed (via VS Code extension or CLI)
- USB cable to connect XIAO ESP32S3 to your computer

### Installation & Upload

1. **Clone this repository**:
   ```bash
   git clone <repository-url>
   cd TFT-Test
   ```

2. **Open in PlatformIO**:
   - Open the project folder in VS Code with PlatformIO extension
   - Or use PlatformIO CLI

3. **Build the project**:
   ```bash
   pio run
   ```

4. **Upload to the board**:
   ```bash
   pio run --target upload
   ```

5. **Monitor serial output**:
   ```bash
   pio device monitor
   ```

---

### Expected Serial Output

```
═══════════════════════════════════════
  TFT Display Test - XIAO ESP32S3
  Arduino IDE 2.3.7
═══════════════════════════════════════
✓ Buzzer initialized
✓ Backlight initialized
Initializing TFT display...
✓ TFT initialized successfully
  Resolution: 240 x 320
✓ Hello World displayed on TFT
✓ Setup complete!
═══════════════════════════════════════

✓ Color test displayed
```

If you see this output and the display shows "Hello World!" followed by color bars, your setup is working correctly!

## Troubleshooting

### Display is blank or white
- Check all pin connections
- Verify power supply (VCC and GND)
- Ensure backlight is connected to GPIO 5
- Try lowering SPI frequency:
  - **Arduino IDE**: Edit `User_Setup.h`, change `SPI_FREQUENCY` to 20MHz or 10MHz
  - **PlatformIO**: Edit `platformio.ini`, change `-D SPI_FREQUENCY=40000000` to 20000000 or 10000000

### Garbled display or wrong colors
- Verify MOSI and MISO are not swapped
- Check if your display uses different driver (not ILI9341)
- Ensure proper ground connection

### Display is dim
- Check backlight connection (GPIO 5 to LED/BL pin)
- Some displays may need a resistor or current limiting on backlight

### Upload fails
- Press and hold BOOT button on XIAO while uploading
- Check USB cable supports data transfer (not just a charging cable)
- Verify correct COM port is selected:
  - **Arduino IDE**: Tools → Port
  - **PlatformIO**: Check `monitor_port` in platformio.ini
- Try a different USB port on your computer

### No serial output
- Ensure serial monitor is set to 115200 baud
- Check USB cable connection
- Press RESET button on XIAO after upload

## Configuration

### Change Display Orientation

Edit the sketch in `setup()` function:
- **Arduino IDE**: Edit `TFT_Hello_World.ino`
- **PlatformIO**: Edit `src/main.cpp`

```cpp
tft.setRotation(0);  // 0=Portrait, 1=Landscape, 2=Portrait(flipped), 3=Landscape(flipped)
```

### Adjust SPI Speed

If you experience display issues, try lowering the SPI frequency:

**Arduino IDE:**
1. Open `Arduino/libraries/TFT_eSPI/User_Setup.h`
2. Find and change:
   ```cpp
   #define SPI_FREQUENCY  40000000  // Try 20000000 or 10000000
   ```

**PlatformIO:**
Edit `platformio.ini`:
```ini
-D SPI_FREQUENCY=40000000  # Try 20000000 or 10000000 if issues occur
```

### Disable Buzzer

Comment out or remove buzzer-related code:
- **Arduino IDE**: Edit `TFT_Hello_World.ino`
- **PlatformIO**: Edit `src/main.cpp`

```cpp
// initBuzzer();
// playSuccessBeep();
```

## Library Dependencies

- **TFT_eSPI** v2.5.43+ by Bodmer
  - Comprehensive graphics library for ESP32
  - Configured via build flags in `platformio.ini`

## Project Structure

```
TFT-Test/
├── TFT_Hello_World/       # Arduino IDE sketch folder
│   ├── TFT_Hello_World.ino  # Arduino sketch file
│   └── User_Setup.h       # TFT_eSPI configuration for Arduino IDE
├── src/
│   └── main.cpp           # PlatformIO main program code
├── include/               # Header files (if needed)
├── lib/                   # Custom libraries
├── test/                  # Unit tests
├── platformio.ini         # PlatformIO configuration
└── README.md             # This file
```

## Next Steps

Once the display is working, you can:

- Add touch functionality (if your display has touch)
- Create a GUI with buttons and controls
- Display sensor data or graphs
- Build a weather station display
- Create a game interface

## License

This is a test/example program. Feel free to use and modify as needed.

## Support

For issues or questions:
- Check PlatformIO documentation
- Review TFT_eSPI library examples
- Verify hardware connections match pin mapping

## Version History

- **v1.1.0** - Added Arduino IDE 2.3.7 support with .ino sketch and User_Setup.h
- **v1.0.0** - Initial release with PlatformIO Hello World test
