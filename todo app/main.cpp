#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;


void ShowMenu(){
    cout << "1. Добавить задачу\n";
    cout << "2. Показать задачи\n";
    cout << "3. Выполнить задачу\n";
    cout << "4. Удалить задачу\n";
    cout << "5. Сохранить задачи\n";
    cout << "0. Выход\n";

}

struct Task
{
    int id;
    string title;
    bool completed;
};

void AddTask(vector<Task>& tasks, int id) {
    Task task;

    task.id = id;
    task.completed = false;

    cout << "Введите название задачи: ";
    getline(cin >> ws, task.title);

    tasks.push_back(task);

    cout << "Задача успешно добавлена!\n";
}

void ShowTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Список задач пуст.\n";
        return;
    }

    cout << "Список задач:\n";
    for (const auto& task : tasks) {
        cout << "ID: " << task.id << ", Название: " << task.title
             << ", Выполнена: " << (task.completed ? "Да" : "Нет") << endl;
    }
}

void CompleteTask(vector<Task>& tasks, int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Задача с ID " << id << " помечена как выполненная.\n";
            return;
        }
    }
    cout << "Задача с ID " << id << " не найдена.\n";
}


void Deletetask(vector<Task>& tasks, int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Задача с ID " << id << " удалена.\n";
            return;
        }
    }
    cout << "Задача с ID " << id << " не найдена.\n";
}

void SaveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для сохранения задач.\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.id << "," << task.title << "," << task.completed << endl;
    }

    cout << "Задачи успешно сохранены в файл " << filename << ".\n";
}


int main(){

    vector<Task> tasks;
    int nextId = 1;

    int choise = -1;

    while (choise != 0)
    {
        ShowMenu();
        cin >> choise;

        switch (choise)
        {
            case 1:
            {
                cout << "Добавление задачи\n";
                AddTask(tasks, nextId++);
                break;
            }

            case 2:
            {
                cout << "Показать задачи\n";
                ShowTasks(tasks);
                break;
            }

            case 3:
            {
                cout << "Выполнить задачу\n";
                int id;
                cout << "Введите ID задачи: ";
                cin >> id;
                CompleteTask(tasks, id);
                break;
            }

            case 4:
            {
                cout << "Удалить задачу\n";
                int id;
                cout << "Введите ID задачи: ";
                cin >> id;
                Deletetask(tasks, id);
                break;
            }

            case 5:
            {
                cout << "Сохранить задачи\n";
                SaveTasks(tasks, "tasks.txt");
                break;
            }

            case 0:
            {
                cout << "Выход из приложения.\n";
                break;
            }

        }
    }
    return 0;
}