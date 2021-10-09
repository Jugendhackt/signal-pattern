int x;
boolean eins;

void setup()
{
pinMode(13, OUTPUT);
pinMode(2, INPUT);
boolean inputRead;
digitalWrite(13, LOW);
}

void loop() {
  
  boolean vorRead = digitalRead(2);
  if (vorRead==true)
  {
    eins = true;
  }
  
  if(!vorRead && eins == true)
  {
    x += 1;
   eins = false;   
  }

  if(x>=2)
  {
  for(int i=0; i < 3; i = i+1)
  {
  digitalWrite(13, HIGH);
  delay(1000);
  
  digitalWrite(13, LOW);
  delay(1000);
  }
  x = 0;
  
  }
}
