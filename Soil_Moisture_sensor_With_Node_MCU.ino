
int sense_Pin = A0; // sensor input at Analog pin A0

void setup() 
{
   Serial.begin(9600);
   pinMode(sense_Pin,INPUT); // define the pinmode 
  
}
void loop() 
{

   int Value = analogRead(sense_Pin); // read the analog value of soilmoisture sensor and store it into the variable "value"
   Serial.println(Value);//print the data of value on serial monitor
   delay(1000);
}

