/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:14 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 19:43:25 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Display.hpp"
#include "Shoot.hpp"

class Player : public Display
{
private:
	int _health;

public:
	//Constructor and destructor
	Player(void);
	Player(Player const &copy);
	Player(int xPos, int yPos);
	~Player(void);

	//operator overloads
	Player & operator=(Player const & src);

	//Member functions of Player
	Shoot* shootMissile(void);
	void direction(int key_input, int yMax, int xMax);
	void takeDamage(void);

	virtual char getType(void) const;
};

#endif
