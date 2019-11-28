#include "../catch.hpp"
#include "../Std/Map.h"

#include <iostream>
#include <string>

using namespace StlStd;
using namespace std;

TEST_CASE("Map - Constructor - All", "[Map]")
{
	Map<string, int> test1;
	test1["Hello"] = 12;
	test1["Hello"] = 24;
	test1["World"] = 31;
	const Map<string, int> test2 = test1;
	cout << test2.At("World") << endl;
	cout << test2.At("Hello") << endl;
	test1.Iterate([](const KeyValuePair<string, int>& pair) 
	{
		cout << pair.Key << ": " << pair.Value << endl;
	});
}