/**
 * srchdelim - searches for a delimiter
 * @s: string
 * @c: char to search for.
 * Return: 1
 */
int srchdelim(char *s, char c)
{
	int count;

	for(count = 0; s[count] != '\0'; count++)
	{
		if (s[count] == c)
		{
			break;
		}
	}
	if (s[count] == c)
		return (1);
	else
		return (0);
}
