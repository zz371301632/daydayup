#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void find_prefix(char str[], int prefix[], int n)
{
  prefix[0] = 0;
  int i = 1;
  int len = 0;
  while (i < n)
  {
    len = prefix[i - 1];
    if (str[len] == str[i])
    {
      prefix[i] = len + 1;
    }
    else
    {
      prefix[i] = 0;
    }
    i++;
  }
}

void to_kmp_key(int prefix[], int n)
{
  for (int i = n-1; i > 0; i--)
  {
    prefix[i] = prefix[i-1];
  }
  prefix[0] = -1;
}

int kmp(char parent[], char prefix[], int kmp[], int n)
{
  int p_n = strlen(parent);
  printf("p_n %d\n", p_n);
  int i = 0;
  int j = 0;
  while (i < p_n)
  {
    while (parent[i] == prefix[j])
    {
      j++;
      printf("i %d\n", i);
      printf("j %d\n", j);
      printf("n %d\n", n);
      if (j > n - 1)
      {
        printf("find:");
        return i;
      }
      else
      {
        j = kmp[j];
        i++;
      }
    }
  }
  printf("not find:");
  return -1;
}

int main()
{
  char parent[] = "befaabcdabcdfeefe";
  char str[] = "abcdabcdf";
  int n = strlen(str);
  int *i_result = malloc(sizeof(int) * n);
  find_prefix(str, i_result, n);
  to_kmp_key(i_result, n);
  // for (int i = 0; i < n; i++)
  // {
  //   printf("%d\n", i_result[i]);
  // }
  int position = kmp(parent, str, i_result, n);
  printf("%d\n", position);
  return 0;
}
