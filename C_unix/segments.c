
#include <stdio.h>
#include <stdlib.h>

/* 
 * The symbols must have some type,
 * or "gcc -Wall" complains:
 * (warning: type defaults to ‘int’ in declaration of ‘etext’)
 * extern etext, edata, end; 
 */
extern char etext, edata, end; 

int main()
{
    printf("First address after boundary:\n");
    printf("TEXT SEGMENT (etext)\t%10p\n", &etext);
    printf("INIT DATA (edata)\t%10p\n", &edata);
    printf("UNINIT DATA (end)\t%10p\n", &end);

return 0;
}
