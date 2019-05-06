/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:36:39 by arherrer          #+#    #+#             */
/*   Updated: 2019/05/05 22:14:10 by arherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Entity {

public:
	// Coplien
	Entity(void);
	Entity(const Entity& that);
	Entity& operator =(const Entity& that);
	~Entity(void);

	// Members
	int x;
	int y;
	int	dx, dy;
	bool alive;
	bool justKilled;
	int counter;
	int counter1;

	virtual void	render(void) const;
	virtual void	move(void);

	void					setColor(int color);

protected:
	int		_color;
private:
};
