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
	auto node{ find_insert_spot(value, root_)};
	add_node(node);
	balance_tree(node);
}

bool Avl::pop_root()
{
	return false;
}

void Avl::add_node(Avl_Node * leaf)
{
	auto value{ leaf->value_ };

	if (!root_)
	{
		root_ = new Avl_Node(value, 0, nullptr, nullptr, nullptr);
		return;
	}
	if (value > leaf->value_)
	{
		leaf->right_ = new Avl_Node(value, 0, leaf, nullptr, nullptr);
		leaf->bal_factor_--;
	}	
	else if (value < leaf->value_)
	{
		leaf->left_ = new Avl_Node(value, 0, leaf, nullptr, nullptr);
		leaf->bal_factor_++;
	}		
}

Avl_Node * Avl::find_insert_spot(int value, Avl_Node* root)
{
	auto tmp{ root };

	while (tmp)
	{
		if (value < tmp->value_ && tmp->left_)
			tmp = tmp->left_;
		else if (value > tmp->value_ && tmp->right_)
			tmp = tmp->right_;
		else	// ??
			return tmp;
	}
	return tmp;
}

void Avl::update_heights(Avl_Node* leaf)
{
	for (auto avl_it{ leaf->up_ }; avl_it; avl_it->up_)
		avl_it->bal_factor_ = avl_it->right_->bal_factor_ 
								+ avl_it->left_->bal_factor_;

}

void Avl::balance_tree(Avl_Node* node)
{
	update_heights(node);
	auto unbalanced_node{find_unbalanced_node(node)};
}

Avl_Node * Avl::find_unbalanced_node(Avl_Node * leaf)
{
	while (leaf)
	{
		if (leaf->bal_factor_ > 1 || leaf->bal_factor_ < -1)
			return leaf;
		leaf = leaf->up_;
	}
	return nullptr;
}

void Avl::right_rot(Avl_Node* node)
{
	auto left_child{ node->left_ };

	if (node->up_)
		swap_child(node->up_, left_child);
	else
		left_child = nullptr;

	auto tmp_right_child{ left_child->right_ };

	assign_as_right_child(left_child, node);
	assign_as_left_child(node, tmp_right_child);
}

void Avl::left_rot(Avl_Node* node)
{
	auto right_child{ node->right_ };

	if (node->up_)
		swap_child(node->up_, right_child);
	else
		right_child->up_ = nullptr;
	
	auto tmp_left_child{ right_child->left_ };

	assign_as_left_child(right_child, node);
	assign_as_right_child(node, tmp_left_child);
}

void Avl::swap_child(Avl_Node * parent, Avl_Node * new_child)
{
	if (new_child->value_ > parent->value_)
		assign_as_right_child(parent, new_child);
	else
		assign_as_left_child(parent, new_child);
}

void Avl::assign_as_right_child(Avl_Node * parent, Avl_Node * child)
{
	parent->right_ = child;
	child->up_ = parent;
}

void Avl::assign_as_left_child(Avl_Node * parent, Avl_Node * child)
{
	parent->left_ = child;
	child->up_ = parent;
}

void Avl::right_left_rot(Avl_Node * right_rot_root)
{
	auto left_rot_root{ right_rot_root->up_ };

	right_rot(right_rot_root);
	left_rot(left_rot_root);
}

void Avl::left_right_rot(Avl_Node * left_rot_root)
{
	auto right_rot_root{ left_rot_root->up_ };
	
	left_rot(left_rot_root);
	right_rot(right_rot_root);
}
