#include <stdio.h>

int strend(char *ps, char *pt);

int strend(char *ps, char *pt)
{
  int count = 0;

  while (*ps != '\0')
    ps++;
  
  while (*pt != '\0')
  {
    pt++;
    count++;
  }
  
  for (count; count >= 0; --count)
  {
    if (*ps != *pt)
      return 0;
    --ps;
    --pt;
  }

  return 1;
}

int main()
{
  char s1[12] = "Birthday";
  char t1[6] = "day";
  printf("s1 = %s, t1 = %s, result = %d\n\n", s1, t1, strend(s1, t1));

  char s2[12] = "Basketball";
  char t2[6] = "bal";
  printf("s2 = %s, t2 = %s, result = %d\n\n", s2, t2, strend(s2, t2));

  char s3[12] = "Railroad";
  char t3[6] = "road";
  printf("s3 = %s, t3 = %s, result = %d\n\n", s3, t3, strend(s3, t3));

  return 0;
}
