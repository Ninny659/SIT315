#define SensorAnaPin A0

void setup()
{
  // Serial rate of data in bps
  Serial.begin(4800);
}

void loop()
{
  
  int SensorOutput = analogRead(SensorAnaPin);

  // Convert SensorOutput to voltage per datasheet
  float ConvertionVoltage = SensorOutput * (5000 / 1024.0);

  // Convert to celius peer datasheet
  float TempCelsius = (ConvertionVoltage - 500) / 10;

  // Print the temperature in the Serial Monitor:
  Serial.print(TempCelsius);
  Serial.print(" Celsius");
  Serial.println();
  
  float TempFahren = (TempCelsius * 1.8) + 32;
    
  Serial.print(TempFahren);
  Serial.print(" Fahrenheit");
  Serial.println();
  
  float TempKelvin = TempCelsius + 273.15;
  Serial.print(TempKelvin);
  Serial.print(" Kelvin");
  Serial.println();

  // Delay in miliseconds
  delay(5000); 
    
 
}