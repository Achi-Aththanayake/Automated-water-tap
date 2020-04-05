  /*
  * Automated Water Tap
  * Ultrasonic Sensor HC-SR04 and Plastic Water Solenoid Valve – 12V – 1/2″ Nominal
  *
  * by Achintha Aththanayake
  *
  */
  // define pins numbers
  // ultrasonic sensor
  const int trigPin = 9;
  const int echoPin = 10;
  // solenoid valve
  int solenoidPin = 4; 
  
  // defines variables
  // ultrasonic sensor
  long duration;
  int distance;
  // solenoid valve
  int space=15; // depend on the position of the ultrasonic sensor
  
  
  void setup()
  {
    pinMode(trigPin, OUTPUT); // set the trigPin as an Output
    pinMode(echoPin, INPUT); // set the echoPin as an Input
    pinMode(solenoidPin, OUTPUT); //set the solenoidPin as an Output
  }

  
  void loop()
  {
    // clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // set the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // read the echoPin 
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance in cm
    distance= duration*0.034/2;

    // switch on the Solenoid valve  
    if (space<=distance)
      digitalWrite(solenoidPin, HIGH);
    // switch off the Solenoid valve
    else                    
      digitalWrite(solenoidPin, LOW);
         
  }
