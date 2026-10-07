/*
Name :- H.Varun
Date :-
*/
#include "database.h"

int save_database(main_node **hashtable,char file[])
{
    if (strcmp(strstr(file,"."),".txt") == 0)
    {
    	FILE *fptr = fopen(file,"w");
    	if(fptr == NULL )
    {
	printf("File Not Opened\n");
    }
    else
    {
	for(int index = 0;index<27;index++)
        {
	    if ( hashtable[index] != NULL )
    	    {
		main_node *temp = hashtable[index];
    		while(temp != NULL)
		{
		    fprintf(fptr,"#%d;%s;%d",index,temp->word,temp->file_count);
		    sub_node *stemp = temp->link;
    		    while(stemp != NULL)
    		    {
			fprintf(fptr,";%s;%d",stemp->file_name,stemp->word_count);
    			stemp = stemp->sub_link;
		    }
    		    fprintf(fptr,"#\n");
    		    temp = temp->main_link;
    		}
    	    }
  	}
	return SUCCESS;
	fclose(fptr);	
    }
    }
    else
    {
	printf("Provide a .txt File\n");
	return FAILURE;
    }
}
