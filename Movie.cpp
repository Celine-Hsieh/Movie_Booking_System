#include "Movie.h"

using namespace std;

Movie::Movie (std::string name){showname=name;}

void Movie::addLinkToOrder(Order *order, int movie_number, int movie_time)
{
    Show show;
    int i;
    string show_time,seat,next_seat;

    ifstream fin;
    fin.open("movie_showtime.csv");

    for(i=0;i<movie_number-1;i++){getline(fin,show.name[i],'\n');}
    getline(fin,show.name[i],',');

    for(int j=0;j<movie_time;j++){getline(fin,show_time,',');}
    fin.close();

    //orderOne.hal_name(orderOne.cinema);
    ofstream fout;

    fout.open("order_detail.csv",ios::app);

    for(i=0;i<order->number;i++)
    {
        order->chr=order->ticket_row[i]+65;
        order->col=order->ticket_col[i]+1;
        char *intStr = new char;
        sprintf(intStr,"%d",order->col);
        string str = string(intStr);
        char y ='/';

        if(i<order->ticket-1){next_seat = order->chr+str+y;}
        else{next_seat = order->chr+str;}
        seat=seat+next_seat;
    }

    //fout<<c.memberid_save<<","<<hall_name<<","<<name[i]<<","<<show_time<<","<<number<<"�H"<<","<<seat<<endl;
    fout<<","<<show.name[i]<<","<<show_time<<","<<order->number<<"�H"<<","<<seat<<endl;
}

void Movie::ticket_print(Order *order, int movie_number, int movie_time)
{
    Show show;
    int i;
    int cost=0;
    char letter;
    string show_time;

    for(i=0;i<order->number;i++)
    {
            cost=cost+250;
    }
    ifstream fin;
    fin.open("movie_showtime.csv");

    for(int i=0;i<movie_number-1;i++){getline(fin,show.name[i],'\n');}
    getline(fin,show.name[i],',');

    for(int j=0;j<movie_time;j++){getline(fin,show_time,',');}
    fin.close();
    cout<<show_time;
    (*this).addLinkToOrder(order, movie_number, movie_time);
    cout<<"\n\n\n\n\t\t\t ________________________________________________________________________\n";
    cout<<"\t\t\t|                                                                       |\n";
    cout<<"\t\t\t|   �˷R���U��,                                                         |\n";
    cout<<"\t\t\t|                  ���ߧA�q�짹��!                                      |\n";
    cout<<"\t\t\t|                                                                       |\n";
    cout<<"\t\t\t|                  �q�����:                                            |\n";
    cout<<"\t\t\t|                            �q�v�W��: "<<show.name[i]<<"                     \n";
    cout<<"\t\t\t|                            �q�v�ɨ�: "<<show_time<<"                         |\n";
    cout<<"\t\t\t|                            �H��: "<<order->number<<"                                    |\n";
    cout<<"\t\t\t|                            �q�v�y��: ";
    for(i=0;i<order->number;i++)
    {
        letter=order->ticket_row[i]+65;
        cout<<letter<<order->ticket_col[i]+1;
        if(i<order->ticket-1){cout<<",";}
    }
    cout<<"\n\t\t\t|                            �O��: "<<order->number<<" * 250 ="<<cost<<"                         |\n";
    cout<<"\t\t\t|                                                                       |\n";
    cout<<"\t\t\t|                                                                       |\n";
    cout<<"\t\t\t|_______________________________________________________________________|\n";
}
