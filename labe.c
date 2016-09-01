//
//  main.c
//  LAB E
//
//  Created by Sonali Carlton on 4/26/16.
//  Copyright (c) 2016 Carlton. All rights reserved.
//


#include <stdio.h>
#include <ctype.h>
#include <string.h>

//sets up book struct
struct BOOK
{
    char title[50];
    char stitle [50];
    char author[50];
    char sauthor [50];
    char genre[50];
    char sgenre[50];
    float rating;
    int pages;
    
};

//protypes function
void menu(struct BOOK [], int*, char*);
void booking(struct BOOK [], int*, char*);
void checkmenuoption(int*);         //goes with menu
struct BOOK getbook(int *);         //goes with booking
void sorter(struct BOOK[], char*, int *);
void sort (struct BOOK [], int *);      //goes with sorter and sort functions
void output(struct BOOK [], int*);

//agains
void againbooks(char *);
void againsort(char*);
void againmenu(char*);

//protypes for sorting functions
void titlesort(struct BOOK [], int *);
void authorsort(struct BOOK [], int *);
void genresort(struct BOOK [], int *);
void ratingsort(struct BOOK [], int *);
void pagesort(struct BOOK [], int *);


int main(void)
{

    //decalres variables
    char repeater ='i';
    struct BOOK abook[100];
    int i =0;
    
    //loops of menu
    do
    {
       
        menu(abook, &i, &repeater );
        againmenu(&repeater);
    }while(repeater =='y');
    
    
    return 0;
}

//***********menu***********************************
void menu (struct BOOK bookie [], int *iptr, char *repeaterptr)
{
    //decalres variables
    static int m= 0;
    int option;
    
    //outputs text
    printf("\nThe following is a menu of options:\n");
    puts("1. Enter Books");
    puts("2. Display Books");
    puts("3. Sort Books:");
    puts("4. Quit");
    printf("Enter which option you want: ");
    scanf("%i", &option);   //gets the acutal option
    
    m++;        //increments
    checkmenuoption(&option);//error trapping
    
    //in case no datat in
    while (m<2 && option>1)
    {
        printf("You haven't entered any books yet, please enter option 1:");
        scanf("%i", &option);
        checkmenuoption(&option);
        
    }
    
    //all goes to the three cases
    switch(option)
    {
        case 1:
            booking(bookie, *&iptr, &*repeaterptr);
            break;
        case 2:
            output(bookie, *&iptr);
            break;
        case 3:
            sorter(bookie, *&repeaterptr, &*iptr);
            break;
        default:            //for the quit function
            printf("Bye Bye");
            break;
    }
    
    
}

//***************booking************************************
void booking (struct BOOK abook8 [], int *iptr, char *repeaterptr)
{
    
    
    //loop to collect info about the books
    do
    {
        
        abook8[*iptr]= getbook(*&iptr);
       ( *iptr)++;    //increments for each book that is put in
        
        againbooks(*&repeaterptr);
        
    }while (*repeaterptr == 'y' && *iptr <100); //incase theres too many books
    
    *repeaterptr = 'i'; //resets repater for next loop
}

