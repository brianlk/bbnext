#include "stdio.h"
#include "string.h"

typedef struct _student_t
{
  char name[20];
  int roll;
  int std;

} student_t;
int main(int argc, char *argv[])
{
    FILE *fp;
  student_t s;
  memset(&s, 0, sizeof(s));
  fp = fopen ("records.dat", "rb");
  if(fp) {
    printf ("== Student Database Display records ==\n");
    if (fread (&s, sizeof(s), 1, fp)) {
      printf ("Name : %s, Roll : %d, Std : %d\n", s.name, s.roll, s.std);
    }
    fclose(fp);

  }
  return 0;
}
