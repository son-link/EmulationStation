#pragma once

#include "../GuiComponent.h"
#include "../views/GameListView.h"

#include "NinePatchComponent.h"
#include "TextComponent.h"

class GuiFastSelect : public GuiComponent
{
public:
	GuiFastSelect(Window* window, GameListView* gamelist);

	bool input(InputConfig* config, Input input);
	void update(int deltaTime);

private:
	void setScrollDir(int dir);
	void scroll();
	void updateGameListCursor();
	void updateGameListSort();
	void updateSortText();

	int mSortId;
	int mLetterId;

	int mScrollDir;
	int mScrollAccumulator;

	NinePatchComponent mBackground;
	TextComponent mSortText;
	TextComponent mLetterText;

	GameListView* mGameList;
};