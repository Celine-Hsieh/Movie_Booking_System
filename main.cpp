#include "main.h"
using namespace std;

int main()
{
    Movie *movie[5] = {new Movie("�m�ǥ������G�}��n"),
                       new Movie("�m�ǭL�n"),
                       new Movie("�m�q���g�n"),
                       new Movie("�m�ͩR�������n�N�~�n"),
                       new Movie("�m�@�Ū��a�n")};

    Customer customer[5];
    Manager manager;

    int interface,i=0; //i = customer count

    cout<<"================================================================================"<<endl;
    cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
    do{
        USER_INTER;
        cin>>interface;

        if (interface == CUSTOMER){customer[i].enter_system(movie);}
        else if(interface == MANAGER){manager.enter_system(movie);}
        else if(interface == LEAVE_SYSTEM || customer[i].after_look == LEAVE_SYSTEM){goto bye;}
        else{cout<<" ��J���~!!\n";}
        i++;

    }while(interface != LEAVE_SYSTEM || customer[i].after_look != LEAVE_SYSTEM || manager.after_look != LEAVE_SYSTEM);

    bye:
        cout<<"\n �P�¨ϥμv���q���t��!\n";
    return 0;
}
