#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string n, int h, int d, int x)
{
    name = n;
    health = h;
    damage = d;
    XP = x;
}

void Enemy::showInformation()
{
    std::cout << "Враг: " << name << std::endl;
    std::cout << "HP: " << health << std::endl;
    std::cout << "Урон: " << damage << std::endl;
    std::cout << "XP за убийство: " << XP << std::endl;
}

void Enemy::takeDAmage(int amount)
{
    health = health - amount;
}

bool Enemy::isAlive()
{
    return health > 0;
};

void Enemy::experienceReward()
{
    std::cout << "Полученно опыта :" << XP << std::endl;
};








