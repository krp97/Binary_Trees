#include "stdafx.h"
#include "..\include\Avl.h"



Avl::Avl()
	: root_{ nullptr }
{}

Avl::Avl(Avl_Node& root)
	: root_{ &root }
{}

Avl::Avl(Avl& avl_tree)
	: root_{ avl_tree.root_ }
{}

Avl::~Avl()
{}

std::string Avl::to_string()
{
	return std::string();
}

void Avl::insert(int value)
{

}

bool Avl::popRoot()
{
	return false;
}
