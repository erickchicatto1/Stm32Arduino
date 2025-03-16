// Definición de pines de los motores usando un array
const int motorPins[6] = { 9, 4, 5, 10, 6, 7 };  // {enA, in1, in2, enB, in3, in4}

// Variables para la velocidad de los motores
int motorSpeedA = 0;
int motorSpeedB = 0;

// Variables para timers
unsigned long previousTime = 0;
const long interval = 2000;  // Intervalo de tiempo en milisegundos (2 segundos)

void setup() {
  // Configurar los pines de los motores como salidas usando un puntero
  for (int i = 0; i < 6; i++) {
    pinMode(*(motorPins + i), OUTPUT);  // Usando aritmética de punteros
  }
}

void loop() {
  unsigned long currentTime = millis();  // Obtener el tiempo actual

  // Controlar los motores en función del tiempo
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;  // Reiniciar el temporizador

    // Alternar entre movimientos: adelante, atrás, giro a la izquierda, giro a la derecha
    static int movementState = 0;  // Estado del movimiento

    switch (movementState) {
      case 0:
        moveForward();  // Mover hacia adelante
        break;
      case 1:
        moveBackward();  // Mover hacia atrás
        break;
      case 2:
        turnLeft();  // Girar a la izquierda
        break;
      case 3:
        turnRight();  // Girar a la derecha
        break;
    }

    movementState = (movementState + 1) % 4;  // Cambiar al siguiente estado
  }

  // Aplicar las velocidades a los motores
  analogWrite(*(motorPins + 0), motorSpeedA);  // enA
  analogWrite(*(motorPins + 3), motorSpeedB);  // enB
}

// Función para mover hacia adelante
void moveForward() {
  digitalWrite(*(motorPins + 1), LOW);   // in1
  digitalWrite(*(motorPins + 2), HIGH);  // in2
  digitalWrite(*(motorPins + 4), LOW);   // in3
  digitalWrite(*(motorPins + 5), HIGH);  // in4
  motorSpeedA = 150;                     // Velocidad reducida
  motorSpeedB = 150;
}

// Función para mover hacia atrás
void moveBackward() {
  digitalWrite(*(motorPins + 1), HIGH);  // in1
  digitalWrite(*(motorPins + 2), LOW);   // in2
  digitalWrite(*(motorPins + 4), HIGH);  // in3
  digitalWrite(*(motorPins + 5), LOW);   // in4
  motorSpeedA = 150;                     // Velocidad reducida
  motorSpeedB = 150;
}

// Función para girar a la izquierda
void turnLeft() {
  digitalWrite(*(motorPins + 1), LOW);   // in1
  digitalWrite(*(motorPins + 2), HIGH);  // in2
  digitalWrite(*(motorPins + 4), LOW);   // in3
  digitalWrite(*(motorPins + 5), HIGH);  // in4
  motorSpeedA = 100;                     // Motor A más lento
  motorSpeedB = 200;                     // Motor B más rápido
}

// Función para girar a la derecha
void turnRight() {
  digitalWrite(*(motorPins + 1), LOW);   // in1
  digitalWrite(*(motorPins + 2), HIGH);  // in2
  digitalWrite(*(motorPins + 4), LOW);   // in3
  digitalWrite(*(motorPins + 5), HIGH);  // in4
  motorSpeedA = 200;                     // Motor A más rápido
  motorSpeedB = 100;                     // Motor B más lento
}