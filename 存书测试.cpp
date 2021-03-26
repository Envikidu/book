#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "book_management.h"

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;

int main()
{
	char name[30],writer[30];
	scanf("%s%s",&name,&writer);
	
	Book a;
	a.id=1;
    a.title=name;
    a.authors=writer;
    a.year=2021;
    a.copies=1;
    
    FILE *BookStorage;
	BookStorage=fopen("BookStorageFile.txt","w+");
	if(!BookStorage)
	{
		printf("error");
		exit(-1);
	}
	
	fwrite(&a,sizeof(a),1,BookStorage);
	fclose(BookStorage);
	
	return 0;
} 


