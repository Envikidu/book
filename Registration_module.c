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
	Users *search_user; // 在用户文件中寻找是否有重名用户 
	
	while(1)
	{
		printf("Please enter your username here(1-10 characters):\n");
	    gets(username);
	    int i,j;
	    
	    for(i=0;i;i++)   //获取用户名长度 
	   {
		   if(username[i]='\0')
		   {
		   		DeleteUserNode(search_user);
				break;
		   }
	   }
	   
	   if(i>10)       //检查用户名长度是否合法 
	   {
	   	    printf("Username is too long! Please reenter."); 
	   	    continue;
	   }
	   
	   
	   
	   
	   
	   
	   
	   /*FILE *Userlist;   //打开用户文件查看该用户名是否已被占用 
	   Userlist=fopen("User_Collection.bin","r");
	   if(!Userlist)
	   {
	   	     printf("error!\n");
	   	     DeleteUserNode(search_user);
	   	     return;
	   }
	   fread(&User_Head,sizeof(User_Head),1,Userlist);  //读取用户头部 
	   search_user=User_Head->next; //指向第一个用户 
	   
	   
	   while(search_user!=NULL)
	   {
	   	    fread(&search_user,sizeof(search_user),1,Userlist);  
	   	    if(strcmp(search_user->name,username)==0)  //找到了相同的名字 
	   	    {
	   	    	printf("This username has been signed already,please try again!\0");
	   	    	fclose(Userlist);
	   	    	DeleteUserNode(search_user);
	   	    	return;
			}
			search_user=search_user->next; //下翻 
			
			if(search_user->next==NULL)
			{
				book_end=search_user; //指向最后一个结点 
			}
	   }
	   
	   
	   
	   CreateUserNode(new_user);
	   user_end->next=new_user;
	   strcpy(new_user->name,username);  //把用户名添加进来 
	   break;*/
	   
	   search_user=User_Head->next;
	   while(search_user!=NULL)
	   {
	   		if(strcmp(search_user->name,username)==0) //找到用户名相同的用户 
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
	   for(i=0;i;i++)   //获取密码的长度 
	   {
		   if(user_password[i]='\0')
		   {
			   break;
		   }
	   }
	   
	   if(i>10)       //检查长度是否合法 
	   {
	   	    printf("Password is too long! Please reenter.\n");
	   	    continue;
	   }
	   
	   strcpy(new_user->password,user_password); //合法的密码 
	   new_user->next=NULL;  //新用户的下一位指NULL 
	   fwrite(&new_user,sizeof(new_user),1,Userlist);   //写入 
	   printf("Your account has been created.\n");
	   DeleteUserNode(new_user);
	   DeleteUserNode(search_user);
	   fclose(Userlist);
	   break;
	}
	
	return;
	
}
