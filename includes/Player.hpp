/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:14 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 10:18:35 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Display.hpp"
#include "Shoot.hpp"

class Player : public Display
{
private:
	int _health;
	int _xPos;
	int _yPos;
	Shoot *_missile;

public:
	//Constructor and destructor
	Player(void);
	Player(Player const &copy);
	Player(int xPos, int yPos);
	~Player(void);

	//Member functions of Player
	Player* shootMissile(void);
	void direction(int key_input);
	void takeDamage(void);
};

#endif
