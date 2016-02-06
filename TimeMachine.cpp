
#include <iostream>
#include "TimeSpan.h"
using namespace std;

int main()
{
    TimeSpan dur15(1,10,1),dur16(1,1,1);
    TimeSpan dur1( 8,-23,0 ), dur2( 7,35,120 ), dur3(-3,73,2), dur4( 1,61,1);
    TimeSpan dur5( 999999, 999999, 999999 ), dur6( 10, 5,-2), dur7(-10), dur8(30);
    TimeSpan dur9(21,0), dur10(-10,0),dur11, dur12(0,1,0), dur13(0,1,0), dur14(0,2,0);
    cout<< "1" << dur1 ;
    cout<< "2" << dur2 ;
    cout<< "3" << dur3 ;
    cout<< "4" << dur4 ;
    cout<< "5" << dur5 ;
    cout<< "6" << dur6 ;
    cout<< "7" << dur7 ;
    cout<< "8" << dur8 ;
    cout<< "9" << dur9 ;
    cout<< "10" << dur10 ;
    cout<< "11" << dur11 ;
    dur1 += dur2;
    dur1 -= dur2;
    dur11 += dur10;
    dur9 -= dur8;
    cout << dur1;
    cout << dur2;
    cout << dur11;
    cout << dur10;
    cout << dur9;
    cout << dur8;
    dur14 = dur12 + dur13;
    dur1 = dur1 - dur2;
    cout << dur1;
    cout <<"dur14 test:"<<dur14<< endl;
    if (dur1 == dur14)
    {
        cout << "Durations are the same." << endl;
    }
    else
    {
        cout << "Durations are different." << endl;
    }
    if (dur1 != dur2)
    {
        cout << "Durations are different." << endl;
    }
    else
    {
        cout << "Durations are the same" << endl;
    }
    
    system("pause");
    return 0;
}
