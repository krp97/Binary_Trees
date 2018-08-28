#include "../include/Avl_Node.h"
#include <string>

Avl_Node::Avl_Node()
	: value_{ 0 }, height_{ 0 }, up_{ nullptr }, left_{ nullptr }, right_{ nullptr }
{}

Avl_Node::Avl_Node(int value, int height, Avl_Node * up, Avl_Node * left, Avl_Node * right)
	:value_{ value }, height_{ height }, up_{ up }, left_{ left }, right_{ right }
{}

Avl_Node& Avl_Node::operator=(Avl_Node & rhs)
{
	height_ = rhs.height_;
	value_ = rhs.value_;
	left_ = rhs.left_;
	right_ = rhs.right_;

	return *this;
}

std::string Avl_Node::to_string()
{
	auto key{ std::to_string(value_) };
	auto height{ std::to_string(height_) };

	return key + " : " + height;
}

Avl_Node::~Avl_Node()
{}
