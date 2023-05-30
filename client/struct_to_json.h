/*
* struct_to_json.h
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#ifndef STRUCT_TO_JSON_H
#define STRUCT_TO_JSON_H

struct StructToJSON {
  char *key;
  char *value;
  int x;
};
typedef struct StructToJSON StructToJSON;

void StructToJSON_constructor(StructToJSON * const self, int x, char *key, char *value, int array_size);
int StructToJSON_method(StructToJSON * const self);

#endif