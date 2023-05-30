/*
* get_mem.c
* Program for get linux memory metrics
* by Brian Leung
* created 2023/05/29
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "regex.h"
#include "struct_to_json.h"


#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64


const char *defined_metrics[] = {
  "MemTo",
  "MemFr",
  "MemAv",
  "SwapT",
  "SwapF",
  "Cache"
};

// TODO
// bool print_json(char *metrics_key, char *metrics_value, int array_size) {
//   StructToJSON s1;
//   StructToJSON_constructor(&s1, metrics_key, metrics_value, array_size);
//   StructToJSON_print_map(&s1);
  // printf("%s => %s\n", metrics_key, metrics_value);
  // StructToJSON *ptr;
  // ptr = (StructToJSON*) malloc(array_size * sizeof(StructToJSON));
  // if (ptr == NULL) {
  //   printf("Memory not allocated.\n");
  //   exit(EXIT_FAILURE);
  // }
  // ptr->key = metrics_key;
  // ptr->value = metrics_value;
  // printf("\"%s\":\"%s\",", metrics_key, metrics_value);
  // xxx(ptr);
  // free(ptr);
// }


bool match_regex(char *str, const char * pattern) {
  regex_t regex;

  int reg_comp = regcomp(&regex, pattern, REG_EXTENDED);
  if (reg_comp != 0) {
    printf("Error:");
    exit(EXIT_FAILURE);
  }
  int reg_exec = regexec(&regex, str, 0, NULL, 0);
  if (reg_exec == 0) {
    return true;
  }
  return false;
} 


char* extact_values(char *str) {
  // Split the string into tokens
  char *delimiter = " ";
  char *token;
  static int count = 0;

  count++;
  printf("---%d\n", count);



  token = strtok(str, delimiter);
  if (match_regex(token, "([a-zA-Z]+):")) {
    printf("%s", token);
  }
  while (token != NULL) {
    if (match_regex(token, "[0-9]+")) {
      printf("%s", token);
      return token;
    }
    token = strtok(NULL, delimiter);
  }

}


bool get_defined_items(FILE *fp) {
  char buffer[BUFFERSIZE];

  // Read the file until eof
  while (!feof(fp)) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer == NULL)
      return false;
    // loop the metrics array and get the metrics
    char *buffer_substr = strndup(buffer, 5);
    int array_size = sizeof(defined_metrics)/sizeof(defined_metrics[0]);
    for (int i=0; i<array_size; i++) {
      if (strcmp(buffer_substr, defined_metrics[i]) == 0){
        // extract the value of each memory items
        // print_json(buffer, extact_values(buffer), array_size);
        // printf("%s", buffer);
        extact_values(buffer);
        puts("===============================");
      }
    }
  }
  return true;
}


int main() {
  FILE *fp;

  // open "/proc/meminfo"
  fp = fopen(MEMINFO, "r");
  if (fp == NULL) {
    puts("Error: Can't open the file!");
    exit(EXIT_FAILURE);
  }
  if ( !get_defined_items(fp) ) {
    printf("Extract failed!");
    exit(EXIT_FAILURE);
  }
  fclose(fp);

  return EXIT_SUCCESS;
}