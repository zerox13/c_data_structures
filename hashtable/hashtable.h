#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define hash_t uint8_t


/**
 * @defgroup hashtable HashTable.
 *
 * @brief hashtable of a key and a value.
 *
 * This module provides an implementation of a hashtable, the elements of
 * which are strings(keyes) and void pointer(value).
 * The hashtable is dynamically allocated and can in principle hold an
 * unlimited number of elements.
 *
 *
 * Example usage:
 *
 *     HashTable *tab = hash_create();
 *
 *     int *data = malloc(sizeof(int*));
 *     *data = 14;
 *
 *     hash_insert(tab, "abc",i);
 *     hash_lookup(tab, "abc");    //returns 14
 *     hash_destroy(s);
 *
 * @auther Abdulsalam Aldahir (dv18aar)
 * @version 3.0
 *
 * @since 2019-02-22
 * @modified 2020-08-21
 * @modified 2022-09-26
 */



typedef struct hashtable HashTable;
typedef struct bucket Bucket;
typedef struct pair Pairr;


/**
 * @brief Creates and returns an empty table.
 *
 * The function hash_destroy() should be called to free resources
 * allocated for the table.
 *
 * @return An empty table.
 * @see hash_destroy
 */
HashTable * hash_create  ();



/**
 * @brief generate an index of the key.
 *
 * @param key The key to generate the index from.
 * @see hash_insert
 */

int hash(const char *key);





/**
 * @brief Frees resources allocate for a the table.
 *
 * @param s The table to destroy.
 * @param freeValues a function to free the value of the list.
 *
 * @see hash_create
 */

void hash_destroy (HashTable *tab, void(*freeValues)(void*));





/**
 * @brief Checks if the a key is a member of the table.
 *
 * @param tab The table.
 * @param key The key to lookup.
 * @return The value of the key.
 * @see hash_insert
 */

void *hash_lookup  (HashTable *tab, const char *key);


/**
 * @brief insert a pair of a value and key to the table.
 *
 * @param tab The table.
 * @param key The key to insert.
 * @param value The value of the key to insert.
 * @see hash_lookup
 */

int hash_insert  (HashTable *tab, const char *key, void *value);
void insertInBucket(Bucket *bucket, const char *key, void *value);
int hash_remove(HashTable *tab, const char *key);
void printHashTable(HashTable *tab);

#endif /* HASHTABLE_H */

