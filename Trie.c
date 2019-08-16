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
    // TODO: Implement the find function
}

void trie_insert(const char *word, trie_t *toTrie)
{
    // TODO: Implement the insertion function
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
