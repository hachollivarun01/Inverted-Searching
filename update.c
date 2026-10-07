/*
Name :- H.Varun
Date  :-
 */

#include "database.h"

int update_database(char file[],main_node  **hashtable)
{
    FILE *fptr = fopen(file,"r");

    if ( fptr == NULL )
    {
	printf("\033[0;31mError : File Opening Not SuccessFull\033[0m\n");
    }
    char str[200];
    fscanf(fptr,"%s",str);

    if ( str[0] == '#' )
    {
	while ( feof(fptr) == 0 )
	{
	    int index = atoi(strtok(&str[1],";"));

	    if ( hashtable[index] == NULL )
	    {
		//printf("index NULL %s\n",str);
		main_node *new = malloc(sizeof(main_node));

		strcpy(new->word,strtok(NULL,";"));

		new->file_count = atoi(strtok(NULL,";"));

		sub_node *new1 = malloc(sizeof(sub_node));
		strcpy(new1->file_name,strtok(NULL,";"));
		new1->word_count = atoi(strtok(NULL,";"));
		new1->sub_link = NULL;
		new->link = new1;
		new->main_link = NULL;
		hashtable[index] = new;
		if ( new->file_count > 1 )
		{
		    int i = 1;
		    while ( i < new->file_count )
		    {
			sub_node *new2 = malloc(sizeof(sub_node));

			strcpy(new2->file_name,strtok(NULL,";"));
			new2->word_count = atoi(strtok(NULL,";"));
			new2->sub_link = NULL;
			sub_node *temp = new->link;
			while ( temp->sub_link != NULL )
			{
			    temp = temp->sub_link;
			}
			temp->sub_link = new2;
			i++;
		    }
		}
	    }
	    else if ( hashtable[index] != NULL )
	    {
		//printf("index not NULL %s\n",str);
		main_node *temp = hashtable[index];
		while ( temp->main_link != NULL )
		{
		    temp = temp ->main_link;
		}

		main_node *new = malloc(sizeof(main_node));

		strcpy(new->word,strtok(NULL,";"));

		new->file_count = atoi(strtok(NULL,";"));

		sub_node *new1 = malloc(sizeof(sub_node));
		strcpy(new1->file_name,strtok(NULL,";"));
		new1->word_count = atoi(strtok(NULL,";"));
		new1->sub_link = NULL;
		new->link = new1;

		new->main_link = NULL;
		temp->main_link = new;
		if ( new->file_count > 1 )
		{
		    int i = 1;
		    while ( i < new->file_count )
		    {
			sub_node *new2 = malloc(sizeof(sub_node));
			strcpy(new2->file_name,strtok(NULL,";"));
			new2->word_count = atoi(strtok(NULL,";"));
			new2->sub_link = NULL;
			sub_node *temp = new->link;
			while ( temp->sub_link != NULL )
			{
			    temp = temp->sub_link;
			}
			temp->sub_link = new2;
			i++;
		    }
		}
	    }
	    fscanf(fptr,"%s",str);
	}
	return SUCCESS;
	fclose(fptr);
    }
    else
    {
	printf("Error !! Not a backup file\n");
    }

}
