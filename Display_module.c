#include "Display_module.h"
#include "book_management.h"
#include "Head_file.h"

void Display_module()
{
	FILE *display;
	display=fopen("Book_Storage.bin","r");
	if(!display)
	{
		printf("Fail to display.\n");
		return;
	}
	
	show=(Book*)malloc(sizeof(Book));
	fread(&Book_Head,sizeof(Book_Head),1,display);
	show=Book_Head->array;
	
	while(show!=NULL)
	{
		printf("%d\t",show.id);
		printf("%s\t",show->title);
		printf("%s\t",show->authors);
		printf("%d\t",show.year);
		printf("%d\n",copies);
		show=show->next;
	}
	fclose(display);
	
	return;
}
