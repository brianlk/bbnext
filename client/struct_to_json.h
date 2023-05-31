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
};
typedef struct StructToJSON StructToJSON;

void StructToJSON_constructor(StructToJSON * const self, char *key_and_value);
void StructToJSON_counter(StructToJSON * const self);

#endif