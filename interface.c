#include "interface.h"
#include "Registration_module.h"
#include "Head_file.h" 
//#include "Login_module"
//#include "Search_books_module.h"
//#include "Display_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free(B)
#define CreateUserNode(U) U=(User*)malloc(sizeof(User))
#define DeleteUserNode(U) free(U)
#define LEN 999

Users *user_end; //ʼ��ָ�����´�����β�ڵ� 
Book *book_end;






void add_user(Users *p)                               //����û� 
{
	CreateUserNode(p);
	
	
	if(User_Head->next==NULL) //����û�ͷ�ڵ����Ϊ�� 
	{
		user_end=User_Head->next;
		return;
	}
	
	user_end=User_Head->next;
	while(user_end->next!=NULL)
	{
		user_end=user_end->next;
	}
	
	user_end->next=p;
	user_end=user_end->next; //ָ��β�� 
	user_end->next=NULL;  //����β�ڵ�ָ�� 
	User_Head->number++;  //�û�������һ 
	return; 
}












void add_book(Book *p)                            //���ͼ�� 
{
	CreateBookNode(p);
	
	
	if(Book_Head->array==NULL) //�������ͷ�ڵ����Ϊ�� 
	{
		book_end=Book_Head->array;
		return;
	}
	
	book_end=Book_Head->array;
	while(book_end->next!=NULL)
	{
		book_end=book_end->next;
	}
	
	book_end->next=p;
	book_end=book_end->next;  //ָ��β�� 
	book_end->next=NULL;  //����β�ڵ�ָ�� 
	Book_Head->length++;  //�鼮������һ 
	return; 
}













int store_books()                         //��ͼ�����������ļ��� 
{
	int book_num=0; //�鼮���� 
	FILE *fp;
	fp=fopen("Book_Storage.txt","w");
	
	
	if(!fp)
	{
		printf("Fail to open book storage file.\n");
		return -1;
	}
	
	Book *z;
	z=Book_Head->array; 
	fprintf(fp,"%d\n\n",Book_Head.length);  //�洢������� 
	
	while(z!=NULL)
	{
		fprintf(fp,"ID:%d\n",z->id);
		fprintf(fp,"Title:%s\n",z->title);
		fprintf(fp,"Authors:%s\n",z->authors);
		fprintf(fp,"Release year:%d\n",z->year);
		fprintf(fp,"The total storage number:%d\n",z->copies);
		fprintf(fp,"Available storage number:%d\n\n",z->now_copies);
		book_num++;
			
		z=z->next;
	}
	
	Book_Head.length=book_num;  //����ͼ������ 
	
	fclose(fp);
	return 1;
}










int load_books()                  //���ļ���ȡ��ͼ������ 
{
	FILE *fp;
	fp=fopen("Book_storage.txt","r");
	Book *p; //�����½ڵ����õ�ָ�� 
	if(!fp)
	{
		printf("Fail to load book storage.\n");
		return -1;
	}
	
	//p=Book_Head->array; //��һ���� 
	char read[LEN];  //��ʱ�洢ÿ������ 
	
	if(fgets(buf,LEN,fp)==NULL) //��һ��Ϊ�� 
	{
		printf("Error.\n");
		return -1;
	}
	
	fgets(read,LEN,fp); 
	sscanf(read,"%d\n",Book_Head.length); //��ȡ��һ�е�ͼ������
	
	fgets(read,LEN,fp);
	for(int i=0;i<Book_Head.length;i++)
	{
		Book *new_book;
		CreateBookNode(new_book);
		fgets(read,LEN,fp);
		sscanf(read,"ID:%d\n",&new_book->id);
		
		char read2[LEN];
		fgets(read,LEN,fp);
		sscanf(read,"Title:\%[^\n]",read2);
		strcpy(new_book->title,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"Authors:\%[^\n]",read2);
		strcpy(new_book->authors,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"Release year:%d\n",&new_book->year);
		
		fgets(read,LEN,fp);
		sscanf(read,"The total storage number:%d\n",&new_book->copies);
		
		fgets(read,LEN,fp);
		sscanf(read,"Available storage number:%d\n",&new_book->now_copies);
		
		fgets(read,LEN,fp);
		
		
		if(i==0)  //��һ������Ľڵ����Head�ĺ����һ�� 
		{
			Book_Head->array=new_book;
			p=new_book;
			continue;
		}
		
		p->next=new_book;  //�����½ڵ� 
		p=new_book;
		
	} 
	
	p->next=NULL;
	fclose(fp);
	return 1;
	
}





