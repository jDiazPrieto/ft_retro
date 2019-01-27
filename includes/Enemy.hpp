/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:01 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 15:17:05 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Display.hpp"

class Enemy : public Display {

private:
    Enemy(void);

public:
    //constructors
    Enemy(int yPos, int xPos);
    Enemy(Enemy & src);
    ~Enemy(void);

    Enemy & operator=(Enemy const & rhs);

    virtual char getType(void) const;
};

#endif