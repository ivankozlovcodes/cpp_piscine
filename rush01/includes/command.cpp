/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:13:26 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 16:14:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

std::string
runCommand(std::string const & cmd)
{
	std::string		data;
	FILE*			stream;
	const int max_buffer = 256;
	char buffer[max_buffer];

	stream = popen(cmd.c_str(), "r");
	if (stream)
	{
		while (!feof(stream))
		{
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
		}
		pclose(stream);
	}
	return (data);
}
