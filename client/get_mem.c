#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "regex.h"
#include "struct_to_json.h"


#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64


const char *metrics[] = {
  "MemTo",
  "MemFr",
  "MemAv",
  "SwapT",
  "SwapF",
  "Cache"
};

bool print_json(char *metrics_key, char *metrics_value, int array_size) {
  // printf("%s => %s\n", metrics_key, metrics_value);
  StructToJSON *ptr;
  ptr = (StructToJSON*) malloc(array_size * sizeof(StructToJSON));
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(EXIT_FAILURE);
  }
  ptr->key = metrics_key;
  ptr->value = metrics_value;
  printf("\"%s\":\"%s\",", metrics_key, metrics_value);
  free(ptr);
}


bool match_regex(char *str) {
  regex_t regex;
  const char *pattern = "[0-9]";
  int reg_comp = regcomp(&regex, pattern, 0);
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

  token = strtok(str, delimiter);
  while (token != NULL) {
    if (match_regex(token)) {
      return token;
    }
    token = strtok(NULL, delimiter);
  }
}


bool extract_items(FILE *fp) {
  char buffer[BUFFERSIZE];

  // Read the file until eof
  while (!feof(fp)) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer == NULL)
      break;
    // loop the metrics array and get the metrics
    char *target = strndup(buffer, 5);
    int array_size = sizeof(metrics)/sizeof(metrics[0]);
    for (int i=0; i<array_size; i++) {
      if (strcmp(target, metrics[i]) == 0){
        // extract the value of each memory items
        print_json(buffer, extact_values(buffer), array_size);
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
  if ( !extract_items(fp) ) {
    printf("Extract failed!");
    exit(EXIT_FAILURE);
  }
  fclose(fp);

  return EXIT_SUCCESS;
}