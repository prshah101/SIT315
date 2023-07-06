//Pin A0 is used for this sensor
int sensorPin = 0;

//Initial setup run upon turning on
void setup()
{
  //Enable a serial communication at a baud rate of 9600 between the Arduino and sensor
  Serial.begin(9600);

  //Enable digital communication to the LED
  pinMode(LED_BUILTIN, OUTPUT);
}

//Repeatedly run this 
void loop()
{
 
  //Read the analof data from the Temperature sensor
 int reading = analogRead(sensorPin);

 //Scale analog reading to votalge value
 float voltage = reading * 4.68;

 //Normalise the voltage to a range of 0 to 5 volts.
 voltage /= 1024.0;
 
 //Calculate Temperature  
 float temperatureC = (voltage - 0.5) * 100;
 //Print Temperature (Sense)
 Serial.print(temperatureC);
 Serial.println(" degrees C");
 
 //Check if the temprature is high or low (Think) 
 //Change LED to on or off depending on that(Act)
 if(temperatureC < 33){
     digitalWrite(LED_BUILTIN, LOW);
     Serial.println("LED is OFF"); 
 }else{
     digitalWrite(LED_BUILTIN, HIGH);
     Serial.println("LED is ON"); 
 }
 
 delay(1000);
}