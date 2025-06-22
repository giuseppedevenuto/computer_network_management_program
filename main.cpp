#include <iostream>
#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"
#include "Net.h"

using namespace std;

int main()
{
    PC* pc= new PC("pc",IP());
    pc->Print();
    cout << "Size:" << pc->Size() << endl;
    cout << "--------------" << endl;

    Net root("root", IP(10,1,3,1));
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;

    root.Add(pc);
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;
    pc->Print();
    cout << "Size:"<< pc->Size()<< endl;
    cout << "--------------" << endl;

    Net* nodo1 = new Net("node1",IP());
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;
    for(int i=0;i<5;i++){
        PC* pc = new PC("pc1",IP());
        nodo1->Add(pc);}
    cout << "--------------" << endl;
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;

    Net* nodo2 = new Net("node2",IP());
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;
    for(int i=0;i<5;i++){
        PC* pc = new PC("pc2",IP());
        nodo2->Add(pc);}
    cout << "--------------" << endl;
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;

    nodo1->AddCopy(nodo2);
    cout << "--------------" << endl;
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;

    root.Add(nodo1);
    cout << "--------------" << endl;
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;

    root.AddCopy(nodo2);
    cout << "--------------" << endl;
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;

    root.Add(nodo2);
    cout << "--------------" << endl;
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;
    nodo1->Print();
    cout << "Size:"<< nodo1->Size()<< endl;
    cout << "--------------" << endl;
    nodo2->Print();
    cout << "Size:"<< nodo2->Size()<< endl;
    cout << "--------------" << endl;

    root.RemoveItem(IP(562,726,1,3));
    cout << "--------------" << endl;
    root.Print();
    cout << "Size:"<< root.Size()<< endl;
    cout << "--------------" << endl;

    return 0;
}
