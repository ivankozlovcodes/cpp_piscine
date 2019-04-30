/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:54:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/29 18:09:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string>

int				getNumber(void);
std::string		toLower(std::string s);
std::string		getInfo(std::string field);
std::string		truncate(std::string s, size_t len);

#endif
