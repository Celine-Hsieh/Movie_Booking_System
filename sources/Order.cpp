#include "Order.h"

using namespace std;

Order::Order(std::string showname, int i){movie_name=showname; movie_number=i;}

int Order::choose_movie(int movie_time, int movie_number)
{
    Show show;
    int i;
    string show_time;
    ifstream fin;
    cout<<"\n\n 電影: "<<movie_name<<endl;

    cout<<"\n\n 選擇場次(1-6): ";
    cin>>movie_time;

    fin.open("movie_showtime.csv");
    for(i=0;i<movie_number-1;i++){getline(fin,show.name[i],'\n');}
    getline(fin,show.name[i],',');

    for(int j=0;j<movie_time;j++){getline(fin,show_time,',');}
    fin.close();

    cout<<"\n\n 場次 "<<movie_time<<": "<<show_time;

    fin.open("movie_showtime.csv");
    for(i=0;i<movie_number-1;i++)
    {
        getline(fin,show.name[i],'\n');
    }
    getline(fin,show.name[i],',');

    fin.close();
    cout<<"\n\n 人數: ";
    cin>>number;

    for(ticket=0;ticket<number;ticket++)//loop for booking the desired no. of tickets as input by user
    {
        (*this).book_seat(movie_number,movie_time,ticket+1);
    }
    return movie_time;
}

void Order::book_seat(int movie_number,int movie_time ,int number_count)//first csv_rowument is for the movie number and 3rd csv_rowument for manager mode
{
    Show show;                                                           //2nd csv_row is for show time
    if(show.seat_display(movie_number,movie_time)==0)
    {
    cout<<"\n\n\t\t\t請輸入第 "<<number_count<<" 個座位編號(ex: A1): ";
    cin>>chr>>col;
    cout<<"\n";

    letter=chr-65;
    col=col-1;

    if(show.seat_print[show.cinema][movie_number][movie_time][letter][col]==0)
    {
        show.seat_print[show.cinema][movie_number][movie_time][letter][col]=1;
        ticket_col[ticket]=col;
        ticket_row[ticket]=letter;
    }else
    {

        while(show.seat_print[show.cinema][movie_number][movie_time][letter][col]!=0)
        {
            cout<<"\n\n\t\t\t["<<chr<<col+1<<"] 座位已有人選! 請輸入其他座位: ";
            cin>>chr>>col;
            letter=chr-65;
            col=col-1;
        }
        show.seat_print[show.cinema][movie_number][movie_time][letter][col]=1;
        ticket_col[ticket]=col;
        ticket_row[ticket]=letter;
    }
    }else
    {
        cout<<"請選擇其他場次!\n";
        show.show_movie_from_file();
    }
}
