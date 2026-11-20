#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

// ------------------------------------------------------------------

void showMenu()
{
    cout << "\n1. Посмотреть книги\n";
    cout << "2. Загрузить книгу\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

// ------------------------------------------------------------------

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y)
    {
        title = t;
        author = a;
        year = y;
    }

    void showInformation()
    {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год: " << year << endl;
        cout << endl;
    }
};

// ------------------------------------------------------------------

int main()
{
    vector<Book> books;

    books.push_back(Book("1984", "George Orwell", 1949));
    books.push_back(Book("Dune", "Frank Herbert", 1965));
    books.push_back(Book("Prikol", "Zaglot VAndam", 1488));
    books.push_back(Book("GOVNOED", "dve bashni", 2001));
    books.push_back(Book("dadadad", "hehehehhee", 1));

    int choosi = -1;

    while (choosi != 0)
    {
        showMenu();
        cin >> choosi;

        switch (choosi)
        {
        case 1:
        {
            for (size_t i = 0; i < books.size(); i++)
            {
                books[i].showInformation();
            }

            break;
        }

        case 2:
        {
            string title;
            string author;
            int year;

            // Удаляем \n, который остался после cin >> choosi
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Введите название книги: ";
            getline(cin, title);

            cout << "Введите автора книги: ";
            getline(cin, author);

            cout << "Введите год книги: ";
            cin >> year;

            // Создаём объект Book
            Book newBook(title, author, year);

            // Добавляем объект в vector
            books.push_back(newBook);

            cout << "Книга добавлена!\n";

            break;
        }

        case 0:
        {
            cout << "Выход из программы.\n";
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