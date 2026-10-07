/*
Name :- H.Varun
Date :-
*/
#include "database.h"

int read_and_validate(char **argv,int argc,slist **head)
{
    for(int i=1;i<argc;i++)
    {
    	if ( strstr(argv[i],".txt") != 0)
    	{

    	    FILE *f1 = fopen(argv[i],"r+");
    	    if ( f1 == NULL )
    	    {
    		return FAILURE;
    	    }
    	    fseek(f1,0L,SEEK_END);
    	    if ( ftell(f1) != 0 )
    	    {	
    		if (insert_at_last(argv[i],head) == SUCCESS ) 
    		{
    		    //printf("Insert at Last Successful\n");
    		}
    		else
    		{
    		    printf("ERROR !! Duplicate Found\n");
    		}
    	    }
    	    else
    	    {
    		printf("ERROR !! Empty file\n");
    	    }	
    	}
    	else
    	{
	    if ( *head == NULL )
	    {
    		printf("ERROR !! Provide a "".txt"" file\n");
    		return FAILURE;
	    }
	    else
	    {
		printf("Error !! Provide a .txt file\n");
		return SUCCESS;
	    }
    	}
    }
    return SUCCESS;
}
int insert_at_last(char filename[],slist **head)
{
    slist *new = malloc(sizeof(slist));
    if ( new == NULL )
    {
	return FAILURE;
    }
    strcpy(new->name,filename);
    new->link = NULL;

    if ( *head == NULL )
    {
	*head = new;
	return SUCCESS;
    }
    slist *temp = *head;
    slist *prev = NULL;
    while(temp != NULL)
    {
	if ( strcmp(temp->name,filename) == 0 )
	{
	    return FAILURE;
	}
	prev = temp;
	temp = temp->link;
    }
    prev->link = new;
    return SUCCESS;   
}
