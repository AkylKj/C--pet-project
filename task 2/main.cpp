#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void showMenu()
{
    cout << "\n===== БАНКОМАТ =====\n";
    cout << "1. Посмотреть баланс\n";
    cout << "2. Пополнить баланс\n";
    cout << "3. Снять деньги\n";
    cout << "4. История Транзакций\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

void withdrawMoney(double& balance, vector<string>& history)
{
    double amount;
    cout << "Какую сумму вы хотите снять?: ";
    cin >> amount;
    

    if (amount <= 0){
        cout << "Сумма должна быть больше нуля!";
        return;
    }
    
    if (amount > balance){

        cout << "У вас недостаточо средств на балансе";
        return;
    }

    balance -= amount;
    string operation = "Снятие: " + to_string (amount);
    history.push_back(operation);
    

}

void depositMoney(double& balance, vector<string>& history)
{
    double amount;

    cout << "На какую сумму вы хотите пополнить баланс?: ";
    cin >> amount;

    if (amount <= 0){
        cout << "Введите сумму больше нуля!";
        return;
    }
    
    balance += amount;
    string operation = "Пополнение: " + to_string (amount);
    history.push_back(operation);

}

void showHistory(const vector<string>& history)
{
 for (int i = 0; i < history.size(); i++)
    {
    cout << history[i] << endl;
    }
}

void saveFiles(double balance, vector<string> history)
{

}

int main(){

    // pin_code
    //int pin_code = 1234;
    //int MaxAtteps = 4; 

    double balance = 1000;
    
    // choose
    int choose;
    vector<string>history;

    while (choose != 0)
    {
        
        // balance
        showMenu();
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Ваш баланс:" << balance << endl;
            break;
        
        case 2:
            depositMoney(balance, history);
            break;

        case 3:  
            withdrawMoney(balance, history);
            break;
        case 4:
            showHistory(history);
            break;
        
        case 0:
            break;

        default:
            cout << "Неверный ввод!!";
            break;
        }

    }
}