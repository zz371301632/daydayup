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

void move_prefix_table(int prefix[], int n)
{
  for (int i = n-1; i > 0; i--)
  {
    prefix[i] = prefix[i-1];
  }
  prefix[0] = -1;
}

void kmp_search(char parent[], char prefix[])
{
  int n = strlen(prefix);
  int *kmp = malloc(sizeof(int) * n);
  find_prefix(prefix, kmp, n);
  move_prefix_table(kmp, n);
  int m = strlen(parent);
  int i = 0;
  int j = 0;
  while (i < m)
  {
    if (j == n - 1 && parent[i] == prefix[j])
    {
      printf("find %d\n", i - j);
      j = kmp[j];
      if (j == -1)
      {
        i++;
        j++;
      }
    }
    if (parent[i] == prefix[j])
    {
      j++;
      i++;
    }
    else
    {
      j = kmp[j];
      if (j == -1)
      {
        i++;
        j++;
      }
    }
  }
}

int main()
{
  char pattern[] = "b";
  char text[] = "abc";
  kmp_search(text, pattern);
  return 0;
}
