#include "shell.h"

/**
 * main - executes shell loop
 * Return: exits with status 0
 */

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH + 1];
	char *params[MAX_NUMBER_OF_PARAMS + 1];
	int cmdCount = 0;

	while (1)
	{
		char *username = getenv("USER");

		printf("%s@shell# ", username);
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
			break;
		if (cmd[_strlen(cmd) - 1] == '\n')
			cmd[_strlen(cmd) - 1] = '\0';
		parseCmd(cmd, params);
		if(_strcmp(params[0], "exit") == 0)
			break;
		if (executeCmd(params) == 0)
			break;
	}
	return (0);
}
