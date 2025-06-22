#ifndef NETWORKITEM_H

#define NETWORKITEM_H

#include <iostream>
#include <string>

#include "IP.h"

using namespace std;

class NetworkItem
{
    protected:
        IP ip;
        string id;
    public:
        NetworkItem(string, const IP&);
        NetworkItem(const NetworkItem&);
        virtual ~NetworkItem();

        virtual void Print() const = 0;
        virtual int Size() const = 0;
        virtual NetworkItem* Clone() const = 0;

        virtual void SetIP(const IP&) = 0;
        virtual IP GetIP() const = 0;
};

#endif // NETWORKITEM_H
