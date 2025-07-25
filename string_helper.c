#include "main.h"
#include <stdlib.h>
/**
 * _strlen - calculates the length of a null-terminated string.
 * @str: pointer to the string.
 *
 * Return: the number of characters in the string,
 *         excluding the null terminator.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	if (!str)
        return 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _stdrup - Duplicates a string into a newly allocated memory space.
 * @str: The input string to duplicate.
 *
 * Return: Pointer to the newly allocated copy of the string,
 *         or NULL if allocation fails or str is NULL.
 *
 * Description: This function allocates memory and copies the content
 * of the input string, including the null terminator, into the new memory.
 */
char *_strdup(char *str)
{
	char *str_cpy;
	int size;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	size = _strlen(str);
	str_cpy = malloc(size + 1);
	if (str_cpy == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		str_cpy[i] = str[i];

	str_cpy[i] = '\0';
	return (str_cpy);
}
