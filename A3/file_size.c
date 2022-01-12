#include "functions.h"

int file_size(FILE *fp)
{
 int sz = 0;
 fseek(fp, 0L, SEEK_END);
 sz = ftell(fp);
 rewind(fp);
 return sz;
}
