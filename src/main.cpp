/**
 * TFT Display Test Program - Hello World
 *
 * Board: Seeed XIAO ESP32S3
 * Display: 2.8" ILI9341 TFT Display (240x320)
 *
 * Pin Connections:
 * ┌─────────────────────────────────────────────────────┐
 * │ Function  │ XIAO GPIO │ TFT Pin │ Description       │
 * ├───────────┼───────────┼─────────┼───────────────────┤
 * │ MISO      │ GPIO 8    │ SDO     │ SPI Data Out      │
 * │ MOSI      │ GPIO 9    │ SDI     │ SPI Data In       │
 * │ SCLK      │ GPIO 7    │ SCK     │ SPI Clock         │
 * │ CS        │ GPIO 3    │ CS      │ Chip Select       │
 * │ DC        │ GPIO 6    │ DC/RS   │ Data/Command      │
 * │ RST       │ GPIO 2    │ RESET   │ Reset             │
 * │ LED       │ GPIO 5    │ LED/BL  │ Backlight Control │
 * │ BUZZER    │ GPIO 1    │ N/A     │ Audio Buzzer      │
 * └─────────────────────────────────────────────────────┘
 */

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

// Pin definitions (defined in platformio.ini, declared here for reference)
#define TFT_MISO 8
#define TFT_MOSI 9
#define TFT_SCLK 7
#define TFT_CS   3
#define TFT_DC   6
#define TFT_RST  2
#define TFT_BL   5
#define BUZZER   1

// Create TFT object
TFT_eSPI tft = TFT_eSPI();

// Color definitions
#define COLOR_BG      0x0000  // Black
#define COLOR_TEXT    0xFFFF  // White
#define COLOR_TITLE   0x07FF  // Cyan
#define COLOR_SUCCESS 0x07E0  // Green
#define COLOR_INFO    0xFFE0  // Yellow

/**
 * Initialize the TFT backlight
 */
void initBacklight() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);  // Turn on backlight
  Serial.println("✓ Backlight initialized");
}

/**
 * Initialize the buzzer (optional)
 */
void initBuzzer() {
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  Serial.println("✓ Buzzer initialized");
}

/**
 * Play a short beep to indicate successful initialization
 */
void playSuccessBeep() {
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(50);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}

/**
 * Display test pattern and Hello World message
 */
void displayHelloWorld() {
  // Clear screen with black background
  tft.fillScreen(COLOR_BG);

  // Draw title bar
  tft.fillRect(0, 0, 240, 40, TFT_NAVY);
  tft.setTextColor(COLOR_TITLE, TFT_NAVY);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("TFT Display Test", 120, 20, 4);

  // Display main message
  tft.setTextColor(COLOR_TEXT, COLOR_BG);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("Hello World!", 120, 100, 7);

  // Display board info
  tft.setTextColor(COLOR_INFO, COLOR_BG);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("XIAO ESP32S3", 120, 160, 4);
  tft.drawString("2.8\" ILI9341", 120, 190, 4);
  tft.drawString("240x320 Display", 120, 220, 2);

  // Display connection status
  tft.setTextColor(COLOR_SUCCESS, COLOR_BG);
  tft.drawString("Connected!", 120, 260, 4);

  // Draw decorative border
  tft.drawRect(5, 45, 230, 270, TFT_WHITE);
  tft.drawRect(6, 46, 228, 268, TFT_WHITE);

  Serial.println("✓ Hello World displayed on TFT");
}

/**
 * Display colorful test pattern
 */
void displayColorTest() {
  delay(3000);  // Show Hello World for 3 seconds

  tft.fillScreen(COLOR_BG);

  // Title
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("Color Test", 120, 10, 4);

  // Draw color bars
  int barHeight = 35;
  int startY = 50;

  tft.fillRect(0, startY + (barHeight * 0), 240, barHeight, TFT_RED);
  tft.fillRect(0, startY + (barHeight * 1), 240, barHeight, TFT_GREEN);
  tft.fillRect(0, startY + (barHeight * 2), 240, barHeight, TFT_BLUE);
  tft.fillRect(0, startY + (barHeight * 3), 240, barHeight, TFT_YELLOW);
  tft.fillRect(0, startY + (barHeight * 4), 240, barHeight, TFT_MAGENTA);
  tft.fillRect(0, startY + (barHeight * 5), 240, barHeight, TFT_CYAN);
  tft.fillRect(0, startY + (barHeight * 6), 240, barHeight, TFT_WHITE);

  // Label colors
  tft.setTextColor(TFT_WHITE, TFT_RED);
  tft.drawString("RED", 120, startY + (barHeight * 0) + 10, 2);

  tft.setTextColor(TFT_BLACK, TFT_GREEN);
  tft.drawString("GREEN", 120, startY + (barHeight * 1) + 10, 2);

  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.drawString("BLUE", 120, startY + (barHeight * 2) + 10, 2);

  tft.setTextColor(TFT_BLACK, TFT_YELLOW);
  tft.drawString("YELLOW", 120, startY + (barHeight * 3) + 10, 2);

  tft.setTextColor(TFT_WHITE, TFT_MAGENTA);
  tft.drawString("MAGENTA", 120, startY + (barHeight * 4) + 10, 2);

  tft.setTextColor(TFT_BLACK, TFT_CYAN);
  tft.drawString("CYAN", 120, startY + (barHeight * 5) + 10, 2);

  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.drawString("WHITE", 120, startY + (barHeight * 6) + 10, 2);

  Serial.println("✓ Color test displayed");
}

/**
 * Arduino setup function
 */
void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n\n═══════════════════════════════════════");
  Serial.println("  TFT Display Test - XIAO ESP32S3");
  Serial.println("═══════════════════════════════════════");

  // Initialize peripherals
  initBuzzer();
  initBacklight();

  // Initialize TFT display
  Serial.println("Initializing TFT display...");
  tft.init();
  tft.setRotation(0);  // Portrait mode (0 or 2), use 1 or 3 for landscape

  Serial.println("✓ TFT initialized successfully");
  Serial.print("  Resolution: ");
  Serial.print(tft.width());
  Serial.print(" x ");
  Serial.println(tft.height());

  // Display Hello World
  displayHelloWorld();

  // Play success beep
  playSuccessBeep();

  Serial.println("\n✓ Setup complete!");
  Serial.println("═══════════════════════════════════════\n");

  // Show color test after 3 seconds
  displayColorTest();
}

/**
 * Arduino loop function
 */
void loop() {
  // Main loop - display is static, nothing to update
  // You can add interactive features here later

  delay(1000);
}
