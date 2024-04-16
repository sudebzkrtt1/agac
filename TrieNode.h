#ifndef TRIENODE_H
#define TRIENODE_H

#include <array>
#include <memory>

class TrieNode {
public:
    bool isEndOfWord;
    std::array<std::shared_ptr<TrieNode>, 26> children;

    TrieNode();
};

#endif //TRIENODE_H
