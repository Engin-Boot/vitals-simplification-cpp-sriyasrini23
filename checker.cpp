#include<iostream>
#include<assert.h>
using namespace std;

class AlertBasetype {
public:
	virtual void raise(const char* vitalname, const char* level) = 0;
};

class AlertSMS : public AlertBasetype {
public:
	void raise(const char* vitalname, const char* level) {
		cout << "SMS: " << vitalname << " is " << level << " !" << endl;
	}
};

class AlertSound : public AlertBasetype {
public:
	void raise(const char* vitalname, const char* level) {
		cout << "Sound: " << vitalname << " is " << level << " !" << endl;
	}
};

class VitalCheck
{
private:
	const char* _name;
	float _value;
	
	float _upper_limit;
	float _lower_limit;
	const char* _level;

	AlertBasetype* _alert;

public:
	VitalCheck();
	VitalCheck(const char*, float, float, float, AlertBasetype* alert);
	
	void SetLevel();
	bool Level_is_ok();  
};
VitalCheck::VitalCheck() : _value(0), _upper_limit(0), _lower_limit(0) {cout<<"default constructor" <<endl}
VitalCheck::VitalCheck(const char* name, float value, float lower_limit, float upper_limit, AlertBasetype* alert) :
_name(name), _value(value), _lower_limit(lower_limit), _upper_limit(upper_limit), _alert(alert)
{
	cout<<"non-default constructor"<<endl;
	SetLevel();
	Level_is_ok();
}
void VitalCheck::SetLevel()
{
	if (_value < _lower_limit)
		_level = "LOW";
	else if (_value > _upper_limit)
		_level = "HIGH";
	else
		_level = "OK";
}
bool VitalCheck::Level_is_ok()
{
	if (_level != "OK")
	{
		_alert->raise(_name, _level);
		return false;
	}
	else
		return true;	
}

class PatientVitals
{
private:
	VitalCheck _bpm;
	VitalCheck _spo2;
	VitalCheck _respRate;
public:
	PatientVitals(float bpm, float spo2, float resprate, AlertBasetype* alert);
};

PatientVitals::PatientVitals(float bpm, float spo2, float respRate, AlertBasetype* alert)
{
	_bpm("BPM", bpm, 70, 150, alert);
	_spo2("SPO2", spo2, 90, 100, alert);
	_respRate("RespRate", respRate, 24, 30, alert);
}


int main()
{
	AlertBasetype *alert_sms, *alert_sound;
	AlertSMS alert1;
	AlertSound alert2;
	alert_sms = &alert1;
	alert_sound = &alert2;

	PatientVitals(60, 80, 20, alert_sms);
	PatientVitals(160, 180, 120, alert_sound);
	PatientVitals(80, 95, 25, alert_sms);

	return 0;
}
