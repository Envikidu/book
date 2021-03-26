#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Borrow.h"
#include "Visitor_account.h"
#include "Head_file.h"
#include "Display_module.h"

void Visitor_account(char account,User *user_online)
{
	while(1)
	{
		printf("Login as %s\n",account);
		printf("Please enter next your next action:\n");
		printf("(1) Borrow books:\n");
		printf("(2) Return books:\n");
		printf("(3) Search books:\n");
		printf("(4) Display all books:\n");
		printf("(5) Logout:\n");
	
		scanf("%d",&visitor_choice);
		switch(visitor_choice)
		{
			case 1:
				Borrow(*user_online);
				continue;
			
			case 2:
				Return();
				continue;
			
			case 3:
				Search_module();
				continue;
				
			case 4:
				Display_module();
				continue;
				
			case 5:
				printf("Logout.\n");
				return;
				
			default:
				printf("Sorry,that do not seem to be an option\n");
				continue;
	 	}
		  
	}

}
