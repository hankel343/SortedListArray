#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
	SortedList list;
	ItemType iTemp;

	int nums[] = { 1, 7, -1, 4, 0 };

	for (int i = 0; i < 5; i++)
	{
		iTemp.Set(nums[i]);
		list.PutItem(iTemp);
		cout << nums[i] << " has been added to the list.\n";
	}

	iTemp.Set(2);

	if (list.IsItemInList(iTemp))
		cout << iTemp.Get() << " was found in the list.\n";
	else
		cout << iTemp.Get() << " was not found in the list.\n";

	cout << "\nHere is the list: \n";
	list.Display();
	


	return 0;
}