//**************checkmenuoption*************************
void checkmenuoption(int *optionptr1)
{
    while(*optionptr1 > 5 || *optionptr1 <1 )   //makes sure its valid
    {
        printf("\nPlease enter a valid option number");
        scanf("%i", *&optionptr1);
        
    }
}
//*************input*****************************************
struct BOOK getbook(int *dptr)
{
    int z=0;
    struct BOOK inputbook;
    // int i=0;
    // int error =0;
    //gets all the info
    getchar();
    printf("\nEnter the title:");
    gets(inputbook.title); //title
    //error traps title
    /*   for(i=0; i<50; i++)
     {
     if(isprint(inputbook.title [i]) == 0)
     error++;
     }
     while(error !=0)
     {
     error = 0;
     printf("Please enter a valid title: ");
     gets(inputbook.title);
     
     for(i=0; i<50; i++)
     {
     if(isprint(inputbook.title [i]) == 0)
     error++;
     }
     }
     */
    printf("\nEnter the author name (last, first):");
    gets(inputbook.author);             //authors name
    /*    //error traps author
     for(i=0; i<50; i++)
     {
     if(isprint(inputbook.author [i]) == 0)
     error++;
     }
     while(error !=0)
     {
     error = 0;
     printf("Please enter a valid author's name: ");
     gets(inputbook.author);
     
     for(i=0; i<50; i++)
     {
     if(isprint(inputbook.author [i]) == 0)
     error++;
     }
     }
     */
    printf("\nEnter the genre:");
    gets(inputbook.genre);          //genre
    /*    //error traps genre
     for(i=0; i<50; i++)
     {
     if(isprint(inputbook.genre [i]) == 0)
     error++;
     }
     while(error !=0)
     {
     error = 0;
     printf("Please enter a valid genre: ");
     gets(inputbook.genre);
     
     for(i=0; i<50; i++)
     {
     if(isprint(inputbook.genre [i]) == 0)
     error++;
     }
     }
     */
    printf("\nEnter the rating (1-10):");
    scanf("%f", &inputbook.rating);         //rating
    //error traps rating
    while(inputbook.rating > 10 || inputbook.rating < 1 )
    {
        printf("Please enter a valid rating between 1-10");
        scanf("%f", &inputbook.rating);
    }
    printf("\nEnter the amount of pages:");
    scanf("%i", &inputbook.pages);      //pages
    //error traps pages
    while(inputbook.pages <1)
    {
        printf("Please enter a valid number of pages: ");
        scanf("%f", &inputbook.rating);
    }
    //processes all the stuff
    strcpy(inputbook.stitle, inputbook.title); //copies
    for(z=0; inputbook.stitle[z] != '\0'; z++)
    {
        
        inputbook.stitle[z]= toupper(inputbook.stitle[z]);   //upercases

    }

    strcpy(inputbook.sauthor, inputbook.author);    //copies
    for(z=0; inputbook.sauthor[z] != '\0'; z++) //upercases
    {
        if(isalpha(inputbook.sauthor[z]) == 1)
            inputbook.sauthor [z] = toupper(inputbook.sauthor[z]);

        
    }
    strcpy(inputbook.sgenre, inputbook.genre);  //copies
    for(z=0;inputbook.sgenre[z] != '\0'; z++)
    {
        
        inputbook.sgenre [z]= toupper(inputbook.sgenre[z]); //upercases
        
    }
    
    (*dptr)++;        //incrememnts for each book
    
    return(inputbook);      //sends back the book
    
    
}

//******************************************************
void sorter(struct BOOK abook9 [], char *repeaterptr, int *iptr)
{
    
    //resets repeater
    *repeaterptr = 'i';
    
    
    //loop for sorting info
    do
    {
        sort(abook9, &*iptr);
        againsort (&*repeaterptr);      //asks again?
    } while (*repeaterptr == 'y');
    
}
//***************sort********************************************
void sort(struct BOOK abook1[100], int *iptr)
{
    //declares input variable
    int option_num;
    
    //text of the options
    printf("\nThese are the options to sort your book collection:\n");
    puts("1. By Title");
    puts("2. By Author");
    puts("3. By Genre");
    puts("4. By Rating");
    puts("5. By Number of Pages");
    
    //gets input
    printf("Please enter the number of the option you want");
    scanf("%i", &option_num);
    //error traps input
    while(option_num > 5 || option_num <1)
    {
        printf("Please enter a valid option");
        scanf("%i", &option_num);
    }
    
    //switch cases foreach option
    switch(option_num)
    {
        case 1:
            titlesort(abook1, *&iptr );     //sends the book and #of books in them
            break;
        case 2:
            authorsort(abook1,*&iptr);
            break;
        case 3:
            genresort(abook1, *&iptr);
            break;
        case 4:
            ratingsort(abook1, *&iptr);
            break;
        case 5:
            pagesort(abook1, *&iptr);
            break;
        default:
            printf("Whoops something went wrong");  //shouldn't actually ever be printed
            
            
    }
    
}

