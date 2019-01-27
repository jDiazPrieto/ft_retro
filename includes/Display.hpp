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
	//constructor
	Display(void);
	
	int _yCord;
	int _xCord;
	int _yDirection;
	int	_xDirection;

public:
	//constructors
	Display(int yCord, int xCord, int yDirection, int xDirection);
	Display(Display & src);
	~Display(void);

	//operator overloads
	Display & operator=(Display const & src);

	// setter functions
	void setYCord(int y);
	void setXCord(int x);
	
	//getter functions
	int	getYCord(void) const;
	int getXCord(void) const;
	int getYDirection(void) const;
	int getXDirection(void) const;
	virtual char getType(void) const = 0;
	
	void update(void) ;
	void draw(void) const;
	

private:
};

#endif
