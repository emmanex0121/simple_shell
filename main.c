#include "shell.h"

/**
 * main - executes shell loop
 * Return: exits with status 0
 */

int main(void)
{
	while (1)
	{
		char *line;
		char **tokens;
		char *buff = NULL;
		char *tmp = NULL;

		printf("$ ");
		line = _getline();
		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			if (!_strchr(tokens[0], '/'))
			{
				buff = get_path_buff_size(tokens[0]);
				tmp = find_path(tokens[0], buff);
				if (tmp)
					tokens[0] = tmp;
			}
			execute(tokens);
		}
		free(buff);
		free(tokens);
		free(line);
	}
	return (0);
}
