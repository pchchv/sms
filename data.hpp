#ifndef data_hpp
#define data_hpp

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
    string AgentId, Contact, PropertySize, RoomType, Location, SellingPrice;

public:
    Data() : AgentId(), Contact(), PropertySize(), RoomType(), Location(), SellingPrice() {}
    Data(string AgentId, string Contact, string PropertySize, string RoomType, string Location, string SellingPrice);
    void setAgentId(string x) { this->AgentId = x; }
    void setContact(string x) { this->Contact = x; }
    void setPropertySize(string x) { this->PropertySize = x; }
    void setRoomType(string x) { this->RoomType = x; }
    void setLocation(string x) { this->Location = x; }
    void setSellingPrice(string x) { this->SellingPrice = x; }
    string getAgentId() { return this->AgentId; }
    string getContact() { return this->Contact; }
    string getPropertySice() { return this->PropertySize; }
    string getRoomType() { return this->RoomType; }
    string getLocation() { return this->Location; }
    string getSellingPrice() { return this->SellingPrice; }
    bool operator>(Data a);
    bool operator<(Data a);
};

Data::Data(string AgentId, string Contact, string PropertySize, string RoomType, string Location, string SellingPrice)
{
    this->AgentId = AgentId;
    this->Contact = Contact;
    this->PropertySize = PropertySize;
    this->RoomType = RoomType;
    this->Location = Location;
    this->SellingPrice = SellingPrice;
}

bool Data::operator>(Data a)
{
    return (SellingPrice > a.getSellingPrice()) ? true : false;
}

bool Data::operator<(Data a)
{
    return (SellingPrice < a.getSellingPrice()) ? true : false;
}

#endif