#ifndef NET_H

#define NET_H

#include <iostream>
#include <string>
#include <list>

#include "NetworkItem.h"
#include "IP.h"

using namespace std;

class Net : public NetworkItem
{
        list<NetworkItem*> NetItemList;
        list<IP> IPList;
    public:
        Net(string, const IP&);
        Net(const Net&);
        ~Net();

        void Print() const;
        int Size() const;
        Net* Clone() const;

        void SetIP(const IP&);
        IP GetIP() const;

        bool AddCopy(const NetworkItem*);
        bool Add(NetworkItem*);
        bool RemoveItem(const IP);
};

#endif // NET_H
