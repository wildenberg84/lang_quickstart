#include "Includes.h"

#define ALERT '\a' // global constant, NOTE that a type is not given here
const char alert = '\a'; // also global constant, lets you declare a type

/****************
* C is pass-by-value !
* use pointers to make changes that persist outside of the function!
****************/

int main(int argc, char *argv[])
// int main(void) -- if you have no need for arguments
{
    char *arg1 = argv[0];
    printf("The first arguments is always the program title (full path) : \n%s\n\n", arg1);

    enum color {Red, Green, Blue = 5, Yellow}; // indexed
    enum color myColor = Blue;
    enum color green = 1;
    enum color yellow = Yellow;

    printf("Blue is: %d, yellow is: %d\n", myColor, yellow);

    // short datatype is short for short signed int
    short signed int one = 10 + 14; // <-- statement (ends with a ; in C)
                        // ^------^ <-- expression
    short int two = 10;
    short three = 10;

    char message[] = "C uses infix operators (10 + 10),\n";
    printf("you can get the length of a string with strlen() : message is %d characters long\n", strlen(message));

    printf(message);
    printf("there's also prefix (+ 10 10) and postfix (10 10 +)\n\n");

    char msg[100];
    strcpy(msg, "since C does't allow you to assign to array, you will have to use strcpy to assign a new value to a char array (string)");
    // use strncpy to prevent buffer overflow, strcpy depends on \0 termination which may not happen!
    printf("%s\n", msg);


    char *token;
    token = strtok(msg, ","); // get first token, use , as delimiter

    register int tokenCount = 1; // register variable for fast access (stored in register), only use if compiler optimization is turned off!!! (basically deprecated)
    while(token != NULL)
    {
        printf("%d : %s\n", tokenCount, token);
        tokenCount++;
        token = strtok(NULL, ",");
    }


    // ANSI C
    char alert = '\a'; // alert (usually OS sound setting), NOTE: this is a command line feature
    printf ("%c", ALERT);

    char first[100];
    char last[100];
    int age;

    printf("use the sizeof operator to determine the size of things, char array first is %d long\n\n", sizeof(first));
    // logical operators
    if(1 == 1 && 2 == 2)
    {
            printf("logical operators consist of two characters (such as &&)\n\n");
    }

    int bit1 = 12;
    int bit2 = 15;

    printf("Bitwise operators are single character like bit1 & bit2 = %d.\n\n", bit1 & bit2); // 00001100, 00001111
    printf("Bitshift operators are the usual double arrows (<<, >>) like 3 >> 2 = %d.\n\n", 3 >> 2); // 00000011, 00000000

    printf("What is your full name?\n");
    scanf("%s %s", first, last);

    printf("Welcome %s, how old are you?\n", first);
    scanf("%d", &age); // digit, & turns a value into a memory address

    _Bool run = 1;
    if(run)                 // <
    {                       //  | <-- compound statement
        first[3] = 'z';     //  |
    }                       // <

    printf("So your first name is %s, your last name is %s and you're %d years old.\n", first, last, age);


    int high = 100;
    char low = (char) high; // explicit cast, wraps around if too large
    printf("casted value : %c\n", low);


    char value[] = "513";
    int converted = atoi(value);
    printf("you can also convert strings to numbers with for example atoi(), which converts it to an integer : %d\n\n", converted);

    // pointers
    runPointers();
    memAlloc();

    // struct
    runStructs();

    // files
    runFiles();
    formattedWrite();
    formattedRead();

    // environment
    getSomeEnv();
    systemCmd();

    /*********************************
    * Skip to data structures
    *********************************/
    printf("Do you want to run the data structures? y / n:\n");
    char response;

    while ((getchar()) != '\n'); // clear input buffer of any remaining newlines (yes there is one from previous scanf)
    response = getchar(); // get a single char from input buffer (this also leaves a newline in the buffer)

    if(response == 'y')
    {
        system("cls"); // WARNING: this is NOT portable!


    }


    // testing (assert)
    error();
    test(); // <-- halts / stops program

    // stdbool.h
    bool on = true;
    if(on == true)
    {
        printf("\nBy using stdbool.h you can use standard bool naming and values!\n");
    }
}
