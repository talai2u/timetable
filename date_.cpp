#include "date_.h"



date_::date_()
{
}

date_::~date_()
{
}

date_::date_(int d, int m, int y )
:_day{d}, _month{m}, _year{y} 
{
    set_dayName();
}

//-------- Setters end getters ---------------

int date_::day() const{
    return _day;
}

void date_::set_day(const int day){
    _day = day;
}

int date_::month() const{
    return _month;
}

void date_::set_month(const int month){
    _month = month;
}

int date_::year() const{
    return _year;
}

void date_::set_year(const int year){
    _year = year;
}

string date_::get_dayName() const{
    if(_year && _month && _day) 
        return _dayName;
    else
        return "Name error !";
}

void date_::set_dayName(){
    if(!_year || !_month || !_day){ 
        _dayName = "Name error !";
        return;
    }
    tm timeStruct = {};
    timeStruct.tm_year = _year - 1900;
    timeStruct.tm_mon = _month - 1;
    timeStruct.tm_mday = _day;
    timeStruct.tm_hour = 12; 
    mktime( &timeStruct );
    _dayName = days[timeStruct.tm_wday];  //  0...6 for Sunday...Saturday
}

//-----------------------------------

string date_::getDate() const{
    string seperator = "-";
    return std::to_string(_year)+seperator+std::to_string(_month)+seperator+std::to_string(_day);
}

string date_::format_d_m_y() const{
    string seperator = "/";
    return std::to_string(_day)+seperator+std::to_string(_month)+seperator+std::to_string(_year);
}

date_ date_::stringToDate(const string mysqlDate){
    
    int year = stoi(mysqlDate.substr(0,4));
    int month = stoi(mysqlDate.substr(5,2));
    int day = stoi(mysqlDate.substr(8));
    
    date_* newDate = new date_(day,month,year);
    return *newDate;
}

void date_::set_strDate(const string strDate){
    int year = stoi(strDate.substr(6));
    int month = stoi(strDate.substr(3,2));
    int day = stoi(strDate.substr(0,2));
        
    _day = day;
    _month = month;
    _year = year;
}


