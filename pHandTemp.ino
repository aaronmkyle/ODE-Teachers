

#define pHPin 1
#define tempPin 0

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  tempMeasure();
  pHMeasure();

  delay(5000);  // delay in between reads for stability
}

float pHMeasure() {

  int pHSensor = analogRead(pHPin);
  float pHVoltage = pHSensor*5.0/1023;
  float pH = (pHVoltage - 1.39)/.075 + .57;
  Serial.println("--------------pH SENSOR DATA--------------");
  //Serial.print("pH Sensor Voltage = ");
  //Serial.println(pHVoltage);
  Serial.print("pH = ");
  Serial.println(pH);
  Serial.println("");

}

float tempMeasure() {
  
  int tempSensor = analogRead(tempPin);
  float tempVoltage = tempSensor *5.0/1023;
  float temperatureC = (tempVoltage - 0.5) * 100 ;                //converting from 10 mv per degree wit 500 mV offset to degrees ((voltage - 500mV) times 100)
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;     //Converting temperature to degrees Fahrenheit

  Serial.println("--------------TEMPERATURE SENSOR DATA--------------");
  //Serial.print("Temp Sensor Voltage = ");
  //Serial.println(tempVoltage);
  Serial.print("Temperature (degrees C) = ");
  Serial.println(temperatureC);
  Serial.print("Temperature (degrees F) = ");
  Serial.println(temperatureF);
  Serial.println("");


}
