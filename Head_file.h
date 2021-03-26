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


UsersArray User_Head; //�û��б��ͷ�� 

FILE *Userlist; //�û��ļ�
FILE *Booklist; //����ļ� 
Book *get_book; 
Users *get_user;
Book *create_book;
Users *create_user;

//Book *book_end;  //ָ������β�ڵ� 



//Used in interface
int choice;




//Used in Registration_module
Users *new_user; //��ӵ����û� 
char username[99]; //�½����û���
char user_password[99]; //�½��û�������
 
 
 
 

//Used in Login_module
char login_user[99];
char login_password[99];
char *manager="librarian";
int login_flag;
Users *search_user_login;//���û��ļ������Ƿ������������û� 
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
char borrow_id[99]; //�û��������ID 
char *borrow_pointer;  // ָ���û�������ID��ָ�� 
int borrow_number;  //�û��������������ID 
Book *book_want;    //�����������Ҫ��������ָ�� 
Book *borrow_end;  //ָ���û�����������β�ڵ� 
Book *has_borrow_search;  //���û��Ѿ����������������ָ��
Book *search_in_lib;  //������������ָ��
Book *copy;  //�ѽ��������û��Ľ����б��� 


//Used in Search_book_module
int search_by_x;
char check_title[99];
char check_author[99];
char check_year[99];
char *check_year_pointer;
int check_year_number;
Book *check_book; //�������ָ��
int have_found_flag; 
 
#endif
