#include <DHT.h>

#define DHTPIN 3      // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // Change to DHT22 if using a different sensor
#define FANPIN 9      // PWM pin for Fan

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(FANPIN, OUTPUT);
}

void loop() {
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    
    if (isnan(temperature)) { // Check for sensor reading errors
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C");

    // Map temperature to fan speed (0-255)
    int speed = map(temperature, 28, 36, 0, 255); // Adjust range as needed
    speed = constrain(speed, 0, 255); // Keep within valid PWM range

    analogWrite(FANPIN, speed); // Set fan speed

    // Display speed level
    Serial.print(" Fan Speed: ");
    Serial.println(speed);

    delay(2000); // Wait before next reading
}
