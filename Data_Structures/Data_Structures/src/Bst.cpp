#include "stdafx.h"
#include "..\include\Bst.h"
#include <fstream>
#include <algorithm>


Bst::~Bst()
{
	while (pop_root());
}

std::string Bst::to_string()
{
	auto output{ std::string() };
	inorder(root_, output);
	return output;
}

void Bst::insert(int value)
{
	auto leaf{ find_insert_spot(value, root_) };
	add_node(leaf, value);
}

void Bst::add_node(Bst_Node* leaf, int value)
{
	if (!leaf)
	{
		root_ = new Bst_Node(value, nullptr, nullptr, nullptr);
		return;
	}
	if (value > leaf->value_)
		leaf->right_ = new Bst_Node(value, leaf, nullptr, nullptr);
	else if (value < leaf->value_)
		leaf->left_ = new Bst_Node(value, leaf, nullptr, nullptr);
}

Bst_Node* Bst::find_insert_spot(int value, Bst_Node* node) const
{
	auto tmp{ node };

	while (tmp)
	{
		if (value < tmp->value_ && tmp->left_)
			tmp = tmp->left_;
		else if (value > tmp->value_ && tmp->right_)
			tmp = tmp->right_;
		else
			return tmp;
	}
	return tmp;
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
	delete child;
}

void Bst::remove_with_children(Bst_Node* node)
{
	// Find the successor and do the following:
	// 1 - Copy value of the successor into the node.
	// 2 - Copy contents of right child of the successor into the successor
	// 3 - Remove the right child of the successor.
	// Note that the successor never has a left child.

	auto successor = find_successor(node);

	node->value_ = successor->value_;

	auto right_succ_child = successor->right_;
	if (right_succ_child)
	{
		*successor = *right_succ_child;
		delete right_succ_child;
	}
	else
	{
		auto succ_parent{ successor->up_ };
		if (succ_parent->value_ > successor->value_)
			succ_parent->left_ = nullptr;
		else
			succ_parent->right_ = nullptr;
		delete successor;
	}	
}

Bst_Node* Bst::find_value(int value) const
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

bool Bst::load_from_file(const std::string& filepath)
{
	std::ifstream input_file;
	input_file.open(filepath);
	
	auto line{ std::string() };
	auto value{ 0 };

	if (input_file.is_open())
	{
		while (!input_file.eof())
		{
			input_file >> line;
			try
			{
				value = stoi(line);
			}
			catch (std::invalid_argument)
			{
				input_file.close();
				throw;
			}
			catch (std::out_of_range)
			{
				input_file.close();
				throw;
			}

			insert(value);
		}
		return true;
	}
	return false;
}

bool Bst::save_to_file(const std::string& filepath)
{
	auto bst_output{ std::string() };
	preorder(root_, bst_output);
	prep_for_saving(bst_output);

	std::ofstream output_file;
	output_file.open(filepath);

	if (output_file.is_open())
	{
		output_file << bst_output;
		output_file.close();
		return true;
	}
	return false;
}

void Bst::prep_for_saving(std::string& toSave)
{
	toSave.erase(std::remove(toSave.begin(), toSave.end(), ' '), toSave.end());
	toSave.replace(toSave.begin(), toSave.end(), ',', '\n');
}
