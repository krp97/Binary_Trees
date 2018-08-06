// Data_Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include\Bst.h"
#include "vld.h"
#include <iostream>

int main()
{
	const std::string io_file{ std::string("data\\BST_1.txt") };
	Bst myTree = Bst();

	myTree.load_from_file(io_file);
	std::cout << myTree.to_string();
	system("pause");
    return 0;
}

