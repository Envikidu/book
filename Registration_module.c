#include "Registration_module.h"
#include "book_management.h"
#include "Head_file.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free(B)
#define CreateUserNode(U) U=(Users*)malloc(sizeof(Users))
#define DeleteUserNode(U) free(U)


void Registration_module(){
	//CreateUserNode(search_user);
	Users *search_user; // ���û��ļ���Ѱ���Ƿ��������û� 
	
	while(1)
	{
		printf("Please enter your username here(1-10 characters):\n");
	    gets(username);
	    int i,j;
	    
	    for(i=0;i;i++)   //��ȡ�û������� 
	   {
		   if(username[i]='\0')
		   {
		   		DeleteUserNode(search_user);
				break;
		   }
	   }
	   
	   if(i>10)       //����û��������Ƿ�Ϸ� 
	   {
	   	    printf("Username is too long! Please reenter."); 
	   	    continue;
	   }
	   
	   
	   
	   
	   
	   
	   
	   /*FILE *Userlist;   //���û��ļ��鿴���û����Ƿ��ѱ�ռ�� 
	   Userlist=fopen("User_Collection.bin","r");
	   if(!Userlist)
	   {
	   	     printf("error!\n");
	   	     DeleteUserNode(search_user);
	   	     return;
	   }
	   fread(&User_Head,sizeof(User_Head),1,Userlist);  //��ȡ�û�ͷ�� 
	   search_user=User_Head->next; //ָ���һ���û� 
	   
	   
	   while(search_user!=NULL)
	   {
	   	    fread(&search_user,sizeof(search_user),1,Userlist);  
	   	    if(strcmp(search_user->name,username)==0)  //�ҵ�����ͬ������ 
	   	    {
	   	    	printf("This username has been signed already,please try again!\0");
	   	    	fclose(Userlist);
	   	    	DeleteUserNode(search_user);
	   	    	return;
			}
			search_user=search_user->next; //�·� 
			
			if(search_user->next==NULL)
			{
				book_end=search_user; //ָ�����һ����� 
			}
	   }
	   
	   
	   
	   CreateUserNode(new_user);
	   user_end->next=new_user;
	   strcpy(new_user->name,username);  //���û�����ӽ��� 
	   break;*/
	   
	   search_user=User_Head->next;
	   while(search_user!=NULL)
	   {
	   		if(strcmp(search_user->name,username)==0) //�ҵ��û�����ͬ���û� 
	   		{
	   			printf("This name has been used.\n");
	   			store_users();
	   			return;
			}
			
			search_user=search_user->next;
	   }
	   
	   
	   
	   
	   
	}
	
	
	
	
	
	
	
	while(1)
	{
	
	    printf("Please enter your password here(1-10 characters):\n");
	    gets(user_password);
	   int i;
	   for(i=0;i;i++)   //��ȡ����ĳ��� 
	   {
		   if(user_password[i]='\0')
		   {
			   break;
		   }
	   }
	   
	   if(i>10)       //��鳤���Ƿ�Ϸ� 
	   {
	   	    printf("Password is too long! Please reenter.\n");
	   	    continue;
	   }
	   
	   strcpy(new_user->password,user_password); //�Ϸ������� 
	   new_user->next=NULL;  //���û�����һλָNULL 
	   fwrite(&new_user,sizeof(new_user),1,Userlist);   //д�� 
	   printf("Your account has been created.\n");
	   DeleteUserNode(new_user);
	   DeleteUserNode(search_user);
	   fclose(Userlist);
	   break;
	}
	
	return;
	
}
