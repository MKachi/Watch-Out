#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class Friendly;
	class Floor
		: public Sprite
	{
	private:
		float		_floorY;
		Sprite*		_dropArea;
		Rect		_area;

		bool init(const float floorY);

	protected:
		Floor();
		virtual ~Floor();

	public:
		static Floor* create(const std::string& filename, const float floorY);

		float getFloorY() { return _floorY; }
		Rect getDropArea() { return _dropArea->getTextureRect(); }

		void initArea(Rect dropArea, Node* layer);
		void dropCheck(Friendly* friendly);

	};
}