#include "stdafx.h"
#include "..\include\Bst.h"

Bst::~Bst()
{

}

std::string Bst::to_string()
{
	auto output = std::string();
	return inorder(root_, output);
}

void Bst::insert(int value)
{
	// Find an appropriate place to insert the input value.
	
	if (!root_)	// Leaf is an uninitialized root.
	{
		root_ = new Bst_Node(value, nullptr, nullptr, nullptr);
		return;
	}
	auto leaf{ find_insert_spot(value, root_) };

	if (value > leaf->value_)
		leaf->right_ = new Bst_Node(value, leaf, nullptr, nullptr);
	else
		leaf->left_ = new Bst_Node(value, leaf, nullptr, nullptr);
	
}

void Bst::popRoot()
{
	if(root_)
		remove(root_);
}

void Bst::remove(int value)
{
	if(root_)
		remove(find_value(value));
}

std::string Bst::inorder(Bst_Node* node, std::string& output)
{
	if (!node)
		return output;

	inorder(node->left_, output);
	output += ", " + node->to_string();
	inorder(node->right_, output);

	return output;
}

std::string Bst::preorder(Bst_Node* node, std::string& output)
{
	if (!node)
		return std::string();

	output += ", " + node->to_string();
	preorder(node->left_, output);
	preorder(node->right_, output);

	return output;
}

std::string Bst::postorder(Bst_Node* node, std::string& output)
{
	if (!node)
		return std::string();

	postorder(node->left_, output);
	postorder(node->right_, output);
	output += ", " + node->to_string();

	return output;
}

Bst_Node * Bst::find_insert_spot(int value, Bst_Node* node) const
{
	if (value < node->value_ && node->left_)
		return find_insert_spot(value, node->left_);

	else if (node->right_)
		return find_insert_spot(value, node->right_);

	else
		return node;
}

void Bst::remove(Bst_Node * node)
{
	if (node)
	{
		if (node->left_ && node->right_)
			remove_with_children(node);
		else if (node->left_ || node->right_)
			remove_single_child(node);
		else
			remove_leaf(node);
	}
}

void Bst::remove_leaf(Bst_Node * node)
{
	if (root_ != node)
	{
		auto parent{ node->up_ };

		if (parent->left_->value_ == node->value_)
			parent->left_ = nullptr;
		else
			parent->right_ = nullptr;

		delete node;
	}
	else
	{
		delete node;
		root_ = nullptr;
	}
}

void Bst::remove_single_child(Bst_Node * node)
{
	auto child{ node->right_ ? node->right_ : node->left_ };

	*node = *child;	// Using the overloaded assignment operator.
	delete child;
}

void Bst::remove_with_children(Bst_Node * node)
{
	// Find the successor and do the following:
	// 1 - Copy value of the successor into the node.
	// 2 - Copy contents of right child of the successor into the successor
	// 3 - Remove the right child of the successor.

	auto successor = find_successor(node);

	node->value_ = successor->value_;

	auto right_succ_child = successor->right_;
	*successor = *right_succ_child;
	delete right_succ_child;
}

Bst_Node * Bst::find_value(int value)
{
	auto tmp_node {root_};

	while (tmp_node)
	{
		if (value > tmp_node->value_)
			tmp_node = tmp_node->right_;
		else if (value < tmp_node->value_)
			tmp_node = tmp_node->left_;
		else
			return tmp_node;
	}
	return tmp_node;
}

Bst_Node * Bst::find_min(Bst_Node * node) const
{
	auto tmp{ node };

	while (tmp)
		tmp = tmp->left_;

	return tmp;

}

Bst_Node * Bst::find_max(Bst_Node * node) const
{
	auto tmp{ node };

	while (tmp)
		tmp = tmp->right_;

	return tmp;
}

Bst_Node * Bst::find_successor(Bst_Node * node)
{
	if (node->right_)
		return find_min(node->right_);
	else
	{
		auto parent{ node->up_ };
		auto tmp_node{ node };

		while (parent)
		{
			if (parent->left_ == tmp_node)
				return parent;

			tmp_node = parent;
			parent = parent->up_;
		}
		return parent;
	}
}

