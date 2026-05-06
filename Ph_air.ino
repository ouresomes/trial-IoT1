#define PH_SENSOR_PIN 34  // Pin sensor pH yang terhubung

// Nilai kalibrasi pH
float pH7_adc = 625; // Nilai ADC untuk pH 7
float pH4_adc = 680; // Nilai ADC untuk pH 4
float pH10_adc = 600; // Nilai ADC untuk pH 10

// Fungsi untuk membaca dan menghitung pH
float readPH(int adcValue) {
  float slope = (pH10_adc - pH4_adc) / (10 - 4);  // Kemiringan (slope) dari pH 4 hingga pH 10
  float intercept = pH7_adc - (slope * 7);  // Intersep pada pH 7
  float pH = (adcValue - intercept) / slope;  // Hitung pH berdasarkan rumus
  return pH;
}

void setup() {
  Serial.begin(115200);  // Mulai komunikasi serial
  analogReadResolution(12);  // Set resolusi ADC 12-bit (0-4095)
  pinMode(PH_SENSOR_PIN, INPUT);  // Set pin sensor pH sebagai input
}

void loop() {
  int sensorValue = analogRead(PH_SENSOR_PIN);  // Baca nilai ADC dari sensor pH
  float pH = readPH(sensorValue);  // Hitung pH berdasarkan nilai ADC
  Serial.print("ADC = ");
  Serial.print(sensorValue);
  Serial.print(" | pH Value: ");  // Tampilkan hasil pH di serial monitor
  Serial.println(pH);
  delay(1000);  // Delay 1 detik
}
