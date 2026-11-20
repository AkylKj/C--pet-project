#include <Player.h>
#include <string>
#include <iostream>

Player::Player(std::string n, int d, int h)
{
    name = n;
    damage = d;
    health = h;
};

void Player::heal(int amount)
{
    health = health + amount;
}

void Player::takeDamage(int amount)
{
    health = health - amount;
}

bool Player::isAlive()
{
    return health > 0;
}


void Player::playerInformation()
{
    std::cout << "Имя: " << name << std::endl;
    std::cout << "ХП: " << health << std::endl;
    std::cout << "Урон: " << damage << std::endl;
}