#define IR_Sensor D1
#define LED D5


void setup()  
 {  
   Serial.begin(9600); // sensor buart rate  
   pinMode(LED,OUTPUT);  // Led Pin Connected To D5 Pin   
   pinMode(IR_Sensor,INPUT); //define the IR Sensor pin D1
 }   
 void loop()   
 {  
  int s1=digitalRead(IR_Sensor); // IR Sensor output pin connected to D1  
  Serial.println(s1);  // See the Value In Serial Monitor     
  delay(100);  
  if(s1 == 1 )  
  {  
   digitalWrite(LED,HIGH); // LED ON  
  }  
   else  
  {  
   digitalWrite(LED,LOW); // LED OFF  
  }  
 }  