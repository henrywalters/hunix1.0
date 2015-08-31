#include "CMD_Maker.h"
#include <string>

CMD_Maker::CMD_Maker()
{
    //ctor
}

CMD_Maker::~CMD_Maker()
{
    //dtor
}

void CMD_Maker::set_prefix(std::string new_pre)
{
    prefix = new_pre;
}
void CMD_Maker::set_dir(std::string new_dir)
{
    dir = new_dir;
}

void CMD_Maker::get_line()
{
    std::cout << prefix << ":~" << dir << "$ ";
    std::string line;
    std::getline(std::cin,line);
    current_cmd = line;
}

int CMD_Maker::word_count()
{
    int x = 1;
    for (int i = 1; i < current_cmd.length(); i++)
    {
        if (current_cmd[i] == ' ' && current_cmd[i-1] != ' ' && i <current_cmd.length() - 1)
        {
            x++;
        }
    }
    return x;
}

std::string * CMD_Maker::words()
{
    std::string * out;
    out = new (std::nothrow) std::string[word_count()];
    int wordStart = 0;
    int wordEnd = 0;
    int index = 0;
    for (int i = 0; i < current_cmd.length(); i++)
    {
        wordEnd++;
        if (current_cmd[i] == ' ' && current_cmd[i-1] != ' ')
        {
            out[index] = current_cmd.substr(wordStart,wordEnd-wordStart-1);
            wordStart = wordEnd;
            index++;
        }
    }
    if (index != word_count())
    {
        out[word_count() - 1] = current_cmd.substr(wordStart, current_cmd.length() - wordStart);
    }
    return out;
}





