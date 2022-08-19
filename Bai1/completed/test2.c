#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    FILE *f = fopen("vanban.txt", "r");
    char c;
    char str[256];
    while (!feof(f))
    {
        c = fgetc(f);//printf("%c", c);
        if (c == '\n' || c = '\r')
        {
            
        }
        else
        {
            printf("%s\n",str);
            str[0]="\0";
        }
    }
}