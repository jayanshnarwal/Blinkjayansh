const int buttonPin = 2; // External button pin
const int ledPin = LED_BUILTIN; // Built-in LED pin on Arduino Nano 33 IoT
bool isBlinking = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    while (digitalRead(buttonPin) == HIGH) {
      // Wait for the button to be released
    }
    
    if (!isBlinking) {
      blinkNameInMorseCode();
      isBlinking = true;
    } else {
      isBlinking = false;
      digitalWrite(ledPin, LOW); // Turn off LED
      delay(1000); // Delay for stability
    }
  }
}

void blinkNameInMorseCode() {
  const int dotDuration = 200; // Duration of a dot in milliseconds
  const int dashDuration = 3 * dotDuration; // Duration of a dash
  
  // Morse code for each letter in "jayansh"
  const int morseCode[] = {
    dotDuration, dashDuration, // J
    dotDuration, dashDuration, dashDuration, dashDuration, // A
    dotDuration, dashDuration, dotDuration, // Y
    dotDuration, dashDuration, dotDuration, dashDuration, // A
    dotDuration, dotDuration, dotDuration, // N
    dashDuration, // S
    dotDuration, dashDuration, dotDuration, dashDuration, dashDuration // H
  };
  
  for (int i = 0; i < sizeof(morseCode) / sizeof(morseCode[0]); i += 2) {
    digitalWrite(ledPin, HIGH); // Turn on LED for dot or dash
    delay(morseCode[i]);
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(morseCode[i + 1]); // Pause between dots and dashes
  }
}