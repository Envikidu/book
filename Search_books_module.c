#include "book_management.h"
#include "Head_file.h"
#include "Search_books_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_book_by_title(char titles[],FILE *file)
{
	fread(&Book_Head,sizeof(Book_Head),1,file);
	check_book=Book_Head->array;
	
	while(check_book!=NULL)
	{
		fread(&check_book,sizeof(check_book),1,file);
		if(strstr(check_book->title,titles))
		{
			have_found_flag=1;
			printf("%d\t",check_book->id);
			printf("%s\t",check_book->title);
			printf("%s\t",check_book->authors);
			printf("%d\n",check_book->copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	have_found_flag=0;
	return;
	
}







void find_book_by_author(char author[],FILE *file)
{
	fread(&Book_Head,sizeof(Book_Head),1,file);
	check_book=Book_Head->array;
	
	while(check_book!=NULL)
	{
		fread(&check_book,sizeof(check_book),1,file);
		if(strstr(check_book->authors,author))
		{
			have_found_flag=1;
			printf("%d\t",check_book->id);
			printf("%s\t",check_book->title);
			printf("%s\t",check_book->authors);
			printf("%d\n",check_book->copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	have_found_flag=0;
	return;
}









void find_book_by_year(int years)
{
	fread(&Book_Head,sizeof(Book_Head),1,file);
	check_book=Book_Head->array;
	
	while(check_book!=NULL)
	{
		fread(&check_book,sizeof(check_book),1,file);
		if(check_book->year==years)
		{
			have_found_flag=1;
			printf("%d\t",check_book->id);
			printf("%s\t",check_book->title);
			printf("%s\t",check_book->authors);
			printf("%d\n",check_book->copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	have_found_flag=0;
	return;
}







void Search_books_module()
{
	have_found_flag=0;
	FILE *look;
	look=fopen("Book_storage.bin");
	while(1)
	{
	
		printf("Please select how to search:\n");
		scanf("%d",&search_by_x);
		printf("(1) Find by title.\n");
		printf("(2) Find by author.\n");
		printf("(3) Find by year.\n");
		printf("(4) Quit.\n");
	
		switch(search_by_x)
		{
			case 1:
				gets(check_title);
				find_book_by_title(check_title,look);
				continue;
			
			case 2:
				gets(check_author);
				find_book_by_author(author,look);
				continue;
			
			case 3:
				gets(check_year);
			
				if (strspn(check_year,"0123456789")!=strlen(check_year))  //检查输入是否都为数字 
		    	{
	 		   		printf("Only numbers are valid characters,please reenter/n");
	 		   		continue;
				}
				
			
				check_year_pointer=(char*)malloc(sizeof(char));
				check_year_pointer=check_year;
				check_year_number=atoi(check_year_pointer);
				free(check_year_pointer);
				find_book_by_year(check_year_number);
				
			case 4:
				flose(look);
				return;
				
			default:
				printf("Invalid option!\n");
				continue;
				
			
		}
	}
}
