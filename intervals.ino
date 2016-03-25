const int ledPin9 = 9;
const int ledPin10 = 10;
const int ledPin11 = 11;
const int ledPin12 = 12;
const int ledPin13 = 13;

int ledState9 = LOW;
int ledState10 = LOW;
int ledState11 = LOW;
int ledState12 = LOW;
int ledState13 = LOW;

unsigned long previousMillis9 = 0;
unsigned long previousMillis10 = 0;
unsigned long previousMillis11 = 0;
unsigned long previousMillis12 = 0;
unsigned long previousMillis13 = 0;

const long interval9 = 1000;
const long interval10 = 500;
const long interval11 = 333;
const long interval12 = 250;
const long interval13 = 200;

void setup() {
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis9 >= interval9) {
    previousMillis9 = currentMillis;
    if (ledState9 == LOW) {
      ledState9 = HIGH;
    } else {
      ledState9 = LOW;
    }
    digitalWrite(ledPin9, ledState9);
  }

  if (currentMillis - previousMillis10 >= interval10) {
    previousMillis10 = currentMillis;

    if (ledState10 == LOW) {
      ledState10 = HIGH;
    } else {
      ledState10 = LOW;
    }

    digitalWrite(ledPin10, ledState10);
  }

  if (currentMillis - previousMillis11 >= interval11) {
    previousMillis11 = currentMillis;
    if (ledState11 == LOW) {
      ledState11 = HIGH;
    } else {
      ledState11 = LOW;
    }
    digitalWrite(ledPin11, ledState11);
  }

  if (currentMillis - previousMillis12 >= interval12) {
    previousMillis12 = currentMillis;
    if (ledState12 == LOW) {
      ledState12 = HIGH;
    } else {
      ledState12 = LOW;
    }
    digitalWrite(ledPin12, ledState12);
  }

  if (currentMillis - previousMillis13 >= interval13) {
    previousMillis13 = currentMillis;
    if (ledState13 == LOW) {
      ledState13 = HIGH;
    } else {
      ledState13 = LOW;
    }
    digitalWrite(ledPin13, ledState13);
  }
}
