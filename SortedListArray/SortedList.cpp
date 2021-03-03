#include "SortedList.h"
#include <iostream>

SortedList::SortedList()
{
	nMaxSize = DEFAULT_ITEMS;
	nLength = 0;
	nCurrentPos = -1;
}

void SortedList::MakeEmpty()
{
	nLength = 0;
	nCurrentPos = -1;
}

void SortedList::PutItem(ItemType iNewItem)
{
	bool bMoreToSearch;
	int index = 0;

	bMoreToSearch = (index < nLength);
	while (bMoreToSearch)
	{
		switch (iNewItem.ComparedTo(pItems[index]))
		{
		case LESS:		bMoreToSearch = false; //index is sitting on the correct insertion location
						break;

		case GREATER:	index++; //Advance index to next array element.
						bMoreToSearch = (index < nLength); //Check to see if there are still elements left
						break;
		}
	}

	for (int i = nLength; i > index; i--) //Shift array elements one to the right starting at the end.
	{
		pItems[i] = pItems[i - 1];
	}
	pItems[index] = iNewItem; //Insert new item at its appropriate location in the sorted array.
	nLength++; //Array grew by one element.
}

void SortedList::DeleteItem(ItemType& iRemovedItem)
{
	int index = 0;
	while (iRemovedItem.ComparedTo(pItems[index]) != EQUAL)
		index++; //If not equal, item not found so advance the index pointer.
	for (int i = index; i < nLength; i++)
		pItems[i] = pItems[i + 1]; //Shift array elements 1 to the left and overwrite deleted data.
	nLength--;
}

int SortedList::GetLength()
{
	return nLength;
}

bool SortedList::IsFull()
{
	return (nLength == nMaxSize);
}

bool SortedList::IsItemInList(ItemType iSearchItem)
{
	//Binary search identifiers:
	int nHigh, nMid, nLow;
	nHigh = nLength - 1;
	nLow = 0;
	nMid = nHigh / 2;

	/*Binary search*/
	while (nLow <= nHigh)
	{
		switch (iSearchItem.ComparedTo(pItems[nMid]))
		{
		case LESS:		nHigh = nMid - 1;
						nMid = (nHigh + nLow) / 2;
						break;

		case GREATER:	nLow = nMid + 1;
						nMid = (nHigh + nLow) / 2;
						break;

		case EQUAL:		return true;
		}
	}

	return false;
}

void SortedList::Display()
{
	for (int i = 0; i < nLength; i++)
	{
		std::cout << pItems[i].Get() << " ";
	}
}

SortedList::~SortedList()
{
}