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
  strcpy(self->key, key);
  char *value = strtok(NULL, ":");
  strcpy(self->value, value);

}

