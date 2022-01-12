#include "functions.h"

int to_decode(int shift){ /*Takes shift used to encode text and returns shift to decode*/
  return (26-shift)%26;
}
