#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    int UDC;
    string author;
    string title;
    int year;
    int count;

};

vector<Book> books;

void addBook() {

    Book book;
    setlocale(LC_ALL, "RU");
    cout << "Введите номер УДК: ";
    cin >> book.UDC;

    cout << "Введите фамилию и инициалы автора: ";
    cin.ignore();
    getline(cin, book.author);

    cout << "Введите название книги: ";
    getline(cin, book.title);

    cout << "Введите год издания: ";
    cin >> book.year;

    cout << "Введите количество экземпляров книги в библиотеке: ";
    cin >> book.count;

    books.push_back(book);
}

void removeBook() {
    int UDC;
    setlocale(LC_ALL, "RU");

    cout << "Введите номер УДК книги, которую хотите удалить: ";
    cin >> UDC;

    for (vector<Book>::iterator it = books.begin(); it != books.end(); it++) {
        if (it->UDC == UDC) {
            books.erase(it);
            cout << "Книга удалена" << endl;
            return;
        }
    }

    cout << "Книга с таким номером УДК не найдена" << endl;
}

void searchBook() {
    string title;

    setlocale(LC_ALL, "RU");
    cout << "Введите название книги, которую хотите найти: ";
    cin.ignore();
    getline(cin, title);

    for (Book book : books) {
        if (book.title == title) {
            cout << "Книга найдена:" << endl;
            cout << "Номер УДК: " << book.UDC << endl;
            cout << "Автор: " << book.author << endl;
            cout << "Название: " << book.title << endl;
            cout << "Год издания: " << book.year << endl;
            cout << "Количество экземпляров в библиотеке: " << book.count << endl;
            return;
        }
    }

    cout << "Книга с таким названием не найдена" << endl;
}

void printBooks() {
    setlocale(LC_ALL, "RU");
    cout << "Список книг:" << endl;
    for (Book book : books) {
        cout << "Номер УДК: " << book.UDC << endl;
        cout << "Автор: " << book.author << endl;
        cout << "Название: " << book.title << endl;
        cout << "Год издания: " << book.year << endl;
        cout << "Количество экземпляров в библиотеке: " << book.count << endl;
        cout << endl;
    }
}

int main() {
    int choice;
    setlocale(LC_ALL, "RU");
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Удалить книгу" << endl;
        cout << "3. Найти книгу по названию" << endl;
        cout << "4. Вывести список всех книг" << endl;
        cout << "5. Выход" << endl;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            printBooks();
            break;
        case 5:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }

    return 0;
}