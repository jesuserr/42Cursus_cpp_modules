/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:57:06 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/07 14:19:04 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool	check_arguments(int argc, char **argv)
{
	std::string		str_aux;

	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		std::cout << "Usage: ./Sed_is_for_losers <file_name> <string_to_find>";
		std::cout << " <new_string>" << std::endl;
		return (false);
	}
	str_aux = argv[2];
	if (!str_aux.length())
	{
		std::cout << "Error: Nothing to replace" << std::endl;
		return (false);
	}
	return (true);
}

bool	open_files(char **argv, std::ifstream *in_file, std::ofstream *out_file)
{
	std::string		str_aux;
	const char		*new_str;
			
	in_file->open(argv[1]);
	if (!in_file->is_open())
	{
		std::cout << "Error: Unable to open source file" << std::endl;
		return (false);
	}
	str_aux = argv[1];
	str_aux.append(".replace");
	new_str = str_aux.c_str();
	out_file->open(new_str);
	if (!out_file->is_open())
	{
		std::cout << "Error: Unable to open target file" << std::endl;
		return (false);
	}
	return (true);
}

int	replace(char **argv, std::string content, std::ofstream *out_file)
{
	size_t		i;
	size_t		pos;
	char		aux[BUFSIZ];
	
	i = 0;
	while (i < content.length())
	{
		pos = content.find(argv[2], i);
		if (pos < content.length())
		{
			content.copy(aux, pos - i, i);
			aux[pos - i] = '\0';
			*out_file << aux << argv[3];
			i = pos + std::string(argv[2]).length();
		}
		else
			break;
	}
	content.copy(aux, content.length() - i, i);
	aux[content.length() - i] = '\0';
	*out_file << aux;
	return (0);
}

/* Safer version using 'find' and 'replace' to perform the replacement,
which avoids the need for manual memory management and buffer size
calculations that are leading to seg fault in some cases.*/
int replace_2(char **argv, std::string content, std::ofstream *out_file)
{
	size_t		pos = 0;
	std::string	to_replace = argv[2];
	std::string	replacement = argv[3];
	
	while ((pos = content.find(to_replace, pos)) != std::string::npos)
	{
		content.replace(pos, to_replace.length(), replacement);
		pos += replacement.length();
	}
	*out_file << content;
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		content;
	
	if (check_arguments(argc, argv) && open_files(argv, &in_file, &out_file))
	{
		std::getline(in_file, content, '\0');
		replace_2(argv, content, &out_file);
		in_file.close();
		out_file.close();
	}
	return (0);
}
