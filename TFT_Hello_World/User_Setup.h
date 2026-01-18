/**
 * TFT_eSPI User Configuration for XIAO ESP32S3 + 2.8" ILI9341 Display
 *
 * This file configures the TFT_eSPI library for Arduino IDE.
 *
 * IMPORTANT INSTALLATION:
 * Place this file in your Arduino libraries folder at:
 * ~/Arduino/libraries/TFT_eSPI/User_Setup.h
 *
 * Or create a file named "User_Setup_Select.h" in the TFT_eSPI library folder
 * and uncomment the line that includes this setup.
 *
 * Pin Connections:
 * ┌────────────────────────────────────────────────────────┐
 * │ Function │ XIAO GPIO │ TFT Pin │ Description          │
 * ├──────────┼───────────┼─────────┼──────────────────────┤
 * │ MISO     │ GPIO 8    │ SDO     │ SPI Data Out         │
 * │ MOSI     │ GPIO 9    │ SDI     │ SPI Data In          │
 * │ SCLK     │ GPIO 7    │ SCK     │ SPI Clock            │
 * │ CS       │ GPIO 3    │ CS      │ Chip Select          │
 * │ DC       │ GPIO 6    │ DC/RS   │ Data/Command Select  │
 * │ RST      │ GPIO 2    │ RESET   │ Reset                │
 * │ LED      │ GPIO 5    │ LED/BL  │ Backlight Control    │
 * └────────────────────────────────────────────────────────┘
 */

#ifndef USER_SETUP_H
#define USER_SETUP_H

// ============================================================================
// DRIVER SELECTION
// ============================================================================
#define USER_SETUP_LOADED

#define ILI9341_DRIVER       // Display driver for 2.8" TFT

// ============================================================================
// DISPLAY RESOLUTION
// ============================================================================
#define TFT_WIDTH  240
#define TFT_HEIGHT 320

// ============================================================================
// PIN DEFINITIONS FOR XIAO ESP32S3
// ============================================================================

// SPI Communication Pins
#define TFT_MISO 8           // GPIO 8 - SPI MISO (SDO on display)
#define TFT_MOSI 9           // GPIO 9 - SPI MOSI (SDI on display)
#define TFT_SCLK 7           // GPIO 7 - SPI Clock (SCK on display)

// Control Pins
#define TFT_CS   3           // GPIO 3 - Chip Select
#define TFT_DC   6           // GPIO 6 - Data/Command (sometimes labeled RS)
#define TFT_RST  2           // GPIO 2 - Reset

// Optional: Backlight Control
#define TFT_BL   5           // GPIO 5 - Backlight LED control

// ============================================================================
// FONT CONFIGURATION
// ============================================================================
// Enable fonts for various text sizes
#define LOAD_GLCD            // Font 1. Original Adafruit 8 pixel font
#define LOAD_FONT2           // Font 2. Small 16 pixel high font
#define LOAD_FONT4           // Font 4. Medium 26 pixel high font
#define LOAD_FONT6           // Font 6. Large 48 pixel high font
#define LOAD_FONT7           // Font 7. 7 segment 48 pixel high font
#define LOAD_FONT8           // Font 8. Large 75 pixel high font

// Enable smooth fonts
#define SMOOTH_FONT
#define LOAD_GFXFF           // FreeFonts. Include access to the 48 Fonts

// ============================================================================
// SPI FREQUENCY SETTINGS
// ============================================================================
// SPI frequency for writing to display
#define SPI_FREQUENCY  40000000  // 40 MHz (maximum for ESP32)

// SPI frequency for reading from display (slower for stability)
#define SPI_READ_FREQUENCY  20000000  // 20 MHz

// Optionally, if display has issues, try these slower speeds:
// #define SPI_FREQUENCY  27000000  // 27 MHz
// #define SPI_FREQUENCY  20000000  // 20 MHz

// ============================================================================
// SPI PORT (ESP32 specific)
// ============================================================================
// ESP32 has two SPI ports: HSPI and VSPI
// Leave undefined to use default VSPI
// #define USE_HSPI_PORT

// ============================================================================
// COLOR DEPTH
// ============================================================================
// The ESP32 has plenty of memory so 16-bit color depth is fine
// Color depth: 16-bit (RGB565)
// This is already the default, but explicitly set for clarity

// ============================================================================
// OTHER OPTIONS
// ============================================================================

// Uncomment to invert display colors (if colors appear wrong)
// #define TFT_INVERSION_ON
// #define TFT_INVERSION_OFF

// Support for displays with different pixel orders
// #define TFT_RGB_ORDER TFT_RGB  // Color order Red-Green-Blue
// #define TFT_RGB_ORDER TFT_BGR  // Color order Blue-Green-Red

#endif // USER_SETUP_H
