const int sensorPin = A0;
const float baselineTmp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //ADコンバータから受け取った値を電圧に変換する
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  //電圧を温度に変換する
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degree C: ");
  Serial.print(temperature);
  Serial.print("\n");

  //LEDを点灯させる
  if (temperature < baselineTmp) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature >= baselineTmp + 2 &&
             temperature < baselineTmp + 4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature >= baselineTmp + 4 &&
             temperature < baselineTmp + 6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if (temperature >= baselineTmp + 6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(1);
}
