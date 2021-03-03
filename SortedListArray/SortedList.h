#ifndef SORTED_H
#define SORTED_H
#define DEFAULT_ITEMS 5
#include "ItemType.h"

class SortedList
{
private:
	int nMaxSize;
	int nLength;
	int nCurrentPos;
	ItemType pItems[5];

public:
	SortedList();
	void MakeEmpty();
	void PutItem(ItemType iNewItem);
	void DeleteItem(ItemType& iRemovedItem);
	int GetLength();
	bool IsFull();
	bool IsItemInList(ItemType iSearchItem);
	void Display();
	~SortedList();
};

#endif SORTED_H