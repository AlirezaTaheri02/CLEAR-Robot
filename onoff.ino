#define TRIG_PIN 12
#define ECHO_PIN 11
#define MOTOR_PIN1_A 8
#define MOTOR_PIN2_A 7
#define MOTOR_PIN1_B 4
#define MOTOR_PIN2_B 5
#define ENA 9
#define ENB 3

float xn1 = 0;
float yn1 = 0;
float output;

long duration;
int distance;
int safeDistance = 10; // فاصله امن به سانتی‌متر

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN1_A, OUTPUT);
  pinMode(MOTOR_PIN2_A, OUTPUT);
  pinMode(MOTOR_PIN1_B, OUTPUT);
  pinMode(MOTOR_PIN2_B, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // ارسال پالس به سنسور التراسونیک
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // دریافت پالس برگشتی
  duration = pulseIn(ECHO_PIN, HIGH);
  distance=duration * 0.034 / 2;
  
  output = 0.7767 * yn1 + 0.1116 * distance + 0.1116 * xn1;
    Serial.print("Raw: ");
    Serial.println(output); 
 
if (9>output || output>11)
{
  if (output >11) {
    digitalWrite(MOTOR_PIN1_A, HIGH);
    digitalWrite(MOTOR_PIN2_A, LOW);
    digitalWrite(MOTOR_PIN1_B, HIGH);
    digitalWrite(MOTOR_PIN2_B, LOW);
    digitalWrite(ENA, HIGH);
    digitalWrite(ENB, HIGH);
  
   } else {
    // در غیر این صورت، موتورها را روشن کنید
    digitalWrite(MOTOR_PIN1_A, LOW);
    digitalWrite(MOTOR_PIN2_A, HIGH);
    digitalWrite(MOTOR_PIN1_B, LOW );
    digitalWrite(MOTOR_PIN2_B, HIGH);
    digitalWrite(ENA, HIGH);
    digitalWrite(ENB, HIGH);
  }
 }
  else{
      //  // اگر فاصله کمتر از فاصله امن باشد، موتورها را متوقف کنید
    digitalWrite(MOTOR_PIN1_A, LOW);
    digitalWrite(MOTOR_PIN2_A, LOW);
    digitalWrite(MOTOR_PIN1_B, LOW);
    digitalWrite(MOTOR_PIN2_B, LOW);
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
  }

  // به‌روزرسانی مقادیر فیلتر پایین گذر
  yn1 = output;
  xn1 = distance;
  
  delay(10);
}
