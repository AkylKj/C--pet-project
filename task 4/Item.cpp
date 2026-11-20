#include <Item.h>
#include <string>

Item::Item(std::string n,int g,int h,int d)
{
    name = n;
    defense = g;
    HP = h;
    damage = d;
};