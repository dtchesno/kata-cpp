#include <memory.h>
#include <stdio.h>

void remove_dup_chars(char *input)
{
    unsigned char dups[256];
    memset(dups, 0, sizeof(dups));

    int end = 0;
    for (int i = 0; input[i] != 0; i++) {
        unsigned char chr = input[i];
        if (dups[chr] != 0)
        {
            // skip char
        }
        else
        {
            dups[chr] = 1;
            input[end] = chr;
            end++;
        }
    }
    input[end] = 0;
}
