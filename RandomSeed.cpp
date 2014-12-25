/*--------------------------------------------------------------------
RandomSeed is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

RandomSeed is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

See GNU Lesser General Public License at <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#include "RandomSeed.h"

uint32_t GenerateRandomSeed(uint8_t analogPin)
{
  uint32_t seed = 0;
  
  // random works best with a seed that can use 31 bits
  // analogRead on a unconnected pin tends toward less than four bits
  // of usefull information, so we call it multiple times and 
  // shift the bits in
  for (int shifts = 0; shifts < 31; shifts += 3)
  {
    seed |= (analogRead(analogPin) & 0x7) << shifts;
  }
  
  return seed;
}