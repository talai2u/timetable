#include "time_.h"

time_::time_()
{
}

time_::~time_()
{
}

time_::time_(int h, int m)
:_hour{h}, _minute{m}
{}

time_::time_(const time_ &t)
:_hour{t.hour()}, _minute{t.minute()}
{

}


//-------- Setters end getters ---------------

int time_::hour() const{
    return _hour;
}

void time_::set_hour(const int hour){
    _hour = hour;
}

int time_::minute() const{
    return _minute;
}

void time_::set_minute(const int minute){
    _minute = minute;
}

//---------------------------------------------

string time_::getTime() const{
    string seperator = ":";
    return std::to_string(_hour)+seperator+std::to_string(_minute)+seperator+"00";
}

time_ time_::stringToTime(const string mysqlTime){
    
    int hour = stoi(mysqlTime.substr(0,2));
    int minute = stoi(mysqlTime.substr(3,2));
    
    time_* newTime = new time_(hour,minute);
    return *newTime;
}

void time_::set_strTime(const string strTime){
    int hour = stoi(strTime.substr(0,2));
    int minute = stoi(strTime.substr(3,2));
    
    _hour = hour;
    _minute = minute;
    
}

