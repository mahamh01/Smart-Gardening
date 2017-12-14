int moisturePin = A4;
int tempPin = A0;
int lightPin = A2 ;
int motorPin = 10;
int moistVal;
int tempVal;
int moisture;

void setup() {
  pinMode (tempPin, INPUT);
  pinMode (moisturePin, INPUT);
  pinMode (lightPin, INPUT);
  pinMode (motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

Serial.println("");
    moistVal = analogRead(moisturePin);
  
    moisture = map(moistVal, 1023, 230, 0, 100);
    Serial.print(moistVal);
    Serial.print("    ");
    
    Serial.print("  Moisture: ");
    Serial.print(moisture);
    Serial.println("%");

    if(moisture < 30)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }

    analogRead(tempPin);
    tempVal = analogRead(tempPin);
  
    float mTempVal = (tempVal/1024.0)*5000.0;
    float cel = mTempVal/9.31;
  
    Serial.print(tempVal);
    Serial.print("    ");
    
    Serial.print(cel);
    Serial.print("°C    ");
  
    float farh = (cel*9.0)/5.0+32;
    Serial.print(farh);
    Serial.println("°F");

    analogRead(lightPin);
    float lightVal = analogRead(lightPin);
    Serial.print(lightVal);
    
    int light = map(lightVal, 1023, 159, 0, 100);
    Serial.print("    ");
    
    Serial.print("  Intensity: ");
    Serial.print(light);
    Serial.println("%");

    
    delay(500);
}
