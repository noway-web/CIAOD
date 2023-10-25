#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool checkFileExistence(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

bool createFileWithNumbers(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 1; i <= 10; ++i) {
            file << i << " "; // Записываем число и пробел после него
        }
        file.close();
        return true;
    } else {
        std::cout << "Не удалось создать файл." << std::endl;
        return false;
    }
}

void displayFileContent(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::cout << "Содержимое файла: " << line << std::endl;
        file.close();
    } else {
        std::cout << "Не удалось открыть файл." << std::endl;
    }
}

bool appendNewRecord(const std::string& filename, const std::string& record) {
    std::ofstream file(filename, std::ios_base::app);
    if (file.is_open()) {
        file << record << " "; // Добавляем запись и пробел после нее
        file.close();
        return true;
    } else {
        std::cout << "Не удалось открыть файл для добавления записи." << std::endl;
        return false;
    }
}

int readNumberByIndex(const std::string& filename, int index) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);
        int number;
        for (int i = 1; i <= index; ++i) {
            iss >> number;
        }
        file.close();
        return number;
    } else {
        std::cout << "Не удалось открыть файл." << std::endl;
        return -1;
    }
}

int countNumbersInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);
        int number, count = 0;
        while (iss >> number) {
            ++count;
        }
        file.close();
        return count;
    } else {
        std::cout << "Не удалось открыть файл." << std::endl;
        return -1;
    }
}

bool createFormattedFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int number, count = 0;
            std::vector<int> numbers;
            while (iss >> number) {
                numbers.push_back(number);
                ++count;
            }
            // Записываем количество чисел перед набором чисел
           
            // Записываем числа из исходного файла
            for (int i = 0; i < count; ++i) {
                outputFile << count - i << " ";
                outputFile << numbers[i] << " ";
                
            }
            outputFile << std::endl;
        }
        
        inputFile.close();
        outputFile.close();
        std::cout << "Новый файл успешно создан." << std::endl;
        return true;
    } else {
        std::cout << "Не удалось открыть файлы." << std::endl;
        return false;
    }
}
