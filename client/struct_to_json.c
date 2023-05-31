/*
* struct_to_json.c
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#include "stdio.h"
#include "string.h"
#include "struct_to_json.h"


void StructToJSON_constructor(StructToJSON * const self, char *key_and_value) {
  char *key = strtok(key_and_value, ":");
  self->key = key;
  char *value = strtok(NULL, ":");
  self->value = value;

  printf("%s => %s\n", self->key, self->value);
}

void StructToJSON_print_map(StructToJSON * const self) {
  printf("%s => %s\n", self->key, self->value);
}