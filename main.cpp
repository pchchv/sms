#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "data.hpp"

using namespace std;

bool findpass(string pass, string id)
{
    string pas, ag;
    bool found = false;
    std::ifstream passwords;
    passwords.open("passwords.in");
    while (!passwords.eof() && !found)
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
    return granted;
}

char menu()
{
    char option;

    cout << "Menu" << endl;
    cout << "(a) Add new property" << endl;
    cout << "(b) Remove property " << endl;
    cout << "(c) Edit sales entries" << endl;
    cout << "(d) Inquire or search property sales" << endl;
    cout << "(e) Monthly property sales transaction report" << endl;
    cout << "(f) List property sale items in ascending or descending order" << endl;
    cout << "(g) Administration - add / remove property agent" << endl;
    cout << "(h) Administration - change password" << endl;
    cout << "(i) Quit" << endl;
    cin >> option;
    return option;
}

void load(std::list<Data> l)
{
    Data datos;
    int i = 0;
    unsigned int encontro, anterior;
    std::string STRING, agentid, contact, size, roomtype, location, sellingprice;
    std::ifstream infile;
    infile.open("data.in");

    while (!infile.eof())
    {
        getline(infile, STRING); // Saves the line in STRING
        encontro = STRING.find(':', 0);
        if (encontro != std::string::npos)
        {
            agentid = STRING.substr(0, encontro);
            datos.setAgentId(agentid);
        }
        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos)
        {
            contact = STRING.substr(anterior, encontro - anterior);
            datos.setContact(contact);
        }
        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos)
        {
            size = STRING.substr(anterior, encontro - anterior);
            datos.setPropertySize(size);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior + 1);

        if (encontro != std::string::npos)
        {
            roomtype = STRING.substr(anterior, encontro - anterior);
            datos.setRoomType(roomtype);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior + 1);

        if (encontro != std::string::npos)
        {
            location = STRING.substr(anterior, encontro - anterior);
            datos.setLocation(location);
        }

        anterior = encontro + 1;
        sellingprice = STRING.substr(anterior, STRING.length() - anterior);

        datos.setSellingPrice(sellingprice);

        l.push_back(datos); // Saved each data from "data.in" to the end of the list

        i++;
    }
    infile.close();
}

int main() {}