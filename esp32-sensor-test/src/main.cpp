#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// I2C (BME280)
#define I2C_SDA 4
#define I2C_SCL 5

// 1-Wire (DS18B20)
#define ONE_WIRE_BUS 6

Adafruit_BME280 bme;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("\n==========================================");
  Serial.println("--- Combined DS18B20 & BME280 Debugger ---");
  Serial.println("==========================================");

  // DS18B20
  sensors.begin();
  int deviceCount = sensors.getDeviceCount();
  Serial.print("[DS18B20] Found ");
  Serial.print(deviceCount);
  Serial.println(" device(s) on the 1-Wire bus.");
  if (deviceCount == 0) {
    Serial.println("[DS18B20] WARNING: No sensor found!");
  }

  // BME280
  Wire.begin(I2C_SDA, I2C_SCL);
  bool bmeStatus = bme.begin(0x76, &Wire);
  if (!bmeStatus) {
    Serial.println("[BME280]  ERROR: Could not find sensor! Check wiring or try 0x77.");
  } else {
    Serial.println("[BME280]  Initialization Success!");
  }

  Serial.println("------------------------------------------\n");
}

void loop() {
  Serial.println(">>> Sensor Readings:");

  // DS18B20
  sensors.requestTemperatures();
  float dsTemp = sensors.getTempCByIndex(0);
  if (dsTemp != DEVICE_DISCONNECTED_C) {
    Serial.print("  [DS18B20] Water Temp: ");
    Serial.print(dsTemp);
    Serial.println(" C");
  } else {
    Serial.println("  [DS18B20] Error: Sensor disconnected!");
  }

  // BME280
  Serial.print("  [BME280]  Air Temp  : ");
  Serial.print(bme.readTemperature());
  Serial.println(" C");

  Serial.print("  [BME280]  Pressure  : ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("  [BME280]  Humidity  : ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println("-------------------------");
  delay(2000);
}
