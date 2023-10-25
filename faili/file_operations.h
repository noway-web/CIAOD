// file_operations.h

#pragma once
#include <string>
#include <vector>


bool checkFileExistence(const std::string& filename);
bool createFileWithNumbers(const std::string& filename);
void displayFileContent(const std::string& filename);
bool appendNewRecord(const std::string& filename, const std::string& record);
int readNumberByIndex(const std::string& filename, int index);
int countNumbersInFile(const std::string& filename);
bool createFormattedFile(const std::string& inputFilename, const std::string& outputFilename);
