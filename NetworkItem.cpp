#include <iostream>
#include "NetworkItem.h"

using namespace std;

NetworkItem::NetworkItem(string id_in, const IP& ip_in) : id(id_in), ip(ip_in)
{
    cout<<"NetworkItem::NetworkItem(\"" << id_in << "\",";
    ip_in.Print();
    cout << ")"<<endl;
}

NetworkItem::NetworkItem(const NetworkItem& other) : id(other.id), ip(other.ip)
{
    cout<<"NetworkItem::NetworkItem(\"" << other.id << "\",";
    other.ip.Print();
    cout << ")"<<endl;
}

NetworkItem::~NetworkItem()
{
    cout<<"NetworkItem::~NetworkItem(\"" << id << "\",";
    ip.Print();
    cout << ")"<<endl;
}
