#include "../include/Bst.h"
#include <fstream>
#include <algorithm>
#include <string>

Bst::~Bst()
{
	while (pop_root());
}

std::string Bst::preorder()
{
	auto output{ std::string() };
	preorder(root_, output);
	return output;
}

std::string Bst::inorder()
{
	auto output{ std::string() };
	inorder(root_, output);
	return output;
}

std::string Bst::postorder()
{
	auto output{ std::string() };
	postorder(root_, output);
	return output;
}

void Bst::insert(int value)
{
	root_ = add_node(root_, nullptr, value);
}

Bst_Node* Bst::add_node(Bst_Node* node, Bst_Node* parent, int value)
{
	if(node == nullptr)
		return new Bst_Node(value, parent, nullptr, nullptr);
	else if (value > node->value_)
		node->right_ = add_node(node->right_, node, value);
	else if (value < node->value_)
		node->left_ = add_node(node->left_, node, value);
	
	return node;
}

bool Bst::pop_root()
{
	if (root_)
	{
		remove(root_);
		return true;
	}
	else
		return false;
}

void Bst::remove(int value)
{
	if(root_)
		remove(find_value(value));
}

Bst_Node* Bst::find_value(int value) const
{
	auto tmp_node{ root_ };

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

void Bst::remove(Bst_Node* node)
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

void Bst::remove_leaf(Bst_Node* node)
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

void Bst::remove_single_child(Bst_Node* node)
{
	auto child{ node->right_ ? node->right_ : node->left_ };

	*node = *child;
	
	if(child->left_)
		child->left_->up_ = node;
	if(child->right_)
		child->right_->up_ = node;	
	
	delete child;
}

void Bst::remove_with_children(Bst_Node* node)
{
	auto successor{ find_successor(node) };
	auto right_succ_child{ successor->right_};

	if (right_succ_child)
	{
		node->value_ = successor->value_;
		*successor = *right_succ_child;
		
		if(right_succ_child->left_)
			right_succ_child->left_->up_ = successor;
		if(right_succ_child->right_)
			right_succ_child->right_->up_ = successor;

		delete right_succ_child;
	}
	else
	{
		auto succ_parent{ successor->up_ };
		if (succ_parent->value_ > successor->value_)
			succ_parent->left_ = nullptr;
		else
			succ_parent->right_ = nullptr;
		node->value_ = successor->value_;

		delete successor;
	}	
}

Bst_Node* Bst::find_successor(Bst_Node* node) const
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

Bst_Node* Bst::find_min(Bst_Node* node) const
{
	auto tmp{ node };

	while (tmp->left_)
		tmp = tmp->left_;

	return tmp;
}

Bst_Node* Bst::find_max(Bst_Node* node) const
{
	auto tmp{ node };

	while (tmp->right_)
		tmp = tmp->right_;

	return tmp;
}

void Bst::inorder(Bst_Node* node, std::string& output)
{
	if (node)
	{
		inorder(node->left_, output);
		output += ", " + node->to_string();
		inorder(node->right_, output);

		if (output.at(0) == ',')
			output = output.substr(1);
	}
}

void Bst::preorder(Bst_Node* node, std::string& output)
{
	if (node)
	{
		output += ", " + node->to_string();
		preorder(node->left_, output);
		preorder(node->right_, output);
		
		if (output.at(0) == ',')
			output = output.substr(1);
	}
}

void Bst::postorder(Bst_Node* node, std::string& output)
{
	if (node)
	{
		postorder(node->left_, output);
		postorder(node->right_, output);
		output += ", " + node->to_string();

		if (output.at(0) == ',')
			output = output.substr(1);
	}
}
