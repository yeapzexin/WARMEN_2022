 #include "CytronMotorDriver.h"
 #include "Servo.h"
// Configure the motor driver.
CytronMD motorright(PWM_DIR, 3, 4);  // PWM = Pin 3, DIR = Pin 4.
CytronMD motorleft(PWM_DIR, 11, 12);
Servo armservo;
const int BUTTON_PIN = 5;

// The setup routine runs once when you press reset.
void setup() {
  //code setup
   armservo.attach(6);
  pinMode(BUTTON_PIN, INPUT);
  //mechanical setup
  armreset(); //reset servo to 0 degree once battery connected
}

void loop() {
  // read button
  int fdegree = 180;
  bool currentState = digitalRead(BUTTON_PIN);  //should receive 'false' if button pressed
  
  if(currentState == true){   //Start routine by pressing button

    delay(1000);
  
     motorleft.setSpeed(255);
     motorright.setSpeed(255);  
      
     delay(400);
     motorleft.setSpeed(40);
     motorright.setSpeed(40);
     delay(200);
      
      motorleft.setSpeed(0); //stop both dcs
      motorright.setSpeed(0);
      delay(200);
      armlift();
      delay(2000);
  
      motorleft.setSpeed(-100); //going back to cable
      motorright.setSpeed(-100);
      delay(1300);
      motorleft.setSpeed(0); //stop going back
      motorright.setSpeed(0);
      
      Serial.println("Servo");
      while(digitalRead(BUTTON_PIN) == false){
        // do nothing, make the button fall into infinity loop until realease and press again
    }
  }
  
}

void armreset()
{
  armservo.write(0);
}
//outside void loop expected to run once.

void armlift()
{
  armservo.write(180);
}
