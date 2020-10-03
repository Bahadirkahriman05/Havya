#define potPin A5
#define ledPin 10
#define Gate 3

int readVal;
int setVal;
int ledVal;
boolean start = 0;
void setup() {

pinMode(13, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(Gate, OUTPUT);
 start = 1;
}

void loop() {
	while(start == 1){
		analogWrite(Gate, 255);
		digitalWrite(13, HIGH);
		delay(10000);
		start = 0;
	}
	digitalWrite(13, LOW);
	readVal = analogRead(potPin);
	setVal = map(readVal, 0, 1023, 185, 255);
	ledVal = map(readVal, 0, 1023, 0, 255);
	analogWrite(ledPin, ledVal);
	analogWrite(Gate, setVal);
	delay(2000);
	analogWrite(Gate, 0);
	delay(1000);
}