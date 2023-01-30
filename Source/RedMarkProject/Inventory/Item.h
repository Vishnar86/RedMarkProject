// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**  item struct would be used for crafting materials, key items, quest items, and mcguffins.
*	 consumables are just that potions, restoratives, poisons, etc.  may create futher structs based off of item struct
*    to allow for each item type/usage i.e poison struct for applying poison to a weapon or pouring into drink/food.
*    this all depends on plans going forward, for now simple base item and restorative/potion/basic consumables should be fine.
*    
*    if item class should not house item struct we can restructure later. 
* 
*    also not familiar with C++ yet, half of this might belong in the .cpp file, if so let me know and I will fix it.
*    consider the current state of struct item as notes for planning for implimentation.  
 * 
 */

public struct item
{
public:
	string itemName;
	string description;
	double baseValue;
	// need enum of player/mod stats to easily and ripidly iterate new items.
	// public enumStatsHealthEtc stats

	bool isStackable;
	int maxStackCount;

	bool consumable;

	void item(string name, string desc, double value, bool isConsumable, bool stackable, int stackMax)
	{

	}

};

public struct consumable : item
{
	public bool targetSelf;

	//needs to store animation and special effect info for thrown vs drank vs poured etc.

	public consumable(string name, string desc, double value, bool isSelfTarget, bool stackable, int stackMax)
	{
		//a loop for adding the enumerated stats to be affected flatly if any.
		targetSelf = isSelfTarget;
	}

	public void activate()
	{
		if (targetSelf)
		{
			activateSelf();
			return;
		}
		else
		{
			activateOther();
			return;
		}
	}

	public void activateOther()
	{
		//enumerate through stat enums in item struct to apply buffs/debuffs to targeted creature.
		//logic for special effects and animations to apply to target.
	}

	public void activateSelf()
	{
		//enumerate through stat enums in item struct to apply buffs/debuffs to self.
		//logic for special effects and animations to apply to self.
	}
}

class REDMARKPROJECT_API Item
{
public:
	

	item newItem(string name, string desc, double value, bool isConsumable, bool isSelfTarget, bool stackable, int stackMax)
	{
		item itm;

		if (isConsumable) { itm = new consumable(string name, string desc, double value, bool isSelfTarget, bool stackable, int stackMax) }
		else { itm = new item(string name, string desc, double value, bool stackable, int stackMax); }
	}
};