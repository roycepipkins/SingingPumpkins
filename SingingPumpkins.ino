/*    
    This file is part of SingingPumpkins.

    SingingPumpkins is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SingingPumpkins is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SingingPumpkins.  If not, see <http://www.gnu.org/licenses/>.*/
    
#include <inttypes.h>
#include <Wire.h>
#include <pgmspace.h>
#include <WaveHC.h>
#include <WaveUtil.h>
#include <Adafruit_PWMServoDriver.h>
#include "Thriller.h"
#include "ServoState.h"


SdReader card;    // This object holds the information for the card
FatVolume vol;    // This holds the information for the partition on the card
FatReader root;   // This holds the information for the volumes root directory
FatReader file;   // This object represent the WAV file
WaveHC wave;      // This is the only wave (audio) object, since we will only play one at a time

Adafruit_PWMServoDriver pwm;

const uint32_t milli_offset = 0;


const int SERVOMIN = 150;
const int SERVOMAX = 600;

const uint8_t servo1_pin = 0;
const uint8_t servo2_pin = 2;
const uint8_t servo3_pin = 4;
const uint8_t servo4_pin = 6;
const uint8_t servo5_pin = 8;
const uint8_t servo6_pin = 10;
const uint8_t servo7_pin = 12;

const uint8_t led1_pin = 1;
const uint8_t led2_pin = 3;
const uint8_t led3_pin = 5;
const uint8_t led4_pin = 7;
const uint8_t led5_pin = 9;
const uint8_t led6_pin = 11;
const uint8_t led7_pin = 13;
const uint8_t led8_pin = 14;
const uint8_t led9_pin = 15;




uint16_t michaelDuty;
uint16_t vincentDuty;
uint16_t servo3Duty;
uint16_t servo4Duty;
uint16_t servo5Duty;
uint16_t servo6Duty;
uint16_t servo7Duty;

uint16_t led1_duty;
uint16_t led2_duty;
uint16_t led3_duty;
uint16_t led4_duty;
uint16_t led5_duty;
uint16_t led6_duty;
uint16_t led7_duty;
uint16_t led8_duty;
uint16_t led9_duty;

ServoState michaelState = {michaelClosed, 0, 0, &michaelDuty, 0, false, michaelClosed, michaelOpen, 0};
ServoState vincentState = {vincentClosed, 0, 0, &vincentDuty, 0, false, vincentClosed, vincentOpen, 0};
ServoState lp1 = {90, 0, 0, &servo3Duty, 0, false, littlePumpkinMin, littlePumpkinMax, 0};
ServoState lp2 = {90, 0, 0, &servo4Duty, 0, false, littlePumpkinMin, littlePumpkinMax, 0};
ServoState lp3 = {90, 0, 0, &servo5Duty, 0, false, littlePumpkinMin, littlePumpkinMax, 0};
ServoState lp4 = {90, 0, 0, &servo6Duty, 0, false, littlePumpkinMin, littlePumpkinMax, 0};
ServoState lp5 = {90, 0, 0, &servo7Duty, 0, false, littlePumpkinMin, littlePumpkinMax, 0};

const uint8_t updatePeriod = 16;
volatile uint8_t updateClock = updatePeriod;
volatile bool timeToUpdate = false;

StateEntry m;
StateEntry v;
StateEntry p1,p2,p3,p4,p5;

uint16_t fromAngle(uint16_t angle)
{
  uint32_t pulse;
  angle = angle << 8;
  pulse = angle / 180;
  pulse *= (SERVOMAX - SERVOMIN);
  pulse = pulse >> 8;
  pulse += SERVOMIN;
  return pulse;
}


void setup()
{

  
  Serial.begin(9600);  
   
  if (!card.init()) {
    //error("Card init. failed!");
  }
  // enable optimize read - some cards may timeout
  card.partialBlockRead(true);
  
  if (!vol.init(card)) {
    //error("No partition!");
  }
  if (!root.openRoot(vol)) {
    //error("Couldn't open root");
  }
  putstring_nl("Files found:");
  root.ls();
  
  pwm.begin();
  pwm.setPWMFreq(60);
  

  
  playfile("Thriller.wav");
}



void UpdateServos()
{
	timeToUpdate = false;

	pwm.setPWM(servo1_pin, 0, michaelDuty); 
	pwm.setPWM(servo2_pin, 0, vincentDuty);  
	pwm.setPWM(servo3_pin, 0, servo3Duty);  
	pwm.setPWM(servo4_pin, 0, servo4Duty);  
	pwm.setPWM(servo5_pin, 0, servo5Duty);
	pwm.setPWM(servo6_pin, 0, servo6Duty);  
	pwm.setPWM(servo7_pin, 0, servo7Duty);   

	/*pwm.setPWM(led1_pin, 0, led1_duty);  
	pwm.setPWM(led2_pin, 0, led2_duty);
	pwm.setPWM(led3_pin, 0, led3_duty);
	pwm.setPWM(led4_pin, 0, led4_duty);
	pwm.setPWM(led5_pin, 0, led5_duty);
	pwm.setPWM(led6_pin, 0, led6_duty);
	pwm.setPWM(led7_pin, 0, led7_duty);
	pwm.setPWM(led8_pin, 0, led8_duty);
	pwm.setPWM(led9_pin, 0, led9_duty);*/
}

