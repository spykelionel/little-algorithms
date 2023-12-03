#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

typedef struct
{
  char from[MAX_LEN + 1];
  char to[MAX_LEN + 1];
} Pair;

int replace(char *para, int N, Pair *pairs, int M, int L)
{

  char *result = malloc(sizeof(char) * (N + 1));
  strcpy(result, para);

  char *word = malloc(sizeof(char) * (L + 1));

  int i, j;
  int index = 0;
  while (index < N)
  {

    // Extract word
    int wordLen = 0;
    while (index + wordLen < N && wordLen <= L &&
           result[index + wordLen] != ' ')
    {
      word[wordLen] = result[index + wordLen];
      wordLen++;
    }
    word[wordLen] = '\0';

    // Check if this word needs to be replaced
    for (i = 0; i < M; i++)
    {
      if (strcmp(word, pairs[i].from) == 0)
      {

        // Replace word
        for (j = 0; j < strlen(pairs[i].to); j++)
        {
          result[index + j] = pairs[i].to[j];
          printf("result[index + j]:%s\n", result[index + j]);
          printf("pairs[i].to[j]:%s\n", pairs[i].to[j]);
          printf("Resutls:%s\n", result);
        }
        index += strlen(pairs[i].to);
        break;
      }
    }

    if (i == M)
    {
      index += wordLen;
    }
  }

  printf("%s\n", result);

  free(word);
  free(result);

  return 0;
}

int main()
{

  int T;
  scanf("%d", &T);
  printf("%d\n", T);

  while (T--)
  {

    int L, M, N;
    scanf("%d %d %d", &L, &M, &N);

    Pair *pairs = malloc(M * sizeof(Pair));
    for (int i = 0; i < M; i++)
    {
      scanf("%s %s", pairs[i].from, pairs[i].to);
    }

    char para[MAX_LEN + 1];
    scanf(" %[^\n]s", para);

    replace(para, N, pairs, M, L);

    free(pairs);
  }

  return 0;
}
