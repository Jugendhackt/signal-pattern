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


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}


void loop()
{
  vorReadRecord = digitalRead(3);

  if (vorReadRecord == true)
    zwei = true;

  if (recordboolean)
    record();
  else
    detectPattern();
}

void record()
{
  if (!vorReadRecord && zwei)
  {
    recordboolean = false;
    zwei = false;
  }
}

void detectPattern()
{
  if (getVorRead() == false)
    eins = true;
    
  if (!vorReadRecord && zwei)
  {
    recordboolean = true;
    zwei = false;
  }

  if (getVorRead() && eins == true)
  {
    endtime = millis();
    elapsedtime = endtime - starttime; // Wie viel zeit seit dem letzten drücken vergangen ist
  }

  if (getVorRead() && eins == true && ((elapsedtime >= 500 * zeit && elapsedtime <= 1000 * zeit) || elapsedtime == endtime))
  {
    x += 1;
    eins = false;
    starttime = millis();
  }
  else if (getVorRead() && eins == true && !((elapsedtime >= 500 * zeit && elapsedtime <= 1000 * zeit) || elapsedtime == endtime))
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

float getElectrodeValue()
{
  float sensorValue = analogRead(A0);
  float millivolt = (sensorValue / 1023) * 5;
  Serial.print(millivolt);
  Serial.print ("x: ");
  Serial.print(x);
  Serial.println();
  delay(100);
  return millivolt;
}

boolean getVorRead()
{
  getElectrodeValue();
  if (getElectrodeValue() > 2)
    return true;
  else if (getElectrodeValue() < 1)
    return false;
}
