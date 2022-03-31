#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Manager.h"

class Show
{
private:
    std::string detail_save[500];
    std::string name[100];
    std::string time[5][5];
    int cinema;

public:
    friend class Manager;
    friend class Customer;
    friend class Movie;
    friend class Order;
    int seat_print[10][100][100][5][8];
    void check_order(std::string memberid_save);
    void show_movie_from_file();
    int seat_display(int movie_number,int movie_time);
};

#endif // SHOW_H_INCLUDED
