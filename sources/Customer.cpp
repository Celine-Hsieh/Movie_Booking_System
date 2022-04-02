#include "Customer.h"

using namespace std;

void Customer::enter_system(Movie *movie[5])
{
    //system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"                              歡迎使用影城購票系統                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
    cout<<"\n\t\t\t\t\t 1. 註冊會員\n";
    cout<<"\n\t\t\t\t\t 2. 登入會員\n";
    cout<<"\n\t\t\t\t\t 3. 回上一頁\n";
    cout<<"\n\n\n\n\n\n";
    cout<<"================================================================================"<<endl;
    cin>>user_in;

    if(user_in==1){(*this).sign_up();}
    else if(user_in==2)
    {
        system("cls");
        cout<<"================================================================================"<<endl;
        cout<<"                              歡迎使用影城購票系統                              "<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"\n\n\n\n\t\t\t 歡迎登入會員!!!\n";
        enter=(*this).log_in(movie);
    }

    if(enter!=0||data_store!=0)
    {
        cout<<"================================================================================"<<endl;
        cout<<"                              歡迎使用影城購票系統                              "<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
        cout<<"\n\t\t\t         1. 查詢訂單\n";
        cout<<"\n\t\t\t         2. 預訂電影\n";
        cout<<"\n\t\t\t         3. 回上一頁\n";
        cout<<"\n\n\n\n\n\n";
        cout<<"================================================================================"<<endl;
        cin>>order_look;

        Show show;
        if(order_look ==1)
        {
            show.check_order(memberid_save);
            cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
            cout<<"\n\t\t\t         1. 預訂電影\n";
            cout<<"\n\t\t\t         2. 回首頁\n";
            cout<<"\n\t\t\t         3. 離開系統\n";
            cout<<"\n\n\n\n\n\n";
            cin>>after_look;

        }else if(order_look==2 || after_look==1)
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
        }else if(order_look==3)
        {
            (*this).enter_system(movie);
        }else
        {
            cout<<"\n\n 輸入無效! 回到首頁\n";
            cout<<"================================================================================"<<endl;
        }
    }
}

void Customer::sign_up()
{
    password="null";
    ofstream fout;
    fout.open("member_detail.csv",ios::app);
    string user_id,user_passwordword;

    fflush(stdin);
    system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"                              歡迎使用影城購票系統                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\t\t\t\t 請輸入姓名: ";
    fflush(stdin);
    getline(cin,user_name);
    cout<<"\n\t\t\t\t 請輸入使用者ID: ";
    fflush(stdin);
    getline(cin,user_id);
    cout<<"\n\t\t\t\t 請輸入使用者密碼: ";
    fflush(stdin);
    getline(cin,user_passwordword);
    fout<<user_name<<","<<user_id<<","<<user_passwordword<<endl;
    memberid_save=user_id;
    cout<<"================================================================================"<<endl;
    fout.close();
    data_store=1;
    system("cls");
}

int Customer::log_in(Movie *movie[5])
{
    string name, id;
    password="null";
    int password_count=0, found_password=0;

    do{
        cout<<"\n\n 請輸入使用者ID: ";
        fflush(stdin);
        cin>>member_id;
        ifstream myfile;
        myfile.open("member_detail.csv");
        found_user=0;

        while(!myfile.eof())
        {
            getline(myfile,name,',');
            getline(myfile,id,',');
            getline(myfile,password,'\n');

            fflush(stdin);
            if(member_id==id && found_user==0)
            {
                found_user++;
                cout<<"\n\n 有會員\n";
                do{
                        cout<<"\n\n 請輸入密碼: ";
                        fflush(stdin);
                        cin>>member_password;
                        if(member_password==password)
                        {
                            found_password++;
                            password_count=0;
                            cout<<"\n\n 歡迎 "<<member_id<<" 登入\n";
                            myfile.close();
                            memberid_save=member_id;
                            //break;

                        }else if(found_password==0)
                        {
                            cout<<"\n 密碼錯誤!!"<<" 剩下 "<<2-password_count<<" 機會 "<<" \n";//password_count is to count no. of attempts left
                            password_count++;
                        }
                }while(password_count<3 && password_count>0);
            }else if(myfile.eof() && found_user==0){cout<<"\n\n 會員不存在\n";}
        }
    }while(found_user==0);
    if (password_count==3){(*this).enter_system(movie);}
    return 1;
}

void Customer::make_booking(Movie movie, int i)
{
    int movie_time;
    Order *order =new Order(movie.showname, i);
    movie_time=order->choose_movie(movie_time, i);
    //system("cls");
    movie.ticket_print(order, i, movie_time);
    cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";
    cout<<"\n\t\t\t\t         1. 繼續訂票\n";
    cout<<"\n\t\t\t\t         2. 回到首頁\n";
    cout<<"\n\t\t\t\t         3. 離開系統\n";
    cin>>in;
}

