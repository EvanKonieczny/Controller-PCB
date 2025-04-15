// Define the relay pin
    const int relayPin = 4;

    void setup() {
      // Set the relay pin as an output
      pinMode(relayPin, OUTPUT);
    }

    void loop() {
      // Turn the relay ON (high voltage circuit on)
      digitalWrite(relayPin, HIGH);
      // delay(2000); // Wait 2 seconds

      // // Turn the relay OFF (high voltage circuit off)
      // digitalWrite(relayPin, LOW);
      // delay(2000); // Wait 2 seconds
    }
