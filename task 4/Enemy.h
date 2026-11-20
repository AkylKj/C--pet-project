#pragma once
#include <string>

class Enemy 
{
    private:
        std::string name;
        int health;
        int damage;
        int XP;

    public:
        Enemy(std::string n, int h, int d, int x);

        // Действия
        void showInformation();
        void takeDAmage(int amount);
        // Состояние
        bool isAlive();
        void experienceReward();


};