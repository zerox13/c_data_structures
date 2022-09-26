#include "hashtable.h"

void freeValue(void *node);

int main(void){
	printf("hell\n");
	HashTable *h= hash_create();

	int* i = malloc(sizeof(int));

	*i = 1;
	hash_insert(h, "a", i);
	void* x = hash_lookup(h, "a");

	printf("%d\n", *(int*)x);
	printHashTable(h);
	hash_destroy(h, freeValue);
	return 0;
}



void freeValue(void *node){

	free((int*)node);

}

