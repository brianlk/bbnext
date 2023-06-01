/*
* struct_to_json.h
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/30
*/


#ifndef STRUCT_TO_JSON_H
#define STRUCT_TO_JSON_H

/* object counter */
extern int counter;

struct StructToJSON {
  char key[100];
  char value[100];
};

struct Map {
  char resource[10];
  struct StructToJSON **data; 
};

typedef struct StructToJSON StructToJSON;

void StructToJSON_constructor(StructToJSON *self, char *key_and_value);

void iterate_queue_render_json(StructToJSON **sj_queue);

#endif