int store_users()    //�洢�û����ļ� 
{
	FILE *fp;
	fp=fopen("User_collection.txt","w");
	int user_number=0;    //�û������� 
	
	if(!fp)
	{
		printf("Fail to open user collection file.\n");
		return -1;
	}
	
	
	
	Users *z;
	z=User_Head->next;
	fprintf(fp,"%d\n\n",User_Head->number);  //�洢�û����� 
	while(z!=NULL)
	{
		fprintf(fp,"Username:%s\n",z->name);
		fprintf(fp,"Password:%s\n",z->password);
		fprintf(fp,"The number of borrowed books:%d\n",z->borrow_number);
		fprintf(fp,"Books in possession:\n");
		
		for(int i=0;i<z->borrowed;i++)
		{
			fprintf(fp,"%d\n",z->borrowed[i]);
		}
		
		fprintf(fp,"\n");
		
		user_number++; 
		z=z->next; 
		
	}
	
	User_Head.number=user_number;  //�����û����� 
	fclose(fp);
	return 1;
	
	
}








int load_users()
{
	FILE *fp;
	fp=fopen("User_collection.txt","r");
	if(!fp)
	{
		printf("Fail to load user collection.\n");
		return -1;
	}
	Users *p  //���ӽڵ����õ�ָ�� 
	
	char read[LEN];
	if(fgets(buf,LEN,fp)==NULL) //�����һ��Ϊ�� 
	{
		printf("Error.\n");
		return -1;
	}
	
	fgets(read,LEN,fp);
	sscanf(read,"%d\n",User_Head.number);  //��ȡ��һ�е��û�����
	
	fgets(read,LEN,fp);
	for(int i=0;i<User_Head.number;i++)
	{
		Users *new_user;
		CreateUserNode(new_user);
		
		char read2[LEN];
		
		fgets(read,LEN,fp);
		sscanf(read,"Username:\%[^\n]",read2);
		strcpy(new_user->name,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"Password:\%[^\n]",read2);
		strcpy(new_user->password,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"The number of borrowed books:%d\n",new_user->borrow_number);
		
		fgets(read,LEN,fp);
		for(int i=0;j<User_Head.number)
		{
			fgets(read,LEN,fp);
			sscanf(read,"%d\n",new_user->borrowed[i]);
		}
		
		
		
		if(i==0)  //��һ������Ľڵ����Head�ĺ����һ�� 
		{
			User_Head->next=new_user; 
			p=new_user;
			continue;
		}
		
		p->next=new_user;  //�����½ڵ� 
		p=new_user;
		
	} 
	
	p->next=NULL;
	fclose(fp);
	
	
}










static void main_menu()
{

	
	
	
	while(1)
	{
		 
		
		printf("Welcome to local library.\n\n");
	    printf("Please enter next your next action.\n");
	    printf("(1) Register an account.\n");
	    printf("(2) Login.\n");
	    printf("(3) Search for books.\n");
	    printf("(4) Display all books.\n");
	    printf("(5) Quit.\n");
	
	    scanf("%d",&choice);
	    switch (choice)
	    {
		case 1:
			Registration_module();
			continue;
			
		case 2:
		//	Login_module();
			continue;
			
		case 3:
		//	Search_books_module();
			continue;
			
		case 4:
		//	Display_module();
			continue;
			
		case 5:
			printf("See you\n.");
			exit(0);
			
		default:
			printf("Sorry,that do not seem to be an option\n");
	    }
	    
	}
	return;
	
}

void run_interface()
{
	main_menu();
}
