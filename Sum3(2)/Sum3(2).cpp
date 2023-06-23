#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

bool isOddLengthWord(const std::string& word) {
    return word.length() % 2 != 0;
}

std::string removeMiddleLetter(const std::string& word) {
    int middleIndex = word.length() / 2;
    return word.substr(0, middleIndex) + word.substr(middleIndex + 1);
}

int main() {
    std::string inputFileName;
    std::string outputFileName;

    std::cout << "Input name input file:  ";
    std::cin >> inputFileName;

    std::cout << "Input name output file: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error vith input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error with output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string word;
        std::string processedLine;

        for (char ch : line) {
            if (std::isalpha(ch) || ch == '\'') {
                word += ch;
            }
            else {
                if (!word.empty()) {
                    if (isOddLengthWord(word)) {
                        word = removeMiddleLetter(word);
                    }
                    if (!processedLine.empty() && processedLine.back() != ' ') {
                        processedLine += ' ';
                    }
                    processedLine += word + ch;
                    word.clear();
                }
                else {
                    processedLine += ch;
                }
            }
        }

        outputFile << processedLine << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Work finish, results in the output file. " << std::endl;

    return 0;
}