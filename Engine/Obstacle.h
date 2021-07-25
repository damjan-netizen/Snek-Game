#pragma once

#include "Board.h"
#include "Location.h"
#include "Snake.h"
#include "Colors.h"
#include <random>

class Obstacle
{
public:
	Obstacle(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Draw(Board& brd) const;
	void Spawn(std::mt19937& rng, const Board& brd, const Snake& snek);
	const Location& GetLocation() const;
private:
	Location loc;
	Color c = Colors::LightGray;
};