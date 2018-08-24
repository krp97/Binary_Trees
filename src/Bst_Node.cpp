#include "../include/Bst_Node.h"

Bst_Node::Bst_Node()
	: value_{ 0 }, up_{ nullptr }, left_{ nullptr }, right_{ nullptr }
{}

Bst_Node::Bst_Node(int value, Bst_Node * up, Bst_Node * left, Bst_Node * right)
	: value_{ value }, up_{ up }, left_{ left }, right_{ right }
{}

Bst_Node::~Bst_Node()
{
}

std::string Bst_Node::to_string()
{
	return std::to_string(value_);
}

Bst_Node& Bst_Node::operator=(Bst_Node & rhs)
{
	left_ = rhs.left_;
	right_ = rhs.right_;
	value_ = rhs.value_;
	return *this;
}

// Protected constructor used in derived classes construction
Bst_Node::Bst_Node(int value)
	: value_{value}
{}
