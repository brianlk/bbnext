#include "stdio.h"
#include "string.h"

typedef struct {
  int id;
  char name[20];
} Student;

void change_name(Student *s) {
  strcpy(s->name,"Brian kp leung");
}

int main() {
  Student s;
  s.id = 100;
  strcpy(s.name, "Brian Leung");
  printf("%d, %s", s.id, s.name);
  change_name(&s);
  printf("%d, %s", s.id, s.name);
}

