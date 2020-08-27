#include <assert.h>

bool is_in_limits (float value, float lower_limit, float upper_limit)
{
  return (value<=upper_limit && value>=lower_limit);
}

/*
bool bpm_is_Ok(float bpm)
{
  return is_in_limits(bpm, 70, 150);
}

bool spo2_is_Ok(float spo2)
{
  return is_in_limits(spo2, 90, 100);
}

bool respRate_is_Ok(float respRate)
{
    return is_in_limits(respRate, 30, 95);
}
*/

bool vitalsAreOk(float bpm, float spo2, float respRate) 
{
    return( is_in_limits(bpm, 70, 150) && is_in_limits(spo2, 90, 100) && is_in_limits(respRate, 30, 95) );  
}

int main() 
{
  assert (is_in_limits(20,10,30) == true);
  assert (is_in_limits(10,20,30) == false);
  assert (is_in_limits(10,10,30) == true);
  assert (is_in_limits(30,10,30) == true);
  
  /*
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  */
}
