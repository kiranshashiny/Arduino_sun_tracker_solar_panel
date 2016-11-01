/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int s0 = analogRead(A0);
  // print out the value you read:
  Serial.print(s0);
  Serial.print(" ");

  int s1 = analogRead(A1);
  // print out the value you read:
  Serial.print(s1);
  Serial.print(" " );

  int s2 = analogRead(A2);
  // print out the value you read:
  Serial.print(s2);
  Serial.println(" ");

 
  int ret = check_higher( s0, s1, s2 );
  // this degrees have to be changed after doing multiple trial and errors.
  
  if ( ret ==1 ) {  myservo.write (30); }
  else if ( ret == 2 ) { myservo.write (90 ); }
  else { myservo.write(150);}
  delay(200);        // delay in between reads for stability
}
// Function that returns a number 1, 2 or 3 depending on if sensor1
// sensor2 or sensor3 has the highest light intensity.

int check_higher( int x, int y, int z ) 
{
  if ( x >= y && x >= z ) {
    Serial.println ( "first LDR has the highest light ");
    return 1;
    
  }
  if ( y >= x && y >= z ) {
    
    Serial.println ( "second LDR has the highest light ");
    return 2;
  }

  if ( z >= x && z >= y ) {
    Serial.println ( "third LDR has the highest light ");
    return 3;
  }
}

