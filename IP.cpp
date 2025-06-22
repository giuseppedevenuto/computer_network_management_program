#include <iostream>
#include "IP.h"

using namespace std;

int IP::counter = 0;

IP::IP(int a, int b, int c, int d)
{
    ip[0] = a;
    ip[1] = b;
    ip[2] = c;
    ip[3] = d;
    cout << "IP(" << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << ")" << endl;
    counter ++;
}

IP::IP(const IP& other)
{
    ip[0] = other.ip[0];
    ip[1] = other.ip[1];
    ip[2] = other.ip[2];
    ip[3] = other.ip[3];
    cout << "IP(" << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << ")" << endl;
    counter ++;
}

IP::~IP()
{
    cout<<"~IP(" << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << ")"<< endl;
    counter --;
    cout << counter << endl;
}

void IP::Print() const
{
    cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] ;
}

bool operator==(const IP& a, const IP& b)
{
    for (int i = 0; i < 4; i++)
    {
        if (a.ip[i] != b.ip[i])
        {
            return false;
        }
    }
    return true;
}

void IP::PrintNIP()
{
    cout << counter << endl;
}
