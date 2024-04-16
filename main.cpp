#include <iostream> // std::cout için
#include "Trie.h"
#include <fstream>
#include <sstream>

int main() {
    Trie trie;
    std::ifstream dictFile("dictionary.txt");
    std::string line;

    if (dictFile.is_open()) {
        getline(dictFile, line); // İlk satırı atla
        while (getline(dictFile, line)) {
            std::cout << "Okunan kelime: " << line << std::endl;
            trie.insert(line);
        }
        dictFile.close();
    }

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");


    if (inputFile.is_open()) {
        getline(inputFile, line);
        while (getline(inputFile, line)) {
            std::cout << "Okunan komut: " << line << std::endl;
            std::istringstream iss(line);
            std::string command, word;
            iss >> command >> word;


            if (command == "search") {
                bool result = trie.search(word);
                std::cout << "Search Sonucu: " << (result ? "true" : "false") << std::endl;
                outputFile << (result ? "true" : "false") << std::endl;
            } else if (command == "prefix") {
                std::vector<std::string> words = trie.startsWith(word);
                std::cout << "Prefix Sonucu: ";
                for (const auto& w : words) {
                    std::cout << w << " ";
                    outputFile << w << " ";
                }
                std::cout << std::endl;
                outputFile << std::endl;
            }
        }
        inputFile.close();
        outputFile.close();
    }

    return 0;
}