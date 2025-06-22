#ifndef PC_H

#define PC_H

#include <iostream>
#include <string>

#include "NetworkItem.h"
#include "IP.h"

using namespace std;

class PC : public NetworkItem
{
        int* memory;
        int size;
    public:
        PC(string, const IP&, int = 1024);
        PC(const PC&);
        ~PC();

        void Print() const;
        int Size() const;
        PC* Clone() const;

        void SetIP(const IP&);
        IP GetIP() const;
};

#endif // PC_H
