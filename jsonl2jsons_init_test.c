#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "jsonl2jsons.h"

int test(const char* tlen, const char* e){
  size_t lt = atol(tlen);
  uint8_t* target = 0 < lt ? (uint8_t*)malloc(lt) : NULL;
  int ia = jsonl2jsons_init(target, lt);
  int ie = atoi(e);
  switch(lt){
    case 0: return ia == ie ? 0 : -1;
    case 1:
    case 2:
      free(target);
      return ia == ie ? 0 : -1;
    default: break;
  }
  int ret = 0;
  switch(lt){
    case 3:  ret = 0 == memcmp(target, "[\0\0",     3) ? 0 : -1; break;
    case 4:  ret = 0 == memcmp(target, "[\0\0\0",   4) ? 0 : -1; break;
    case 5:  ret = 0 == memcmp(target, "[\0\0\0\0", 5) ? 0 : -1; break;
  }
  free(target);
  return ret;
}

int main(int argc, char** argv){
  void* labels[] = {
    NULL,
    &&a1,
    NULL,
    &&a3,
  };
  goto* labels[argc];
  a1: return test("0", "-1");
  a3: return test(argv[1], argv[2]);
}
