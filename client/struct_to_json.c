/*
* struct_to_json.c
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "struct_to_json.h"

void StructToJSON_constructor(StructToJSON * const self, char *key_and_value) {
  
  char *key = strtok(key_and_value, ":");
  self->key = key;
  char *value = strtok(NULL, ":");
  self->value = value;

  // initialize the object and trigger counter
  StructToJSON_counter(self);

  printf("%s => %s\n", self->key, self->value);
}

void StructToJSON_counter(StructToJSON * const self) {
  static int count = 0;
  count += 1;
  printf("%d", count);
}
