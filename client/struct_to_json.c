/*
* struct_to_json.c
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#include "stdio.h"
#include "struct_to_json.h"


void StructToJSON_constructor(StructToJSON * const self, char *key, char *value, int array_size) {
  self->key = key;
  self->value = value;
}

void StructToJSON_print_map(StructToJSON * const self) {
  printf("%s => %s\n", self->key, self->value);
}