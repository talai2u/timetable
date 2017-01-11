#ifndef DATE__H
#define DATE__H

#include <string>
#include <iostream>
#include <ctime>


using namespace std;

class date_
{
public:
    date_();
    date_(int d, int m, int y);
    ~date_();
    
    string days[7] =  {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
    
    //--Setters && Getters
    
    int day() const; 
    void set_day(const int day);
    
    int month() const; 
    void set_month(const int month);
    
    int year() const; 
    void set_year(const int year);

    string get_year();
    
    string get_dayName() const;
    void set_dayName();
    
    void set_strDate(const string strDate);
    
    //--------------------------------
    
    string getDate() const;
    string format_d_m_y() const;
    date_ stringToDate(const string mysqlDate);
    
    
    
private:
    int _day;
    int _month;
    int _year;
    string _dayName;

};

#endif // DATE__H
