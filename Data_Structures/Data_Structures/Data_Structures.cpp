// Data_Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include\Bst.h"
#include "vld.h"
#include "include/Avl.h"
#include <iostream>

// TODO:
// - AVL insertion, balancing
// - Fix the leaf bug in bst
// -  ?

int main()
{
	const std::string io_file{ std::string("data\\BST_1.txt") };
	Bst myTree = Bst();
	Avl myAvl{ Avl() };

	auto output{ std::string() };
	myAvl.preorder(myAvl.get_root(), output);
	std::cout << output << std::endl;
	system("pause");
    return 0;
}

