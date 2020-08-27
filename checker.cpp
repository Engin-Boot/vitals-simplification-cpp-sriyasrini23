#include <assert.h>

bool is_in_limits (float value, float lower_limit, float upper_limit)
{
  return ( value<upper_limit && value>lower_limit);
}

bool bpm_is_Ok(float bpm)
{
  return is_in_limit(bpm, 70, 150);
}

bool spo2_is_Ok(float spo2)
{
  return is_in_limit(spo2, 90, 100);
}

bool respRate_is_Ok(float respRate)
{
    return is_in_limit(bpm, 30, 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) 
{
    return( bpm_is_Ok(bpm) && spo2_is_Ok(spo2) && respRate_is_Ok(respRate) );  
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
