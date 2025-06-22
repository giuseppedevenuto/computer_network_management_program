#include <iostream>
#include "PC.h"

using namespace std;

PC::PC(string id_in, const IP& ip_in, int mem) : NetworkItem(id_in, ip_in)
{
    size = mem;
    memory = new int[mem];
    cout<<"PC::PC(\"" << id_in << "\",";
    ip_in.Print();
    cout << ")"<<endl;
}

PC::PC(const PC& other) : NetworkItem(other.id, other.ip)
{
    size = other.size;
    memory = new int[other.size];
    cout<<"PC::PC(\"" << other.id << "\",";
    other.ip.Print();
    cout << ")"<<endl;
}

PC::~PC()
{
    delete [] memory;
    cout<<"PC::~PC(\"" << id << "\",";
    ip.Print();
    cout << ")"<<endl;
}

void PC::Print() const
{
    cout << "ID: " << id << "; IP: ";
    ip.Print();
    cout<<endl;
}

int PC::Size() const
{
    return size * sizeof(int);
}

PC* PC::Clone() const
{
    return new PC(*this);
}

void PC::SetIP(const IP& ip_in)
{
    cout<<"PC(\""<<id<<"\",";
    ip.Print();
    cout<<")---->>>>PC(\""<<id<<"\",";
    ip_in.Print();
    cout<<")"<<endl;
    ip = ip_in;
}

IP PC::GetIP() const
{
    return ip;
}
