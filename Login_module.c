#include "book_management.h"
#include "Login_module.h"
#include "Head_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free((void *B))
#define CreateUserNode(U) U=(User*)malloc(sizeof(User))
#define DeleteUserNode(U) free((void *U))


void Login_module()
{
	//search_user_login=(User*)malloc(sizeof(Users)); 
	CreateUserNode(search_user_login); 
	FILE *Userlist;
	Userlist=fopen("User_Collection.bin");
	fread(&User_Head,sizeof(User_Head),1,Userlist);
	
	
	
	
	
	while(1)
	{
		printf("Please enter your username:\n");
	    gets(login_user);
	    search_user_login=User_Head->next;
	    
		
		if(!Userlist)
		{
			printf("error!\n");
			return;
		 } 
		
	
	
	    while(search_user_login!=NULL)  //check if this user exist
	    {
	    	fread(&search_user_login,sizeof(search_user_login),1,Userlist);
	    	if(strcmp(search_user_login->name,login_user)==0)  //the account has been found
	    	{
	    		exist=1;
	    		break;
			}
			search_user_login=search_user_login->next;
		}
		
		if(exist==0)
		{
			printf("This account not exist, please try again.\n");
			continue;
		}
		
		
		
		
		
		
		
		printf("Please enter password:\n");
		gets(login_password);

		
		while(1)  //check if this password correct
		{
		    if(strcmp(search_user_login->password,login_password)==0)  //password correct
		    {
		    	printf("Login successfully.\n");
		    	free(search_user_login);
		    	fclose(Userlist);
		    	break;
			}
			
			else
			{
				printf("Wrong password,please try again!\n");
				free(search_user_login);
				fclose(Userlist);
				return;
			}
		}
		
		
		
		if(strcmp(login_user, manager) == 0)  //login as librarian
		{
			login_flag=2;
			printf("Login as librarian.\n");
			librian_account();
			
		}
		
		else
		{
			login_flag=1;
			Visitor_account(login_user,search_user_login);
		}
		
		return;
	
	}

	
}
