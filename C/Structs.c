#include <stdio.h>
#include "Includes.h"

// pass-by-value means every struct (including data) gets copied!!
void someMethod(struct book *input)
{
    if(!input)
    {
        input->ISBN = 12345L; // changes are visible on the outside of the function,
                              // and nothing is copied except for the pointer value (memory address)
        printf("new ISBN : %ld\n\n", input->ISBN);
    }

    return;
}

void runStructs()
{
    struct date today;
    today.day = 30;
    today.month = 8;
    today.year = 2018;

    struct date newDate = {2018, 12, 28};
    today = (struct date) {2015, 3, 20}; // compound literals
    today = (struct date) {.day = 12, .month = 3, .year = 2010}; // this way you can arrange the arguments however you want

    // create a struct on the fly
    struct tmp
    {
        int test;
    } tmpStruct;

    tmpStruct.test = 12;
    printf("\n\n%d\n", tmpStruct.test);


    // array of structures
    struct date allDates[20];
    allDates[0].year = 2010; // you have to set each field separately
    allDates[19].day = 31;

    struct date newDates[10] = {[1].year = 2018, [1].month = 10, [1].day = 26};
    struct date otherDates[3] = {{2010, 1, 1}, {2011, 1, 1}, {2012, 1, 1}}; // note that the internal {} are optional


    struct book book1;
    strcpy(book1.author, "Stephen King");
    book1.ISBN = 123456789L;
    book1.releaseDate.year = 2015;
    book1.releaseDate.month = 10;
    book1.releaseDate.day = 12;

    printf("%s released a book with the ISBN %ld on %d-%d-%d\n", book1.author, book1.ISBN, book1.releaseDate.year, book1.releaseDate.month, book1.releaseDate.day);


    Book *book2 = NULL; // <-- using user define type name for struct book
    book2 = malloc(sizeof(struct book)); // WARNING, always use the type you're using,
                                         // book2 in this case only allocates the size of the pointer and can cause very unpredictable behaviour
                                         // (or no error at all)

    if(!book2)
    {
        printf("could not allocate memory");
        exit(1);
    }

    strcpy((*book2).author, "Author here");
    (*book2).ISBN = 987654321L;
    book2->releaseDate.year = 2009; // struct->member is the same as (*struct).member
    book2->releaseDate.month = 12;
    book2->releaseDate.day = 14;
    // pointers to structs are so frequently used that C has a shorthand notation implemented

    printf("%ld\n", book2->ISBN);

    someMethod(book2); // if the return is removed from this function, C does NOT wait for it to finish

    /***************************
    * release allocated memory
    ***************************/
    free(book2);
    book2 = NULL;

    return;
}


