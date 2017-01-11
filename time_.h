#ifndef TIME__H
#define TIME__H

#include <string>
#include <iostream>
using namespace std;

class time_
{
public:
    time_();
    ~time_();
    time_(int h, int m);
    time_(const time_ &t);
   
    
    //--Setters && Getters
    
    int hour() const; 
    void set_hour(const int hour);
    
    int minute() const; 
    void set_minute(const int minute);
     
    
    //--------------------------------
    
    string getTime() const;
    
    time_ stringToTime(const string mysqlTime);
    
    void set_strTime(const string strTime);
    
private:
    int _hour;
    int _minute;

};

#endif // TIME__H
