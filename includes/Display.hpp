/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:24:56 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 16:36:42 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

class Display {

protected:

	int _yCord;
	int _xCord;
	int _yDirection;
	int	_xDirection;

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
