const int pulsePin = 2; // Pin, an dem der Münzprüfer angeschlossen ist
volatile int pulseCount = 0; // Anzahl der erkannten Pulse
unsigned long lastPulseTime = 0; // Zeit des letzten Pulses
const unsigned long resetTime = 2000; // Zeit in Millisekunden, nach der zurückgesetzt wird
const unsigned long minPulseInterval = 100; // Minimaler Pulsintervall in Millisekunden

// Pins für die Ausgänge
const int pin10Cent = 3;
const int pin20Cent = 4;
const int pin50Cent = 5;
const int pin1Euro = 6;
const int pin2Euro = 7;

int lastPulseValue = 0; // Um die letzte Pulsanzahl zu speichern
bool outputActive = false; // Status des Ausgangs
unsigned long outputStartTime = 0; // Zeit, wann der Ausgang aktiviert wurde
unsigned long pulseResetTime = 0; // Zeit, wann der Puls zurückgesetzt werden soll

void countPulse() {
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime > minPulseInterval) {
    pulseCount++; // Puls zählen
    lastPulseTime = currentTime; // Zeit des letzten Pulses aktualisieren
  }
}

void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
  pinMode(pulsePin, INPUT_PULLUP); // Pin als Eingang mit Pull-Up aktivieren
  attachInterrupt(digitalPinToInterrupt(pulsePin), countPulse, RISING); // Interrupt für steigende Flanke

  // Setze die Ausgangspins
  pinMode(pin10Cent, OUTPUT);
  pinMode(pin20Cent, OUTPUT);
  pinMode(pin50Cent, OUTPUT);
  pinMode(pin1Euro, OUTPUT);
  pinMode(pin2Euro, OUTPUT);
  
  // Alle Ausgänge auf LOW setzen
  digitalWrite(pin10Cent, LOW);
  digitalWrite(pin20Cent, LOW);
  digitalWrite(pin50Cent, LOW);
  digitalWrite(pin1Euro, LOW);
  digitalWrite(pin2Euro, LOW);
}

void loop() {
  // Überprüfen, ob die Zeit seit dem letzten Puls größer als resetTime ist
  if (millis() - lastPulseTime >= resetTime) {
    // Speichere die letzte Pulsanzahl
    lastPulseValue = pulseCount;

    // Aktiviere den entsprechenden Ausgang basierend auf lastPulseValue
    switch (lastPulseValue) {
      case 1:
        digitalWrite(pin10Cent, HIGH); // 10 Cent
        break;
      case 2:
        digitalWrite(pin20Cent, HIGH); // 20 Cent
        break;
      case 3:
        digitalWrite(pin50Cent, HIGH); // 50 Cent
        break;
      case 4:
        digitalWrite(pin1Euro, HIGH); // 1 Euro
        break;
      case 5:
        digitalWrite(pin2Euro, HIGH); // 2 Euro
        break;
      default:
        // Keine Aktion für mehr als 5 Pulse
        break;
    }

    outputStartTime = millis(); // Zeit, wann der Ausgang aktiviert wurde
    pulseResetTime = outputStartTime + 40; // Setze Zeit für Pulsreset
    outputActive = true; // Status auf aktiv setzen
  }

  // Wenn der Ausgang aktiv ist, warte 500 ms und setze ihn dann auf LOW
  if (outputActive && (millis() - outputStartTime >= 500)) {
    // Setze alle Ausgänge auf LOW
    digitalWrite(pin10Cent, LOW);
    digitalWrite(pin20Cent, LOW);
    digitalWrite(pin50Cent, LOW);
    digitalWrite(pin1Euro, LOW);
    digitalWrite(pin2Euro, LOW);
    
    outputActive = false; // Ausgang deaktivieren

    // Setze die Pulsanzahl zurück, nachdem 40 ms vergangen sind
    if (millis() >= pulseResetTime) {
      pulseCount = 0; // Pulsanzahl zurücksetzen
      lastPulseTime = millis(); // Zurücksetzen des Zeitstempels
    }
  }
}
