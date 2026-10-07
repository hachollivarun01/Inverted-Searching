/*
Name :- H.Varun
Date :-
*/
#include "database.h"

int create_database(slist **head,main_node **hashtable)
{
    if ( *head == NULL )
    {
	printf("No Files\n");
    }
    slist *temp = *head;
    while(temp != NULL)
    {
	FILE *f1 = fopen(temp->name,"r");
	fseek(f1,0L,SEEK_END);
	int n = ftell(f1);
	fseek(f1,0,SEEK_SET);
	char word[10];	
	while ( ftell(f1) != n )
	{
	    int w = 0;
    	    fscanf(f1,"%s ",word);
	    int index = toupper(word[0]) % 65 ;

	    if ( index > 25 ) 
	    {
		index = 26;
	    }
	    if ( hashtable[index] == NULL )
	    {
		main_node *new = malloc(sizeof(main_node));
		sub_node *new1 = malloc(sizeof(sub_node));
		if ( new == NULL )
		{
		    if ( new1 == NULL )
		    {
			printf("FAILURE\n");
		    }
		}
		new->file_count = 1;
		strcpy(new->word,word);
		new->main_link = NULL;
		new1->word_count = 1;
		strcpy(new1->file_name,temp->name);
		new1->sub_link = NULL;
		new->link = new1;
		hashtable[index] = new;
	    }
	    else if ( hashtable[index] != NULL )
	    {
		int flag = 0;
		main_node *temp1 = hashtable[index];
		main_node *prev = NULL;
		while(temp1 != NULL)
		{
		    prev = temp1;
		    if ( strcmp(temp1->word,word) == 0 )
		    {
			sub_node *temp2 = temp1->link;
			sub_node *prev1 = NULL;
			int flag1 = 0;
			while ( temp2 != NULL )
			{
			    prev1 = temp2;
			    if ( strcmp(temp2->file_name,temp->name) == 0 )
			    {
				flag1 = 1;
				w++;
				if ( w > temp2->word_count )
				{
    				    temp2->word_count++;
				}
			    }
			    temp2 = temp2->sub_link;
			}
			if (flag1 == 0)
			{
			sub_node *new = malloc(sizeof(sub_node));
			strcpy(new->file_name,temp->name);
			new->word_count = 1;
			new->sub_link = NULL;
			prev1->sub_link = new;
			temp1->file_count++;
			}
			flag = 1;
		    }
		    temp1 = temp1->main_link;
		}
		if ( flag == 0 )
		{
		main_node *new = malloc(sizeof(main_node));
		sub_node *new1 = malloc(sizeof(sub_node));
		new->file_count = 1;
		strcpy(new->word,word);
		new->main_link = NULL;
		new1->word_count = 1;
		strcpy(new1->file_name,temp->name);
		new1->sub_link = NULL;
		new->link = new1;
		prev->main_link = new;
		}
	    }
	    }
	temp = temp->link;
}
return SUCCESS;
}
