#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Order.h"
#include "Show.h"
#include "Movie.h"

class Customer
{
private:
    int data_store=0, found_user=0;
    int user_in, enter, order_look, in;
    std::string user_name, password, memberid_save, member_id, member_password;
    void sign_up();
    int log_in(Movie *movie[5]);

public:
    //friend class Order;
    //friend class Movie;
    int after_look;
    void enter_system(Movie *movie[5]);
    void make_booking(Movie movie, int i);
};

#endif // CUSTOMER_H_INCLUDED
