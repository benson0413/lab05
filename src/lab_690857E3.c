#include <stdio.h>

void copy(char *psource, char *ptarget, unsigned num_char)
{
    char *p = ptarget;
    unsigned i = 0;

    if (psource == NULL || ptarget == NULL)
    {
        return;
    }

    while (i < num_char && *psource != '\0')
    {
        *p = *psource;
        p++;
        psource++;
        i++;
    }
    *p = '\0';
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
    unsigned len = 0;

    if (psrc1 == NULL || psrc2 == NULL || ptarget == NULL || buffer_size == 0)
    {
        return;
    }

    copy(psrc1, ptarget, buffer_size - 1);

    while (ptarget[len] != '\0')
    {
        len++;
    }

    copy(psrc2, ptarget + len, buffer_size - 1 - len);
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above