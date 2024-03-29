int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;

char incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == '1') {
      digitalWrite(ledPin1, HIGH);
    } else if (incomingByte == '2') {
      digitalWrite(ledPin1, LOW);
    } else if (incomingByte == '3') {
      digitalWrite(ledPin2, HIGH);
    } else if (incomingByte == '4') {
      digitalWrite(ledPin2, LOW);
    } else if (incomingByte == '5') {
      digitalWrite(ledPin3, HIGH);
    } else if (incomingByte == '6') {
      digitalWrite(ledPin3, LOW);
    } else if (incomingByte == '7') {
      digitalWrite(ledPin4, HIGH);
    } else if (incomingByte == '8') {
      digitalWrite(ledPin4, LOW);
    }
  }
}
