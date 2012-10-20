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
    
struct StateEntry
{
	uint32_t 	time;
	uint8_t		mode;
};

enum States
{
	FastJabber = 1,
	SlowClose = 2,
	FastClose = 3,
	FastOpen = 4,
	HoldOpen = 5,
	PulseClose = 6
};

const uint8_t FastJabberIncrement = 12;
const uint8_t SlowCloseIncrement = 4;
const uint8_t HoldOpenIncrement = 4;
const uint8_t PulseCloseCount = 3;


const uint8_t michaelClosed = 40;
const uint8_t michaelOpen = 90;

const uint8_t vincentClosed = 50;
const uint8_t vincentOpen = 90;

const uint8_t littlePumpkinMin = 20;
const uint8_t littlePumpkinMax = 170;

StateEntry littlePumpkinStates[] PROGMEM =
{
{17500, 1},
{312081, 2},
{999999, 0}
};


StateEntry vincentStates[] PROGMEM =
{
{0,             2},
{264270,	1	/*FAST_JABBER*/},	
{267148,	2	/*SLOW_CLOSE*/},	
{267887,	1	/*FAST_JABBER*/},	
{270480,	2	/*SLOW_CLOSE*/},	
{271699,	1	/*FAST_JABBER*/},	
{274423,	4	/*FAST_CLOSE*/},	
{275296,	1	/*FAST_JABBER*/},	
{277828,	4	/*FAST_CLOSE*/},	
{279309,	1	/*FAST_JABBER*/},	
{281418,	2	/*SLOW_CLOSE*/},	
{282466,	1	/*FAST_JABBER*/},	
{284864,	2	/*SLOW_CLOSE*/},	
{286248,	1	/*FAST_JABBER*/},	
{289002,	5	/*HOLD_OPEN*/},	
{289626,	4	/*FAST_CLOSE*/},	
{290466,	1	/*FAST_JABBER*/},	
{293254,	5	/*HOLD_OPEN*/},	
{294036,	4	/*FAST_CLOSE*/},	
{314476,	1	/*FAST_JABBER*/},	
{316719,	2	/*SLOW_CLOSE*/},	
{317293,	1	/*FAST_JABBER*/},	
{319997,	2	/*SLOW_CLOSE*/},	
{320350,	1	/*FAST_JABBER*/},	
{322748,	4	/*FAST_OPEN*/},	
{322895,	2	/*SLOW_CLOSE*/},	
{323863,	1	/*FAST_JABBER*/},	
{327120,	2	/*SLOW_CLOSE*/},	
{328561,	1	/*FAST_JABBER*/},	
{330744,	2	/*SLOW_CLOSE*/},	
{331540,	1	/*FAST_JABBER*/},	
{334892,	4	/*FAST_CLOSE*/},	
{335664,	1	/*FAST_JABBER*/},	
{338109,	2	/*SLOW_CLOSE*/},	
{339338,	1	/*FAST_JABBER*/},	
{342767,	5	/*HOLD_OPEN*/},	
{343916,	2	/*SLOW_CLOSE*/},
{999999, 0}	
/*{344860,	1	},	
{354932,	2	},*/
};

