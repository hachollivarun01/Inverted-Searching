/*
Name :- H.Varun
Date :-
*/
#include "database.h"

void display(main_node **hashtable)
{
    //printf("[index]->[word]->[file_count]->[file_name]->[word_count]\n\n");

    for(int index = 0;index<27;index++)
    {
	if ( hashtable[index] != NULL )
	{
	    main_node *temp = hashtable[index];

	    while(temp != NULL)
	    {
		printf("#%d;%s;%d",index,temp->word,temp->file_count);

		sub_node *stemp = temp->link;
		while(stemp != NULL)
		{
		    printf(";%s;%d",stemp->file_name,stemp->word_count);
		    stemp = stemp->sub_link;
		}
		printf("\n");
		temp = temp->main_link;
	    }
	}
    }
}
