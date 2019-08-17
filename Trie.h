#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TRIE_CHARACTER_COUNT 28

// define the Trie structure
typedef struct Trie
{
    bool isWord;
    struct Trie *children[TRIE_CHARACTER_COUNT];
}
trie_t;

// Key function
int key_fromChar(char character);

// Trie functions
trie_t *trie_create(bool isWord);
void trie_insert(const char *word, trie_t *toTrie);
bool trie_find(const char *word, trie_t *inTrie);
void trie_destroy(trie_t *trie);

#endif
