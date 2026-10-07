#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node
{
    char name[20];
    struct Node *link;
}slist;

typedef struct sub_node
{
    int word_count;
    char file_name[10];
    struct sub_node *sub_link;
}sub_node;

typedef struct main_node
{
    int file_count;
    char word[10];
    struct sub_node *link;
    struct main_node *main_link;
}main_node;

#define SUCCESS 1
#define FAILURE 0

int read_and_validate(char *[],int ,slist **head);
int insert_at_last(char [],slist **head);
int create_database(slist **head,main_node **);
int search_database(main_node **hashtable,char []);
int save_database(main_node **hashtable,char []);
int update_database(char file[],main_node **hashtable);
void display(main_node **);
