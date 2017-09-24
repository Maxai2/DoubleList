#include <iostream>
#include <string>
#include "DoubleList.h"

using namespace std;

void main()
{
	List list;
	list.add(11);
	list.add(22);
	list.add(33);
	list.add(44);

	for (int i = 0; i < list.getCount(); i++)
	{
		cout << list[i] << endl;
	}

	list.insert(25, 1);
	cout << endl;
	for (int i = list.getCount() - 1; i >= 0; i--)
	{
		cout << list[i] << endl;
	}

	list.add(55);
	cout << endl;
	for (int i = 0; i < list.getCount(); i++)
	{
		cout << list[i] << endl;
	}

	list.remove(2);
	cout << endl;
	for (int i = list.getCount() - 1; i >= 0; i--)
	{
		cout << list[i] << endl;
	}


}