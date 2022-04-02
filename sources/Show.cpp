#include "Show.h"

using namespace std;

void Show::check_order(string memberid_save)
{
    Manager manager;
    int line=0;
    int i=0,detail_count=0;
    string id_save[5];

    ifstream fin;
    fin.open("order_detail.csv");
    cout<<" 訂位明細:\n";

    do
    {
        getline(fin,detail_save[line],'\n');
        line++;
    }while(!fin.eof());

    for(i=0; i<line; i++)
    {
        id_save[i]=detail_save[i].substr(0,detail_save[i].find(','));
        if (id_save[i]==memberid_save)//show all member id's order
        {
            cout<<"\t\t"<<detail_save[i]<<"\n";
            detail_count++;
        }else if( memberid_save == "NULL")//show all order
        {
            cout<<"\t\t"<<detail_save[i]<<"\n";
            detail_count++;
        }
    }
    fin.close();
    cout<<"\n以上總共有 "<<detail_count<<" 筆訂單\n";

}

void Show::show_movie_from_file()
{
    int i=0;
    cout<<"\n\n 電影時刻表:\n\n\n";
    ifstream fin;
    fin.open("movie_showtime.csv");

    while(!fin.eof())
    {
        cout<<"\n ";
        getline(fin,name[i],',');
        cout<<"影廳 :\t"<<i+1<<name[i]<<endl<<endl;
        cout<<"\t";
        cout<<"上映時間: "<<name[i]<<" :-  "<<endl;
        int j=0;
        getline(fin,time[i][j],'\n');
        cout<<"\t";
        cout<<time[i][j]<<endl<<endl;
        i++;//to access the different movie names
    }
    fin.close();
}

int Show::seat_display(int movie_number,int movie_time)
{
    int i,j,full;
    char letter='A';
    ifstream fin;
    fin.open("movie_showtime.csv");
    for(i=0;i<movie_number-1;i++)
    {
        getline(fin,name[i],'\n');
    }
    getline(fin,name[i],',');
    cout<<"\n\n\t    以下是電影 [ "<<name[i]<<" ] 的影城座位表: \n";
    cout<<"\n\n\t\t      已預定的座位標記為 [x] \n\n";
    fin.close();

    for(i=0;i<5;i++)
    {
        letter='E';
        letter=letter-i;
        cout<<"\t  ";
        for(j=0;j<8;j++)
        {
            if(seat_print[cinema][movie_number][movie_time][4-i][j]==1)
            {
                cout<<"["<<" X"<<"]";
                full++;
            }
            else{cout<<"["<<letter<<j+1<<"]";}
            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]
            if(j==1||j==5)
                cout<<"\t";
        }
        cout<<"\n\n";
        if(i==4)
        {
            cout<<"\n\n\t\t\t  螢幕位置\n";
            cout<<"\t______________________________________________________________________________________________________________";
        }
    }
    if(full==40)
    {
        cout<<"\n\n\t\t\t  訂位已滿!\n";
        return 1;
    }else{return 0;}
}
