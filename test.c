int		test_input_t(char *str)
{
	int		i;

	i = 0
	while (str[i])
	{
		if ((i % 5 != 4) && (str[i] != '#' || str[i] != '.'))
			return (0);
		if ((i % 5 == 4) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		test_len(char *str)
{
	if ((ft_strlen(str) + 1) % 21 != 0)
		return (0)
	if ((ft_strlen(str) > ))
	return (1);
}

int		test_endl(char *str)
{
	int		i;

	i = 21;
	while (str[i])
	{
		if (str[i] != '\n')
			return (0);
		i += 21;
	}
}

int		test_4tetri(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (i == 4)
		return (1);
	return (0);
}