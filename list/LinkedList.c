/**
 * Singly LinkedList.
 * 
 * 
 * @author  Abdulsalam Aldahir
 * @since   2019-9-13
 *
 */

#include "LinkedList.h"

struct lnode{
	void *value;
	struct lnode *next;
};
typedef struct lnode Lnode;

struct list{
	Lnode *root;
};



List *createList(){
	List *list = (List*)malloc(sizeof(List));
	allocErrorHandle(list);

	list->root = NULL;
	return list;
}

bool insert(List *list, void *value){
	if(list == NULL || value == NULL){
		fprintf(stderr, "Error!!\n");
		return true;
	}

	Lnode *node = (Lnode*)malloc(sizeof(Lnode));
	allocErrorHandle(node);

	node->value = value;
	node->next = list->root;
	list->root = node;
	return false;
}

void *pop(List *list){
	if(list == NULL){
		fprintf(stderr, "Error: List NULL?!\n");
	}else if( list->root == NULL){
		fprintf(stdout, "List Empty?!\n");
	}
	Lnode *node = list->root;
	void *data = node->value;
	list->root = list->root->next;
	free(node);
	return data;
}

bool isListEmpty(List *list){
	return (list->root == NULL);
}

void destroyList(List *list, void(*freeData)(void*)){
	if(list == NULL || freeData == NULL){
		fprintf(stderr, "Error: Didnt find parameters!\n");
	}

	Lnode *subList = list->root;
	Lnode *tempNode;
	while(subList != NULL){
		tempNode = subList;
		subList =subList->next;
		if(tempNode->value != NULL){
			freeData(tempNode->value);
			free(tempNode->value);
		}
		free(tempNode);
	}
	free(list);
}


void allocErrorHandle(void *p){
	if(p == NULL){
		perror("Malloc error!");
	}
}