void UpdateStateMachine(ServoState& state)
{
	switch(state.mode)
	{
	case FastJabber:
		state.lastMode = FastJabber;
		if (state.angle <= state.minAngle)
		{
			state.flag = true;
		}
		else if (state.angle >= state.maxAngle)
		{
			state.flag = false;
		}
		if (state.flag)
		{
			state.angle += FastJabberIncrement;
		}
		else
		{
			state.angle -= FastJabberIncrement;
		}
		break;
	case SlowClose:
		state.lastMode = SlowClose;
		if (state.angle > state.minAngle)
			state.angle -= SlowCloseIncrement;
		break;
	case FastClose:
		state.lastMode = FastClose;
		state.angle = state.maxAngle;
		break;
	case FastOpen:
		state.lastMode = FastOpen;
		state.angle = state.minAngle;
		break;
	case HoldOpen:
		
		if (state.angle <= state.maxAngle)
			state.angle += HoldOpenIncrement;
		state.lastMode = HoldOpen;
		break;
	case PulseClose:
		
		if (state.lastMode != PulseClose)
		{
			state.counter = PulseCloseCount;
			state.flag = false;
		}
		if (!state.flag)
		{
			if (--state.counter)
			{
				state.angle = state.minAngle;
			}
			else state.flag = true;
		}
		else
		{
			state.angle = state.maxAngle;
		}
		state.lastMode = PulseClose;
		break;
        case SlowJabber:
                state.lastMode = SlowJabber;
		if (state.angle <= state.minAngle)
		{
			state.flag = true;
		}
		else if (state.angle >= state.maxAngle)
		{
			state.flag = false;
		}
		if (state.flag)
		{
			state.angle += SlowJabberIncrement;
		}
		else
		{
			state.angle -= SlowJabberIncrement;
		}
		break;
        case StopArduino:
                while(1); 
	default:
		break;
	}
	
	*(state.duty) = fromAngle(state.angle);
}

void CheckSchedule(ServoState& state, StateEntry& entry)
{
	uint32_t c_time = millis();
	
	if (c_time >= entry.time + milli_offset)
	{
		state.mode = entry.mode;
		state.schedIdx++;
	}
        
}

void loop()
{
        m.time = pgm_read_dword(&(michaelStates[michaelState.schedIdx].time));
        m.mode = pgm_read_byte(&(michaelStates[michaelState.schedIdx].mode));
        v.time = pgm_read_dword(&(vincentStates[vincentState.schedIdx].time));
        v.mode = pgm_read_byte(&(vincentStates[vincentState.schedIdx].mode));
        p1.time = pgm_read_dword(&(littlePumpkinStates[lp1.schedIdx].time));
        p1.mode = pgm_read_byte(&(littlePumpkinStates[lp1.schedIdx].mode));
        
        p2.time = pgm_read_dword(&(littlePumpkinStates[lp2.schedIdx].time));
        p2.mode = pgm_read_byte(&(littlePumpkinStates[lp2.schedIdx].mode));
        
        p3.time = pgm_read_dword(&(littlePumpkinStates[lp3.schedIdx].time));
        p3.mode = pgm_read_byte(&(littlePumpkinStates[lp3.schedIdx].mode));
        
        
        p4.time = pgm_read_dword(&(littlePumpkinStates[lp4.schedIdx].time));
        p4.mode = pgm_read_byte(&(littlePumpkinStates[lp4.schedIdx].mode));
        
	
        p5.time = pgm_read_dword(&(littlePumpkinStates[lp5.schedIdx].time));
        p5.mode = pgm_read_byte(&(littlePumpkinStates[lp5.schedIdx].mode));

	CheckSchedule(michaelState, m);
	CheckSchedule(vincentState, v);
        CheckSchedule(lp1, p1);
        CheckSchedule(lp2, p2);
        CheckSchedule(lp3, p3);
        CheckSchedule(lp4, p4);
        CheckSchedule(lp5, p5);
	
	UpdateStateMachine(michaelState);
	UpdateStateMachine(vincentState);

        UpdateStateMachine(lp1);
        UpdateStateMachine(lp2);
        UpdateStateMachine(lp3);
        UpdateStateMachine(lp4);
        UpdateStateMachine(lp5);

	UpdateServos();

        delay(17);
}




void jaw()
{
    int pos;
    //30 to 90 for the jaw
    for(pos = 40; pos < 90; pos += 4)  // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
      pwm.setPWM(0, 0, fromAngle(pos));      // tell servo to go to position in variable 'pos'
      pwm.setPWM(2, 0, fromAngle(pos));
      pwm.setPWM(4, 0, fromAngle(pos));
      pwm.setPWM(6, 0, fromAngle(pos));
      pwm.setPWM(8, 0, fromAngle(pos));
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for(pos = 90; pos>=40; pos-=4)     // goes from 180 degrees to 0 degrees
    {                                
      pwm.setPWM(0, 0, fromAngle(pos));             // tell servo to go to position in variable 'pos'
      pwm.setPWM(2, 0, fromAngle(pos));
      pwm.setPWM(4, 0, fromAngle(pos));
      pwm.setPWM(6, 0, fromAngle(pos));
      pwm.setPWM(8, 0, fromAngle(pos));
      delay(15);                       // waits 15ms for the servo to reach the position
    } 
}

/*
 * Play a file and wait for it to complete
 */
void playcomplete(char *name) {
  playfile(name);
  while (wave.isplaying);
  
  // see if an error occurred while playing
  sdErrorCheck();
}
/*
 * Open and start playing a WAV file
 */
void playfile(char *name) {
  if (wave.isplaying) {// already playing something, so stop it!
    wave.stop(); // stop it
  }
  if (!file.open(root, name)) {
    PgmPrint("Couldn't open file ");
    Serial.print(name); 
    return;
  }
  if (!wave.create(file)) {
    PgmPrintln("Not a valid WAV");
    return;
  }
  // ok time to play!
  wave.play();
}

void sdErrorCheck(void) {
  if (!card.errorCode()) return;
  PgmPrint("\r\nSD I/O error: ");
  Serial.print(card.errorCode(), HEX);
  PgmPrint(", ");
  Serial.println(card.errorData(), HEX);
  while(1);
}
