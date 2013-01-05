#define analogReadValue 800 //the value that the LDR will have when the LED is on
#define delimiter '@' 
#define clock 50

int syncCount = 0;


void setup()
{
   Serial.begin(9600);
}

void loop()
{
  String data = readData(0);
  Serial.println(data);
}

String readData(int myDataPin) 
{
  pinMode(myDataPin, INPUT);
  String data = "";
  int tempBit = 0;
  char tempByte = 0;
  int pinState;

  while(1)
  {
  if(analogRead(0) > analogReadValue)
  {
    syncCount++;
    if(syncCount > 15) //Check if LED has been countinuesly on for 15 x 50ms
    {
      digitalWrite(13,HIGH);
      while(analogRead(myDataPin) > analogReadValue)
      {
        //Stays in this loop until the LED turns off
      } 
      delay(500+clock/2); //make sure that the reading off the individual bits occour in the middle of a period
      
      while(tempByte != delimiter)
        {
          for (int i=0; i<8; i++)
          {
            tempBit = analogRead(myDataPin);
            if (tempBit > analogReadValue) 
            {
              pinState = 1;
              tempByte = tempByte | (1 << i);
            }
          delay(50);
          }
          if(tempByte != delimiter)
          {
            data += tempByte; //Build the final data string char by char
          } 
          else
          {
            return data;
          }
          tempByte = 0;
        }
        syncCount = 0;
    }
  
  }
  else
  {
  syncCount = 0; 
  }
  delay(clock);
  }
}

  
