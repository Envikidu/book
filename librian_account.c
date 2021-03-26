#include "book_management.h"
#include "interface.h"
#include "librian.h"
#include "display_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteNode(B) free((void *B))


int store_books(FILE *file)
{
	search_book=(Book*)malloc(sizeof(Book));
	FILE *add;
	add=fopen("Book_Storage.bin","r");
	
	
	if(!file);
	{
		printf("error!\n");
		return;
	}
	

	
	while(1)
	{
		printf("Please enter ID of the book that you want to add:\n");
	    printf("(An 8-digit sequence of numbers)\n");
	    gets(book_id);
	    
	    if (strspn(book_id,"0123456789")!=strlen(book_id))
	    {
	    	printf("Only numbers are valid characters,please reenter/n");
	    	continue;
		}
		
		int i=0;
		for(i;book_id[i]!='\0';i++);
		if(i>8)
		{
			printf("Book ID is too long,please reenter:\n");
			continue;
		}
		
		if(i<8)
		{
			printf("Book ID is too short,please reenter:\n");
			continue;
		}
		
		fread(&Book_Head,sizeof(Book_Head),1,file);
		search_book=Book_Head->array;
		id_pointer=book_id;
		id_number=atoi(id_pointer);
		
		while(search_book!=NULL)
		{
			if(id_number==search_book.id)
			{
				new_book_flag=1;
				printf("The book is already in library.\n");
				printf("Book ID\t");
				printf("Book title\t");
				printf("Authors\t");
				printf("Release year\t");
				printf("Copies number\n");
				
				printf("%d\t",search_book.id);
				printf("%s\t",search_book->title);
				printf("%s\t",search_book->authors);
				printf("%d\t",search_book.year);
				printf("%d\n",search_book.copies);
				printf("Please enter the number you want to add(an integer greater than 0):\n");
				scanf("%d",&new_add_number);
				if(new_add_number<0)
				{
					printf("Invalid input!\n");
					break;
				}
				
				search_book.copies+=new_add_number;
				fwrite(&search_book,sizeof(search_book),1,add);
				printf("Adding successfully.\n");
				free(search_book);
				break;
			}
			
			search_book=search_book->next;
			if(search_book->next==NULL)
			{
				book_end=search_book;
			}
			
		}
		
		
		
		
		if(new_book_flag==0)
		{	
			CreateNode(B);
			book_end->next=B;
			
			B.id=id_number;
        	printf("Please enter book title:\n");
			gets(new_book);
			B->title=new_book;
			printf("Please enter autor name:\n");
			gets(new_author);
			B->authors=new_author;
		
			while(1)
			{
				printf("Please enter release year:\n");
		    	gets(new_release_time);
		    	if (strspn(new_release_time,"0123456789")!=strlen(new_release_time))
	        	{
	    			printf("Only numbers are valid characters,please reenter/n");
	    			continue;
		    	}
		    
		    	time_pointer=new_release_time;
		    	time_number=atoi(time_pointer);
		    	B.year=time_number;
		    
			}

			printf("Please enter the number you want to add(an integer greater than 0):\n");
			scanf("%d",&new_add_number);
			B.copies=new_add_number;
			fwrite(&B,sizeof(B),1,add);
			DeleteNode(B);
			free(search_book);
			fclose(add);
			
			printf("Adding successfully.\n");
		}
		
		return;
		
	}

	
	
	
	
}


void librian_account()
{
	printf("------------------------------------\n");
	printf("Login as librian\n");
	
	int librian_choice;
	
	while(1)
	{
	    printf("Please enter next your next action.\n");
	    printf("(1) Add books into library.\n");
	    printf("(2) Remove books from libary.\n");
	    printf("(3) Search for books.\n");
	    printf("(4) Display all books.\n");
	    printf("(5) Logout.\n");
	
	    scanf("%d",&librian_choice);
	    switch (librian_choice)
	    {
		case 1:
			FILE *book_storage;
	        book_storage=fopen("Book_Storage.bin","r");
			store_books(book_storage);
			continue;
			
		case 2:
			remove_books();
			
		case 3:
			Search_books_module();
			
		case 4:
			Display_module();
			continue;
			
		case 5:
			printf("Logout.\n");
			login_flag=0;
			return;
			
		default:
			printf("Sorry,that do not seem to be an option\n");
	}
}
