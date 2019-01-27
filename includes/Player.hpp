/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:14 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 17:40:55 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP
#define SHIP '>'

#include "GameObject.hpp"
#include "Display.hpp"

class Player : public Display
{
private:

public:
	//Constructor and destructor
	Player(void);
	Player(int xPos, int yPos);
	~Player(void);

	//Member functions of Player
	Player shootMissile(void);
	void direction(int key_input);
};

#endif
