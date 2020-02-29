#pragma once

#include <stdint.h>

#include <string.h>

typedef struct {
  void* ctx;
  char* (*read_line)(void* ctx, char* buf, const uint16_t size);
} jsonl2jsons_reader;

char* jsonl2jsons_reader_f(void* ctx, char* buf, const uint16_t size){
  FILE* fp = (FILE*)ctx;
  return fgets(buf, size, fp);
}

ssize_t jsonl2jsons_append_rows(jsonl2jsons_reader r, uint8_t* j, const size_t jl, char* l, const uint16_t ll){
  switch(ll){ case 0: return -1; }
  switch(jl){
    case 0: return -1; /* no space for []\0 */
    case 1: return -1; /* no space for  ]\0 */
    case 2: return -1; /* no space for   \0 */
  }
  switch(NULL == j || NULL == l ? -1 : 0){
    case 0: break;
    default: return -1;
  }
  memset(j, 0, jl);
  j[0] = '[';
  size_t offset = 1;

  char* line = r.read_line(r.ctx, l, ll);
  int rc = 0;
  for(; NULL != line && 0 == rc; line = r.read_line(r.ctx, l, ll)){
    rc = jsonl2jsons_append(line, j, jl, offset);
    offset += 0 == rc ? strlen(line) : 0;
  }
  j[offset-1] = ']';
  return 0 == rc ? offset : -1;
}
