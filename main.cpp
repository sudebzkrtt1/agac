#include <iostream>
#include "Trie.h"
#include <fstream>
#include <sstream>

/**
 * Main application entry point for the Trie-based dictionary search program.
 * It loads words from a dictionary file into a Trie structure, then processes commands from an input file
 * to search words and prefixes, outputting results to an output file.
 */
int main() {
    Trie trie;
    std::ifstream dictFile("dictionary.txt");
    std::string line;

    if (dictFile.is_open()) {
        getline(dictFile, line);
        while (getline(dictFile, line)) {

            trie.insert(line);
        }
        dictFile.close();
    }

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");


    if (inputFile.is_open()) {
        getline(inputFile, line);
        while (getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string command, word;
            iss >> command >> word;


            if (command == "search") {
                bool result = trie.search(word);
                outputFile << (result ? "true" : "false") << std::endl;
            } else if (command == "prefix") {
                std::vector<std::string> words = trie.startsWith(word);
                for (const auto& w : words) {
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