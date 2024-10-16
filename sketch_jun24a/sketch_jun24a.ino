void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 bps
}

void loop() {
    int leftValue = analogRead(A3);   // Read the value from the left sensor
    int rightValue = analogRead(A1);  // Read the value from the right sensor

    Serial.print("Left Sensor: ");
    Serial.println(leftValue);

    Serial.print("Right Sensor: ");
    Serial.println(rightValue);

    delay(500);  // Wait for half a second before updating
}
