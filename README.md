# Title: Replace occurrences

Description:

Given a list of M pairs of words, with each word no longer than a given length L, find and replace all the occurrences of the first word of each pair by it's second word, inside a given paragraph of length N.

Input description:

The first line of the input contains the number of test cases, T. T test cases then follow. For each, the first line contains 3 space separated integers, corresponding to the values of L, M and N respectively. Following is M lines of pairs of words. Following that is the paragraph within which to find and replace occurrences.

Output description:

The first line must contain the number of test cases, T. Following must be T lines, where each contains the corresponding result of the test case.

Constraints:
1 <= T <= 1 000
1 <= L <= 1 000 000
1 <= M <= 1 000
1 <= N <= 1 000 000 000

Sample input:
2
5 3 28
Aaa Bbb
Ccc Ddddd
Eeeee Fff
Aaa Bbb Ccc Ddd EeeeeK Fffff
14 3 42
is was
an horrible
. !
This is an example paragraph to test with.

Sample output:
2
Bdd Bdd Ddddd Ddd FffK Fffff
This was horrible example paragraph to test with!

Assumptions:

- The "first words" are unique, meaning there will never be a clash about which of the M pairs of words to use when an occurrence is found.

- In this context, a "word" is any sequence of characters that does not contain white spaces. Therefore "." must be considered as a word.

- A paragraph contains no newline character, therefore the result will also contain no newline character.

- There may be tests cases with no occurrences to be replaced.

Deliverables:

- Write a program specifically in C that solves the problem, and by using standard C libraries only.

- Determine, and explain your analysis through which you determined, the time complexity as well as the space complexity of your program, each as a function of L, M and N.

Quality requirements:

- Your solution must solve the problem.

- Your algorithm must have no higher than an O(N*log(M)*L) time complexity, and must have no higher than an O((N+M)\*L) space complexity.

- Your source code must be properly indented, and have properly descriptive variables and functions names.

Train:

If you struggle to solve this problem to it's quality requirements then consider first following the training offer at <https://www.estenligne.com/other/Offre-de-formation.txt?v=2.1.0>
