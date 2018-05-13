#include "Header.h"

void step_clr(sf::Color & clr)
{
	clr.r = clr.r + 5 < 0x100 ? clr.r + 5 : 0xff;
	clr.g = clr.g + 3 < 0x100 ? clr.g + 5 : 0xff;
	clr.b = clr.b + 2 < 0x100 ? clr.b + 5 : 0xff;
}

void drawM(sf::Vector2<TYPE> x, sf::Vector2<TYPE> y, TYPE epsi)
{
	//const TYPE epsilon = 0.005;
	sf::Vector2i sizewindow((int)((x.y - x.x) / epsi), (int)((y.y - y.x) / epsi));
	sf::RenderWindow window(sf::VideoMode(sizewindow.x, sizewindow.y), "Mandelbroth");
	sf::Image im;
	const int max_it = 150;
	const int infinity_sqr = 10000;
	im.create(sizewindow.x, sizewindow.y);

	sf::Color clr;
	int xim = 0, yim = 0;
	for (TYPE currx = x.x; currx <= x.y; currx += epsi, ++xim)
	{
		yim = 0;
		while (xim >= sizewindow.x)
			--xim;
		for (TYPE curry = y.x; curry <= y.y; curry += epsi, ++yim)
		{
			while (yim >= sizewindow.y)
				--yim;
			clr = sf::Color::Black;
			Complex<TYPE> curr;

			im.setPixel(xim, yim, sf::Color::Black);

			for (int i = 0; i < max_it; ++i)
			{
				if (curr.module_sqr() >= infinity_sqr)
				{
					im.setPixel(xim, yim, clr);
					break;
				}
				curr = curr * curr + Complex<TYPE>(currx, curry);
				step_clr(clr);
			}
		}
	}
	sf::Sprite s;
	sf::Texture t;
	t.loadFromImage(im);
	s.setTexture(t);
	im.saveToFile("result.png");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(s);
		window.display();
	}
}