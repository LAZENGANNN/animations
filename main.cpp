#include "SFML/Graphics.hpp"
#include "explosion.h"

using namespace sf;

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(800, 600), "SFML Works!");
	Explosion exp1;
	expInit(exp1, Vector2f{ 400, 300 });

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ��������� ���� 
		window.clear();
		expDraw(window, exp1);
		window.display();
	}

	return 0;
}