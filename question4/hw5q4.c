#include <stdio.h>

void strncpy(char *ps, char *pt, int n);

void strncpy(char *ps, char *pt, int n)
{
  int i;

  for (i = 0; i < n; ++i)
  {
    if (*pt == '\0')
      break;
    *ps = *pt;
    ps++;
    pt++;
  }
}

int main()
{
  char s1[12] = "Football";
  char t1[12] = "Railroad";
  printf("s1 = %s, t1 = %s, n1 = 4\n", s1, t1);
  strncpy(s1, t1, 4);
  printf("%s\n\n", s1);
  
  char s2[12] = "Himself";
  char t2[12] = "Her";
  printf("s2 = %s, t2 = %s, n2 = 5\n", s2, t2);
  strncpy(s2, t2, 5);
  printf("%s\n\n", s2);

  char s3[12] = "Computer";
  char t3[12] = "Monitor";
  printf("s3 = %s, t3 = %s, n3 = 5\n", s3, t3);
  strncpy(s3, t3, 5);
  printf("%s\n\n", s3);

  return 0;
}
