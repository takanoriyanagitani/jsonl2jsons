#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "jsonl2jsons.h"

int test(const char* json_line, const char* tlen, const char* offset, const char* expected, const char* erc){
  long lt = atol(tlen);
  long lo = atol(offset);
  int rc = atoi(erc);
  uint8_t* target = 0 < lt ? (uint8_t*)malloc(lt) : NULL;
  switch(NULL != target && 3 <= lt ? 1 : 0){
    case 0: break;
    default:
      target[0] = '[';
      break;
  }
  int arc = jsonl2jsons_append(json_line, target, lt, lo);
  switch(lt){
    default: break;
    case 0: return arc == rc ? 0 : -1;
    case 1:
    case 2:
    case 3:
    case 4:
      free(target);
      return arc == rc ? 0 : -1;
  }
  int ret = rc == arc && NULL != target && 0 == memcmp(expected, target, strlen(expected)) ? 0 : -1;
  free(target);
  return ret;
}

int test_rows(const char* i1, const char* i2, const char* e){
  size_t s1 = strlen(i1);
  size_t se = strlen(e);
  uint8_t* target = (uint8_t*)malloc(se+1);
  jsonl2jsons_init(target, se+1);
  int ok = 0 == jsonl2jsons_append(i1, target, se+1, 1);
  ok = ok && 0 == jsonl2jsons_append(i2, target, se+1, 1+s1);
  ok = ok && NULL != memset(target+se-1, ']', 1);
  int ret = NULL != target && 0 == memcmp(e, target, se+1) ? 0 : 0 < fprintf(stdout, "expected: %s, actual: %s\n", e, target);
  free(target);
  return ok ? ret : -1;
}

int main(int argc, char** argv){
  switch(argc){
    default: return test("{}\n", "16384", "1", "[{},", "0");
    case 6:  return test(argv[1], argv[2], argv[3], argv[4], argv[5]);
    case 5:  return test_rows(argv[1], argv[2], argv[3]);
  }
  return 0;
}
