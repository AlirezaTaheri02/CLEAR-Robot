#define TRIG_PIN 12
#define ECHO_PIN 13
#define MOTOR_PIN1 4
#define MOTOR_PIN2 5
#define ENA 3
// mv
const int numReadings = 10; // تعداد نمونه‌ها برای محاسبه میانگین
long readings[numReadings]; // آرایه برای نگهداری نمونه‌ها
int readIndex = 0; // شاخص برای نمونه فعلی
long total = 0; // مجموع نمونه‌ها
long average = 0; // میانگین نمونه‌ها
float filteredDistance = 0; // مقدار فیلتر شده
float alpha = 0.1; // ضریب میانگین نمایی (0 < alpha < 1)

//
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
   for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
}}

void loop() {
  // ارسال پالس به سنسور التراسونیک
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
//

  // حذف مقدار قدیمی از مجموع
  total = total - readings[readIndex];
  
  // ذخیره مقدار جدید در آرایه
  readings[readIndex] = distance;
  
  // افزودن مقدار جدید به مجموع
  total = total + readings[readIndex];
  
  // بروزرسانی شاخص برای نمونه بعدی
  readIndex = readIndex + 1;
  
  // اگر شاخص به انتهای آرایه رسید، به ابتدای آرایه بازگردد
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  
  // محاسبه میانگین
  average = total / numReadings;
  
   // محاسبه مقدار فیلتر شده
  filteredDistance = alpha * distance + (1 - alpha) * filteredDistance;
  
  // دریافت پالس برگشتی و محاسبه مدت زمان
  duration = pulseIn(ECHO_PIN, HIGH);

  // محاسبه فاصله
  distance = duration * 0.034 / 2;
  output = 0.969 * yn1 + 0.0155 * distance + 0.0155 * xn1;

  // چاپ فاصله در سریال مانیتور
  Serial.print("Raw: ");
  Serial.print(distance); 
  Serial.print(", "); 
  Serial.print("Filtered(LP_5): ");
 Serial.print(output);
  Serial.println();
  Serial.print("Average Distance: ");
 // Serial.println(average);
    // چاپ مقدار فیلتر شده در سریال مانیتور
  Serial.print("Filtered Distance: ");
  Serial.println(filteredDistance);
  
  delay(100); // تأخیر بین اندازه‌گیری‌ها

  // به‌روزرسانی مقادیر قبلی
  yn1 = output;
  xn1 = distance;
}
