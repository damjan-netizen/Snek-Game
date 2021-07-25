#include "Obstacle.h"

Obstacle::Obstacle(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	Spawn(rng, brd, snek);
}

void Obstacle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Obstacle::Spawn(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth());
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight());

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snek.IsInTile(newLoc));
	loc = newLoc;
}

const Location& Obstacle::GetLocation() const
{
	return loc;
}


