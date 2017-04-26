
#pragma once
const	double	PI = 3.14159265;

static	const	int		SCR_W			= 800;
static	const	int		SCR_H			= 480;
static	const	int		MAX_ASTEROIDS	= 2;
static	const	int		OFF_SCR_OFFSET	= 130;
static	const	int		DELAY			= 10;

struct LevelData
{
	int largeAst;
	int medAst;
	int smallAst;
	int tinyAst;
};