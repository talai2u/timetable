#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>
using namespace std;

class time
{
public:
    time();
    time(int h, int m);
    ~time();
    
    //--Setters && Getters
    
    int hour() const; 
    void set_hour(const int hour);
    
    int minute() const; 
    void set_minute(const int minute);
     
    
    //--------------------------------
    
    string getTime() const;
    
private:
    int _hour;
    int _minute;
};

#endif // TIME_H
