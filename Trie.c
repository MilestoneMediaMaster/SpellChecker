#include "Trie.h"

// MARK: Key Function

int key_fromChar(char character)
{
    char c = tolower(character);

    // allow only characters between A-Z (and a couple of notable characters)
    if (!((c >= 'a' && c <= 'z') || c == '\'' || c == '-'))
        return -1;

    switch (c)
    {
        case '-':
            return 26;
            break;

        case '\'':
            return 27;
            break;

        default:
            // this results in a value between 0 - 25, where "a" = 0 and "z" = 25
            return abs('a' - c);
            break;
    }
}

// MARK: Trie Functions

trie_t *trie_create(bool isWord)
{
    trie_t *trie_node = malloc(sizeof(trie_t));

    if (trie_node != NULL)
    {
        trie_node->isWord = isWord;

        // set all of our newly-initialised Trie node's children to NULL
        for (int i = 0; i < TRIE_CHARACTER_COUNT; ++ i)
            trie_node->children[i] = NULL;
    }

    return trie_node;
}

bool trie_find(const char *word, trie_t *inTrie)
{
    trie_t *pointer = inTrie;

    int index = 0;
    int length = strlen(word);

    while (index < length && pointer != NULL)
    {
        int key = key_fromChar(word[index]);
        index ++;

        // skip invalid characters
        if (key == -1) continue;

        // If we can't descend any further, it's not a valid word
        if (pointer->children[key] != NULL)
            pointer = pointer->children[key];
        else return false;
    }

    return pointer->isWord;
}

void trie_insert(const char *word, trie_t *toTrie)
{
    trie_t *pointer = toTrie;

    int length = strlen(word);

    for (int i = 0; i < length; ++ i )
    {
        const int key = key_fromChar(word[i]);

        if (key == -1) continue;

        // if the child node doesn't exist, create it
        if (pointer->children[key] == NULL)
            pointer->children[key] = trie_create(false);

        // go deeper in the pathway
        pointer = pointer->children[key];
    }

    // the last node in this path acts as a marker to denote that this is a valid word
    pointer->isWord = true;
}

void trie_destroy(trie_t *trie)
{
    // guard against NULL releases
    if (trie == NULL)
        return;

    // destroy all nodes in this pathway
    for (int i = 0; i < TRIE_CHARACTER_COUNT; ++ i)
        if (trie->children[i] != NULL)
            trie_destroy(trie->children[i]);

    // release the allocation used by this node
    free(trie);
}
