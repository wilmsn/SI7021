#include <SI7021.h>

SI7021 tempsensor;

void setup() {

  tempsensor.begin();
  Serial.begin(9600);
  Serial.println(" SI7021 example1");
  Serial.println(" ");
}

void loop() {

  Serial.print("Temperature: ");
  Serial.print(tempsensor.readTemperature());
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(tempsensor.readHumidity());
  Serial.println(" %");
  delay(1000);
}
