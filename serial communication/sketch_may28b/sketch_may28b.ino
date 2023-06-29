int B_R = 3;             // Pin number for button B_R
int B_R_state = LOW;     // Variable to store the current state of button B_R
int LAST_B_R_state = LOW; // Variable to store the previous state of button B_R
int L_R_state = LOW;     // Variable to store the state of an output (L_R)

void setup() {
  Serial.begin(9600);     // Initialize the serial communication at a baud rate of 9600
  pinMode(B_R, INPUT);    // Set the pin for button B_R as an input
}

void loop() {
  B_R_state = digitalRead(B_R);  // Read the current state of button B_R

  // Check if the button B_R is pressed (transition from LOW to HIGH)
  if (B_R_state == HIGH && LAST_B_R_state == LOW) {
    // Toggle the state of output L_R
    if (L_R_state == LOW) {
      L_R_state = HIGH;
    } else {
      L_R_state = LOW;
    }
    Serial.println(L_R_state);  // Print the current state of output L_R
  }

  LAST_B_R_state = B_R_state;   // Update the previous state of button B_R
  delay(50);                    // Debounce delay to avoid multiple readings
}
