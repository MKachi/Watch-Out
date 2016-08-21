#pragma once

#include "cocos2d.h"
#include "Friendly.h"

namespace cocos2d
{
	enum class Difficulty
	{
		Easy,
		Normal,
		Hard,
	};

	class GameManager
	{
	private:
		Difficulty		_difficulty;
		int				_score = 0;
		float			_timeScale = 1.0f;
		std::vector<std::string> _enemyImages;

	public:
		bool			_playerLife[3];
		bool			_playerCatche[3];
		static GameManager* getInstance();
		static void destroy();

		void pushEnemyImage(const std::string& filename);
		size_t getEnemyImageCount() { return _enemyImages.size(); }
		const std::string& getEnemyImage(int index) { return _enemyImages[index]; }

		void setDifficulty(const Difficulty difficulty);
		Difficulty getDifficulty() { return _difficulty; }

		void setSelectCountrys(const int index, Country country);
		Country getSelectCountrys(const int index);

		void setTimeScale(float timeScale);
		float getTimeScale() { return _timeScale; }

		void setScoreZero();
		void upScore();
		int getScore() { return _score; }
		int getBestScore();

		void addMoney(int money);
		void minusMoney(int money);
		int getMoney() { return UserDefault::getInstance()->getIntegerForKey("Money"); }

		std::function<void()> endGame = [=]() {};
	};
}