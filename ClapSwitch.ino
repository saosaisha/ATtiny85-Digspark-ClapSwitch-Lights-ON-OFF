/*Sensor tepuk tangan atau calapswitch
 
 Radal05
 https://www.youtube.com/c/Radal05
 02 Desember 2021
 
 */
int sound_sensor = 2;  //PB2 sebagai input sensor
int relay = 1;       //PB1 sebagai output relay
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;

void setup()
{
pinMode(sound_sensor, INPUT);
pinMode(relay, OUTPUT);
}
void loop()
{
 int status_sensor = digitalRead(sound_sensor);
  if (status_sensor == 0)
  {
    if (clap == 0)
    {
      detection_range_start = detection_range = millis();
      clap++;
    }
    else if (clap > 0 && millis()-detection_range >= 50)
    {
      detection_range = millis();
      clap++;
    }
  }
  if (millis()-detection_range_start >= 400)
  {
    if (clap == 2 )
    {
      if (!status_lights)
        {
          status_lights = true;
          digitalWrite(relay, HIGH);
        }
        else if (status_lights)
        {
          status_lights = false;
          digitalWrite(relay, LOW);
        }
    }
    clap = 0;
  }
}
