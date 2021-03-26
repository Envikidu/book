#ifndef HEAD_FILE_GUARD__H 
#define HEAD_FILE_GUARD__H
#include "book_management.h"




//Used in Registration_module
typedef struct _Users{
	char name[11];
	char password[11];
	int borrowed[99]; 
	int borrow_number;
	struct _Users *next;
	
}Users;


typedef struct _UsersArray{
	struct Users *next;
	int number;
}UsersArray;


UsersArray User_Head; //用户列表的头部 

FILE *Userlist; //用户文件
FILE *Booklist; //书库文件 
Book *get_book; 
Users *get_user;
Book *create_book;
Users *create_user;

//Book *book_end;  //指向书库的尾节点 



//Used in interface
int choice;




//Used in Registration_module
Users *new_user; //添加的新用户 
char username[99]; //新建的用户名
char user_password[99]; //新建用户的密码
 
 
 
 

//Used in Login_module
char login_user[99];
char login_password[99];
char *manager="librarian";
int login_flag;
Users *search_user_login;//在用户文件中找是否有输入的这个用户 
int exist=0;



//Used in Librian_account
char book_id[99];
int new_book_flag=0;
char new_book[99];
char new_author[99];
char new_release_time[99];
char new_number[99];
int new_add_number;
Book *search_book;
int number_of_same=0;
char *id_pointer;
char *time_pointer;
int id_number;



//Used in Display_module
Book *show;


//Used in Vistor_account
int visitor_choice;


//Used in Borrow 
char borrow_id[99]; //用户所输入的ID 
char *borrow_pointer;  // 指向用户所输入ID的指针 
int borrow_number;  //用户所输入的整数型ID 
Book *book_want;    //在书库里找需要被借的书的指针 
Book *borrow_end;  //指向用户所借过的书的尾节点 
Book *has_borrow_search;  //在用户已经借过的书中搜索的指针
Book *search_in_lib;  //在书库里找书的指针
Book *copy;  //把借的书接在用户的借书列表里 


//Used in Search_book_module
int search_by_x;
char check_title[99];
char check_author[99];
char check_year[99];
char *check_year_pointer;
int check_year_number;
Book *check_book; //搜索书的指针
int have_found_flag; 
 
#endif
