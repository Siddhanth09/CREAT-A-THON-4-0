#define MQ3 A0
 #define Buzzer 15
 //#define LED 9
 #define Thres_Val 450
 #include <ThingSpeak.h>
 #include <ESP8266WiFi.h>
  WiFiClient Client;
 int value;
 int enA = 16;//d0
 int enB = 13;//d7
 int in1 = 5;//d1
 int in2 = 4;//d2
 int in3 = 14;//d5
 
 int in4 = 12;//d6

 const char *nam="Redmi Note 9 Pro";
 const char *password="Yogesh@1";
 
  const char *host ="api.thingsspeak.com";
const char apiKey[]="9773XAEHBOACUVV5";
 
 void setup() 
 {
  Serial.begin(38400); 

  WiFi.begin(nam, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
   Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());

   pinMode(MQ3, INPUT);
   pinMode(Buzzer, OUTPUT);
   //pinMode(LED, OUTPUT);
   Serial.begin(38400); 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  ThingSpeak.begin(Client);
  
 }
 void loop() {
   int value;
   value=analogRead(MQ3);   
   Serial.println(value);
 if ( value > Thres_Val )   //if alcohol is detected
   {
     //digitalWrite ( LED , LOW );   
     tone(Buzzer,1000); 
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
     
                 
 }
 else {
     //digitalWrite(LED, HIGH);       
     noTone(Buzzer); 
     enA = 1;
     enB = 1;
     digitalWrite(in1, HIGH);
     digitalWrite(in2, HIGH);
     digitalWrite(in3, HIGH);
     digitalWrite(in4, HIGH);              
 }
   ThingSpeak.writeField(1984845, 1, value, apiKey);
 delay (500);            
 }