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
    
struct ServoState
{
	uint16_t	angle;
	uint8_t		lastMode;
	uint8_t		mode;
	uint16_t* 	duty;
	uint8_t		counter;
	bool 		flag;
	uint16_t    minAngle;
	uint16_t    maxAngle;
	uint16_t	schedIdx;
};
