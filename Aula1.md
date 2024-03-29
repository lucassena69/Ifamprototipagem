# Ifamprototipagem

// Definir los pines de los LEDs
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;

void setup() {
  // Configurar los pines como salidas
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // Inicializar comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Verificar si hay datos disponibles para leer
  if (Serial.available() > 0) {
    // Leer el comando enviado desde la Raspberry Pi
    char command = Serial.read();

    // Ejecutar el comando correspondiente
    switch (command) {
      case '1':
        digitalWrite(ledPin1, HIGH);
        break;
      case '2':
        digitalWrite(ledPin2, HIGH);
        break;
      case '3':
        digitalWrite(ledPin3, HIGH);
        break;
      case '4':
        digitalWrite(ledPin4, HIGH);
        break;
      case '0':
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3,
