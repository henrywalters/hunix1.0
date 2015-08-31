#ifndef HUNIX_H
#define HUNIX_H
#include <string>
#include <iostream>


class Hunix
{
    std::string username;
    std::string dir;
    public:
        Hunix();
        virtual ~Hunix();
        void bash();
        bool login();
        void settings(std::string,std::string);

    protected:
    private:
};

#endif // HUNIX_H
