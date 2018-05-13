#include <iostream>
#include "Header.h"

void drawM(sf::Vector2<TYPE> x, sf::Vector2<TYPE> y, TYPE epsi);

int main()
{
	TYPE x1, x2, y1, y2, epsi;
	std::cout << "x1 x2 y1 y2 \n";
	std::cin >> x1 >> x2 >> y1 >> y2;
	if (x1 > x2 || y1 > y2 || x1<-2.25 || x2>0.75 || y1<-1.5 || y2>1.5)
	{
			std::cout << "error";
	}
	else
	{
		if (x2 - x1 >= y2 - y1)
		{
			epsi = (x2 - x1) / 600;
		}
		else
		{
			epsi = (y2 - y1) / 600;
		}
		drawM(sf::Vector2<TYPE>(x1, x2), sf::Vector2<TYPE>(y1, y2), epsi);
	}
}