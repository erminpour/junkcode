
/*
 * string_init.h
 * Victor Erminpour
 * (C) 2018
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    //String literals are stored as arrays of char with a terminating 
    //0 byte, so the size of the array is 
    //7 ('s', 't', 'r', 'i', 'n', 'g', 0). 
    char string[] = "string";
    fprintf(stdout, "%s\n", string);

    // Should print 6, as strlen() doesn;t count '\0'
    fprintf(stdout, "strlen(string) = %d\n", strlen(string));

return 0;
}




