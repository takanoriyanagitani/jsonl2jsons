#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "jsonl2jsons.h"

int test(const char* ni, const char* ne, const char* cr){
  int cd = chdir("./testdata");
  FILE* fi = fopen(ni, "r");
  FILE* fe = fopen(ne, "r");

  jsonl2jsons_reader r = {
    fi,
    jsonl2jsons_reader_f,
  };
  uint8_t j[16384] = {0};
  char    l[1024]  = {0};
  ssize_t offset = jsonl2jsons_append_rows(r, j, 16384, l, 1024);
  ssize_t sr     = atol(cr);

  uint8_t* eb = 0 < offset ? (uint8_t*)malloc(offset) : NULL;
  size_t   es = fread(eb, 1, offset, fe);

  int ci = NULL != fi && 0 == fclose(fi) ? 0 : -1;
  int ce = NULL != fe && 0 == fclose(fe) ? 0 : -1;
  int ok = 1;
  ok = ok && 0 == cd;
  ok = ok && 0 == ci;
  ok = ok && 0 == ce;
  ok = ok && 0 < offset;
  ok = ok && sr == offset;
  ok = ok && es == offset;
  ok = ok && 0 == memcmp(eb, j, offset);
  ok = ok && -1 == jsonl2jsons_append_rows(r, NULL, 0, NULL, 0);
  ok = ok && -1 == jsonl2jsons_append_rows(r, NULL, 0, NULL, 1);
  ok = ok && -1 == jsonl2jsons_append_rows(r, NULL, 1, NULL, 1);
  ok = ok && -1 == jsonl2jsons_append_rows(r, NULL, 2, NULL, 1);
  ok = ok && -1 == jsonl2jsons_append_rows(r, NULL, 3, NULL, 1);
  free(eb);
  return ok ? 0 : -1;
}

int main(int argc, char** argv){
  switch(argc){
    default: return test("i1.jsonl", "e1.json", "70");
    case 4:  return test(argv[1],    argv[2],   argv[3]);
  }
}
