/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:42:31 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 18:14:23 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

# include "ft_gkrellm.hpp"
// # include "wxstuff.hpp"


class MyApp: public wxApp
{
	public:
		virtual bool OnInit();
};


class GraphicDisplay : public IMonitorDisplay
{

	public:
		GraphicDisplay(void)
		{
			// MyApp app;
			char **argv = NULL;
			int i = 0;
			wxApp* pApp = new MyApp(); 
			wxApp::SetInstance(pApp);
			wxEntry(i, argv);
			// app.init();
		}

		~GraphicDisplay(void) { };

		void		main(void) { }
		void		refresh(void) { }
		void		render(void) { }

};

#endif