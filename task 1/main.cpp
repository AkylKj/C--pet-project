#include <iostream>
#include <random>

int main() {
    // Генератор случайного числа
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    int secret = dist(gen);
    int number;

    while (true) {
        std::cout << "Угадайте число от 1 до 100: ";

        // Проверяем, что пользователь ввёл число
        if (!(std::cin >> number)) {
            std::cout << "Введите число, а не буквы или знаки!\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            continue;
        }

        // Проверяем диапазон
        if (number < 1 || number > 100) {
            std::cout << "Число должно быть от 1 до 100!\n";
            continue;
        }

        // Сравниваем с загаданным числом
        if (number == secret) {
            std::cout << "Вы победили!!\n";
            break;
        } 
        else if (number < secret) {
            std::cout << "Загаданное число больше. Попробуйте ещё раз.\n";
        } 
        else {
            std::cout << "Загаданное число меньше. Попробуйте ещё раз.\n";
        }
    }

    return 0;
}