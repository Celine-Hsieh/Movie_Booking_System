#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Order.h"
#include "Movie.h"
#include "Show.h"

class Manager
{
private:
    int in;
    int order_look;
    int password_count=0;
    int star=0;
    std::string password;

public:
    int after_look;
    void enter_system(class Movie *movie[5]);
    void password_proctect();
    void manager(Movie *movie[5]);
    void make_booking(Movie movie, int i);
};

#endif // MANAGER_H_INCLUDED
