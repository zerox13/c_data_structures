#include "hashtable.h"

struct pair{
	char *key;
	void *value;
};



struct bucket{
	struct pair *arr;        // Arrayen (utan storlek ty dynamiskt allokerad).
	int capacity;     // Storleken på arrayen.
	int size;         // Storleken på den inbäddade listan.

};



struct hashtable{
	struct bucket *buckets;    // Arrayen (utan storlek ty dynamiskt allokerad).
	int size;       // Storleken på arrayen.
	int capacity;
};


HashTable *hash_create(){
	HashTable *h = calloc(1, sizeof(struct hashtable));
	if (h == NULL){
		perror("Alloc");
	}

	h->size = 25;
	h->capacity = 0;
	h->buckets = calloc(1, h->size * sizeof(struct bucket));
	if (h->buckets == NULL){
		perror("Alloc");
	}
	return h;
}


int hash_insert (HashTable *tab, const char *key, void *value){
	int index = hash(key);
	Bucket *bucket = tab->buckets + index; 
	insertInBucket(bucket, key, value);
	tab->capacity++;
	return 0;
}


//Help function to the hash_insert()

void insertInBucket(Bucket *bucket ,const char *key, void *value){
	if(bucket->arr == NULL){
		bucket->arr = calloc(1, 10* sizeof(struct pair));
		if(bucket->arr == NULL){
			perror("Alloc");
			exit(EXIT_FAILURE);
		}

		bucket->capacity = 10;
		bucket->size = 1;
		bucket->arr[0].value = value;
		bucket->arr[0].key = (char *)key;

	}else{
		int size = bucket->size;
		int i;
		for(i = 0; i< size; i++){
			if(strcmp(bucket->arr[i].key, key) == 0){
				bucket->arr[i].value = value;
				return;
			}
		}
		if(bucket->capacity == size){
			bucket->capacity *=2;
			bucket->arr = realloc(bucket->arr, bucket->capacity);
			if(bucket->arr ==  NULL){
				printf("Error: realloc couldnt allocate memory (4)\n");
			}
		}
		bucket->arr[size].key = (char*)key;
		bucket->arr[size].value = value;
		bucket->size++;
		return;
	}
}





void *hash_lookup(HashTable *tab, const char *key){

	int index = hash(key);

	int size = tab->buckets[index].size;

	if(!size){

		printf("key not found\n");

		return NULL;

	}



	for(int i = 0; i < size; i++){

		if (strncmp(tab->buckets[index].arr[i].key, key, strlen(key))== 0){

			return tab->buckets[index].arr[i].value;

		}

	}

	return NULL;

}



//TODO: TEST that is work!

int hash_remove(HashTable *tab, const char *key){

	int i, j,  size, index = hash(key);

	Pairr *pairs;



	size = tab->buckets[index].size;

	if(!size){

		printf("key not found\n");

		return -1;

	}

	pairs = tab->buckets[index].arr;



	for(i = 0; i < size; i++){

		if (strcmp(pairs[i].key, (char *)key)== 0){

			for(j = 0; j < size-i-1; j++){

				pairs[i+j] = pairs[i+j+1];

			}

		}

	}

	tab->buckets[index].size--;



	return 0;

}



void hash_destroy (HashTable *tab, void(*freeValues)(void*)){
	int i, j;
	for(i = 0; i < tab->size; i++){
		for(j = 0; j< tab->buckets[i].size; j++){
			freeValues(tab->buckets[i].arr[j].value);
		}
		free(tab->buckets[i].arr);
	}
	free(tab->buckets);
	free(tab);
}



// Not a very good hash function, but works for now hihi :3
int hash(const char* key) {
	return (key[0] % 10);
}

/*Debugging function, print the whole hashTable*/
void printHashTable(HashTable *tab){
	int i, j;
	Bucket bucket;
	Pairr *arr;
	for(i = 0; i < tab->size; i++){
		bucket = tab->buckets[i];
		arr = bucket.arr;
		if(arr != NULL){
			for(j = 0; j < bucket.size; j++){
				printf("Bucket[%d]", i);
				printf("     KEY: %s", arr->key);
				printf("     VALUE: %d\n", *(int*)(arr + j)->value);

			}
		}
	}
}
