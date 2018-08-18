#include "..\include\Rbt.h"

Rbt::Rbt()
	: root_{ nullptr }, sentinel_{new Rbt_Node(0, 'B', nullptr, nullptr, nullptr) }
{

}

Rbt::Rbt(Rbt_Node * root)
	: root_{ root }, sentinel_{new Rbt_Node(0, 'B', nullptr, nullptr, nullptr)}
{

}


Rbt::~Rbt()
{

}

void Rbt::insert(int value)
{
	root_ = add_node(root_, nullptr, value);
}

Rbt_Node * Rbt::add_node(Rbt_Node * node, Rbt_Node* parent, const int value)
{
	if (node == sentinel_)
	{
		auto tmp{ new Rbt_Node(value, 'R', parent, sentinel_, sentinel_) };

		if (root_ = nullptr)
			tmp->color_ = 'B';
		return tmp;
	}
	else if (value > node->value_)
		add_node(node->right_, node, value);
	else if (value < node->value_)
		add_node(node->left_, node, value);

	balance(node);
	return nullptr;
}

Rbt_Node* Rbt::balance(Rbt_Node * node)
{
	if (node != root_ || node->up_->color_ != 'B')
	{
		auto uncle{ get_uncle(node) };

		if (uncle->color_ == 'R')
			red_uncle_fix(node, uncle);	// this doesn't have to return a node
		else
			black_uncle_fix(node, uncle);
	}
}

Rbt_Node * Rbt::get_uncle(Rbt_Node * node)
{
	auto grandparent{ node->up_->up_ };

	if (node->up_ == grandparent->right_)
		return grandparent->left_;
	else
		return grandparent->right_;
}

Rbt_Node * Rbt::red_uncle_fix(Rbt_Node* node, Rbt_Node* uncle)
{
	auto parent{ node->up_ };
	auto grandparent{ parent->up_ };
	
	parent->color_ = 'B';
	uncle->color_ = 'B';
	if(grandparent != root_)
		grandparent->color_ = 'R';

	return node;
}

Rbt_Node * Rbt::black_uncle_fix(Rbt_Node* node, Rbt_Node* uncle)
{
	
	return nullptr;
}

Rbt_Node * Rbt::rot_right(Rbt_Node * node)
{
	auto left_child{ node->left_ };

	if (node->up_)
		left_child->up_ = node->up_;
	else
	{
		root_ = left_child;
		left_child->up_ = nullptr;
	}
	node->up_ = left_child;

	node->left_ = left_child->right_;
	if (left_child->right_ != sentinel_)
		left_child->right_->up_ = node;

	left_child->right_ = node;

	return left_child;
}

Rbt_Node * Rbt::rot_left(Rbt_Node * node)
{
	auto right_child{ node->right_ };

	if (node->up_)
		right_child->up_ = node->up_;
	else
	{
		root_ = right_child;
		right_child->up_ = nullptr;
	}
	node->up_ = right_child;
	node->right_ = right_child->left_;

	if (right_child->left_ != sentinel_)
		right_child->left_->up_ = node;

	right_child->left_ = node;

	return right_child;
}

Rbt_Node * Rbt::rot_right_left(Rbt_Node * node)
{
	auto right_child{ node->right_ };
	node->right_ = rot_right(right_child);
	return rot_left(node);
}

Rbt_Node * Rbt::rot_left_right(Rbt_Node * node)
{
	auto left_child{ node->left_ };
	node->left_ = rot_left(left_child);
	return rot_right(node);
}
