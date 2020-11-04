// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;
//cheat way to count words as we load nodes
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //gets key of the word
    int key = hash(word);

    //temp node pointing to first value in hash table at key
    node *temp_ptr = table[key];

    while (temp_ptr != NULL)
    {
        //if 0 words match, strcasecmp compares words irrespective on case
        if (strcasecmp(temp_ptr->word, word) == 0)
        {
            return true;
        }
        //sets temp_ptr to the next pointer in the linked list
        temp_ptr = temp_ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;
    //loops over word until null term char
    for (int i = 0; word[i] != '\0'; i++)
    {
        value += tolower(word[i]);
    }

    return value % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opens file for read only and checks if opened correctly
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        return false;
    }
    //max word size + 1 for '\0'
    char word[LENGTH + 1];

    //reads one word at a time, EOF returned at end of file
    while (fscanf(dict_file, "%s", word) != EOF)
    {
        //allocates memory to word_node pointer
        node *word_node = malloc(sizeof(node));
        if (word_node == NULL)
        {
            //NULL == out of memory
            return false;
        }
        //adds word to the word portion of our node
        strcpy(word_node->word, word);

        //creates a key for our word - Hash table
        int key = hash(word);

        if (table[key] == NULL)
        {
            //if there is nothing in the hast table that that key set next to Null and add it to the table
            word_node->next = NULL;
            table[key] = word_node;
        }
        else
        {
            //if table has something at index of key, we add new node to the front and point the new node to the old first node
            word_node->next = table[key];
            table[key] = word_node;
        }
        word_count++;
    }
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];

        while (tmp != NULL)
        {
            //grab pointer for next node and free previous node
            node *to_be_freed = tmp;
            tmp = tmp->next;
            free(to_be_freed);
        }
        //nulls out the row in the hash table
        table[i] = NULL;
    }
    return true;
}
