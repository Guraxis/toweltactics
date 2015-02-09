#ifndef MAIN_H
#define MAIN_H
#include <SDL/SDL.h>

float nahoda(float min, float max)
{
	return (float)rand()/RAND_MAX*(max-min)+min;
}

class Coord
{
public:
	int x;
	int y;
};

class Tile
{
public:
	Coord pixelcoord;
	Coord tilecoord;
	int terrain;
};

int terraindiff(int terrain)
{
	switch(terrain)
	{
	case 1:

		break;
	}
}

class Entity
{
public:
	Coord coord;
	Tile tile;
};

Coord gettilecoord(int x, int y)
{
	Tile tile;
	tile.pixelcoord.x = x;
	tile.pixelcoord.y = y;
	return(tile.pixelcoord);
}

int movetotile(Entity ent, int x, int y)
{
	ent.coord = gettilecoord(x,y);
	ent.tile.tilecoord.x = x;
	ent.tile.tilecoord.y = y;
}

int gototile(Entity ent, Coord origin, Coord end, Tile tile[9][9])
{
	int direction, duration;
	if(origin.x==end.x&&origin.y==end.y)direction = 0;
	if(origin.x<end.x&&origin.y==end.y)direction = 1;
	if(origin.x<end.x&&origin.y>end.y)direction = 2;
	if(origin.x==end.x&&origin.y>end.y)direction = 3;
	if(origin.x>end.x&&origin.y>end.y)direction = 4;
	if(origin.x>end.x&&origin.y==end.y)direction = 5;
	if(origin.x>end.x&&origin.y<end.y)direction = 6;
	if(origin.x==end.x&&origin.y<end.y)direction = 7;
	if(origin.x<end.x&&origin.y<end.y)direction = 8;

	switch(direction)
	{
	case 0:
		break;
	case 1:
		if(tile[origin.x+1][origin.y].terrain!=0)
		{
			for(int i=1; i<9; i++)
			{
				duration+=terraindiff(tile[origin.x+i][origin.y].terrain);
				if(tile[origin.x+i][origin.y].terrain==0){break;}
				if(tile[origin.x+i][origin.y].tilecoord.x==tile[end.x][end.y].tilecoord.x){break;}
			}
		}
		else{break;}
		break;
	}

}

#endif // MAIN_H
