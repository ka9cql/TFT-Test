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
 * │ DC        │ GPIO 44   │ DC/RS   │ Data/Command      │
 * │ RST       │ GPIO 43   │ RESET   │ Reset             │
 * │ LED       │ GPIO 2    │ LED/BL  │ Backlight Control │
 * │ BUZZER    │ GPIO 1    │ N/A     │ Audio Buzzer      │
 * └─────────────────────────────────────────────────────┘
 */

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pin definitions
#define TFT_MISO 8
#define TFT_MOSI 9
#define TFT_SCLK 7
#define TFT_CS   3
#define TFT_DC   44
#define TFT_RST  43
#define TFT_BL   2
#define BUZZER   1

// Create display object with hardware SPI
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// Color definitions
#define COLOR_BG      ILI9341_BLACK
#define COLOR_TEXT    ILI9341_WHITE
#define COLOR_TITLE   ILI9341_CYAN
#define COLOR_SUCCESS ILI9341_GREEN
#define COLOR_INFO    ILI9341_YELLOW

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
  tft.fillRect(0, 0, 240, 40, ILI9341_NAVY);
  tft.setTextColor(COLOR_TITLE);
  tft.setTextSize(2);
  tft.setCursor(25, 12);
  tft.println("TFT Display Test");

  // Display main message
  tft.setTextColor(COLOR_TEXT);
  tft.setTextSize(4);
  tft.setCursor(15, 100);
  tft.println("Hello");
  tft.setCursor(15, 135);
  tft.println("World!");

  // Display board info
  tft.setTextColor(COLOR_INFO);
  tft.setTextSize(2);
  tft.setCursor(20, 180);
  tft.println("XIAO ESP32S3");
  tft.setCursor(15, 200);
  tft.println("2.8\" ILI9341");
  tft.setTextSize(1);
  tft.setCursor(50, 225);
  tft.println("240x320 Display");

  // Display connection status
  tft.setTextColor(COLOR_SUCCESS);
  tft.setTextSize(3);
  tft.setCursor(15, 260);
  tft.println("Connected!");

  // Draw decorative border
  tft.drawRect(5, 45, 230, 270, ILI9341_WHITE);
  tft.drawRect(6, 46, 228, 268, ILI9341_WHITE);

  Serial.println("✓ Hello World displayed on TFT");
}

/**
 * Display colorful test pattern
 */
void displayColorTest() {
  delay(3000);  // Show Hello World for 3 seconds

  tft.fillScreen(COLOR_BG);

  // Title
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(40, 10);
  tft.println("Color Test");

  // Draw color bars
  int barHeight = 35;
  int startY = 50;

  tft.fillRect(0, startY + (barHeight * 0), 240, barHeight, ILI9341_RED);
  tft.fillRect(0, startY + (barHeight * 1), 240, barHeight, ILI9341_GREEN);
  tft.fillRect(0, startY + (barHeight * 2), 240, barHeight, ILI9341_BLUE);
  tft.fillRect(0, startY + (barHeight * 3), 240, barHeight, ILI9341_YELLOW);
  tft.fillRect(0, startY + (barHeight * 4), 240, barHeight, ILI9341_MAGENTA);
  tft.fillRect(0, startY + (barHeight * 5), 240, barHeight, ILI9341_CYAN);
  tft.fillRect(0, startY + (barHeight * 6), 240, barHeight, ILI9341_WHITE);

  // Label colors
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(80, startY + (barHeight * 0) + 10);
  tft.println("RED");

  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(65, startY + (barHeight * 1) + 10);
  tft.println("GREEN");

  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(75, startY + (barHeight * 2) + 10);
  tft.println("BLUE");

  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(60, startY + (barHeight * 3) + 10);
  tft.println("YELLOW");

  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(50, startY + (barHeight * 4) + 10);
  tft.println("MAGENTA");

  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(75, startY + (barHeight * 5) + 10);
  tft.println("CYAN");

  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(70, startY + (barHeight * 6) + 10);
  tft.println("WHITE");

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
  Serial.println("  Pin Configuration:");
  Serial.printf("    MISO: GPIO %d\n", TFT_MISO);
  Serial.printf("    MOSI: GPIO %d\n", TFT_MOSI);
  Serial.printf("    SCLK: GPIO %d\n", TFT_SCLK);
  Serial.printf("    CS:   GPIO %d\n", TFT_CS);
  Serial.printf("    DC:   GPIO %d\n", TFT_DC);
  Serial.printf("    RST:  GPIO %d\n", TFT_RST);

  // Initialize SPI with custom pins
  Serial.println("  Setting up SPI...");
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI);

  // Initialize display
  Serial.println("  Calling tft.begin()...");
  tft.begin();
  delay(100);
  tft.setRotation(0);  // Portrait mode (0 or 2), use 1 or 3 for landscape

  Serial.println("✓ TFT initialized successfully");
  Serial.print("  Resolution: ");
  Serial.print(tft.width());
  Serial.print(" x ");
  Serial.println(tft.height());

  // Test display is responsive
  Serial.println("  Testing display...");
  tft.fillScreen(ILI9341_RED);
  delay(500);
  tft.fillScreen(ILI9341_GREEN);
  delay(500);
  tft.fillScreen(ILI9341_BLUE);
  delay(500);
  Serial.println("✓ Display test complete");

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
