//
// Created by SUDE on 4/7/2024.
//

#include "Trie.h"


Trie::Trie() : root(std::make_shared<TrieNode>()) {}

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

bool Trie::search(const std::string& word) const {
    std::shared_ptr<TrieNode> node = root;
    for (char ch : word) {
        if (!node->children[ch - 'a']) return false;
        node = node->children[ch - 'a'];
    }
    return node->isEndOfWord;
}

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
