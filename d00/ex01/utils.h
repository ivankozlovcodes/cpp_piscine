/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:54:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/06/25 16:11:33 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string>

int				getNumber(void);
std::string		toLower(std::string s);
std::string		getInfo(std::string field);
std::string		truncate(std::string s, int len);

#endif
