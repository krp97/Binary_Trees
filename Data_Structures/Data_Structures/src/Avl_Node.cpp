#include "stdafx.h"
#include "..\include\Avl_Node.h"



Avl_Node::Avl_Node()
	: Bst_Node(0), bal_factor_{ 0 }, up_{ nullptr }, left_{ nullptr }, right_{ nullptr }
{}

Avl_Node::Avl_Node(int value, int bal_factor, Avl_Node * up, Avl_Node * left, Avl_Node * right)
	:Bst_Node(value), bal_factor_{ bal_factor }, up_{ up }, left_{ left }, right_{ right }
{}

void Avl_Node::operator=(Avl_Node & rhs)
{
	bal_factor_ = rhs.bal_factor_;
	value_ = rhs.value_;
	left_ = rhs.left_;
	right_ = rhs.right_;
}

Avl_Node::~Avl_Node()
{}
