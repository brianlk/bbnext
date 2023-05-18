/* Student Database Add records */
#include <stdio.h>
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
  fp = fopen ("records.dat", "wb");
  if(fp) {
    printf ("== Student Database Add records ==\n");
    printf ("Name : ");
    scanf ("%[^\n]", s.name);
    fflush (stdin);
    printf ("Roll : ");
    scanf ("%d", &s.roll);
    printf ("Std : ");
    scanf ("%d", &s.std);
    if (fwrite(&s, sizeof(s), 1, fp)) {
      printf ("Record added.");
    }
    fclose(fp);

 }
 return 0;
}
