#ifndef CMD_MAKER_H
#define CMD_MAKER_H
#include <string>
#include <iostream>

class CMD_Maker
{
    std::string prefix = "";
    std::string dir = "";
    std::string current_cmd = "";
    public:
        CMD_Maker();
        virtual ~CMD_Maker();
        void set_prefix(std::string);
        void set_dir(std::string);
        void get_line();
        int word_count();
        std::string * words();
    protected:
    private:
};

#endif // CMD_MAKER_H
