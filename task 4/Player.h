#pragma once 
#include <string>

class Player 
{
    private:
       std::string name;
        int damage;
        int health;

    public:
        Player(std::string n, int d, int h);

        // Действия
        void attack();
        void heal(int amount);
        void takeDamage(int amount);

        // Статус
        bool isAlive();
        void playerInformation();

};