int sensorPin = A0;      // LDR'nin bağlı olduğu pin
int ledPin = 9;          // LED pin
int buzzerPin = 8;       // Buzzer pin
int threshold = 500;     // Eşik değeri (karanlık seviyesi)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);  // Işık seviyesini seri monitöre yazdır

  if (sensorValue < threshold) {
    digitalWrite(ledPin, HIGH);       // LED yanıyor
    digitalWrite(buzzerPin, HIGH);    // Buzzer ötüyor
    Serial.println("HIRSIZ VAR!!!");
  } else {
    digitalWrite(ledPin, LOW);        // LED sönüyor
    digitalWrite(buzzerPin, LOW);     // Buzzer susuyor
    Serial.println("GÜVENLİ ALAN");
  }

  delay(500);
}