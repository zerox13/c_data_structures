#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"

int main(void){
	printf("Test LinkedList\n\n");

	printf("Creating a list..\n");
	List *list = createList();
	printf("Testing if list is empty ----> ");
	if(isListEmpty(list)){
		printf("CORRECT! List is empty!!\n");
	}else{
		printf("ERROR! SOMETHING IS WRONG!\n");
	}

	int nrOfData = 5;



	printf("\n\nCreateing %d nodes\n", nrOfData);
	for(int i = 0; i<nrOfData; i++){
		int *data = malloc(sizeof(int));
		*data = i;
		insert(list, (void*)data);
	}


	
	printf("Testing if they are the same ---> ");
	for(int i = nrOfData -1; i >= 0; i--){
		int *datapop = (int*)pop(list);
		if(*datapop != i){
			printf("Something is wrong!!!!!\n");
		}
	}

	printf("Everything is correct!!\n\n");

}
