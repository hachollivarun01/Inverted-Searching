/*
Name :- H.Varun
Date :-
*/
#include "database.h"

int search_database(main_node **hashtable,char word[])
{
    int index = toupper(word[0]) % 65;

    if ( hashtable[index] != NULL )
    {
	main_node *mtemp = hashtable[index];
	int flag = 0;
	while(mtemp != NULL)
	{
	    if ( strcmp(mtemp->word,word) == 0 )
	    {
		printf("%d	%s	%d",index,mtemp->word,mtemp->file_count);
		sub_node *stemp = mtemp->link;
		while(stemp != NULL)
		{
		    printf("	%s		%d\n",stemp->file_name,stemp->word_count);
		    stemp = stemp->sub_link;
		}
		flag = 1;
	    }
	    mtemp = mtemp->main_link;
	}
	if ( flag == 0 )
	{
	    printf("Error !! There is No Word in the Database\n");
	}
	
    }
    else
    {
	printf("Error !! There is No Word in the Database\n");
    }
}
