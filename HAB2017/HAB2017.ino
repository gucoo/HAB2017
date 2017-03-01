/* 
 *  *************************************
 *  This program serves to command the 
 *  slave arduino which houses three 
 *  sensors(Am2315, MMA8451, MPL3115A2).
 *  
 *  Authors:
 *    Erick Ramirez
 *    
 *    
 *  Notes(TBD): 
 *   
 *  *************************************
 */

//Include the libraries required for our program to work.
#include <Wire.h> //i2c library to communicate with slave devices.
#include <Adafruit_AM2315.h> //The "Dongle" outside temp sensor.
#include <Adafruit_MMA8451.h> //Accelorometer
#include <Adafruit_Sensor.h> //Accerlorometer
#include <Adafruit_MPL3115A2.h> //Barometer
#include <LED.h> //Library for controlling leds

 
//Initialize the AM2315
Adafruit_AM2315 dongle;
//Initialize the MMA8451
Adafruit_MMA8451 accel = Adafruit_MMA8451();
//Initialize the MPL3115A2
Adafruit_MPL2115A2 baro = Adafruit_MPL2115A2();
//Initialize the LED'S
LED redLed = LED(4);
LED yellowLed = LED(3);
LED greenLed = LED(2)




void setup() {
  //Variable initialization
  boolean sensorStatus; //Triggers an error code;
 //Join the i2c bus(Adress is optional for Master)
  Wire.begin(); 
  //Check sensor status
  sensorStatus = initSensors();
  if(sensorStatus != true){
    //Error team needs to inspect error codes
    redLed.on();
    //Keep displaying the error until team fixes it
    while(1);
  }else{
    green.on();
  }
}



void loop() {
  // put your main code here, to run repeatedly:

}

//Function to check sensor status
boolean initSensors(){
  boolean stat = true;
  //Check if the sensor is working
  if(! am2315.begin()){
    //Turn on red light and blink for two seconds
    redLed.blink(4000);
    stat = false;
  }
  if(! accel.begin()){
    //Turn on red light and blink for four seconds
    redLed.blink(8000);
    stat = false;
  }
  if(! baro.begin()){
    //Turn on red Light and blink for six seconds
    redLed.blink(12000);
    stat = false
  }
  return stat;
}


