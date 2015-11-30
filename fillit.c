// recuperation du fichier et de l'ensemble des tetrinos
char	*read_c_b_c(int const fd)
{
	char	*str;
	char	*tmp;

	if (!(str) = ft_strnew(1))
		return (NULL);
	while ((ret = read(fd, buf, 1) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strnew(ft_strlen(str) + 1)))
			return (NULL);
		str = ft_strcpy(str, tmp);
		str = ft_strcat(str, buf);
		free(tmp);
	}
	return (str);
}

// verification forme des tetrinos (soit patern soit if # test des i+1 j+1 pour la continuite des tetrinos)

char	**cut_str(char *str)
{
	size_t	i;
	char	**tab_s
	i = 21;
	while (i < ft_strlen(str))
	{
		str[i] = '\t';
		i += 21;
	}
	tab_s = ft_strsplit(str, '\t');
	return (tab_s);
}

char	**change_char(char **tab_s)
{
	char	let;
	int		i;

	let = 'A';
	while (*tab_s)
	{
		while (*tab_s[i] && let != 'Z')
		{
			if (*tab_s[i] == '#')
				*tab_s[i] = let;
			i++;
		}
		let++;
		(*tab_s)++;
	}
	return (tab_s);
}