#pragma once
#include "SFML/Graphics.hpp"

struct Explosion {
	/*static const int size = 9;*/
	sf::Texture textureArr[9];
	sf::Sprite sprite;
	sf::Clock timer;
	int frame;
	sf::Vector2f pos;
};

void expInit(Explosion& exp, sf::Vector2f pos) {
	exp.pos = pos;
	for (int i = 0; i < 9; i++) {
		exp.textureArr[i].loadFromFile("exp" + std::to_string(i) + ".jpg");
	}
	exp.sprite.setTexture(exp.textureArr[0]);
	exp.sprite.setPosition(pos);
	exp.timer.restart();
	exp.frame = 0;
}

void expDraw(sf::RenderWindow& window, Explosion& exp) {
	float time = exp.timer.getElapsedTime().asMilliseconds();
	
	
	if (time > 125.f) {
		exp.frame++;
		exp.sprite.setTexture(exp.textureArr[exp.frame]);
		exp.timer.restart();
		float exp_width = exp.sprite.getGlobalBounds().width;
		float exp_height = exp.sprite.getGlobalBounds().height;
		float exp_x = exp.pos.x - exp_width / 2;
		float exp_y = exp.pos.y - exp_height / 2;
		exp.sprite.setPosition(exp_x, exp_y);
	}
	if (exp.frame > 8) exp.frame = 0;
	window.draw(exp.sprite);
}