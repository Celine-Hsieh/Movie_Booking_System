#include "main.h"
using namespace std;

int main()
{
    Movie *movie[5] = {new Movie("《暮光之城：破曉》"),
                       new Movie("《怪胎》"),
                       new Movie("《歌喉讚》"),
                       new Movie("《生命中的美好意外》"),
                       new Movie("《一級玩家》")};

    Customer customer[5];
    Manager manager;

    int interface,i=0; //i = customer count

    cout<<"================================================================================"<<endl;
    cout<<"                              歡迎使用影城購票系統                              "<<endl;
    do{
        USER_INTER;
        cin>>interface;

        if (interface == CUSTOMER){customer[i].enter_system(movie);}
        else if(interface == MANAGER){manager.enter_system(movie);}
        else if(interface == LEAVE_SYSTEM || customer[i].after_look == LEAVE_SYSTEM){goto bye;}
        else{cout<<" 輸入錯誤!!\n";}
        i++;

    }while(interface != LEAVE_SYSTEM || customer[i].after_look != LEAVE_SYSTEM || manager.after_look != LEAVE_SYSTEM);

    bye:
        cout<<"\n 感謝使用影城訂票系統!\n";
    return 0;
}
