#include "time.h"

time::time()
{
}

time::~time()
{
}

time::time(int h, int m)
:_hour{h}, _minute{m}
{}


//-------- Setters end getters ---------------

int time::hour() const{
    return _hour;
}

void time::set_hour(const int hour){
    _hour = hour;
}

int time::minute() const{
    return _minute;
}

void time::set_minute(const int minute){
    _minute = minute;
}

//---------------------------------------------

string time::getTime() const{
    string seperator = ":";
    return std::to_string(_hour)+seperator+std::to_string(_minute)+seperator+"00";
}


