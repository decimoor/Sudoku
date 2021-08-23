#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "DataBase.h"
const int SCREEN_WIDTH = 605, SCREEN_HEIGHT = 604;
const int AnimationTime = 10;

class Game
{
private:
	sf::RenderWindow window;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

	sf::RectangleShape rect;
	sf::RectangleShape flickeringRect;
	sf::Vector2i frIndices;
	bool isFlickering;

	std::vector<sf::Sprite> nums;
	sf::Vector2f blocksPositions[FIELD_WIDTH_HEIGHT][FIELD_WIDTH_HEIGHT];
	sf::Clock clock;

	sf::Text text;

public:

	Game(const std::string& path)
	{
		window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sudoku");
		FillWindowWithTemplate(path);
		SetBlocksPositions();
		isFlickering = false;
		window.setKeyRepeatEnabled(false);
		clock.restart();
	}

	bool isOpen()
	{
		return window.isOpen();
	}

	void Draw(SudokuField& sf)
	{
		window.clear();
		window.draw(mapSprite);
		window.draw(rect);
		window.draw(flickeringRect);
		DrawNumsOnField(sf);
		window.draw(text);
		window.display();

	}

	void DrawNumsOnField(SudokuField& sf)
	{
		for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
		{
			for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
			{
				if (sf.field[i][j].front != '0')
				{
					sf::Texture t;
					t.loadFromFile("NumbersImages/" + std::to_string(sf.field[i][j].front - 48) + ".png");
					sf::Sprite sprite;
					sprite.setTexture(t);
					sprite.setPosition(blocksPositions[i][j]);
					window.draw(sprite);
				}
			}
		}
	}
	void DealWinthInput(SudokuField& sf)
	{
		sf::Mouse mouse;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Left Button were clicked\n";
				isFlickering = true;
				frIndices = { 10, 10 };
				CreateRectByPosition(142, 204, 174, 255, flickeringRect, mouse.getPosition(window));
				clock.restart();
			}
			if (isFlickering && event.KeyPressed)
			{
				int toPut = 10;
				switch (event.key.code)
				{
					case sf::Keyboard::Num0:
						toPut = 0;
						break;
					case sf::Keyboard::Num1:
						toPut = 1;
						break;
					case sf::Keyboard::Num2:
						toPut = 2;
						break;
					case sf::Keyboard::Num3:
						toPut = 3;
						break;
					case sf::Keyboard::Num4:
						toPut = 4;
						break;
					case sf::Keyboard::Num5:
						toPut = 5;
						break;
					case sf::Keyboard::Num6:
						toPut = 6;
						break;
					case sf::Keyboard::Num7:
						toPut = 7;
						break;
					case sf::Keyboard::Num8:
						toPut = 8;
						break;
					case sf::Keyboard::Num9:
						toPut = 9;
						break;
				}
				if (!sf.PutNumber(toPut, frIndices.x, frIndices.y))
					std::cout << "Wrong step\n";
			}
		}
		CreateRectByPosition(180, 245, 112, 255, rect, mouse.getPosition(window));
		sf::Time time;
		time = clock.getElapsedTime();
		std::cout << time.asMilliseconds() << std::endl;
		if (isFlickering && time.asSeconds() < 0.5f)
		{
			flickeringRect.setFillColor({ 142, 204, 174, 255 });
		}
		else if (time.asSeconds() > 0.5f && time.asSeconds() < 1.f or !isFlickering)
		{
			flickeringRect.setFillColor({ 0, 0, 0, 0 });
		}
		else
		{
			clock.restart();
		}
		

		if (sf.Win())
		{
			text.setString("Congratualtions! You won!");
			text.setCharacterSize(40);
			text.setPosition(300.f, 300.f);
		}
	}

private:
	template <class T>
	void CreateRectByPosition(sf::Uint8 R, sf::Uint8 G, sf::Uint8 B, sf::Uint8 A, sf::RectangleShape& rect1, T pos)
	{
		for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
		{
			for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
			{
				if (pos.x - blocksPositions[i][j].x <= 56 && pos.x - blocksPositions[i][j].x > 0 && pos.y - blocksPositions[i][j].y <= 56 && pos.y - blocksPositions[i][j].y > 0)
				{
					rect1.setFillColor({ R, G, B, A });
					rect1.setSize({ 56.f, 56.f });
					rect1.setPosition(blocksPositions[i][j]);
					if (frIndices.x == 10 && frIndices.y == 10) 
					{
						frIndices = { i, j };
					}
				}
			}
		}
	}

	void FillWindowWithTemplate(const std::string& path)
	{
		mapTexture.loadFromFile(path);
		mapSprite.setTexture(mapTexture);
	}

	void SetBlocksPositions()
	{
		for (int vblock = 0; vblock < FIELD_WIDTH_HEIGHT / 3; vblock++)
		{
			for (int i = 0; i < FIELD_WIDTH_HEIGHT / 3; i++)
			{
				for (int hblock = 0; hblock < FIELD_WIDTH_HEIGHT / 3; hblock++)
				{
					for (int j = 0; j < FIELD_WIDTH_HEIGHT / 3; j++)
					{
						blocksPositions[vblock*3 + i][hblock*3 + j] = { 26.f + 59.f * j + 187.f * hblock, 26.f + 59.f * i + 187.f * vblock };

					}
				}
			}
		}
	}
};
