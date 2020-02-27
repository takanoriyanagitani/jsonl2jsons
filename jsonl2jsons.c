#include <stdio.h>
#include <stdlib.h>

#include "jsonl2jsons.h"

int sub(const char* i, const char* o){
  FILE* fi = NULL;
  FILE* fo = NULL;
  fi = NULL == i ? NULL : fopen(i, "rb");
  fo = NULL == o ? NULL : fopen(o, "wb");
  int ret = jsonl2jsons(fi, fo);
  int ci = NULL == fi ? 1 : 0 == fclose(fi);
  int co = NULL == fo ? 1 : 0 == fclose(fo);
  return ci && co && 0 == ret ? 0 : -1;
}

int main(int argc, char** argv){
  switch(argc){
    default: return sub(NULL,    NULL);
    case 2:  return sub(argv[1], NULL);
    case 3:  return sub(argv[1], argv[2]);
  }
}
