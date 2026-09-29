#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// -------- DFPlayer --------
SoftwareSerial mySerial(10, 11);
DFRobotDFPlayerMini player;

// -------- Flex Pins --------
#define F1 A0
#define F2 A1
#define F3 A2
#define F4 A3

// -------- YOUR CALIBRATION --------
#define TH1 13// A0
#define TH2 15// A1
#define TH3 14 // A2
#define TH4 15// A3

// -------- Control --------
unsigned long lastPlay = 0;
const int delayBetweenWords = 2000;

// -------- Stable Read --------
int readStable(int pin) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += analogRead(pin);
    delay(2);
  }
  return sum / 5;
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  if (!player.begin(mySerial)) {
    Serial.println("DFPlayer ERROR");
    while (true);
  }

  player.volume(25);
  Serial.println("System Ready (Using Your Calibration)");
}

void loop() {

  // Read sensors
  int f1 = readStable(F1);
  int f2 = readStable(F2);
  int f3 = readStable(F3);
  int f4 = readStable(F4);

  // Convert to digital using YOUR conditions
  int d1 = (f1 < TH1) ? 1 : 0;
  int d2 = (f2 < TH2) ? 1 : 0;
  int d3 = (f3 < TH3) ? 1 : 0;
  int d4 = (f4 < TH4) ? 1 : 0;

  // Debug output
  Serial.print("Analog: ");
  Serial.print(f1); Serial.print(" ");
  Serial.print(f2); Serial.print(" ");
  Serial.print(f3); Serial.print(" ");
  Serial.print(f4);

  Serial.print(" | Digital: ");
  Serial.print(d1); Serial.print(" ");
  Serial.print(d2); Serial.print(" ");
  Serial.print(d3); Serial.print(" ");
  Serial.println(d4);

  // Debounce
  if (millis() - lastPlay < delayBetweenWords) return;

  // Count bent fingers
  int total = d1 + d2 + d3 + d4;

  // Only single finger allowed
  if (total == 1) {

    if (d1 == 1) {
      player.play(1); // 0001.mp3
      Serial.println("A0 → 0001.mp3");
    }
    else if (d2 == 1) {
      player.play(2); // 0002.mp3
      Serial.println("A1 → 0002.mp3");
    }
    else if (d3 == 1) {
      player.play(3); // 0003.mp3
      Serial.println("A2 → 0003.mp3");
    }
    else if (d4 == 1) {
      player.play(4); // 0004.mp3
      Serial.println("A3 → 0004.mp3");
    }

    lastPlay = millis();
  }
}