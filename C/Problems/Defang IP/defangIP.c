#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * defangIPaddr(char * address){
    char *re = malloc(22);
    char *out = re;
    while (*address) {
        if (*address == '.') {
            *out++ = '[';
            *out++ = '.';
            *out++ = ']';
            *address++;
        } else {
            *out++ = *address++;
        }
    }
    *out = '\0';
    return re;
}

int main()
{
    char *str = "1.1.1.1";
    printf("%s", defangIPaddr(str));
    return 0;
}