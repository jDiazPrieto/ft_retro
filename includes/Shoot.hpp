/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:23:06 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 15:23:09 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_HPP
# define SHOOT_HPP

# include "Display.hpp"

class Shoot : public Display {

public:

    //constructors
    Shoot(int yCord, int xCord);
    Shoot(Shoot & src);
    ~Shoot(void);

    //operator overloads
    Shoot & operator=(Shoot const & src);

    char getType(void) const;
    
private:
     //constructors
    Shoot(void); 

};

#endif
