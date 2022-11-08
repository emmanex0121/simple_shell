#include "shell.h"

/**
 * parseCmd - populates commands
 * @cmd: input command
 * @params: arguments
 */
void parseCmd(char *cmd, char **params)
{
	for (int i = 0; i < MAX_NUMBER_OF_PARAMS; i++)
	{
		params[i] = strsep(&cmd," ");
		if (params[i] == NULL)
			break;
	}
}

/**
 * executeCmd - executes commands
 * @params: arguments
 * Return: 1 if error encountered 0 otherwise
 */
int executeCmd(char **params)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: ");
		return (1);
	}
	else if (pid == 0)
	{
		execve(params[0], params, environ);
		char *error = strerror(errno);

		printf("./shell: %s\n", error);
		return (0);
	}
	else
	{
		int childStatus;

		waitpid(pid, &childStatus, 0);
		return (1);
	}
}
