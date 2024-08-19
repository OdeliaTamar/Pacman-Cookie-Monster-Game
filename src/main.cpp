#include "Controller.h"
#include <SFML/Graphics.hpp>
int main()
{
	srand(std::time(nullptr));
	Controller c;
	c.run();
}
