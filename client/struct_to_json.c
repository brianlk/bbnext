/*
* struct_to_json.c
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#include "stdio.h"
#include "struct_to_json.h"


void StructToJSON_constructor(StructToJSON * const self, int x, char *key, char *value, int array_size) {
  self->x = x;
  self->key = key;
  self->value = value;
  printf("aaa %d\n", self->x);
  printf("bbb %s\n", self->key);
  printf("ccc %s\n", self->value);
}