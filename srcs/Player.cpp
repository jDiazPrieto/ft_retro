#include "../includes/Player.hpp"

Player::Player(void)
{
	return ;
}

Player::Player(Player const &copy)
{
	*this = copy;
	return;
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
void Player::direction(int key_input, int yMax, int xMax)
{
	//TODO Bound checking top and bottom
	if (key_input == KEY_UP || key_input == 'w' || key_input == 'W')
		if (this->_yCord != yMax)
			this->_yCord = _yCord++;
	if (key_input == KEY_DOWN || key_input == 's' || key_input == 'S')
		if (this->_yCord != 0)
		this->_yCord = _yCord--;
	if (key_input == KEY_LEFT || key_input == 'a' || key_input == 'A')
		if (this->_xCord != 0)
		this->_xCord = _xCord--;
	if (key_input == KEY_RIGHT || key_input == 'd' || key_input == 'D')
		if (this->_yCord != xMax)
	return ;
}

void Player::takeDamage(void)
{
	_health--;
	return ;
}

char Player::getType(void) const {
	return 'p';
}
