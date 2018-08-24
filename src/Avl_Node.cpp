#include "../include/Avl_Node.h"
#include <string>

Avl_Node::Avl_Node()
	: value_{ 0 }, bal_factor_{ 0 }, up_{ nullptr }, left_{ nullptr }, right_{ nullptr }
{}

Avl_Node::Avl_Node(int value, int bal_factor, Avl_Node * up, Avl_Node * left, Avl_Node * right)
	:value_{ value }, bal_factor_{ bal_factor }, up_{ up }, left_{ left }, right_{ right }
{}

Avl_Node& Avl_Node::operator=(Avl_Node & rhs)
{
	bal_factor_ = rhs.bal_factor_;
	value_ = rhs.value_;
	left_ = rhs.left_;
	right_ = rhs.right_;

	return *this;
}

std::string Avl_Node::to_string()
{
	auto key{ std::to_string(value_) };
	auto height{ std::to_string(bal_factor_) };

	return key + " : " + height;
}

Avl_Node::~Avl_Node()
{}
