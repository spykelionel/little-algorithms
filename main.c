/**
 * Word Replacement Program
 *
 * Description:
 *   This program takes as input a paragraph and a set of word pairs. It
 *   replaces occurrences of specified words with their corresponding replacements
 *   in the given paragraph. The replacements are performed based on the provided
 *   word pairs.
 *
 * Inputs:
 *   - T: Number of test cases
 *   - For each test case:
 *     - L: Maximum word length
 *     - M: Number of word pairs
 *     - N: Paragraph length
 *     - pairs: Array of M word pairs (find and replace word)
 *     - para: Paragraph string
 *
 * Outputs:
 *   - Modified paragraph strings for each test case with specified replacements.
 *
 * Note:
 *   - The program utilizes a custom function 'replace' to perform the word
 *     replacements in the paragraph.
 *   - The word replacement is case-sensitive.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

/** Structure to represent pairs of words for replacement */
typedef struct
{
  char from[MAX_LEN + 1];
  char to[MAX_LEN + 1];
} Pair;

/**
 * Function to replace words in a given paragraph
 *
 * @param para Paragraph to be modified
 * @param N Length of the paragraph
 * @param pairs Array of word pairs for replacement
 * @param M Number of word pairs
 * @param L Maximum word length
 * @return 0 on success
 */
int replace(char *para, int N, Pair *pairs, int M, int L)
{
  /*
   * Implementation details:
   *   - Allocates memory for the result paragraph
   *   - Extracts words one by one from the input paragraph
   *   - Checks if the word needs to be replaced based on the provided pairs
   *   - Performs replacement if necessary
   *   - Prints the resulting paragraph
   *   - Frees allocated memory
   */

  char *result = malloc(sizeof(char) * (N + 1));
  strcpy(result, para);

  char *word = malloc(sizeof(char) * (L + 1));

  int i, j;
  int index = 0;
  while (index < N)
  {
    /* Extract word */
    int wordLen = 0;
    // printf("Begin word extraction\n");
    while (index + wordLen < N && wordLen <= L &&
           result[index + wordLen] != ' ')
    {
      word[wordLen] = result[index + wordLen];
      wordLen++;
    }
    word[wordLen] = '\0';
    // printf("Completed word extraction succesffully\n");
    // printf("Extracted word %s\n", word);

    /* Check if this word needs to be replaced */
    for (i = 0; i < M; i++)
    {
      if (strcmp(word, pairs[i].from) == 0)
      {
        /* Replace word */
        for (j = 0; j < strlen(pairs[i].to); j++)
        {
          result[index + j] = pairs[i].to[j];
          // printf("Replaced %s with %s\n", pairs[i].from, pairs[i].to);
        }
        index += strlen(pairs[i].to);
        break;
      }
      else
      {
        printf("This was horrible example paragraph to test with!\n");
        return 0;
      }
    }

    /* Move index to the next word, if it equals number of word pairs.*/
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

/** Main function */
int main()
{
  /*
   * Implementation details:
   *   - Reads the number of test cases (T)
   *   - For each test case:
   *     - Reads values for L, M, and N
   *     - Allocates memory for an array of pairs
   *     - Reads pairs of words for replacement
   *     - Reads the paragraph
   *     - Calls the replace function
   *     - Frees allocated memory for pairs
   */

  int T, exitStatus = 0;
  scanf("%d", &T);

  while (T--)
  {
  }
  int L, M, N;
  scanf("%d %d %d", &L, &M, &N);

  Pair *pairs = malloc(M * sizeof(Pair));
  for (int i = 0; i < M; i++)
  {
    scanf("%s %s", pairs[i].from, pairs[i].to);
  }

  /*The paragraph input to be modified*/
  char para[MAX_LEN + 1];
  scanf(" %[^\n]s", para);

  replace(para, N, pairs, M, L);

  free(pairs);

  printf("Exiting with Status: %d\n", exitStatus);
  return (exitStatus);
}
