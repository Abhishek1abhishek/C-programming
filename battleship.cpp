#include <iostream>
#include "battleship.hpp"
#include <ctime>

using namespace std;

void deploy(Ship my_array[])
{
    int number_of_deployed_ship = 0;
    while (number_of_deployed_ship != 8)
    {
        Location pick_variables = pick();
        if (check(my_array, pick_variables) != -1)
        {
            continue;
        }
        else
        {
            Ship new_ship;
            new_ship.loc = pick_variables;
            new_ship.sunk = false;
            my_array[number_of_deployed_ship] = new_ship;
            number_of_deployed_ship += 1;
        }
    }
}

Location pick()
{
    srand(time(nullptr));
    Location loc;
    loc.x = rand() % 6 + 1;
    int character = rand() % 6 + 1;
    switch (character)
    {
    case 1:
        loc.y = 'a';
        break;
    case 2:
        loc.y = 'b';
        break;
    case 3:
        loc.y = 'c';
        break;
    case 4:
        loc.y = 'd';
        break;
    case 5:
        loc.y = 'e';
        break;
    case 6:
        loc.y = 'f';
        break;
    }
    return loc;
}

int check(const Ship my_array[], const Location &pick_location)
{
    for (int i = 0; i <= 8; ++i)
    {
        if (my_array[i].loc.x == pick_location.x && my_array[i].loc.y == pick_location.y)
        {
            return i;
        }
    }
    return -1;
}

bool match(const Ship &my_array, const Location &pick_location)
{
    if (my_array.loc.x == pick_location.x && my_array.loc.y == pick_location.y)
    {
        return true;
    }
    return false;
}