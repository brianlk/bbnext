/*
* struct_to_json.h
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#ifndef STRUCT_TO_JSON_H
#define STRUCT_TO_JSON_H

// object counter
extern int counter;

struct StructToJSON {
  char key[100];
  char value[100];
};
typedef struct StructToJSON StructToJSON;

void StructToJSON_constructor(StructToJSON * const self, char *key_and_value);

void iterate_queue(StructToJSON **sj_queue);

#endif