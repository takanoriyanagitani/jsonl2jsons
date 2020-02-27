#include <stdio.h>
#include <stdlib.h>

#include "jsonl2jsons.h"

int test(const char* json_line, const char* tlen, const char* offset, const char* expected){
  long lt = atol(tlen);
  long lo = atol(offset);
  uint8_t* target = (uint8_t*)malloc(lt);
  switch(NULL != target && 3 <= lt ? 1 : 0){
    case 0: break;
    default:
      target[0] = '[';
      break;
  }
  printf("lt: %ld, lo: %ld\n", lt, lo);
  int appended = NULL != target ? jsonl2jsons_append(json_line, target, lt, lo) : -1;
  switch(appended){
    default: break;
    case 0:
      //target[lo+strlen(json_line)-1] = ']';
      break;
  }
  printf("appended: %d, slen: %ld\n", appended, strlen(json_line));
  printf("target: %.*s\n", 1 + (int)strlen(json_line), target);
  int ret = 0 == appended && NULL != target && 0 == memcmp(expected, target, strlen(expected)) ? 0 : -1;
  free(target);
  return ret;
}

int main(int argc, char** argv){
  switch(argc){
    default: return test("{}\n", "16384", "1", "[{},");
    case 5:  return test(argv[1], argv[2], argv[3], argv[4]);
  }
  return 0;
}
