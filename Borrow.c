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
		if (strspn(borrow_id,"0123456789")!=strlen(borrow_id))  //检查输入ID是否都为数字 
	    {
	    	printf("Only numbers are valid characters,please reenter/n");
	    	continue;
		}
		
		borrow_pointer=borrow_id;
		borrow_number=atoi(borrow_pointer);  //字符转数字 
		
		
		if(!user_file)
		{
			printf("error!\n");
			return;
		}
		
		
		
		
		
		
		
		
		
		
		fread(&borrower,sizeof(borrower),1,user_file);   //读取书库中要借书的用户 
		has_borrow_search=borrow->Book;  //指向在借书列表的第一本书 
		

		
		while(has_borrow_search!=NULL)   //在用户所借的书中找此书有没有被借过 
		{
			if(has_borrow_search->id==borrow_number)  //借过了未还 
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
			
			
			
			
			
			
			
			
			fread(&search,sizeof(search,1,user_file));  //在文件中下翻 
			has_borrow_search=has_borrow_search->next;  //链表中下翻 
			if(has_borrow_search->next==NULL) //当前所指的是最后一本书 
			{
				borrowed_end=has_borrow_search;  //指向所借过书的尾部 
			}
		}
		 
		
		
		
		
		
		
		
		
		fread(&Book_Head,sizeof(Book_Head),1,book_file);  //从文件中读出书库的头 
		search_in_lib=Book_Head->array;
		
		while(search_in_lib!=NULL)    //按照ID在书库里找书 
		{
			fread(&search_in_lib,sizeof(search_in_lib),1,book_file)
			if(search_in_lib->id==borrow_number&&search_in_lib->copies>0)  //在书库找到这本书而且库存大于0 
			{
				search_in_lib->copies-1;  //库存-1 
				copy=search_in_lib;     //制造新的借书列表节点 
				borrow_end->next=copy;   //把借到的这本书接在所借过图书链表的尾部
				copy->next=NULL;   //链表尾节点指空 
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
			
			if(search_in_lib->id==borrow_number&&search_in_lib->copies==0) //在书库里找到这本书但库存为0 
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
		
		printf("This book is not in the storage.\n"); //如果上述操作都没能执行，那么就没有找到 
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
