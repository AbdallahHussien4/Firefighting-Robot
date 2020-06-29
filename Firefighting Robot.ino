//Note : You Should Make the front sensor on a high value > 3V , after rotating the right motor or left motor 2 full rotations (90 degree).
// because that in the reality the robot change its direction too and an empty path are available in front of it.
unsigned long PM=0,previousMillisR=0,previousMillisL=0,previousMillisF=0,previousfire=0;
bool state=false;
int lastStepR=0,lastStepL=0,lastStepF=0,fire=0,RS=0,LS=0;
void setup() {
  pinMode(0,INPUT_PULLUP),pinMode(2,INPUT_PULLUP),pinMode(1,OUTPUT);
  for(int i=3;i<=5;i++)pinMode(i,INPUT);
  for(int i=6;i<=13;i++)pinMode(i,OUTPUT);
  for(int i=15;i<=19;i++)pinMode(i,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), FightFire, CHANGE);
}

void loop() {
  unsigned long CM=millis();
    if((CM-PM)>=1000)
    {
      state=!state;
      digitalWrite(15,state);
      PM=millis();
    }
    if(fire == 2 && millis() >= previousfire + 500){
      fire = 1; 
    }
    if(fire==1)
    {
      MoveFront();
    }
  else if(!digitalRead(0))
  {
    
    if(GetDistance(8)<=200)
    {
        if(GetDistance(16)<=200)
        {
            if(GetDistance(32)<=200)
            {
                MoveRight(19,18,17,16);
                MoveLeft(13,12,11,10);
            }
            else if(LS<32)
            {
               MoveLeft(10,11,12,13);
            }
            else{
                 MoveRight(16,17,18,19);
                 MoveLeft(10,11,12,13);
            }
            }
        else if(RS<32)
        {
           MoveRight(16,17,18,19);
        }
        else{
          MoveRight(16,17,18,19);
          MoveLeft(10,11,12,13);
        }
        }
    else
    {
       MoveRight(16,17,18,19);
       MoveLeft(10,11,12,13);  
       RS=0;
       LS=0;
    }
  }   
}
void MoveLeft(int i, int j ,int k , int m){
  unsigned long CM=millis();
  if(CM - previousMillisL > 100)
    { 
    Move(i,j,k,m,lastStepL);
      previousMillisL = CM;  
      lastStepL++;
      LS++;
    }
   if(lastStepL>3)
      lastStepL=0;
 }

 void MoveRight(int i, int j ,int k , int m){
  unsigned long CM=millis();
  if(CM - previousMillisR > 100)
    { 
      Move(i,j,k,m,lastStepR);
      previousMillisR = CM;  
      lastStepR++;
      RS++;
    }
   if(lastStepR>3)
      lastStepR=0;
 }

void MoveFront(){
unsigned long CM=millis();
  if(CM - previousMillisF > 100)
    { 
      Move(6,7,8,9,lastStepF);
      previousMillisF = CM;  
      lastStepF++;
    }
   if(lastStepF>3)
      lastStepF=0;
}
void Move(int i, int j ,int k , int m,int s)
{
    switch(s)
      {
          case 0:
            digitalWrite(i, HIGH);  
            digitalWrite(j, LOW);
            digitalWrite(k, LOW);   
            digitalWrite(m, LOW);   
            break;
          case 1:
            digitalWrite(i, LOW);  
            digitalWrite(j, HIGH);
            digitalWrite(k, LOW);   
            digitalWrite(m, LOW);
            break;
          case 2:
            digitalWrite(i, LOW);  
            digitalWrite(j, LOW);
            digitalWrite(k, HIGH);   
            digitalWrite(m, LOW);
            break;
          case 3:
            digitalWrite(i, LOW);  
            digitalWrite(j, LOW);
            digitalWrite(k, LOW);   
            digitalWrite(m, HIGH);
            break;
   }
}
int GetDistance(int i){
  unsigned long currentMicros = micros();
  float distance;
  digitalWrite( 1, LOW ); 
  while(micros()-currentMicros<2);
  digitalWrite( 1, HIGH );
  currentMicros = micros();
  while(micros()-currentMicros<10);
  digitalWrite( 1, LOW );
  int duration; 
  int counter = 0;
  while(  --counter!=0  )
  {
  if( PIND & i ) 
  {
    currentMicros = micros();
    break;
  }
  }
  while( --counter!=0 )
  {
  if( (PIND & i)==0 ) 
  {
    duration = micros()-currentMicros;
    break;
  }
  }
  distance = ( duration/2 ) * 0.0344;

   return distance;
}

void FightFire(){
  if(digitalRead(2) == LOW){
   if(!fire ){
      previousfire = millis();    
      fire = 2;
    }
    else{
      fire = 0;
    }
  }
  else{
    if(fire == 2 && millis() < previousfire + 500){
      fire = 0;
    }
  }
}
