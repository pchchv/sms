#include <iostream>
#include <fstream>

using namespace std;

bool findpass(string pass, string id)
{
    string pas, ag;
    bool found = false;
    std::ifstream passwords;
    passwords.open("passwords.in");
    while (!passwords.eof() && !found) // To get you all the lines.
    {
        passwords >> pas >> ag;

        if (pass == pas && ag == id)
        {
            found = true;
        }
    }
    passwords.close();
    return found;
}

bool login(string agentid, string password)
{
    bool pass, granted = false;

    pass = findpass(password, agentid);
    if (pass)
    {

        cout << "access granted" << endl;
        granted = true;
    }
    else
    {
        cout << "\nLogin Failed!!\n";
    }
    return (granted);
}

int main() {}