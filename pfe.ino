#include <LiquidCrystal.h>
#include <Keypad.h>
int Pir=10;
int Buzzer=11;
int screenOffMsg =0;
String password="0000";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = false;
boolean alarmActivated = false;
boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false;
boolean passChanged = false;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keypressed;
//define the cymbols on the buttons of the keypads
char keyMap[ROWS][COLS] = {
{'1','2','3','F1'},
{'4','5','6','F2'},
{'7','8','9','F3'},
{'*','0','#','F3'}
};
byte rowPins[ROWS] = { 9, 8, 7, 6}; //Row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3,2};
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS,
COLS);
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
void setup(){
Serial.begin(9600);
pinMode(Pir,INPUT);
pinMode(Buzzer,OUTPUT);
lcd.begin(16,2);
}
void loop() {
if (activateAlarm) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Alarm will be");
lcd.setCursor(0,1);
lcd.print("activated in");
int countdown = 3; // 3 seconds count down before activating the alarm
while (countdown != 0) {
lcd.setCursor(13,1);
lcd.print(countdown);
countdown--;
delay(500);
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Alarm Activated!");
activateAlarm = false;
alarmActivated = true;
}
if (alarmActivated == true){
if ( digitalRead(Pir)==HIGH) {
tone(Buzzer,2000); // Send 1KHz sound signal###
lcd.clear();
enterPassword();
}
}
if (!alarmActivated) {
if (screenOffMsg == 0 ){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("1 - Activate");
lcd.setCursor(0,1);
lcd.print("2 - Change Pass");
screenOffMsg = 1;
}
keypressed = myKeypad.getKey();
if (keypressed =='1'){ //If A is pressed, activate the alarm
tone(Buzzer, 100, 500);
activateAlarm = true;
}
else if (keypressed =='2') {
lcd.clear();
int i=1;
tone(Buzzer, 2000, 100);
tempPassword = "";
lcd.setCursor(0,0);
lcd.print("Current Password");
lcd.setCursor(0,1);
lcd.print(">");
passChangeMode = true;
passChanged = true;
while(passChanged) {
  keypressed = myKeypad.getKey();
if (keypressed != NO_KEY){
if (keypressed == '0' || keypressed == '1' || keypressed == '2' ||
keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed == '6' ||
keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempPassword += keypressed;
lcd.setCursor(i,1);
lcd.print("*");
i++;
tone(Buzzer, 2000, 100);
}
}
if (i > 5 || keypressed == '#') {
tempPassword = "";
i=1;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Current Password");
lcd.setCursor(0,1);
lcd.print(">");
}
if ( keypressed == '*') {
i=1;
tone(Buzzer, 2000, 100);
if (password == tempPassword) {
tempPassword="";
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Set New Password");
lcd.setCursor(0,1);
lcd.print(">");
while(passChangeMode) {
keypressed = myKeypad.getKey();
if (keypressed != NO_KEY){
if (keypressed == '0' || keypressed == '1' || keypressed ==
'2' || keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed ==
'6' || keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempPassword += keypressed;
lcd.setCursor(i,1);
lcd.print("*");
i++;
tone(Buzzer, 2000, 100);
}
}
if (i > 5 || keypressed == '#') {
  tempPassword = "";
i=1;
tone(Buzzer, 2000, 100);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Set New Password");
lcd.setCursor(0,1);
lcd.print(">");
}
if ( keypressed == '*') {
i=1;
tone(Buzzer, 2000, 100);
password = tempPassword;
passChangeMode = false;
passChanged = false;
screenOffMsg = 0;
}
}
}
}
}
}
}
}
void enterPassword() {
int k=5;
tempPassword = "";
activated = true;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" *** ALARM *** ");
lcd.setCursor(0,1);
lcd.print("Pass>");
while(activated) {
keypressed = myKeypad.getKey();
if (keypressed != NO_KEY){
if (keypressed == '0' || keypressed == '1' || keypressed == '2' ||
keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed == '6' ||
keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempPassword += keypressed;
lcd.setCursor(k,1);
lcd.print("*");
k++;
}
}
if (k > 9 || keypressed == '#') {
tempPassword = "";
k=5;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" *** ALARM *** ");
lcd.setCursor(0,1);
lcd.print("Pass>");
}
if ( keypressed == '*') {
if ( tempPassword == password ) {
activated = false;
alarmActivated = false;
noTone(Buzzer);
screenOffMsg = 0;
}
else if (tempPassword != password) {
lcd.setCursor(0,1);
lcd.print("Wrong! Try Again");
delay(100);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" *** ALARM *** ");
lcd.setCursor(0,1);
lcd.print("Pass>");
}
}
}
}