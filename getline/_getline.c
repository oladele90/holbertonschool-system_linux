#include "_getline.h"

char *_getline(const int fd)
{
	static char buffer[READ_SIZE];
	static ssize_t buffer_index;
	static ssize_t read_bytes;

	char *line = NULL;
	size_t line_length = 0;

	while (1)
	{
		if (buffer_index >= read_bytes)
		{
			buffer_index = 0;
			read_bytes = read(fd, buffer, READ_SIZE);
			if (read_bytes <= 0)
			{
				if (line_length == 0)
					return (NULL);
				line = realloc(line, line_length + 1);

				line[line_length] = '\0';
				return (line);
			}
		}
		while (buffer_index < read_bytes)
		{
			if (buffer[buffer_index] == '\n')
			{
				line = realloc(line, line_length + 1);

				line[line_length] = '\0';
				buffer_index++;
				return (line);
			}
				line = realloc(line, line_length + 1);

				line[line_length] = buffer[buffer_index];
				line_length++;
				buffer_index++;
		}
	}
}
