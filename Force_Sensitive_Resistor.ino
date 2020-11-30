/******************************************************************************

******************************************************************************/
const int FSR_PIN_0 = A0; 
const int FSR_PIN_1 = A1; 
const int FSR_PIN_2 = A2;
const int FSR_PIN_3 = A3;

void setup() 
{
  Serial.begin(9600);
  pinMode(FSR_PIN_0, INPUT);
  pinMode(FSR_PIN_1, INPUT);
  pinMode(FSR_PIN_2, INPUT);
  pinMode(FSR_PIN_3, INPUT);
}

void loop() 
{
  int fsrADC_0 = analogRead(FSR_PIN_0);
  int fsrADC_1 = analogRead(FSR_PIN_1);
  int fsrADC_2 = analogRead(FSR_PIN_2);
  int fsrADC_3 = analogRead(FSR_PIN_3);


  if (fsrADC_0 > 40) // If the analog reading is non-zero
  {
    // Use ADC reading to calculate voltage:
    float fsrV_0 = fsrADC_0 * 5 / 1023.0;
    float force_0;
    force_0 =  fsrV_0 * 200;
    Serial.println("Head: " + String(force_0) + " lbf");
    Serial.println();

    float fsrV_1 = fsrADC_1 * 5 / 1023.0;
    float force_1;
    force_1 =  fsrV_1 * 200;
    Serial.println("Ribs: " + String(force_1) + " lbf");
    Serial.println();
        
    float fsrV_2 = fsrADC_2 * 5 / 1023.0;
    float force_2;
    force_2 =  fsrV_2 * 200;
    Serial.println("Ribs: " + String(force_2) + " lbf");
    Serial.println();
        
    float fsrV_3 = fsrADC_3 * 5 / 1023.0;
    float force_3;
    force_3 =  fsrV_3 * 200;
    Serial.println("Solar Plexus: " + String(force_3) + " lbf");
    Serial.println();

    delay(100);
  }
  else
  {
    // No pressure detected
  }
}
