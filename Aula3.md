int redLed = 2;
int yellowLed = 3;
int greenLed = 4;

char incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'R') {
      redLight();
    } else if (incomingByte == 'Y') {
      yellowLight();
    } else if (incomingByte == 'G') {
      greenLight();
    }
  }
}

void redLight() {
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

void yellowLight() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);
}

void greenLight() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
}
