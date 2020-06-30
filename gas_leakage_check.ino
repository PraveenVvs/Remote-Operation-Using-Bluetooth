int ssensor=A0;
int gsensor=A2;
int gas_value;
int sound_value;
void setup()
{

pinMode(ssensor,INPUT);
pinMode(gsensor,INPUT);
Serial.begin(9600);

}

void loop()
{
  char b,a;
while(1)
{
gas_value=analogRead(gsensor);
sound_value=analogRead(ssensor);
if(Serial.available())
{
  a=Serial.read();
  if(a=='1')
  b=1;
  else if(a=='2')
  b=2;
}
if(b==1)
{
Serial.print(gas_value);
Serial.println(" mg");
}
if(b==2)
{
Serial.print(sound_value,DEC);
Serial.println(" hz");
}
delay(200);
}
}
