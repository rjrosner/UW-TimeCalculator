
//Main purpose of interface is to run the  fixTime() fuction then returned correct calculations.
//via istream ostream
//Operator's preform overloading implementing addition subtraction and unary negation.
#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

TimeSpan::TimeSpan (double sec)
{
    hours = 0;
    minutes =0;
    seconds = sec;
    fixTime();
}
TimeSpan::TimeSpan (double min,double sec)
{
    hours = 0;
    minutes = min;
    seconds = sec;
    fixTime();
}

TimeSpan::TimeSpan(double hrs, double min, double sec)
{
    hours = hrs;
    minutes = min;
    seconds = sec;
    fixTime();
}
void TimeSpan::fixTime()
{

    if  (seconds >= MAX_MIN_SEC)
    {
        while ( seconds >= MAX_MIN_SEC)
        {
        minutes++;
        seconds = seconds - MAX_MIN_SEC;
        }
    }
    if  (minutes >= MAX_MIN_SEC)
    {
        while(minutes>=MAX_MIN_SEC)
    {
        hours++;
        minutes = minutes - MAX_MIN_SEC;
    }
    }
    
    if  (seconds <= -MAX_MIN_SEC)
    {
        while ( seconds <= -MAX_MIN_SEC)
        {
            minutes++;
            seconds = seconds - MAX_MIN_SEC;
        }
    }
    if  (minutes <= -MAX_MIN_SEC)
    {
        while(minutes<=-MAX_MIN_SEC)
        {
            hours++;
            minutes = minutes - MAX_MIN_SEC;
        }
    }

    if (minutes < 0 && hours > 0)
    {
        hours --;
        minutes += MAX_MIN_SEC;
    }
    if (minutes > 0 && hours < 0)
    {
        hours ++;
        minutes -= MAX_MIN_SEC;
    }
    if (seconds < 0 && minutes > 0)
    {
        minutes --;
        seconds += MAX_MIN_SEC;
    }
    if (seconds > 0  && minutes < 0)
    {
        minutes ++;
        seconds -= MAX_MIN_SEC;
    }

}

int TimeSpan::getHours() const
{
    return hours;
}
int TimeSpan::getMinutes() const
{
    return minutes;
}
int TimeSpan::getSeconds() const
{
    return seconds;
}

void TimeSpan::setHours(int hrs)
{
    hours = hrs;
}

void TimeSpan::setMinutes(int min)
{
    minutes= min;
}

void TimeSpan::setSeconds(int sec)
{
    seconds = sec;
}
//-------------------------------------------------------
TimeSpan TimeSpan::operator+(const TimeSpan &dur) const
{
    TimeSpan tempDur;
    
    tempDur.hours +=dur.hours;
    tempDur.minutes +=dur.minutes;
    tempDur.seconds +=dur.seconds;
    tempDur.fixTime();
    return tempDur;
}

TimeSpan TimeSpan::operator-(const TimeSpan &dur) const
{
    TimeSpan tempDur;
    
    tempDur.hours -=dur.hours;
    tempDur.minutes -=dur.minutes;
    tempDur.seconds -=dur.seconds;
    tempDur.fixTime();
    return tempDur;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &dur)
{
    hours = dur.hours;
    minutes = dur.minutes;
    seconds = dur.seconds;
    fixTime();
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &dur)
{
    hours = dur.hours;
    minutes = dur.minutes;
    seconds = dur.seconds;
    fixTime();
    return *this;
}

//-------------------------------------------------------------
ostream& operator << (ostream &outStream, const TimeSpan &dur)
{
    outStream <<"Hours: "<< dur.getHours()<<"\tMinutes: "<< dur.getMinutes()<<"\tSeconds: "<< dur.getSeconds()<<"\t\n";
    return outStream;
}

istream& operator >> (istream &inStream, TimeSpan &dur)
{
    
    inStream >> dur.hours>> dur.minutes>> dur.seconds;
    dur.fixTime();
    return inStream;
}

bool TimeSpan::operator!=(const TimeSpan &dur) const
{
    return ((hours != dur.hours)||(minutes != dur.minutes)||(seconds != dur.seconds));
}

bool TimeSpan::operator==(const TimeSpan &dur) const
{
    return ((hours == dur.hours) && (minutes == dur.minutes) && (seconds == dur.seconds));
}

TimeSpan TimeSpan::operator-() const
{
    TimeSpan tempDur;
    tempDur.hours = -hours;
    tempDur.minutes = -minutes;
    tempDur.seconds = -seconds;
    return tempDur;
}



TimeSpan::~TimeSpan()
{
}
