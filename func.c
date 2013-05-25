#include "func.h"
#include "head.h"

char *split(const char *str, int start, int end)
{
    char *out = (char *)malloc(sizeof(char) * (end-start+1));
    memcpy(out, str+start, end-start);
    *(out+end-start)='\0';
    return out;
}
