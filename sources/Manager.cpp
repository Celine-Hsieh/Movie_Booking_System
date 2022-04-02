#include "Manager.h"

using namespace std;

void Manager::enter_system(Movie *movie[5])
{
    while(password_count<3)
    {
        (*this).password_proctect();
        if(password=="key")
        {
            (*this).manager(movie);//the manager mode to set the number of seats available for booking
            password_count=3;
        }else
        {
            cout<<"\n 密碼錯誤!!"<<" 剩下 "<<2-password_count<<" 機會 "<<" \n";//password_count is to count no. of attempts left
            password_count++;
        }
    }

}

void Manager::password_proctect()
{
    cout<<"\n\n 請輸入管理者密碼: ";
    cin>>password;
    //system("cls");
    while(star<password.length())
    {
        if(star==0){cout<<"\n\n 請輸入管理者密碼: \n\n";}
        cout<<" * ";
        star++;
    }
}

void Manager::manager(Movie *movie[5])
{
    Show show;
    //system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"                              歡迎使用影城購票系統                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\n\n\t\t\t         1. 查詢所有訂單\n";
    cout<<"\n\t\t\t         2. 後台預訂電影\n";
    cout<<"\n\t\t\t         3. 回首頁\n";
    cout<<"\n\n\n\n\n\n";
    cout<<"================================================================================"<<endl;
    cin>>order_look;
    string memberid_save="NULL";
    if(order_look ==1)
    {
        show.check_order(memberid_save);
        cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
        cout<<"\n\t\t\t         1. 後台預訂電影\n";
        cout<<"\n\t\t\t         2. 回首頁\n";
        cout<<"\n\t\t\t         3. 離開系統\n";
        cout<<"\n\n\n\n\n\n";
        cin>>after_look;

    }else if(order_look == 2 || after_look == 1)
    {
        do
        {
            show.show_movie_from_file();
            cout<<"\n\n 選擇電影選項: ";
            int i;
            cin>>i;
            int movie_number=i;
            i--;
            (*this).make_booking(*movie[i], movie_number);
        }while(in==1);
    }else if(order_look>3 || order_look<1)
    {
        cout<<"\n\n 輸入無效! 回到首頁\n";
        cout<<"================================================================================"<<endl;
    }
}

void Manager::make_booking(Movie movie, int i)
{
    int movie_time;
    Order *order = new Order(movie.showname, i);
    movie_time = order->choose_movie(movie_time, i);
    //system("cls");
    movie.ticket_print(order, i, movie_time);
    cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
    cout<<"\n\t\t\t         1. 繼續訂票\n";
    cout<<"\n\t\t\t         2. 回到首頁\n";
    cout<<"\n\t\t\t         3. 離開系統\n";
    cin>>in;
}
