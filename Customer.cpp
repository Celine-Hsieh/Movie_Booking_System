#include "Customer.h"

using namespace std;

void Customer::enter_system(Movie *movie[5])
{
    //system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
    cout<<"\n\t\t\t\t\t 1. ���U�|��\n";
    cout<<"\n\t\t\t\t\t 2. �n�J�|��\n";
    cout<<"\n\t\t\t\t\t 3. �^�W�@��\n";
    cout<<"\n\n\n\n\n\n";
    cout<<"================================================================================"<<endl;
    cin>>user_in;

    if(user_in==1){(*this).sign_up();}
    else if(user_in==2)
    {
        system("cls");
        cout<<"================================================================================"<<endl;
        cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"\n\n\n\n\t\t\t �w��n�J�|��!!!\n";
        enter=(*this).log_in(movie);
    }

    if(enter!=0||data_store!=0)
    {
        cout<<"================================================================================"<<endl;
        cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
        cout<<"\n\t\t\t         1. �d�߭q��\n";
        cout<<"\n\t\t\t         2. �w�q�q�v\n";
        cout<<"\n\t\t\t         3. �^�W�@��\n";
        cout<<"\n\n\n\n\n\n";
        cout<<"================================================================================"<<endl;
        cin>>order_look;

        Show show;
        if(order_look ==1)
        {
            show.check_order(memberid_save);
            cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
            cout<<"\n\t\t\t         1. �w�q�q�v\n";
            cout<<"\n\t\t\t         2. �^����\n";
            cout<<"\n\t\t\t         3. ���}�t��\n";
            cout<<"\n\n\n\n\n\n";
            cin>>after_look;

        }else if(order_look==2 || after_look==1)
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
        }else if(order_look==3)
        {
            (*this).enter_system(movie);
        }else
        {
            cout<<"\n\n ��J�L��! �^�쭺��\n";
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
    cout<<"                              �w��ϥμv���ʲ��t��                              "<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\n\n\n\t\t\t\t �п�J�m�W: ";
    fflush(stdin);
    getline(cin,user_name);
    cout<<"\n\t\t\t\t �п�J�ϥΪ�ID: ";
    fflush(stdin);
    getline(cin,user_id);
    cout<<"\n\t\t\t\t �п�J�ϥΪ̱K�X: ";
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
        cout<<"\n\n �п�J�ϥΪ�ID: ";
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
                cout<<"\n\n ���|��\n";
                do{
                        cout<<"\n\n �п�J�K�X: ";
                        fflush(stdin);
                        cin>>member_password;
                        if(member_password==password)
                        {
                            found_password++;
                            password_count=0;
                            cout<<"\n\n �w�� "<<member_id<<" �n�J\n";
                            myfile.close();
                            memberid_save=member_id;
                            //break;

                        }else if(found_password==0)
                        {
                            cout<<"\n �K�X���~!!"<<" �ѤU "<<2-password_count<<" ���| "<<" \n";//password_count is to count no. of attempts left
                            password_count++;
                        }
                }while(password_count<3 && password_count>0);
            }else if(myfile.eof() && found_user==0){cout<<"\n\n �|�����s�b\n";}
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
    cout<<"\n\n\n\n\n\t\t\t �п�ܾާ@: ";
    cout<<"\n\t\t\t\t         1. �~��q��\n";
    cout<<"\n\t\t\t\t         2. �^�쭺��\n";
    cout<<"\n\t\t\t\t         3. ���}�t��\n";
    cin>>in;
}

