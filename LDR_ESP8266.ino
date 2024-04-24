#define LDR A0 // define the pin of LDR 

void setup() 
{
Serial.begin (9600); //Define the baudrate for serial communication
pinMode(LDR,INPUT); // define the mode of peripheral
}

void loop() 
{
int LDR_Data = analogRead(LDR); // the the data of LDR and store it into the LDR_Data
Serial.println("LDR Data"); // print LDR Data on serial monitor
Serial.println(LDR_Data); // print the value of LDR_Data
delay(1000); // delay for 1 second
}
