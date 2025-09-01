// --- ESP32 Rainbow Effect (Common Anode using analogWrite) ---

// Define the GPIO pins for your RGB LED
const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;

void setup() {
  // Set the LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // The color brightness will change from 0 to 255
  for (int brightness = 0; brightness <= 255; brightness++) {
    // Phase 1: Fade from Red to Green
    // Red fades out (value goes from 0 to 255 -> off)
    // Green fades in (value goes from 255 to 0 -> on)
    analogWrite(redPin, 255 - (255 - brightness));
    analogWrite(greenPin, 255 - brightness);
    analogWrite(bluePin, 255); // Blue is off
    delay(10);
  }

  for (int brightness = 0; brightness <= 255; brightness++) {
    // Phase 2: Fade from Green to Blue
    // Green fades out
    // Blue fades in
    analogWrite(redPin, 255); // Red is off
    analogWrite(greenPin, 255 - (255 - brightness));
    analogWrite(bluePin, 255 - brightness);
    delay(10);
  }

  for (int brightness = 0; brightness <= 255; brightness++) {
    // Phase 3: Fade from Blue to Red
    // Blue fades out
    // Red fades in
    analogWrite(redPin, 255 - brightness);
    analogWrite(greenPin, 255); // Green is off
    analogWrite(bluePin, 255 - (255 - brightness));
    delay(10);
  }
}