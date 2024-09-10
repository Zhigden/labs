#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Создаем текстовый файл с произвольным числом строк
    ofstream outFile("random.txt");
    int numLines;
    cout << "Введите количество строк: ";
    cin >> numLines;
    cin.ignore();

    for (int i = 0; i < numLines; i++) {
        string line;
        getline(cin, line);
        outFile << line << endl;
    }

    outFile.close();

    // Находим самую длинную строку
    ifstream inFile("random.txt");
    string longestLine;
    int maxLength = 0;

    // Меняем местами первое и последнее слово в самой длинной строке
    int firstSpace = longestLine.find(' ');
    int lastSpace = longestLine.rfind(' ');

    string firstWord = longestLine.substr(0, firstSpace);
    string lastWord = longestLine.substr(lastSpace + 1);

    longestLine.replace(0, firstSpace, lastWord);
    longestLine.replace(lastSpace + 1, lastWord.length(), firstWord);

    // Записываем измененную строку в новый файл
    ofstream outFile2("output.txt");
    outFile2 << longestLine << endl;
    outFile2.close();

    cout << "Самая длинная строка с поменянными местами первым и последним словом сохранена в файле output.txt" << endl;

    return 0;
}