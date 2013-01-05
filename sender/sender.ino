byte transmit = 13; //define our transmit pin
byte mask = 1; //our bitmask


void setup()
{
   pinMode(transmit,OUTPUT);
   Serial.begin(9600);
   digitalWrite(2, LOW);
}

void loop()
{
char data[] = "HELLO";
sendData(data);
delay(1000);

}

void sendData(char * data)
{
  data[strlen(data)] = '@';
  digitalWrite(transmit, HIGH);
  delay(1000);
  digitalWrite(transmit, LOW);
  delay(500);
  

//Serial.println(data);

int i=0;
while(data[i]){
  int k = 0;
  for (mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
    digitalWrite(2, HIGH);
    if (data[i] & mask){ // if bitwise AND resolves to true
      digitalWrite(transmit,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(transmit,LOW); // send 0
    }
  //  Serial.println(data[i]);
  // Serial.print("    ");
  // Serial.print(k);
     k++;

    delay(30); //delay  

    
}
  i++;
  
}

    //Serial.println(data2.substring(i,l));
  
   //String singleChar = data2.substring(i,l),DEC;    

}


