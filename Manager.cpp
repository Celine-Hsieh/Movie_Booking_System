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
            cout<<"\n �K�X���~!!"<<" �ѤU "<<2-password_count<<" ���| "<<" \n";//password_count is to count no. of attempts left
            password_count++;
        }
    }

}

void Manager::password_proctect()
{
    cout<<"\n\n �п�J�޲z�̱K�X: ";
    cin>>password;
    //system("cls");
    while(star<password.length())
    {
        if(star==0){cout<<"\n\n �п�J�޲z�̱K�X: \n\n";}
        cout<<" * ";
        star++;
    }
}

void Manager::manager(Movie *movie[5])
{
    Show show;
    //system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\n\n\t\t\t         1. �d�ߩҦ��q��\n";
    cout<<"\n\t\t\t         2. ��x�w�q�q�v\n";
    cout<<"\n\t\t\t         3. �^����\n";
    cout<<"\n\n\n\n\n\n";
    cout<<"================================================================================"<<endl;
    cin>>order_look;
    string memberid_save="NULL";
    if(order_look ==1)
    {
        show.check_order(memberid_save);
        cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
        cout<<"\n\t\t\t         1. ��x�w�q�q�v\n";
        cout<<"\n\t\t\t         2. �^����\n";
        cout<<"\n\t\t\t         3. ���}�t��\n";
        cout<<"\n\n\n\n\n\n";
        cin>>after_look;

    }else if(order_look == 2 || after_look == 1)
    {
        do
        {
            show.show_movie_from_file();
            cout<<"\n\n ��ܹq�v�ﶵ: ";
            int i;
            cin>>i;
            int movie_number=i;
            i--;
            (*this).make_booking(*movie[i], movie_number);
        }while(in==1);
    }else if(order_look>3 || order_look<1)
    {
        cout<<"\n\n ��J�L��! �^�쭺��\n";
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
    cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
    cout<<"\n\t\t\t         1. �~��q��\n";
    cout<<"\n\t\t\t         2. �^�쭺��\n";
    cout<<"\n\t\t\t         3. ���}�t��\n";
    cin>>in;
}
