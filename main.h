#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Manager.h"
#include "Order.h"
#include "Movie.h"

#define USER_INTER {cout<<"================================================================================"<<endl;\
                    cout<<"\n\n\n\n\n\t\t\t 請選擇操作: ";\
                    cout<<"\n\t\t\t\t\t 1. 訂票系統\n";\
                    cout<<"\n\t\t\t\t\t 2. 管理系統\n";\
                    cout<<"\n\t\t\t\t\t 3. 離開系統 ";\
                    cout<<"\n\n\n\n\n\n";\
                    cout<<"================================================================================"<<endl;}

#define LEAVE_SYSTEM 3
#endif // MAIN_H_INCLUDED
