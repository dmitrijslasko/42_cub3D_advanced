#include "libft.h"

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;
	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*read_buffer_until_find_newline(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;
	char	*tmp;
	if (!stash)
		stash = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	if (!buffer || !stash)
		return (0);
	bytes_read = 1;
	while (bytes_read && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}
char	*trim_line_from_stash(const char *line, char *stash)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	i = 0;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	i = ft_strlen(line);
	j = ft_strlen(stash);
	new_str = (char *)ft_calloc(j - i + 1, sizeof(char *));
	if (!new_str)
	{
		free(stash);
		return (0);
	}
	j = 0;
	while (stash[i])
		new_str[j++] = stash[i++];
	new_str[j] = 0;
	free(stash);
	return (new_str);
}
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (0);
	}
	stash = read_buffer_until_find_newline(fd, stash);
	if (!stash)
		return (0);
	line = extract_line(stash);
	stash = trim_line_from_stash(line, stash);
	return (line);
}
