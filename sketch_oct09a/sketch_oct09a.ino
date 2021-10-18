int corIn; // Number of inputs that correspond to the selected pattern
boolean eins;
boolean reco;
boolean recordboolean;
int drueckanzahl = 2;
int timeInterval = 2;
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
  if (recordboolean)
    record();
  else
    detectPattern();
}

void record()
{
  if (!vorReadRecord && reco)
  {
    recordboolean = false;
    reco = false;
  }
}

void detectPattern()
{
  vorReadRecord = digitalRead(3);

  if (vorReadRecord == true)
    reco = true;
    
  if (getVorRead() == false)
    eins = true;
    
  if (!vorReadRecord && reco)
  {
    recordboolean = true;
    reco = false;
  }

  if (getVorRead() && eins == true)
  {
    endtime = millis();
    elapsedtime = endtime - starttime; // Wie viel zeit seit dem letzten drücken vergangen ist
  }

  if (getVorRead() && eins == true && ((elapsedtime >= 500 * timeInterval && elapsedtime <= 1000 * timeInterval) || elapsedtime == endtime))
  {
    corIn += 1;
    eins = false;
    starttime = millis();
  }
  else if (getVorRead() && eins == true && !((elapsedtime >= 500 * timeInterval && elapsedtime <= 1000 * timeInterval) || elapsedtime == endtime))
  {
    starttime = 0;
    corIn = 0;
  }
  if (corIn >= drueckanzahl)
  {
    for (int i = 0; i < 3; i = i + 1)
    {
      digitalWrite(13, HIGH);
      delay(1000);

      digitalWrite(13, LOW);
      delay(1000);
      starttime = 0;
    }
    corIn = 0;
  }
}

float getElectrodeValue()
{
  float sensorValue = analogRead(A0);
  float millivolt = (sensorValue / 1023) * 5;
  Serial.print(millivolt);
  Serial.print ("Correct input: ");
  Serial.print(corIn);
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
