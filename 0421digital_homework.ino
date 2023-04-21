byte ssd[10][7] = {
  {0,0,0,0,0,0,1}, 
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0}
  };
const int buttonPin = 10;
int num = 0;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,1);
  pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin(19200);
}

void ssw(byte digit){
  byte pin = 2;
  for(byte seg = 0;seg < 7;seg++){
    digitalWrite(pin,ssd[digit][seg]);
    pin++;
    }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  // put your main code here, to run repeatedly:
  if(buttonState == LOW){
    num++;
    if(num > 9){
    num = 0;
    }
    delay(1000);
    }
  ssw(num);
  Serial.println(num);
}
