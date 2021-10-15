// Variablen bennen
int x;
boolean eins;
boolean zwei;
boolean drei;
boolean vier;
boolean fuenf;
boolean recordboolean;
int drueckanzahl = 2;
int zeit = 2;
int starttime = 0;
int endtime = 0;
int elapsedtime = 0;
boolean vorReadRecord;

// Aufbau des Arduinos
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  boolean inputRead;
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

//
void loop()
{
  vorReadRecord = digitalRead(3);
  boolean vorRead = digitalRead(2);  // bei dieser methode 2 option true/false
  Serial.println(x);
  delay(10);
  if (vorRead == true)
  {
    eins = true;
  }

  if (vorReadRecord == true)
  {
    zwei = true;
  }

  if (recordboolean)
  {
    record();
  }
  else
  {

    if (!vorReadRecord && zwei)
    {
      recordboolean = true;
      zwei = false;
    }

    // Abfrage ob die taste gedrückt wurde
    if (!vorRead && eins == true)
    {
      endtime = millis();
      elapsedtime = endtime - starttime; // Wie viel zeit seit dem letzten drücken vergangen ist

    }



    if (!vorRead && eins == true && ((elapsedtime >= 500 * zeit && elapsedtime <= 1000 * zeit) || elapsedtime == endtime)) // entweder wird die taste zum zweiten mal in einem bestimmt zeitraum gedrückt oder es wird zum ersten mal gedrückt
    {
      x += 1;
      eins = false;
      starttime = millis();
    }
    else if (vorRead && eins == true && !((elapsedtime >= 500 * zeit && elapsedtime <= 1000 * zeit) || elapsedtime == endtime)) // diese zeile wird nur ausgeführt wenn die oberen zwei optionnicht erfüllt wurden oder wenn die taste vor länger als zwei ode
      //er weniger als eine sekunde gedrückt worden ist
    {
      starttime = 0;
      x = 0;
    }
    if (x >= drueckanzahl)
    {
      for (int i = 0; i < 3; i = i + 1)
      {
        digitalWrite(13, HIGH);
        delay(1000);

        digitalWrite(13, LOW);
        delay(1000);
        starttime = 0;
      }
      x = 0;
    }

  }
}

void record()
{
  if (!vorReadRecord && zwei)
  {
    recordboolean = false;
    zwei = false;
  }
}

  //TEST
