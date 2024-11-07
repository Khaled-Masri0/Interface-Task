#define green 2
#define yellow 3
#define red 5
#define echo 10
#define trig 11

// for initialization
void setup(){
	pinMode(green,OUTPUT);
  	pinMode(yellow,OUTPUT);
 	pinMode(red,OUTPUT);
  	pinMode(echo,INPUT);
  	pinMode(trig,OUTPUT);
    Serial.debug(9600);
}

// infinite loop
void loop(){
  long duration, cm;
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  
  duration = pulseIn(echo,HIGH);
  cm = duration / 29 / 2;
  
  long distance = map(analogRead(A4),0,1023,1,12);
  long upper = 20*distance ;
  long lower = 10*distance ;
  Serial.println(distance);
  
    if(cm>upper){
    digitalWrite(green,HIGH);
  	digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
  	}
  else if(cm<= upper && cm>=lower ){
    digitalWrite(green,LOW);
  	digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
  }
  else {
   digitalWrite(green,LOW);
  	digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
  }

  
}