#pragma once

#include <stdint.h>

#include <string.h>

int jsonl2jsons_init(uint8_t* target, size_t tlen){
  switch(tlen){
    case 0: return -1; // no space for []\0
    case 1: return -1; // no space for  ]\0
    case 2: return -1; // no space for   \0
    default: return NULL != target && NULL != memset(target, 0, tlen) && NULL != memset(target, '[', 1) ? 0 : -1;
  }
}
