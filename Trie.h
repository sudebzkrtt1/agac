#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <vector>
/**
 * A Trie data structure class for fast word searching and prefix matching.
 * It provides methods to insert words, search for a word, and find all words starting with a given prefix.
 */
class Trie {
private:
    std::shared_ptr<TrieNode> root;

public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word) const;
    std::vector<std::string> startsWith(const std::string& prefix) const;
private:
    void autoSuggest(const std::shared_ptr<TrieNode>& node, std::vector<std::string>& result, const std::string& currentPrefix) const;
};

#endif //TRIE_H
