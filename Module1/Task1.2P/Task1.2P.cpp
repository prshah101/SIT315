//Pin A0 is used for this sensor
int sensorPin = 0;
//Pin 2 is used for this button
const uint8_t btn_pin = 2;


//uint8_t btn_prev = HIGH;
uint8_t led_state = LOW;

//Initial setup run upon turning on
void setup()
{
  //Enable a serial communication at a baud rate of 9600 between the Arduino and sensor
  Serial.begin(9600);

  //Enable digital communication between the LED and arduino
  pinMode(LED_BUILTIN, OUTPUT);
  
  //Enable digital communication between the button and arduino
  pinMode(btn_pin, INPUT_PULLUP);
   
  //Attach an interrupt to the button pin, toggleButton is excecuted when the interrupt occurs. Interrupt is triggered upon any fall.
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggleButton, FALLING);
}

//Repeatedly run this 
void loop()
{
 
 /// Nothing needed here
}

void toggleButton(){
  //Read the analog data from the Temperature sensor
 int reading = analogRead(sensorPin);

 //Scale analog reading to votalge value
 float voltage = reading * 5.015;

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