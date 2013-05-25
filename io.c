#include "io.h"
#include "head.h"

char *read_file(const char *p)
{
    FILE *fp = fopen(p, "rb");
    char *buf = (char *)malloc(sizeof(char) * MAX_CHAR);
    if(!fp) {
        printf("Open file %s failed", p);
        exit(1);
    }
    fgets(buf, MAX_CHAR, fp);
    fclose(fp);
    return buf;
}

void write_file(const char *p, const char *data)
{
    FILE *fp = fopen(p, "w");
    if(!fp) {
        printf("Open file %s failed", p);
        exit(1);
    }
    fputs(data, fp);
    fclose(fp);
}

int file_exist(const char *p)
{
    if(access(p, 0) == -1)
        return 0;
    return 1;
}
