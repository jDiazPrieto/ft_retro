/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:39:02 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 16:42:12 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYLIST_HPP
# define DISPLAYLIST_HPP

#include "Display.hpp"

struct node {
	Display *display;
	struct node * next;
};

class DisplayList {
	
private:

	struct node *_beginList;
	int _len;

public:

	//constructors
	DisplayList(void);
	DisplayList(DisplayList & src);
	~DisplayList(void);

	void addToList(Display *display);
	struct s_node *getIndex(int index) const;
	void removeNode(int index);
};

#endif
