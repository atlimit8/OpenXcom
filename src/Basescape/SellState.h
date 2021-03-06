#pragma once
/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "../Engine/State.h"
#include "../Savegame/Transfer.h"
#include "../Menu/OptionsBaseState.h"
#include <vector>
#include <string>
#include <set>

namespace OpenXcom
{

class TextButton;
class Window;
class Text;
class TextList;
class ComboBox;
class Timer;
class Base;

/**
 * Sell/Sack screen that lets the player sell
 * any items in a particular base.
 */
class SellState : public State
{
private:
	Base *_base;
	TextButton *_btnOk, *_btnCancel;
	Window *_window;
	Text *_txtTitle, *_txtSales, *_txtFunds, *_txtQuantity, *_txtSell, *_txtValue, *_txtSpaceUsed;
	ComboBox *_cbxCategory;
	TextList *_lstItems;
	std::vector<TransferRow> _items;
	std::vector<int> _rows;
	std::vector<std::string> _cats;
	std::set<std::string> _craftWeapons, _armors;
	size_t _sel;
	int _total;
	double _spaceChange;
	Timer *_timerInc, *_timerDec;
	Uint8 _ammoColor;
	OptionsOrigin _origin;
	/// Gets the category of the current selection.
	std::string getCategory(int sel) const;
	/// Gets the row of the current selection.
	TransferRow &getRow() { return _items[_rows[_sel]]; }
public:
	/// Creates the Sell state.
	SellState(Base *base, OptionsOrigin origin = OPT_GEOSCAPE);
	/// Cleans up the Sell state.
	~SellState();
	/// Runs the timers.
	void think();
	/// Updates the item list.
	void updateList();
	/// Handler for clicking the OK button.
	void btnOkClick(Action *action);
	/// Handler for clicking the Cancel button.
	void btnCancelClick(Action *action);
	/// Handler for pressing an Increase arrow in the list.
	void lstItemsLeftArrowPress(Action *action);
	/// Handler for releasing an Increase arrow in the list.
	void lstItemsLeftArrowRelease(Action *action);
	/// Handler for clicking an Increase arrow in the list.
	void lstItemsLeftArrowClick(Action *action);
	/// Handler for pressing a Decrease arrow in the list.
	void lstItemsRightArrowPress(Action *action);
	/// Handler for releasing a Decrease arrow in the list.
	void lstItemsRightArrowRelease(Action *action);
	/// Handler for clicking a Decrease arrow in the list.
	void lstItemsRightArrowClick(Action *action);
	/// Handler for pressing-down a mouse-button in the list.
	void lstItemsMousePress(Action *action);
	/// Increases the quantity of an item by one.
	void increase();
	/// Decreases the quantity of an item by one.
	void decrease();
	/// Changes the quantity of an item by the given value.
	void changeByValue(int change, int dir);
	/// Updates the quantity-strings of the selected item.
	void updateItemStrings();
	/// Handler for changing the category filter.
	void cbxCategoryChange(Action *action);
};

}
