#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Order.h"
#include "Customer.h"

class Movie
{
private:
    std::string showname;
    int number;

public:
    Movie (std::string name);
    //friend class Order;
    friend class Manager;
    friend class Customer;
    void addLinkToOrder(class Order *order, int movie_number, int movie_time);
    void ticket_print(class Order *order, int movie_number, int movie_time);
};
#endif // MOVIE_H_INCLUDED
