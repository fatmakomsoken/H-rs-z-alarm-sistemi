# H-rs-z-alarm-sistemi
Arduino ile geliştirilen ışık sensörlü hırsız larm sistemi
# Hırsız Alarm Sistemi 🚨

Bu proje, Arduino UNO ve ışık sensörü (LDR) kullanarak basit bir hırsız alarm sistemidir. Ortam ışığına bağlı olarak LED ve buzzer ile uyarı verir. Tinkercad üzerinde devresi çizilmiş ve test edilmiştir.

## 🔧 Kullanılan Bileşenler
- Arduino UNO
- LDR (Fotoresistör)
- 10KΩ direnç
- LED
- 220Ω direnç
- Buzzer
- Breadboard ve jumper kablolar

## ⚙️ Çalışma Mantığı
- LDR üzerinden gelen ışık seviyesi belli bir eşiğin altına düşerse sistem bunu "ışığın kesildiği" yani bir engel/hırsız olabileceği şeklinde algılar.
- Bu durumda LED yanar ve buzzer alarm verir.
- Tinkercad üzerinden devre şeması çizilmiştir ve başarıyla çalışmaktadır.

## 💻 Kodlar
```cpp
int ldrPin = A0;
int ledPin = 9;
int buzzerPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < 300) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
