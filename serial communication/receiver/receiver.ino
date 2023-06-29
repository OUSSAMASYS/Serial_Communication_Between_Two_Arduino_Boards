int ledPin = 13;  // Pin number for the LED

void setup() {
  Serial.begin(9600);       // Initialize the serial communication at a baud rate of 9600
  pinMode(ledPin, OUTPUT);  // Set the pin for the LED as an output
}

void loop() {
  if (Serial.available() > 0) {  // Check if there is data available to read from the serial communication
    char receivedData = Serial.read();  // Read the received data from the serial communication and store it in a variable

    // Check if the received data is '1' (indicating the request to turn on the LED)
    if (receivedData == '1') {
      digitalWrite(ledPin, HIGH);  // Turn on the LED by setting the pin to HIGH
    }
    // Check if the received data is '0' (indicating the request to turn off the LED)
    else if (receivedData == '0') {
      digitalWrite(ledPin, LOW);   // Turn off the LED by setting the pin to LOW
    }
  }
}
