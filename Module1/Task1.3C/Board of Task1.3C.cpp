//Pin A0 is used for the TMP sensor
const int sensorPin = 0;
//Pin 2 is used for button 1 (left)
const uint8_t btn_pin = 2;
//Pin 3 is used for button 2 (right)
const uint8_t btn2_pin = 3;
//Pin 12 is used for led 2 (right)
const int ledPin = 12;
//Initialise the state of the led as low
uint8_t led_state = LOW;
//Initial value of the Photoresistor sensor
int photoresistorValue = 0;
//Pin A1 is used for the Photoresistor sensor
int photoresistorPin = 1;

//Initial setup run upon turning on
void setup()
{
  //Enable a serial communication at a baud rate of 9600 between the Arduino and sensor
  Serial.begin(9600);

  //Enable digital communication between the LED and arduino
  pinMode(LED_BUILTIN, OUTPUT);

  //Enable digital communication between the LED and arduino
  pinMode(ledPin, OUTPUT);
  
  //Enable digital communication between the button and arduino
  pinMode(btn_pin, INPUT_PULLUP);

  //Enable digital communication between the button and arduino
  pinMode(btn2_pin, INPUT_PULLUP);

  //Enable communication between the Photoresistor sensor and arduino
  pinMode(photoresistorPin, INPUT);
   
  //Attach an interrupt to the button pin, toggleButton is excecuted when the interrupt occurs. Interrupt is triggered upon any fall.
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggleButton, FALLING);

  //Attach an interrupt to the button pin, toggleButton2 is excecuted when the interrupt occurs. Interrupt is triggered upon any fall.
  attachInterrupt(digitalPinToInterrupt(btn2_pin), toggleButton2, FALLING);
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
 //Print Temperature on the serial monitor
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

void toggleButton2(){
//Read the analog data from the Photoresistor sensor
 photoresistorValue = analogRead(photoresistorPin);

//Print the Photoresistor's value on the serial monitor
 Serial.print(photoresistorValue);
 Serial.println(" ohms");

 //Check if the photoresistorValue is high or low (Think) 
 //Change LED to on or off depending on that(Act)
 if(photoresistorValue < 350){
     digitalWrite(ledPin, LOW);
     Serial.println("LED2 is OFF"); 
 }else{
     digitalWrite(ledPin, HIGH);
     Serial.println("LED2 is ON"); 
 }

 delay(1000);

}