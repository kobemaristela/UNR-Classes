

#include "StringFunctions.h"

/** Counts characters in str array until a NULL-character '\0' is
found, then it returns that number excluding the '\0' one **/
/** The return type size_t represents an unsigned integral number
large enough to contain the maximum possible number of a storage
size that can appear on a target architecture **/
size_t myStringLength(const char * str)
{
    size_t myCount = 0;
    while(str[myCount] != '\0')
    {
        myCount++;
    }

    return myCount;
}

/** Returns 0 when the C-strings match, i.e. their characters are
equal one-by-one until a NULL-character '\0' is found in both
strings and at the same position as well **/
/** Returns a value < -1 if the first character that does not
match has a lower value in str1 than in str2 **/
/** Returns a value > 1 if the first character that does not match
has a higher value in str1 than in str2 **/
int myStringCompare(const char * str1, const char * str2)
{
    int myX;
    for(myX = 0; (myX < myStringLength(str1)) || (myX < myStringLength(str2)); myX++)
    {
        if (str1[myX] != str2[myX])
        {
            if(str1[myX] < str2[myX])
            {
                return -1;
            }
            else if (str1[myX] > str2[myX])
            {
                return 1;
            }
        }
    }

    if ((str1[myX+1] && str2[myX+1]) == '\0')
    {
        return 0;
    }
}

/** Copies characters from source to destination array until a
NULL-character '\0' is found in source, then it NULL-terminates
destination too **/
/** Returns a pointer to the destination array **/
char *myStringCopy(char * destination, const char * source)
{
    int myX;
    destination[0] = '\0';
    for(myX = 0; source[myX] != '\0'; myX++)
    {
        destination[myX] = source[myX];
    }

    destination[myX] = '\0';

    return destination;
}

/** Appends the content of source to the destination array **/
/** This means that the NULL-terminator of destination is
overwritten by the first character of source and a NULL-character
'\0' is appended at the end of the concatenated Cstring in
destination **/
/**  Returns a pointer to the destination array **/
char * myStringCat(char * destination, const char * source)
{
    char* tempFinal = destination;

    while(*destination != '\0')
    {
        destination++;
    }

    do
    {
        *destination++ = *source++;
    }while(*source != '\0');

    *destination = '\0';

    return tempFinal;
}