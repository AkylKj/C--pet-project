#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>


using namespace std;

// ------------------------------------------------------------------

void ShowMenu()
{
    cout << "\n1. Показать персонажа\n";
    cout << "2. Инвентарь\n";
    cout << "3. Исследовать мир\n";
    cout << "4. Начать бой\n";
    cout << "5. Магазин\n";
    cout << "6. Сохранить игру\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

// ------------------------------------------------------------------

class Player
{
private:
    string name;
    int health;
    int damage;

public:
    Player(string n, int h, int d)
    {
        name = n;
        health = h;
        damage = d;
    }

    void Heal(int amount)
    {
        health = health + amount;
    }

    void takeDamage(int amount)
    {
        health = health - amount;

        cout << name
             << " получает "
             << amount
             << " урона!"
             << endl;
    }

    bool isAlive()
    {
        return health > 0;
    }

    int getDamage()
    {
        return damage;
    }

    void playerInformation()
    {
        cout << "Ваше имя: " << name << endl;
        cout << "Ваше HP: " << health << endl;
        cout << "Ваш DMG: " << damage << endl;
    }
};



// ------------------------------------------------------------------

class Enemy
{
private:
    string name;
    int health;
    int damage;
    int XP;

public:
    Enemy(string n, int h, int d, int x)
    {
        name = n;
        health = h;
        damage = d;
        XP = x;
    }

    void takeDamage(int amount)
    {
        health = health - amount;

        cout << name
             << " получает "
             << amount
             << " урона!"
             << endl;
    }

    bool isAlive()
    {
        return health > 0;
    }

    int getDamage()
    {
        return damage;
    }

    void showInformation()
    {
        cout << "Враг: " << name << endl;
        cout << "HP: " << health << endl;
        cout << "DMG: " << damage << endl;
    }

    void experienceReward()
    {
        cout << "Получено опыта: " << XP << endl;
    }
};


void Battle (Player & player, Enemy & enemy){
    while(player.isAlive() && enemy.isAlive()){
        int battleChooice;

        cout << "1. Атаковать\n";
        cout << "2. Лечиться\n";
        cout << "3. Бежать";

        cin >> battleChooice;

        if (battleChooice == 1){
            enemy.takeDamage(player.getDamage());
        }
        else if (battleChooice == 2){
            player.Heal(10);
            cout << "Вы восстановились на 10 HP ";
        }

        else if (battleChooice == 3){
            cout << "Вы убежали...";
            break;
        }

        else {
            cout << "Такой команды нету...";
        }

        if (!enemy.isAlive()){
            cout << "Враг побеждён!!!";
            enemy.experienceReward();
            break;
        }

        player.takeDamage(enemy.getDamage());

        if (!player.isAlive()){
            cout << "Вы погибли...";
            break;
        }
    }
}

class Item 
{
    private:
    
    string name;
    int damage;
    int cost;



    public: 
};

// ------------------------------------------------------------------

int main()
{
    Player player("Hero", 100, 15);

    int chooise = -1;

    while (chooise != 0)
    {
        ShowMenu();
        cin >> chooise;

        switch (chooise)
        {
        case 1:
        {
            player.playerInformation();
            break;
        }

        case 2:
        {
            cout << "Инвентарь пока пуст.\n";
            break;
        }

        case 3:
        {
            cout << "Вы исследуете мир...\n";
            break;
        }

        case 4:
        {
            Enemy enemy("Goblin", 50, 8, 25);
            Battle(player, enemy);
            break;
        }

        case 5:
        {
            cout << "Магазин пока не реализован.\n";
            break;
        }

        case 6:
        {
            cout << "Сохранение пока не реализовано.\n";
            break;
        }

        case 0:
        {
            cout << "Выход из игры.\n";
            break;
        }

        default:
        {
            cout << "Неизвестная команда.\n";
            break;
        }
        }
    }

    return 0;
}