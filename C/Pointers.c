#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(char *to, char *from)
{
    while(*from) // strings in C are terminated with '\n' (NULL) which is equal to 0
        *to++ = *from++;

    *to = '\0'; // set last character to NULL to indicate the end of the string
}

int doubleUp(int value)
{
    return value * 2;
}

void functionArg(int (*funct)(int)) { // function as argument
   printf("*****  %d  *****\n\n", funct(5));
}

void runPointers()
{
    /***************************************************************
    *                           POINTERS
    ***************************************************************/
    int age = 10;
    int *pAge = &age; // create a pointer pAge and assign the memory address of the variable (value) age
    *pAge = *pAge + 3; // assign a new value by dereferencing the pointer pAge
    printf("new age : %d\n", *pAge);
    printf("and its memory address %p\n\n", (void*)&age); // print pointer addresses with %p, warning void* creates an unidentified pointer type


    int *emptyPointer = NULL; // always assign a new pointer, even if it's NULL (does not point to anything)
    int *p, q; // NOTE only p is a pointer here, q is a regular int
    printf("pointers in this compiler use %d bytes\n\n", (int)sizeof(p)); // cast is not always needed

    char value[] = "513";
    int converted = atoi(value);
    const int *pConst = &converted; // value cannot be changed
    int *const pInt = &converted; // pointer address cannot be changed
    const int *const pUnchangable = &converted; // cannot change value or address
    //*pConst = 12; <-- error
    //pInt = &pAge; <-- error

    char *direct = "direct assignment is also possible\n";

    /****************************************************************
    *                      POINTERS TO POINTERS
    ****************************************************************/
    char text[] = "pointing to pointers";
    char *pointer = text; // array is the address so no & needed
    char **pointer_to_pointer = &pointer; // pointer to pointer address

    printf("original char array : %s\n", text);
    printf("1 : %s\n", pointer);
    printf("2 : %s\n", *pointer_to_pointer);


    int var = 999;
    int *pointer2 = &var; // array is the address so no & needed
    int **pointer_to_pointer2 = &pointer2; // pointer to pointer address

    printf("original  : %d\n", var);
    printf("1 : %d\n", *pointer2);
    printf("2 : %d\n\n", **pointer_to_pointer2);


    /**********************************
    *      POINTERS TO FUNCTIONS
    **********************************/
    /**
    printf("%p --- %p", copyString, &copyString); // <-- point to the address of the function copyString
    void (*copyString)(char *to, char *from);// = copyString; // NEVER NAME THE POINTER THE SAME AS THE FUNCTION!!!
    * ^-- now it points to the newly created pointer, and so does the (original) function pointer
    * the above overwrites the pointer pointing to the function, leading to unpredictable/undefined function behaviour
    printf("\n\n\n\n%p --- %p", copyString, *copyString);
    */
    void (*copyString2)(float *to, float *from) = copyString; // <-- not the same, but compiles just fine (gives a warning with a decent compiler)
    /** The pointer symbol binds to the type by default,
    *   so the function pointer needs the parenthesis to indicate
    *   that the pointer is actually on the name and not on the return type. */

    typedef void (*stringCopy)(char *to, char *from);
    stringCopy cpy = &copyString; // basically renames the function

    char original[] = "yep it's original!";
    char fake[] = "counterfeit!";
    cpy(original, fake);
    printf("Is it fake?");
    printf("\n%s\n\n", original);

    functionArg(doubleUp); // <-- takes the address of doubleUp (note: no brackets) and uses it as argument to a function

    /**********************************
    *       ARRAYS AND POINTERS
    **********************************/
    char someText[] = "This is some text"; // one byte each
    char *pSomeText = someText;

    printf("%s\n", someText);
    printf("Text has a length of %d characters.\n", strlen(someText));
    printf("The pointer points to '%c' and its address is %p.\n", *pSomeText, pSomeText);
    // array is stored as a bunch of pointers, so pointer + 1 is the next index no matter the data type
    printf("%p refers to the next address in memory and contains '%c'.\n", (pSomeText+1), *(pSomeText+1));
    printf("all the way up to the %d-th character (in memory address %p), which is '%c', because arrays are stored in sequential memory locations.\n\n", strlen(someText), (pSomeText + strlen(someText) - 1), *(pSomeText + strlen(someText) - 1));
    // note that C also starts from 0-index, so the last index in an array is start (pointer) + (strlen - 1)
    // Obviously you can also use &someText[index]

    // indexing using pointer arithmetic
    char *index = someText;

    while(*index != '\0')
    {
        printf("%c ", *index);
        index++;
    }

    printf("\n");


    /***************************************************************
    *                      POINTERS AND STRINGS
    ***************************************************************/
    char string1[50];
    char string2[] = "Text to be copied."; // arrays are actually pointers

    copyString(string1, string2); // to, from
    printf("%s\n", string2);
    printf("%s\n\n", string1);

    /**********************************
    *           POINTER SWAP
    **********************************/
    int swapOne = 1, swapTwo = 2;

    // int *pOne, *pTwo; <-- pointer points to random address, always use NULL or assign immediately
    // assigning a value to an uninitialized pointer overwrites some unknown memory address and may cause your entire system to crash!!!
    int *pOne = NULL, *pTwo = NULL; // NULL = 0, can test with if(!pOne) etc
    pOne = &swapOne;
    pTwo = &swapTwo;

    *pOne = *pOne ^ *pTwo;
    *pTwo = *pOne ^ *pTwo;
    *pOne = *pTwo ^ *pOne;

    printf("one : %d, two : %d\n", *pOne, *pTwo);

    return;
}

void memAlloc()
{
    //int *pNumbers = (int*) malloc(25 * sizeof(int)); // reserve space for 25 int in memory, note that malloc returns a void pointer so you need to cast it
    // NOTE: the cast here is not strictly needed, because C automatically converts a void pointer
    // C++ however DOES require the cast, so it's habit vs cleaner code

    // Clean C code would be
    int *pNumbers = malloc(25 * sizeof *pNumbers); // *pNumbers returns the value (and therefore type) of pNumbers

    if(!pNumbers)
    {
        // NULL is a zero
        // if malloc fails to allocate memory it returns NULL
        // exit program?
    }

    free(pNumbers); // free memory from pointer
    pNumbers = NULL; // break link to memory address (still pointing to it even though you released it)


    pNumbers = calloc(25, sizeof(int)); // calloc initializes the data to all 0's, almost same as malloc, but the arguments are amount and size
    // you can also use types with sizeof
    // Note that you need the extra brackets here! If it's a type (int, double and so on), you must include the brackets!

    // rest works the same
    if(!pNumbers)
    {}

    pNumbers = realloc(pNumbers, 50 * sizeof *pNumbers); // attempts to allocate another 25 ints in memory.
    // NOTE: specifying less (or 0) will actually deallocate from the provided pointer
    // must not have been free'd yet!

    if(!pNumbers) // again, check if realloc succeeded
    {}

    free(pNumbers); // free memory from pointer, ALWAYS call free if you call malloc/calloc
    pNumbers = NULL; // break link to memory address (still pointing to it even though you released it)

    return;
}


