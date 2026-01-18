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

### Expected Serial Output

```
═══════════════════════════════════════
  TFT Display Test - XIAO ESP32S3
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

## Troubleshooting

### Display is blank or white
- Check all pin connections
- Verify power supply (VCC and GND)
- Ensure backlight is connected to GPIO 5
- Try adjusting `SPI_FREQUENCY` in `platformio.ini` (lower to 20MHz or 10MHz)

### Garbled display or wrong colors
- Verify MOSI and MISO are not swapped
- Check if your display uses different driver (not ILI9341)
- Ensure proper ground connection

### Display is dim
- Check backlight connection (GPIO 5 to LED/BL pin)
- Some displays may need a resistor or current limiting on backlight

### Upload fails
- Press and hold BOOT button on XIAO while uploading
- Check USB cable supports data transfer
- Verify correct COM port in PlatformIO

### No serial output
- Ensure serial monitor is set to 115200 baud
- Check USB cable connection
- Press RESET button on XIAO after upload

## Configuration

### Change Display Orientation

Edit `src/main.cpp`, line in `setup()` function:
```cpp
tft.setRotation(0);  // 0=Portrait, 1=Landscape, 2=Portrait(flipped), 3=Landscape(flipped)
```

### Adjust SPI Speed

Edit `platformio.ini`:
```ini
-D SPI_FREQUENCY=40000000  # Try 20000000 or 10000000 if issues occur
```

### Disable Buzzer

Comment out or remove buzzer-related code in `src/main.cpp`:
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
├── src/
│   └── main.cpp           # Main program code
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

- **v1.0.0** - Initial release with Hello World test
