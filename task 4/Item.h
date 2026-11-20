#pragma oncle
#include <string>


class Item
{
    private:
        std::string name_item;
        int defense;
        int HP;
        int damage;


    public:
        Item(std::string n,int g,int h,int d);

        // Описание 
        void information_Item();

        // Действия 
        

};