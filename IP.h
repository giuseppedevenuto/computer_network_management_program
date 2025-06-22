#ifndef IP_H

#define IP_H

#include <iostream>

using namespace std;

class IP
{
        int ip[4];
        static int counter;
    public:
        IP(int = 0, int = 0, int = 0, int = 0);
        IP(const IP&);
        ~IP();

        void Print() const;
        friend bool operator==(const IP&, const IP&);

        static void PrintNIP();
};

#endif // IP_H
