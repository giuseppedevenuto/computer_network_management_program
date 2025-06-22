#include <iostream>
#include "Net.h"
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 999);

Net::Net(string id_in, const IP& ip_in) : NetworkItem(id_in, ip_in)
{
    int i1 = dist(gen);
    int i2 = dist(gen);
    for (int i = 0; i < 20; i++)
    {
        IPList.emplace_back(i1, i2, 1, i + 2);
    }
    cout<<"Net::Net(\"" << id_in << "\",";
    ip_in.Print();
    cout << ")"<<endl;
}

Net::Net(const Net& other) : NetworkItem(other.id, other.ip), IPList(other.IPList)
{
    cout<<"Net::Net(\"" << other.id << "\",";
    other.ip.Print();
    cout << ")"<<endl;
    for (NetworkItem* item : other.NetItemList)
    {
        if (item != nullptr)
        {
            NetItemList.push_back(item->Clone());
        }
    }
}

Net::~Net()
{
    cout<<"Net::~Net(\"" << id << "\",";
    ip.Print();
    cout << ")"<<endl;
    for (NetworkItem* item : NetItemList)
    {
        delete item;
    }
}

void Net::Print() const
{
    cout << "ID: " << id << "; IP: ";
    ip.Print();
    cout<<endl;
    for (NetworkItem* item : NetItemList)
    {
        item->Print();
    }
}

int Net::Size() const
{
    int sum = 0;
    for (NetworkItem* item : NetItemList)
    {
        sum += item->Size();
    }
    return sum;
}

Net* Net::Clone() const
{
    return new Net(*this);
}

void Net::SetIP(const IP& ip_in)
{
    cout<<"Net(\""<<id<<"\",";
    ip.Print();
    cout<<")---->>>>Net(\""<<id<<"\",";
    ip_in.Print();
    cout<<")"<<endl;
    ip = ip_in;
}

IP Net::GetIP() const
{
    return ip;
}

bool Net::AddCopy(const NetworkItem* item)
{
    IP assignedIP = IPList.front();
    IPList.pop_front();

    NetworkItem* newItem = item->Clone();
    newItem->SetIP(assignedIP);
    NetItemList.push_back(newItem);

    return true;
}

bool Net::Add(NetworkItem* item)
{
    IP assignedIP = IPList.front();
    IPList.pop_front();

    item->SetIP(assignedIP);
    NetItemList.push_back(item);
    return true;
}

bool Net::RemoveItem(const IP ipremove)
{
    cout<<"IP(";
    ipremove.Print();
    cout<<") will be removed"<<endl;

    list<NetworkItem*> newNetItemList;
    bool itemRemoved = false;

    for (NetworkItem* item : NetItemList)
    {
        if (item->GetIP() == ipremove)
        {
            IPList.push_back(ipremove);
            delete item;
            itemRemoved = true;
        }
        else
        {
            newNetItemList.push_back(item);
        }
    }
    if (itemRemoved)
    {
        NetItemList = newNetItemList;
    }
    return itemRemoved;
}
