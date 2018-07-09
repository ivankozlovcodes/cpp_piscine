/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:58:23 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 17:58:54 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <ctime>
# include <string>
# include <vector>
# include <time.h>
# include <sstream>
# include <fstream>
# include <unistd.h>
# include <limits.h>
# include <curses.h>
# include <iostream>
#include <sys/utsname.h>
// # include <ncurses.h>

# include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

# include "BaseModule.hpp"
# include "RAMModule.hpp"
# include "CPUModule.hpp"
# include "OSInfoModule.hpp"
# include "NetworkModule.hpp"
# include "DateTimeModule.hpp"
# include "HostNameModule.hpp"

# include "TerminalDisplay.hpp"
# include "GraphicDisplay.hpp"

#endif
