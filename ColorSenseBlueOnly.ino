/* This code works with GY-31 TCS3200 TCS230 color sensor module
 *  It select a photodiode set and read its value (Red Set/Blue set/Green set) and displays  it on the Serial monitor
 * Refer to www.surtrtech.com for more details
 */

#define  s0 8       //Module pins wiring
#define s1 9
#define s2 10
#define s3 11
#define  out 12

int data=0;        //This is where we're going to stock our values

void  setup() 
{
   pinMode(s0,OUTPUT);    //pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

   Serial.begin(9600);   //intialize the serial monitor baud rate
   
   digitalWrite(s0,HIGH);  //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%  (recommended)
   digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and  LOW/HIGH is  2%

    //Set the photodiode sense color to Blue
    digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   
}

void loop()                  //Every 2s we select  a photodiodes set and read its data
{

  int blue = GetData();
  blue = map(blue,5,60,255,0);


   Serial.print("Blue value= ");
   Serial.print(blue);            //it's a time duration measured,  which is related to frequency as the sensor gives a frequency depending on the color
   Serial.print("\	");           //The higher the frequency the lower the duration
   Serial.println();

   delay(2000);
}

int GetData(){
   data=pulseIn(out,LOW);       //here  we wait until "out" go LOW, we start measuring the duration and stops when "out"  is HIGH again
   return data;
   
   delay(20);
}

