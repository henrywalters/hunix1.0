#include <iostream>
#include <HaSql.h>
#include <CMD_Maker.h>
#include <Hunix.h>
using namespace std;



int main()
{
    Hunix hu;
    bool logged_in = false;
    while (logged_in == false)
    {
        logged_in = hu.login();
    }
    hu.bash();
    return 0;
}
