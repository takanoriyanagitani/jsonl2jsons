#pragma once

#include <stdint.h>

#include <string.h>

int jsonl2jsons_append(const char* json_line, uint8_t* target, const size_t tlen, const size_t offset){
  static size_t required = 0;
  static size_t slen = 0;
  static int copied = 0;
  slen = strlen(json_line);
  required = jsonl2jsons_append_len(slen, offset);
  copied = required <= tlen && NULL != target && NULL != memcpy(target+offset, json_line, slen-1) ? 1 : 0;
  switch(copied){
    default: return -1;
    case 1:
      *(target+offset+slen-1) = ',';
      return 0;
  }
}
