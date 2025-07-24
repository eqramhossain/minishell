#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char		*input;
	static int	count = 0;

	while ((input = readline("demo> ")) != NULL)
	{
		if (*input)
		{
			add_history(input);
		}
		// Simulate an "asynchronous" message after 3 commands
		count++;
		if (count == 3)
		{
			printf("\n[System message: Background job finished!]\n");
			// Tell Readline we're now on a new line
			rl_on_new_line();
			// Redraw the prompt and input line
			rl_redisplay();
		}
		// Exit on "exit"
		if (strcmp(input, "exit") == 0)
			break ;
		printf("You typed: %s\n", input);
	}
	puts("Bye!");
	return (0);
}
