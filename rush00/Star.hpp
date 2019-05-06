/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:01:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/05 23:03:11 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_HPP
# define START_HPP

# include "Entity.hpp"

# include <string>

class Star : public Entity
{
	public:
		Star(void);
		Star(std::string s);
		~Star(void);
		Star(Star const & src);
		Star &operator=(Star const & rhs);

		std::string					getStar() const;
		void								render() const;
		void								move();

		static std::string	getRandomStar(void);

	private:
		std::string			_star;
		int							_skipMove;
};

# define STAR_1 "\
 | \n\
-O-\n\
 | \n"

# define STAR_2 "\
 * \n\
***\n\
 * "

# define STAR_3 "\
        *\n\
 *    .\n\
   .  *   .\n\
*  .  ..  *\n\
     *   *\n\
"

# define STAR_4 "\
 ,-,-.\n\
/.( +.\\\n\
\\ {. */\n\
 `-`-'\n\
"

# define COMET "---====D"

#endif
