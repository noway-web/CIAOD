#include <iostream>
#include "file_operations.h"

int main() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    if (checkFileExistence(filename)) {
        std::cout << "Файл существует и открыт успешно." << std::endl;

        // Создание файла с числами и добавление новой записи
        createFileWithNumbers(filename);
        appendNewRecord(filename, "42");

        // Отображение содержимого файла
        std::cout << "Содержимое файла:" << std::endl;
        displayFileContent(filename);

        // Чтение числа по порядковому номеру
        int index;
        std::cout << "Введите порядковый номер числа для чтения: ";
        std::cin >> index;
        int number = readNumberByIndex(filename, index);
        if (number != -1) {
            std::cout << "Число по указанному индексу: " << number << std::endl;
        }

        // Определение количества чисел в файле
        int count = countNumbersInFile(filename);
        if (count != -1) {
            std::cout << "Количество чисел в файле: " << count << std::endl;
        }

        // Создание форматированного файла
        if (createFormattedFile(filename, "output.txt")) {
            std::cout << "Новый файл успешно создан." << std::endl;
        } else {
            std::cout << "Не удалось создать новый файл." << std::endl;
        }
    } else {
        std::cout << "Файл не существует или не может быть открыт." << std::endl;
    }

    return 0;
}
