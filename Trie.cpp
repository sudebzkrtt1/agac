//
// Created by SUDE on 4/7/2024.
//

#include "Trie.h"


Trie::Trie() : root(std::make_shared<TrieNode>()) {}
/**
 * Inserts a word into the Trie.
 * Each character of the word is checked and corresponding TrieNode is created if not already present.
 * @param word The word to be inserted into the Trie.
 */
void Trie::insert(const std::string& word) {
    std::shared_ptr<TrieNode> node = root;
    for (char ch : word) {
        if (!node->children[ch - 'a']) {
            node->children[ch - 'a'] = std::make_shared<TrieNode>();
        }
        node = node->children[ch - 'a'];
    }
    node->isEndOfWord = true;
}

/**
 * @brief Searches for a word in the trie.
 *
 * @param word The word to search within the trie.
 * @return true if the word is found, false otherwise.
 */
bool Trie::search(const std::string& word) const {
    std::shared_ptr<TrieNode> node = root;
    for (char ch : word) {
        if (!node->children[ch - 'a']) return false;
        node = node->children[ch - 'a'];
    }
    return node->isEndOfWord;
}
/**
    * @brief Finds all words in the trie that start with the given prefix.
    *
    * @param prefix The prefix to search for in the trie.
    * @return std::vector<std::string> A list of words that start with the specified prefix.
    */
std::vector<std::string> Trie::startsWith(const std::string& prefix) const {
    std::shared_ptr<TrieNode> node = root;
    std::vector<std::string> result;
    for (char ch : prefix) {
        if (!node->children[ch - 'a']) return result;
        node = node->children[ch - 'a'];
    }
    autoSuggest(node, result, prefix);
    return result;
}
/**
    * @brief Helper function to collect all words in the trie that start from the given node.
    *
    * @param node The current trie node to start searching from.
    * @param result A reference to a vector of strings to hold the resulting words.
    * @param currentPrefix The current prefix formed by the path to this node.
    */

void Trie::autoSuggest(const std::shared_ptr<TrieNode>& node, std::vector<std::string>& result, const std::string& currentPrefix) const {
    if (node->isEndOfWord) {
        result.push_back(currentPrefix);
    }

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char nextChar = 'a' + i;
            autoSuggest(node->children[i], result, currentPrefix + nextChar);
        }
    }
}
