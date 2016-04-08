const int Pin1 = 13;
const int Pin2 = 12;
const int Pin3 = 11;
const int Pin4 = 10;
const int Pin5 = 9;

int State1 = LOW;
int State2 = LOW;
int State3 = LOW;
int State4 = LOW;
int State5 = LOW;

String line;
String PinIdString;
String IntervalString;

unsigned long previousMicros1 = 0;
unsigned long previousMicros2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;

unsigned long interval1 = 1000000;
unsigned long interval2 = 500000;
unsigned long interval3 = 333;
unsigned long interval4 = 250;
unsigned long interval5 = 200;

void setup() {
  Serial.begin(9600);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
}

void SerialEvent() {
  int i = 0;
  line = Serial.readString();
  PinIdString = line.substring(0, 2);
  IntervalString = line.substring(3, line.length());
  Serial.println("PinID: " + PinIdString);
  Serial.println("Interval: " + IntervalString);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();
  ChangeStates(currentMillis, currentMicros);
  Write(); //digital write для всех

  if (Serial.available() > 0) { //если есть принятый символ
    SerialEvent();
  }
  else {
    ChangeInterval();
  }
}

void Write() {
  digitalWrite(Pin1, State1);
  digitalWrite(Pin2, State2);
  digitalWrite(Pin3, State3);
  digitalWrite(Pin4, State4);
  digitalWrite(Pin5, State5);
}

int ChangeInterval() {
  switch (PinIdString.toInt()) {
    case 13:
      interval1 = IntervalString.toInt(); break;
    case 12:
      interval2 = IntervalString.toInt(); break;
    case 11:
      interval3 = IntervalString.toInt(); break;
    case 10:
      interval4 = IntervalString.toInt(); break;
    case 9:
      interval5 = IntervalString.toInt(); break;
    default:
      /* Serial.print("Error");*/ break;
  }
}

void ChangeStates(unsigned long currentMillis, unsigned long currentMicros) {
  if (currentMicros - previousMicros1 >= interval1) {
    previousMicros1 = currentMicros;
    if (State1 == LOW) {
      State1 = HIGH;
    } else {
      State1 = LOW;
    }
  }
  if (currentMicros - previousMicros2 >= interval2) {
    previousMicros2 = currentMicros;
    if (State2 == LOW) {
      State2 = HIGH;
    }
    else {
      State2 = LOW;
    }
  }
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    if (State3 == LOW) {
      State3 = HIGH;
    } else {
      State3 = LOW;
    }
  }
  if (currentMillis - previousMillis4 >= interval4) {
    previousMillis4 = currentMillis;
    if (State4 == LOW) {
      State4 = HIGH;
    } else {
      State4 = LOW;
    }
  }
  if (currentMillis - previousMillis5 >= interval5) {
    previousMillis5 = currentMillis;
    if (State5 == LOW) {
      State5 = HIGH;
    }
    else {
      State5 = LOW;
    }
  }
}
