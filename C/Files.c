#include "Includes.h"

#define FILEIN "Test.txt"
#define FILEOUT "out.txt"

void readSize()
{
    FILE *fp = NULL; // set to NULL to avoid access violations!
    int len;

    fp = fopen(FILEOUT, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);

    len = ftell(fp);
    fclose(fp);

    printf("Total size of file %s is %d bytes.\n", FILEOUT, len);

    return;
}

void formattedWrite()
{
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2018);

   fclose(fp);

   return;
}

void formattedRead()
{
   char str1[10], str2[10], str3[10];
   int year;
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fputs("We are in 2012", fp);

   rewind(fp);
   fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

   printf("Read String1 |%s|\n", str1 );
   printf("Read String2 |%s|\n", str2 );
   printf("Read String3 |%s|\n", str3 );
   printf("Read Integer |%d|\n", year );

   fclose(fp);

   return;
}

void runFiles()
{
    // store volatile memory to disk / non-volatile memory
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = ' ';

    fp = fopen(FILEIN, "r"); // use rb for binary mode

    if (fp == NULL)
    {
        printf("\nFile does not exist!\n");
        return;
    }
    else
    {
        printf("input file found\n");
    }

    // create a temp file
    fp1 = fopen(FILEOUT, "w"); // use wb for binary mode

    if (fp1 == NULL)
    {
        printf("Failed to create a new file");
        return;
    }
    else
    {
        printf("output file found\n");
    }

    // copy characters from in file to out file
    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    // Print text in output file
    fp = fopen(FILEOUT, "r");

    if (fp == NULL)
    {
        printf("output file dissapeared!");
        return;
    }

    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);

    printf("\n");

    fclose(fp);
    fp = NULL;
    fp1 = NULL;


    readSize();

    return;
}
