void Mode_PrecPushCallback(void *ptr)  // Press event for button Mode_Prec
{
  num_mode--;
  if(num_mode<0){num_mode=7;}
  Serial.print("Nom_Mode.txt=\"");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);

}  // End of press event

void Mode_suivPushCallback(void *ptr)  // Press event for button Mode_suiv
{
  num_mode++;
  if(num_mode>7){num_mode=0;}
  Serial.print("Nom_Mode.txt=\"");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);

}  // End of press event

void Mode_1PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=0;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff); 
}

void Mode_2PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=1;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\""); 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_3PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=2;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_4PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=3;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\""); 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_5PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=4;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\""); 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_6PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=5;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_7PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=6;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\""); 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void Mode_8PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  num_mode=7;
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\""); 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}
void annulerp1PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void annulerp2PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}

void annulerp3PushCallback(void *ptr)  // Press event for button Mode_1
{
  Serial.print("page 0");
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print("Nom_Mode.txt=\"");
  Serial.print(modeliste[num_mode]);// This is the value you want to send to that object and atribute mentioned before.
  Serial.print("\"");  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}


void writerpm(int rpm){
  Serial.print("rpm.val=");
  Serial.print(rpm);// This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}
void writervit(int vit){
  Serial.print("vit.val=");
  Serial.print(vit);// This is the value you want to send to that object and atribute mentioned before. 
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}
void writerap(int rap){
  Serial.print("rap.val=");
  Serial.print(rap);// This is the value you want to send to that object and atribute mentioned before.  
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
}
