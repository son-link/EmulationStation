#include "views/gamelist/GridGameListView.h"

#include "views/ViewController.h"
#include "Locale.h"

GridGameListView::GridGameListView(Window* window, FileData* root) : ISimpleGameListView(window, root),
	mGrid(window)
{
	mGrid.setPosition(0, mSize.y() * 0.2f);
	mGrid.setSize(mSize.x(), mSize.y() * 0.8f);
	addChild(&mGrid);

	populateList(root->getChildrenListToDisplay());
}

FileData* GridGameListView::getCursor()
{
	return mGrid.getSelected();
}

void GridGameListView::setCursor(FileData* file)
{
	if(!mGrid.setCursor(file))
	{
		populateList(file->getParent()->getChildrenListToDisplay());
		mGrid.setCursor(file);
	}
}

bool GridGameListView::input(InputConfig* config, Input input)
{
	if(config->isMappedTo("left", input) || config->isMappedTo("right", input))
		return GuiComponent::input(config, input);

	return ISimpleGameListView::input(config, input);
}

void GridGameListView::populateList(const std::vector<FileData*>& files)
{
	mGrid.clear();
	for(auto it = files.cbegin(); it != files.cend(); it++)
	{
		mGrid.add((*it)->getName(), (*it)->getThumbnailPath(), *it);
	}
}

void GridGameListView::launch(FileData* game)
{
	ViewController::get()->launch(game);
}

std::vector<HelpPrompt> GridGameListView::getHelpPrompts()
{
	std::vector<HelpPrompt> prompts;
	prompts.push_back(HelpPrompt("up/down/left/right", _("SCROLL")));
	prompts.push_back(HelpPrompt("a", _("LAUNCH")));
	prompts.push_back(HelpPrompt("b", _("BACK")));
	return prompts;
}
