/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:58:23 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/07 21:16:50 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <ctime>
# include <string>
# include <vector>
# include <time.h>
# include <sstream>
# include <unistd.h>
# include <limits.h>
# include <curses.h>
# include <iostream>
#include <sys/utsname.h>
// # include <ncurses.h>

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

# include "BaseModule.hpp"
# include "OSInfoModule.hpp"
# include "DateTimeModule.hpp"
# include "HostNameModule.hpp"

# include "TerminalDisplay.hpp"

#endif
