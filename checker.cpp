#include <assert.h>
#include <iostream>


void raiseSoundAlert (const char * vitalName, const char* level)
{
  std::cout << "Sound: " << vitalName << " is " << level << std::endl;
}

bool level_is_ok (const char* name, float value, float lower_limit, float upper_limit)
{

  if (value<lower_limit)
  {
   raiseSoundAlert (name, "LOW");
    return false;
  }
  else if (value>upper_limit)
  {
    raiseSoundAlert (name, "HIGH");
    return false;
  }
  else 
    return true;
    
}

bool is_in_limits (float value, float lower_limit, float upper_limit)
{ 
  return (value<=upper_limit && value>=lower_limit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) 
{
    return( level_is_ok("bpm",bpm, 70, 150) 
           && level_is_ok("spo2",spo2, 90, 100) 
           && level_is_ok("respRate",respRate, 30, 95) );  
}

int main() 
{
  
  
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(vitalsAreOk(80, 90, 100) == false);
}
