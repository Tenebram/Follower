const int enA = 7;  // PWM pin za brzinu motora A
const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 8;
const int enB = 10; // PWM pin za brzinu motora B
const int leftSensorPin = 11; // Pin za IR senzor sa leve strane
const int rightSensorPin = 12; // Pin za IR senzor sa desne strane

const int brzina_desni = 255;
const int brzina_levi = 150;

/*
 * desni 110  2.8 140 4.3
 * levi 140  4.5  150 2.7
 */

void setup() {
  // Postavljanje pinova kao izlazi ili ulazi
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
}

void loop() {
  // Čitanje stanja senzora
  int leftSensor = digitalRead(leftSensorPin);
  int rightSensor = digitalRead(rightSensorPin);

  // Ukoliko su oba senzora na liniji
  if (leftSensor == LOW && rightSensor == LOW) {
    // Idi pravo
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, brzina_levi); // Postavljamo brzinu motora A na maksimum
    analogWrite(enB, brzina_desni); // Postavljamo brzinu motora B na maksimum
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Ako je levi senzor van linije
    // Idi desno
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, brzina_levi); // Smanjujemo brzinu motora A
    analogWrite(enB, brzina_desni); // Postavljamo brzinu motora B na maksimum
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Ako je desni senzor van linije
    // Idi levo
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, brzina_levi); // Postavljamo brzinu motora A na maksimum
    analogWrite(enB, brzina_desni); // Smanjujemo brzinu motora B
  }
  // Ukoliko su oba senzora van linije
  else {
    // Zaustavi se
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Isključujemo motor A
    analogWrite(enB, 0); // Isključujemo motor B
  }
}
