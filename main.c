/*
Name :- H.Varun
Date :-
*/
#include "database.h"
int flag = -1;
int main(int argc,char *argv[])
{
    slist *head = NULL;
    char arr[10];
    char file[10];
    main_node *hashtable[27] = {NULL};
    if ( argc > 1 )
    {
	if ( read_and_validate(argv,argc,&head) == SUCCESS)
	{
	    printf("\033[0;32mSuccessful : inserting file name into file linked list\033[0m\n");
	    int choice;
	    char c;
	    do
	    {
    		printf("Select Your Choice Among Following Options :\n1.Create DataBase\n2.Display DataBase\n3.Search DataBase\n4.Save DataBase\n5.Update DataBase\nEnter Your Choice:");
    		scanf("%d",&choice);
    		switch(choice)
    		{
    		    case 1:
    			if ( create_database(&head,hashtable) == SUCCESS )
    			{
			    flag = 1;
    			    printf("Creataion of Database is Successful\n");
    			}
    			break;
    		    case 2:
    			display(hashtable);
    			break;
    		    case 3:
    			printf("Enter the Word to be search in tha database : ");
    			scanf("%s",arr);
    			search_database(hashtable,arr);
    			break;
    		    case 4:
    			printf("Enter the Filename to save the database : ");
    			scanf("%s",file);
    			if ( save_database(hashtable,file) == SUCCESS )
			{
			    printf("Save Database Successful\n");
			}
			else
			{
			    printf("Save Database Not Successful\n");
			}
    			break;
    		    case 5:
			if ( flag != 1 )
			{
    			    printf("Enter the file name to update data : ");
    			    scanf("%s",file);
			    if ( update_database(file,hashtable) == SUCCESS )
			    {
				printf("Data Added Successfull into the DataBase\n");
			    }
			    else
			    {
				printf("Error!! File already in the Database\n");
			    }
			}
			else
			{
			    printf("File Already created so update not possible\n");
			} 
		     	break;
    		    default:
    			printf("Please Enter the Correct Choice\n");
    			break;
		}
			printf("Do you want to continue ? \nEnter y to continue and n to discontinue\n");
		getchar();
    		scanf("%c",&c);
	    }while(c == 'y');

	}
	else
	{
	    printf("Read Failure\n");
	}
    }
    else
    {
	printf("Please Provide Atleast two Arguments\n");
    }
   return 0;
}