//******************titlesort*************************************
void titlesort(struct BOOK abook2[100], int *iptr)
{
    //decalres variables
    int a = 0;
    int b = 0;
    int comp;
    struct BOOK box;
    
    //traverses and buble sorts
    for( a=0; a <*iptr; a++ )
    {   for(b=0; b<(*iptr-1); b++)
        {
           
            comp = strcmp(abook2[b].stitle, abook2[b+1].stitle);    //compares the string sizes
            
        /*    //if the first word is 'THE' itll subtract from the comp value
            if(abook2[b].stitle[0]=='T' && abook2[b].stitle[1]=='H' &&abook2[b].stitle[2] =='E')
                comp = comp-225;*/
            
                
            printf("%i", comp);
            if (comp > 0)       //swithces
            {   box = abook2 [b];
                abook2 [b] = abook2 [b +1];
                abook2 [b+1] = box;
            }
        }
    }
    
    output(abook2, *&iptr);
    
}
//******************authorsort*************************************
void authorsort(struct BOOK abook3[100], int *iptr)
{
    //decalres variables
    int a = 0;
    int b = 0;
    int comp;
    struct BOOK box;
    
    //trasverses and bubble sorts
    for( a=0; a <*iptr; a++ )
    {   for(b=0; b< (*iptr-1); b++)
        {
            comp = strcmp(abook3[b].sauthor, abook3[b+1].sauthor);  //compares sizes
            if (comp > 0)   //switches
            {   box = abook3 [b];
                abook3 [b] = abook3 [b +1];
                abook3 [b+1] = box;
            }
        }
    }
    
    output(abook3, *&iptr);
}

//******************genresort*************************************
void genresort(struct BOOK  abook4[100],int  *iptr)
{
    
    //decalres varaibles
    int a = 0;
    int b = 0;
    int comp;
    struct BOOK box;
    
    //traverses andbuble sorts
    for( a=0; a <*iptr; a++ )
    {
        for(b=0; b<(*iptr -1); b++)
        {
            comp = strcmp(abook4[b].sgenre, abook4[b+1].sgenre);    //copmares strings
            if (comp > 0)       //switches
            {   box = abook4 [b];
                abook4 [b] = abook4 [b +1];
                abook4 [b+1] = box;
            }
        }
    }
    
    output(abook4, *&iptr);
    
}

//******************ratingsort*************************************
void ratingsort(struct BOOK abook5 [100], int *iptr)
{
    
    //decalres varaibles
    int a = 0;
    int b = 0;
    struct BOOK box;
    
    //traverses and buble sorts
    for( a=0; a <*iptr; a++ )
    {   for(b=0; b< (*iptr -1); b++)
        {
            if (abook5[b].rating> abook5[b+1].rating)   //compares ratings
            {   box = abook5 [b];       //swtiches
                abook5 [b] = abook5 [b +1];
                abook5 [b+1] = box;
            }
        }
    }
    
    output(abook5, *&iptr);
}

//******************pagesort*************************************
void pagesort(struct BOOK abook6 [100], int *iptr)
{
    
    //decalres varaibles
    int a = 0;
    int b = 0;
    struct BOOK box;
    
    //traverses and buble sorts
    for( a=0; a <*iptr; a++ )
    {
        for(b=0; b< (*iptr-1); b++)
        {
            if (abook6[b].pages > abook6[b+1].pages)    //copares pages
            {   box = abook6 [b]; //swithces
                abook6 [b] = abook6[b +1];
                abook6 [b+1] = box;
            }
        }
    }
    
    output(abook6, *&iptr);
}

//***********output**************
void output(struct BOOK abook7[], int *hptr)
{
    int d;
    
    puts("List of Books:\n");
    printf("%30s|%20s|%20s|%20s|%10s|\n", "Title", "Author", "Genre", "Rating","Pages");    //gives the top of the table
    
    for(d=0; d<*hptr ; d++) ///fior each indiv line for each book
        printf("%31s%21s%21s%21.2f%11i\n", abook7[d].title, abook7[d].author , abook7[d].genre ,abook7[d].rating, abook7[d].pages);
}

//*************again*******************************************
void againbooks(char *repeaterptr)
{
    getchar();      //ges the trash
    printf("\n\nDo you have another book? (y/n):");
    
    //gets the repeat and lowercases if upper case
    
    *repeaterptr = getchar();
    
    *repeaterptr = tolower(*repeaterptr);
    
    
}

//*************again*******************************************
void againsort(char *repeaterptr)
{
    
    getchar();  //gets the trash
    printf("\n\nDo you want to sort again? (y/n):");
    
    //gets the repeat and lowercases if upper case
    
    *repeaterptr = getchar();
    *repeaterptr = tolower (*repeaterptr);
    
}

//*************again*******************************************
void againmenu(char *repeaterptr)
{
    getchar();      //trash
    
    
    printf("\n\nDo you want to run the menu again? (y/n):");
    
    //gets the repeat and lowercases if upper case
    
    *repeaterptr = getchar();
    *repeaterptr = tolower (*repeaterptr);
    
}


