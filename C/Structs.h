#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct date // structs are best declared in the header file, store associated functions in the .c file
{
    int year;
    int month;
    int day;
};

typedef struct book // use typedef to name the struct type (basically name object type)
{
        char author[100];
        long ISBN;
        struct date releaseDate;
} Book;

struct sizeOfData24
{
    int a; // 4 bytes
    int c; // 4 bytes
    double b; // 8 bytes
    long long int d; // 8 bytes

    /****************************************************
    * The above results in 24 bytes (machine dependent)
    ****************************************************/
};

struct sizeOfData32
{
    int a; // 4 bytes
    double b; // 8 bytes
    int c; // 4 bytes
    long long int d; // 8 bytes

    /******************************************************************************************************************
    * The above results in 32 bytes (machine dependent)
    *
    * Storage for the basic C datatypes on an x86 or ARM processor doesn’t normally start at arbitrary byte addresses
    * in memory. Rather, each type except char has an alignment requirement;
    *
    * chars can start on any byte address, but 2-byte shorts must start on an even address,
    * 4-byte ints or floats must start on an address divisible by 4, and 8-byte longs or doubles must start on an
    * address divisible by 8 (and so on).
    *
    * Signed or unsigned makes no difference.
    *
    * The reason for this is that basic C types on x86 and ARM are self-aligned. Pointers, whether 32-bit (4-byte)
    * or 64-bit (8-byte) are self-aligned too.
    *
    * Self-alignment makes access faster because it facilitates generating single-instruction fetches and puts of the
    * typed data. Without alignment constraints, on the other hand, the code might end up having to do two or more
    * accesses spanning machine-word boundaries.
    * Characters are a special case; they are equally expensive from anywhere they live inside a single machine word.
    * That’s why they don’t have a preferred alignment.
    *
    * See http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding for more.
    ******************************************************************************************************************/
};

struct dateTime
{
    struct date Date;
    struct time // does not exist outside of dateTime
    {
        int hours;
    };
};

void runStructs();

#endif // STRUCTS_H_INCLUDED