StateEntry michaelStates[] PROGMEM =
{
{0,             2},
{59293,	1	/*FAST_JABBER*/},	
{60023,	5	/*HOLD_OPEN*/},	
{61108,	6	/*PULSE_CLOSE*/},	
{61617,	4	/*FAST_CLOSE*/},	
{61975,	1	/*FAST_JABBER*/},	
{64031,	5	/*HOLD_OPEN*/},	
{65160,	2	/*SLOW_CLOSE*/},	
{67306,	1	/*FAST_JABBER*/},	
{68143,	5	/*HOLD_OPEN*/},	
{69479,	4	/*FAST_CLOSE*/},	
{70118,	1	/*FAST_JABBER*/},	
{72168,	5	/*HOLD_OPEN*/},	
{73222,	6	/*PULSE_CLOSE*/},	
{73567,	1	/*FAST_JABBER*/},	
{74260,	5	/*HOLD_OPEN*/},	
{75483,	4	/*FAST_CLOSE*/},	
{75978,	1	/*FAST_JABBER*/},	
{78480,	5	/*HOLD_OPEN*/},	
{79377,	2	/*SLOW_CLOSE*/},	
{81640,	1	/*FAST_JABBER*/},	
{82303,	5	/*HOLD_OPEN*/},	
{83316,	2	/*SLOW_CLOSE*/},	
{83944,	1	/*FAST_JABBER*/},	
{86224,	5	/*HOLD_OPEN*/},	
{87225,	4	/*FAST_CLOSE*/},	
{87430,	1	/*FAST_JABBER*/},	
{89372,	4	/*FAST_CLOSE*/},	
{89757,	1	/*FAST_JABBER*/},	
{90550,	5	/*HOLD_OPEN*/},	
{91143,	6	/*PULSE_CLOSE*/},	
{91716,	2	/*SLOW_CLOSE*/},	
{92570,	5	/*HOLD_OPEN*/},	
{93082,	6	/*PULSE_CLOSE*/},	
{93571,	1	/*FAST_JABBER*/},	
{94070,	4	/*FAST_CLOSE*/},	
{94361,	1	/*FAST_JABBER*/},	
{97649,	4	/*FAST_CLOSE*/},	
{97907,	1	/*FAST_JABBER*/},	
{98710,	5	/*HOLD_OPEN*/},	
{99822,	4	/*FAST_CLOSE*/},	
{100616,	4	/*FAST_OPEN*/},	
{101262,	6	/*PULSE_CLOSE*/},	
{102179,	4	/*FAST_CLOSE*/},	
{102457,	1	/*FAST_JABBER*/},	
{106804,	5	/*HOLD_OPEN*/},	
{109991,	2	/*SLOW_CLOSE*/},	
{113200,	1	/*FAST_JABBER*/},	
{114352,	6	/*PULSE_CLOSE*/},	
{116008,	1	/*FAST_JABBER*/},	
{116926,	5	/*HOLD_OPEN*/},	
{117930,	6	/*PULSE_CLOSE*/},	
{118788,	1	/*FAST_JABBER*/},	
{121004,	5	/*HOLD_OPEN*/},	
{121905,	2	/*SLOW_CLOSE*/},	
{124255,	1	/*FAST_JABBER*/},	
{124949,	5	/*HOLD_OPEN*/},	
{126080,	6	/*PULSE_CLOSE*/},	
{126820,	1	/*FAST_JABBER*/},	
{128990,	5	/*HOLD_OPEN*/},	
{130313,	1	/*FAST_JABBER*/},	
{131049,	5	/*HOLD_OPEN*/},	
{131870,	2	/*SLOW_CLOSE*/},	
{132697,	1	/*FAST_JABBER*/},	
{135998,	2	/*SLOW_CLOSE*/},	
{137693,	4	/*FAST_OPEN*/},	
{138252,	4	/*FAST_CLOSE*/},	
{138664,	1	/*FAST_JABBER*/},	
{139139,	4	/*FAST_OPEN*/},	
{140247,	2	/*SLOW_CLOSE*/},	
{140994,	1	/*FAST_JABBER*/},	
{143288,	5	/*HOLD_OPEN*/},	
{143768,	4	/*FAST_CLOSE*/},	
{144225,	1	/*FAST_JABBER*/},	
{145192,	5	/*HOLD_OPEN*/},	
{145767,	2	/*SLOW_CLOSE*/},	
{146616,	1	/*FAST_JABBER*/},	
{147339,	5	/*HOLD_OPEN*/},	
{148441,	2	/*SLOW_CLOSE*/},	
{149348,	4	/*FAST_OPEN*/},	
{149861,	6	/*PULSE_CLOSE*/},	
{150299,	6	/*PULSE_CLOSE*/},	
{150865,	1	/*FAST_JABBER*/},	
{154405,	5	/*HOLD_OPEN*/},	
{154857,	1	/*FAST_JABBER*/},	
{155426,	4	/*FAST_CLOSE*/},	
{156487,	5	/*HOLD_OPEN*/},	
{156976,	6	/*PULSE_CLOSE*/},	
{157686,	2	/*SLOW_CLOSE*/},	
{159233,	1	/*FAST_JABBER*/},	
{161513,	6	/*PULSE_CLOSE*/},	
{161697,	1	/*FAST_JABBER*/},	
{162025,	4	/*FAST_CLOSE*/},	
{165759,	1	/*FAST_JABBER*/},	
{169710,	5	/*HOLD_OPEN*/},	
{170631,	6	/*PULSE_CLOSE*/},	
{170808,	5	/*HOLD_OPEN*/},	
{172215,	4	/*FAST_CLOSE*/},	
{173651,	1	/*FAST_JABBER*/},	
{177783,	5	/*HOLD_OPEN*/},	
{179009,	4	/*FAST_CLOSE*/},	
{180191,	1	/*FAST_JABBER*/},	
{181985,	5	/*HOLD_OPEN*/},	
{184078,	4	/*FAST_CLOSE*/},	
{184684,	4	/*FAST_OPEN*/},	
{184741,	2	/*SLOW_CLOSE*/},	
{186851,	1	/*FAST_JABBER*/},	
{187868,	5	/*HOLD_OPEN*/},	
{188732,	4	/*FAST_CLOSE*/},	
{188910,	1	/*FAST_JABBER*/},	
{189389,	4	/*FAST_CLOSE*/},	
{189754,	1	/*FAST_JABBER*/},	
{191846,	5	/*HOLD_OPEN*/},	
{193119,	4	/*FAST_CLOSE*/},	
{195201,	1	/*FAST_JABBER*/},	
{196032,	5	/*HOLD_OPEN*/},	
{196628,	2	/*SLOW_CLOSE*/},	
{197713,	1	/*FAST_JABBER*/},	
{200094,	5	/*HOLD_OPEN*/},	
{200917,	4	/*FAST_CLOSE*/},	
{201296,	1	/*FAST_JABBER*/},	
{202062,	5	/*HOLD_OPEN*/},	
{203475,	4	/*FAST_CLOSE*/},	
{203837,	1	/*FAST_JABBER*/},	
{206196,	5	/*HOLD_OPEN*/},	
{206951,	2	/*SLOW_CLOSE*/},	
{207371,	1	/*FAST_JABBER*/},	
{208510,	4	/*FAST_CLOSE*/},	
{209349,	1	/*FAST_JABBER*/},	
{210149,	5	/*HOLD_OPEN*/},	
{211404,	4	/*FAST_CLOSE*/},	
{211803,	1	/*FAST_JABBER*/},	
{214123,	5	/*HOLD_OPEN*/},	
{214706,	4	/*FAST_CLOSE*/},	
{215185,	1	/*FAST_JABBER*/},	
{216129,	5	/*HOLD_OPEN*/},	
{216943,	4	/*FAST_CLOSE*/},	
{217458,	1	/*FAST_JABBER*/},	
{218249,	5	/*HOLD_OPEN*/},	
{218794,	6	/*PULSE_CLOSE*/},	
{219447,	2	/*SLOW_CLOSE*/},	
{220201,	1	/*FAST_JABBER*/},	
{226184,	2	/*SLOW_CLOSE*/},	
{227350,	4	/*FAST_OPEN*/},	
{227899,	6	/*PULSE_CLOSE*/},	
{228284,	2	/*SLOW_CLOSE*/},	
{230216,	1	/*FAST_JABBER*/},	
{232412,	4	/*FAST_CLOSE*/},	
{237914,	1	/*FAST_JABBER*/},	
{238557,	5	/*HOLD_OPEN*/},	
{238845,	6	/*PULSE_CLOSE*/},	
{239635,	2	/*SLOW_CLOSE*/},	
{240512,	4	/*FAST_OPEN*/},	
{240998,	6	/*PULSE_CLOSE*/},	
{241758,	1	/*FAST_JABBER*/},	
{245610,	5	/*HOLD_OPEN*/},	
{246339,	6	/*PULSE_CLOSE*/},	
{246967,	4	/*FAST_CLOSE*/},	
{247555,	5	/*HOLD_OPEN*/},	
{248109,	6	/*PULSE_CLOSE*/},	
{248771,	2	/*SLOW_CLOSE*/},	
{250205,	1	/*FAST_JABBER*/},	
{252613,	4	/*FAST_CLOSE*/},	
{261912,	1	/*FAST_JABBER*/},	
{262718,	5	/*HOLD_OPEN*/},	
{263827,	2	/*SLOW_CLOSE*/},	
{278231,	1	/*FAST_JABBER*/},	
{279242,	2	/*SLOW_CLOSE*/},	
{294322,	1	/*FAST_JABBER*/},	
{295222,	5	/*HOLD_OPEN*/},	
{295615,	2	/*SLOW_CLOSE*/},	
{297072,	4	/*FAST_OPEN*/},	
{298234,	1	/*FAST_JABBER*/},	
{299319,	5	/*HOLD_OPEN*/},	
{299967,	2	/*SLOW_CLOSE*/},	
{300857,	1	/*FAST_JABBER*/},	
{312081,	2	/*SLOW_CLOSE*/},
{999999, 0}
};
