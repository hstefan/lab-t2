#include <iostream>
#include "list.h"

int main(int argc, char* argv[])
{
	ds::list<int> foo;
	for(int i = 0; i < 20; ++i)
		foo.push_back(i);
	foo.pop_back();
	foo.pop_front();
	for(ds::list<int>::iterator it = foo.begin(); it != foo.end(); it++)
		std::cout <<  *it << std::endl;
	int a;
	std::cin >> a;
}