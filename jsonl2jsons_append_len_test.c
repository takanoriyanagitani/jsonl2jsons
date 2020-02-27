#include <stdio.h>
#include <stdlib.h>

#include "jsonl2jsons.h"

int test(const char* slen, const char* offset, const char* expected){
  long ls = atol(slen);
  long lo = atol(offset);
  long le = atol(expected);
  long la = jsonl2jsons_append_len(ls, lo);
  return la == le ? 0 : 1;
}

int main(int argc, char** argv){
  switch(argc){
    default: return test("0", "0", "1");
    case 4:  return test(argv[1], argv[2], argv[3]);
  }
  return 0;
}
