#define TRIG_PIN 12
#define ECHO_PIN 13
#define MOTOR_PIN1 4
#define MOTOR_PIN2 5
#define ENA 3
float xn1 = 0;
float yn1 = 0;
float output;
long duration;
int distance;
int safeDistance = 20; // فاصله امن به سانتی‌متر

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // ارسال پالس به سنسور التراسونیک
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // دریافت پالس برگشتی و محاسبه مدت زمان
  duration = pulseIn(ECHO_PIN, HIGH);

  // محاسبه فاصله
  distance = duration * 0.034 / 2;
  output = 0.969*yn1 + 0.0155*distance + 0.0155*xn1;
  // چاپ فاصله در سریال مانیتور
  Serial.print("Raw: ");
  Serial.print(distance); 
  //Serial.print(", "); 
  //Serial.print("Filtered: ");
  //Serial.print(output);
  //Serial.print(", ");

  delay(10); // یک ثانیه تأخیر بین اندازه‌گیری‌ها
  yn1 = output;
  xn1=distance;
}
