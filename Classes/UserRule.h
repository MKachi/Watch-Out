#pragma once

enum 
{ 
	SCREEN_WIDTH = 720, 
	SCREEN_HEIGHT = 1280,
	SHOW_FPS = true,
};

#define GAME_TITLE "WatchOut"
#define START_SCENE TitleScene

template<typename T>
inline T clamp(T data, T min, T max)
{
	if (data > max)
	{
		return max;
	}
	else if (data < min)
	{
		return min;
	}
}