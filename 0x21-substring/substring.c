#include "substring.h"

/**
 * hash - hashing the value
 * @s: string to will be hash
 * @end: end index of the string
 *
 * Return: hash value of the string
 */
unsigned long hash(const char *s, int end)
{
	int i = 0;
	const int p = 31, m = 1e9 + 9;
	/* some values for hashing the value */
	unsigned long hash_value = 0, p_pow = 1;

	for (; i < end; ++i)
	{
		hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return (hash_value);
}

/**
 * operation - will be count the number of words and comparre the value
 * @str_len: length of the string
 * @nb_words: number of words the string has
 * @length: length of the words of var words
 * @count: and interation space to liberate the memory
 * @hashes: will be the hashing value
 * @s: the string
 * @res: the space of the response
 * @n: size of result array
 *
 * Return: returning the number positin pointer
 */
int *operation(int str_len, int nb_words, int length, int *count,
			unsigned long *hashes, const char *s, const char **words,
			int *res, int *n)
{
	int i = 0, j = 0, k = 0, counting = 0;
	unsigned long result_hash;

	for (i = 0; i <= str_len - nb_words * length; ++i)
	{
		memset(count, 0, nb_words * sizeof(*count));
		counting = 0;
		for (j = 0; j < nb_words; ++j)
		{
			result_hash = hash(s + i + j * length, length);
			for (k = 0; k < nb_words; ++k)
			{
				if (count[k] == 1)
					continue;

				if (hashes[k] == result_hash &&
				    !strncmp(s + i + j * length, words[k], length))
				{
					count[k] = 1;
					++counting;
					break;
				}
			}
		}
		if (counting == nb_words)
		{
			res[*n] = i;
			*n += 1;
		}
	}

	return (res);
}

/**
 * find_substring - finds all the possible substrings containing a list of
 * words within a given string.
 * @s: string to check
 * @words: list of words
 * @nb_words: size of @words
 * @n: size of result array
 * Return: list of indecies where permutations start
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0;
	int *res = calloc(1000, sizeof(*res));
	int *count = malloc(nb_words * sizeof(*count));
	unsigned long *hashes = calloc(nb_words, sizeof(*hashes));

	if (!res || !count || !s || !words || !*words || !nb_words || !n ||
	    !hashes)
	{
		return (NULL);
	}
	*n = 0;

	for (; i < nb_words; ++i)
		hashes[i] = hash(words[i], strlen(words[i]));

	res = operation(
	    strlen(s) /* lenght of the string*/,
	    nb_words,
	    strlen(words[0]) /* lenght of the words*/,
	    count,
	    hashes,
	    s,
	    words,
	    res,
	    n);

	free(count);
	free(hashes);

	return (res);
}
