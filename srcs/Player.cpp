#include "Player.hpp"

Player::Player(void)
{
	return ;
}

Player::Player(Player const &copy)
{
	*this = copy;
	return (*this);
}

Player::Player(int xPos, int yPos)
{
	this->_xCord = xPos * 0;
	this->_yCord = yPos / 2;
	this->_health = 1;
	this->_missile = NULL;
	return ;
}

Player::~Player(void)
{
	return ;
}

Shoot* Player::shootMissile(void)
{
	Shoot *missile = new Shoot(this->_xCord + 1, this->_yCord);
	return (missile);
}
void Player::direction(int key_input)
{
	//TODO Bound checking top and bottom
	if (key_input == KEY_UP || key_input == 'w' || key_input == 'W')
		//Bound check top
		this->_yCord = _yCord++;
	if (key_input == KEY_DOWN || key_input == 's' || key_input == 'S')
		this->_yCord = _yCord--;
	if (key_input == KEY_LEFT || key_input == 'a' || key_input == 'A')
		//Bound check bottom
		this->_xCord = _xCord--;
	if (key_input == KEY_RIGHT || key_input == 'd' || key_input == 'D')
		this->_xCord = _xCord++;
	return ;
}

void Player::takeDamage(void)
{
	_health--;
	return ;
}
