#include <assert.h>
#include<iostream>
using namespace std;

class AlertBasetype {
public:
	virtual void alert(const char* vitalname, const char* level) = 0;
};

class AlertSMS : public AlertBasetype {
public:
	void alert(const char* vitalname, const char* level) {
		cout << "SMS: " << vitalname << " is " << level << " !" << endl;
	}
};

class AlertSound : public AlertBasetype {
public:
	void alert(const char* vitalname, const char* level) {
		cout << "Sound: " << vitalname << " is " << level << " !" << endl;
	}
};

int main()
{
	AlertBasetype *alert1, *alert2;
	AlertSMS sms;
	AlertSound sound;
	
	alert1 = &sms;
	alert1->alert("BP","high");

	alert2 = &sound;
	alert2->alert("SPO2", "LOW");

	return 0;
}
