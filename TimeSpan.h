
//public interface for a time machine calculator
#ifndef TimeSpan_H
#define TimeSpan_H

#include <algorithm>
#include <iostream>
using namespace std;
int const MAX_MIN_SEC =60;
class TimeSpan
{
    friend istream& operator>>(istream &inStream, TimeSpan &dur);
    friend ostream& operator<<(ostream &outStream, const TimeSpan &dur);
    
public:
    
    TimeSpan();
    TimeSpan(double sec);
    TimeSpan(double min, double sec);
    TimeSpan(double hrs, double min, double sec);
    
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void setHours(int hrs);
    void setMinutes(int min);
    void setSeconds(int sec);
    
    
    TimeSpan operator+(const TimeSpan &dur) const;
    TimeSpan operator-(const TimeSpan &dur) const;
    
    
    TimeSpan& operator+=(const TimeSpan &dur);
    TimeSpan& operator-=(const TimeSpan &dur);
    
    bool operator !=(const TimeSpan &dur)const;
    bool operator ==(const TimeSpan &dur)const;
    
    TimeSpan operator-()const;
    
    ~TimeSpan();
    
private:
    int hours;
    int minutes;
    int seconds;
    void fixTime();
    
};
#endif
