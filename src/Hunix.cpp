#include "Hunix.h"
#include "HaSql.h"
#include "CMD_Maker.h"
using namespace std;

Hunix::Hunix()
{
    //ctor
}

Hunix::~Hunix()
{
    //dtor
}

bool Hunix::login()
{
    HaSql db;
    db.db_open("userbase");
    cout << "1.) login\n2.) register\n";
    bool valid = false;
    int input;
    while (!valid)
    {
        cout << "input: ";
        cin >> input;
        if (input != 1 && input != 2)
        {
            cout << "invalid input\n";
        }
        else { valid = true; }
    }
    if (input == 2)
    {
        db.db_enter_row();
        return false;
    }
    else
    {
        cout << "Username: ";
        string user,pass;
        cin >> user;
        cout << "password: ";
        cin >> pass;
        string * match = db.select("username",user);

        if (match[0] == user + " " + pass + " ")
        {

            cout << "Access granted\nwilkommen " + user << "\n";
            settings("",user);
            return true;

        }
        else { cout << "Acess Denied\n"; }

    }
    return false;

}

void Hunix::settings(string direc, string user)
{
    dir = direc;
    username = user;
}

void Hunix::bash()
{
    CMD_Maker cmdline;

    string prefix = username + "@HunixEnv";

    bool running = true;
    while (running)
    {
        cmdline.set_dir(dir);
        cmdline.set_prefix(prefix);
        cmdline.get_line();
        string * words = cmdline.words();
        int word_count = cmdline.word_count();

        if (word_count == 1 && words[0] == "hasql")
        {
            HaSql db;
            db.hasql_cmdln();
        }
        else if (words[0] == "mkdir" && word_count == 2)
        {
            HaSql dirs;
            dirs.db_open("dir_box");
            string * existing = dirs.select("dir",words[1]);
            if (words[1] + " " != existing[0]){
                string box[1] = { words[1] };
                dirs.db_enter_row_array(box);
            }
            else { cout << "dir already exists\n"; }
        }
        else if (words[0] == "cd" && word_count == 2)
        {
            HaSql dirs;
            dirs.db_open("dir_box");
            string * existing = dirs.select("dir",words[1]);
            if (words[1] + " " == existing[0]){
                settings(words[1], username);
            }
            else if (words[1] == "~/") { settings("",username); }
            else { cout << "directory does not exist\n"; }
        }
        else if (words[0] == "ls" && word_count == 1)
        {
            HaSql dirs;
            dirs.db_open("dir_box");
            dirs.ls();
        }
    }

}
