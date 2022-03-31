#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Customer.h"
//#include "Manager.h"
#include "Show.h"

enum choose_user {CUSTOMER=1, MANAGER};

class Order
{
private:
    std::string null;
    int number, ticket, movie_number, movie_time;
    int ticket_row[5], ticket_col[8];
    int col,letter;
    char chr;

    int choose_movie(int movie_time, int movie_number);
    void book_seat(int movie_number,int movie_time ,int number_count);

public:
    std::string movie_name;
    Order(std::string showname, int i);
    friend class Manager;
    friend class Customer;
    friend class Movie;
};

#endif // ORDER_H_INCLUDED
