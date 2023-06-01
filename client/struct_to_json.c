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

/* object counter */
int counter = 0;

void StructToJSON_constructor(StructToJSON *self, char *key_and_value) {
  
  char *key = strtok(key_and_value, ":");
  strcpy(self->key, key);
  char *value = strtok(NULL, ":");
  strcpy(self->value, value);

}

void iterate_queue_render_json(StructToJSON **sj_queue) {
  printf("%s", "{");
  for (int i=0; i<counter; i++) {
    /* print the objects in queue */
    printf("\"%s\":\"%s\",", (sj_queue[i])->key, (sj_queue[i])->value);
    /* release the previous allocated address */
    free(sj_queue[i]);
  }
  printf("%s", "}");
}

