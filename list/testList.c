#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"

int main(void){
	printf("hello world\n");
	List *list = createList();

	int *data = malloc(sizeof(int));
	int *data1 = malloc(sizeof(int));
	int *data2 = malloc(sizeof(int));
	int *data3 = malloc(sizeof(int));
	int *data4 = malloc(sizeof(int));

	*data = 2;
	*data1 = 3;
	*data2 = 4;
	*data3 = 5;
	*data4 = 6;

	insert(list, (void*)data);
	insert(list, (void*)data1);
	insert(list, (void*)data2);
	insert(list, (void*)data3);
	insert(list, (void*)data4);
	
	int *datapop = (int*)pop(list);
	printf("%d\n", *datapop);

	datapop = (int*)pop(list);
	printf("%d\n", *datapop);

	datapop = (int*)pop(list);
	printf("%d\n", *datapop);

	datapop = (int*)pop(list);
	printf("%d\n", *datapop);

	datapop = (int*)pop(list);
	printf("%d\n", *datapop);

}
