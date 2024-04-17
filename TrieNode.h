#ifndef TRIENODE_H
#define TRIENODE_H

#include <array>
#include <memory>
/**
 * Represents a single node in a Trie, which may contain multiple children.
 * Each node can potentially represent the end of a word in the Trie and can point to up to 26 other TrieNode children.
 */

class TrieNode {
public:
    bool isEndOfWord;
    std::array<std::shared_ptr<TrieNode>, 26> children;

    TrieNode();
};

#endif //TRIENODE_H
