#include "stdafx.h"
#include "Bst_Node.h"

Bst_Node::~Bst_Node()
{
}

std::string Bst_Node::to_string()
{
	return std::to_string(this->value_);
}

void Bst_Node::operator=(Bst_Node & rhs)
{
	this->left_ = rhs.left_;
	this->right_ = rhs.right_;
	this->value_ = rhs.value_;
}
