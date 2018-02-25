#include <stdio.h>

void strcat(char *ps, char *pt);

void strcat(char *ps, char *pt)
{
  while (*ps != '\0')
    ps++;
  while (*pt != '\0')
  {
    *ps = *pt;
    ps++;
    pt++;
  }
}

int main()
{
  char s1[12] = "Birth";
  char t1[5] = "day";
  printf("s1 = %s, t1 = %s\n", s1, t1);
  strcat(s1, t1);
  printf("%s\n\n", s1);

  char s2[12] = "Basket";
  char t2[5] = "ball";
  printf("s2 = %s, t2 = %s\n", s2, t2);
  strcat(s2, t2);
  printf("%s\n\n", s2);

  char s3[12] = "Rail";
  char t3[5] = "road";
  printf("s3 = %s, t3 = %s\n", s3, t3);
  strcat(s3, t3);
  printf("%s\n\n", s3);

  return 0;
}
