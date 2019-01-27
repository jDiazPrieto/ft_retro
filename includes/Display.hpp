/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:24:56 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 19:26:59 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP
// Add a sprite for the player's ship, enemy's ship, and the shoot

class Display {

protected:

	int _yCord;
	int _xCord;
	int _yDirection;
	int _xDirection;

public:

	//constructor
	Display(void);
	Display(int y, int x, int yDirection, int xDirection);
	Display(Display & src);
	~Display(void);

	// setter functions
	void setYCord(void);
	void setXCord(void);

	//getter functions
	int	getYCord(void) const;
	int getXCord(void) const;

	void update(void) const;
	void draw(void) const;
};

#endif
