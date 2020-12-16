/**
 * @author  Abdulsalam Aldahir
 * @since   2019-9-13
 * 
 * OBS: User is responsable to give a free function to free the data
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//
//
struct lnode{
	void *value;
	struct lnode *next;
};
typedef struct lnode Lnode;

struct list{
	Lnode *root;
};


typedef struct list List;

/**
 * @Description       Allocate memory for the list
 *
 * @param dataSize    The size of the object to be added.
 *                    NOTE:This is just to make sure no other
 *                    datatypes can be added.
 *
 * @return            A pointer to the list in the heap.
 *
 */
List *createList();

/**
 * @Description       Adds elemet to the list.
 *
 * @param list        The list to add to it
 * @param value       The value to be added
 *
 * @return           True if everything went well, and false if an error occur.
 *
 */
bool insert(List *list,  void *value);

void *pop(List *list);

/**
 * @Description       Free memory resources of the list .
 *
 * @param list        The list to get freed.
 * @param freeData    Function pointer to let the list
 *                    know how to free.
 *
 */
void destroyList(List *list, void(*freeData)(void*));

/**
	* @Description      Checks if a pointer is NULL, if so it calls perror()
	*                   with error Message.
	* @param p          The void pointer to be Checked
	*
**/
void allocErrorHandle(void *p);
#endif /* LINKEDLIST_H */
