// Variablen bennen
int x;
boolean eins;
int starttime = 0;
int endtime= 0;
int elapsedtime=0;

// Aufbau des Arduinos
void setup()
{
pinMode(13, OUTPUT);
pinMode(2, INPUT);
boolean inputRead;
digitalWrite(13, LOW);
}

// 
void loop() {
  
  boolean vorRead = digitalRead(2);  // bei dieser methode 2 option true/false
  if (vorRead==true)
  {
    eins = true;
  }
  // Abfrage ob die taste gedrückt wurde 
  if(!vorRead && eins == true)
  {
    endtime = millis();
    elapsedtime = endtime - starttime; // Wie viel zeit seit dem letzten drücken vergangen ist 
  
  }
  if(!vorRead && eins == true && ((elapsedtime >= 1000 && elapsedtime <= 2000)|| elapsedtime == endtime)) // entweder wird die taste zum zweiten mal in einem bestimmt zeitraum gedrückt oder es wird zum ersten mal gedrückt
  {
    x += 1;
   eins = false;   
   starttime = millis();
  }
  else if(vorRead && eins == true && !((elapsedtime >= 1000 && elapsedtime <= 2000)|| elapsedtime == endtime)) // diese zeile wird nur ausgeführt wenn die oberen zwei optionnicht erfüllt wurden oder wenn die taste vor länger als zwei ode
  //er weniger als eine sekunde gedrückt worden ist
  {
    starttime = 0;
  }
 if(x>=3)
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
