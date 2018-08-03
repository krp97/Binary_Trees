#pragma once
#include "../include/Bst_Node.h"
#include <string>

class Bst
{
public:
	
	Bst() : root_{ nullptr } {};
	virtual ~Bst();

	virtual std::string to_string();


protected:
	Bst_Node * root_;

private:

};