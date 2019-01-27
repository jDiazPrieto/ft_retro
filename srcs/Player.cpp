#include "Player.hpp"

Player::Player(void)
{
	return ;
}

Player::Player(int xPos, int yPos)
{
	this->_xCord = xPos * 0;
	this->_yCord = yPos / 2;
	return ;
}

Player::~Player(void)
{
	return ;
}

Shoot* Player::shootMissile(void)
{
	Shoot *missle = new Shoot(this->_xCord + 1, this->_yCord);
	return (missle);
}
void Player::direction(int key_input)
{
	if (key_input == KEY_UP)
		this->_yCord = _yCord++;
	if (key_input == KEY_DOWN)
		this->_yCord = _yCord--;
	if (key_input == KEY_LEFT)
		this->_xCord = _xCord--;
	if (key_input == KEY_RIGHT)
		this->_xCord = _xCord++;
	return ;
}
