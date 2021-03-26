#include "Borrow.h"
#include "Head_file.h"
#include "Book_management.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free((void *B))
#define CreateUserNode(U) U=(User*)malloc(sizeof(User))
#define DeleteUserNode(U) free((void *U))

void Borrow(User *borrower)
{
	
	borrow_pointer=(char*)malloc(sizeof(char));
	CreateBookNode(book_want);
	CreateBookNode(borrow_end);
	CreateBookNode(has_borrow_search);
	CreateBookNode(search_in_lib);
	CreateBookNode(copy);
	FILE *user_file;
	user_file=fopen("User_collection.bin");
	FILE *book_file;            
	book_file=fopen("Book_Storage.bin");
	
	
	
	
	
	while(1)
	{
		printf("Enter the ID number of book you want to borrow:\n")
		gets(borrow_id);
		if (strspn(borrow_id,"0123456789")!=strlen(borrow_id))  //�������ID�Ƿ�Ϊ���� 
	    {
	    	printf("Only numbers are valid characters,please reenter/n");
	    	continue;
		}
		
		borrow_pointer=borrow_id;
		borrow_number=atoi(borrow_pointer);  //�ַ�ת���� 
		
		
		if(!user_file)
		{
			printf("error!\n");
			return;
		}
		
		
		
		
		
		
		
		
		
		
		fread(&borrower,sizeof(borrower),1,user_file);   //��ȡ�����Ҫ������û� 
		has_borrow_search=borrow->Book;  //ָ���ڽ����б�ĵ�һ���� 
		

		
		while(has_borrow_search!=NULL)   //���û�����������Ҵ�����û�б���� 
		{
			if(has_borrow_search->id==borrow_number)  //�����δ�� 
			{
				printf("You has borrowed this book!\n");
				DeleteBookNode(has_boorow_search);
				DeleteBookNode(borrowed_end);
				DeleteBookNode(borrow_want);
				DeleteBookNode(search_in_lib);
				fclose(user_file);
				fclose(book_file);
				return;
			}
			
			
			
			
			
			
			
			
			fread(&search,sizeof(search,1,user_file));  //���ļ����·� 
			has_borrow_search=has_borrow_search->next;  //�������·� 
			if(has_borrow_search->next==NULL) //��ǰ��ָ�������һ���� 
			{
				borrowed_end=has_borrow_search;  //ָ����������β�� 
			}
		}
		 
		
		
		
		
		
		
		
		
		fread(&Book_Head,sizeof(Book_Head),1,book_file);  //���ļ��ж�������ͷ 
		search_in_lib=Book_Head->array;
		
		while(search_in_lib!=NULL)    //����ID����������� 
		{
			fread(&search_in_lib,sizeof(search_in_lib),1,book_file)
			if(search_in_lib->id==borrow_number&&search_in_lib->copies>0)  //������ҵ��Ȿ����ҿ�����0 
			{
				search_in_lib->copies-1;  //���-1 
				copy=search_in_lib;     //�����µĽ����б�ڵ� 
				borrow_end->next=copy;   //�ѽ赽���Ȿ����������ͼ�������β��
				copy->next=NULL;   //����β�ڵ�ָ�� 
				printf("Borrow successfully.\n");
				DeleteBookNode(book_want);
				DeleteBookNode(borrow_end);
				DeleteBookNode(has_borrow_search);
				DeleteBookNode(search_in_lib);
				DeleteBookNode(copy);
				fclose(user_file);
				fclose(book_file);
				return; 
			}
			
			if(search_in_lib->id==borrow_number&&search_in_lib->copies==0) //��������ҵ��Ȿ�鵫���Ϊ0 
			{
				printf("The book has been borrowed out.\n");
				DeleteBookNode(book_want);
				DeleteBookNode(borrow_end);
				DeleteBookNode(has_borrow_search);
				DeleteBookNode(search_in_lib);
				DeleteBookNode(copy);
				fclose(user_file);
				fclose(book_file);
				return;
			}
			
			search=search->next;
			
		}
		
		printf("This book is not in the storage.\n"); //�������������û��ִ�У���ô��û���ҵ� 
		DeleteBookNode(book_want);
		DeleteBookNode(borrow_end);
		DeleteBookNode(has_borrow_search);
		DeleteBookNode(search_in_lib);
		DeleteBookNode(copy);
		fclose(user_file);
		fclose(book_file);
		return;
		
		
		
		
	}
}
