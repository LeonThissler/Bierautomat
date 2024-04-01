//Programm ist noch nicht getestet

// Pin-Definitionen 
const int coinInputPin = 2; // Pin für den Münzeingang
const int outputPin10 = 3;  // Ausgangspin für 10 Cent
const int outputPin20 = 4;  // Ausgangspin für 20 Cent
const int outputPin50 = 5;  // Ausgangspin für 50 Cent
const int outputPin100 = 6; // Ausgangspin für 1 Euro
const int outputPin200 = 7; // Ausgangspin für 2 Euro

void setup() {
  // Initialisierung der Pins
  pinMode(coinInputPin, INPUT);
  pinMode(outputPin10, OUTPUT);
  pinMode(outputPin20, OUTPUT);
  pinMode(outputPin50, OUTPUT);
  pinMode(outputPin100, OUTPUT);
  pinMode(outputPin200, OUTPUT);

  // Startet die Serielle Kommunikation (zum Debuggen)
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = millis(); // Startzeit des Messvorgangs
  int coinCount = 0; // Anzahl der Impulse
  
  // Innerhalb von 10 Sekunden zählen, wie viele Impulse kommen
  while (millis() - startTime < 10000) {
    if (digitalRead(coinInputPin) == HIGH) {
      delay(50); // Kurze Verzögerung für Stabilität
      coinCount++;
    }
  }

  // Überprüft den Wert der Münze basierend auf der Anzahl der Impulse
  switch (coinCount) {
    case 1: // 10 Cent
      digitalWrite(outputPin10, HIGH);
      break;
    case 2: // 20 Cent
      digitalWrite(outputPin20, HIGH);
      break;
    case 3: // 50 Cent
      digitalWrite(outputPin50, HIGH);
      break;
    case 4: // 1 Euro
      digitalWrite(outputPin100, HIGH);
      break;
    case 5: // 2 Euro
      digitalWrite(outputPin200, HIGH);
      break;
    default:
     
      break;
  }

  // delay damit Ausgänge lang genug gesetzt bleiben
  delay(1000);

  // Setzt Ausgänge zurück
  digitalWrite(outputPin10, LOW);
  digitalWrite(outputPin20, LOW);
  digitalWrite(outputPin50, LOW);
  digitalWrite(outputPin100, LOW);
  digitalWrite(outputPin200, LOW);
}
