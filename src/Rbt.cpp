#include "../include/Rbt.h"

Rbt::Rbt()
	: sentinel_{new Rbt_Node ()}
{
	root_ = sentinel_;
}

Rbt::Rbt(Rbt_Node * root)
	: root_{ root }, sentinel_{new Rbt_Node()}
{

}

Rbt::~Rbt()
{

}

std::string Rbt::preorder()
{
	auto output{std::string()};
	preorder(root_, output);
	return output.substr(1);
}

void Rbt::preorder(Rbt_Node* node, std::string& output)
{
	if (node != sentinel_)
	{
		output += ", " + node->to_string();
		preorder(node->left_, output);
		preorder(node->right_, output);
	}
}

std::string Rbt::inorder()
{
	auto output{std::string()};
	inorder(root_, output);
	return output.substr(1);
}

void Rbt::inorder(Rbt_Node* node, std::string& output)
{
	if (node != sentinel_)
	{
		inorder(node->left_, output);
		output += ", " + node->to_string();
		inorder(node->right_, output);
	}
}

std::string Rbt::postorder()
{
	auto output{std::string()};
	postorder(root_, output);
	return output.substr(1);
}


void Rbt::postorder(Rbt_Node* node, std::string& output)
{
	if (node != sentinel_)
	{
		postorder(node->left_, output);
		postorder(node->right_, output);
		output += ", " + node->to_string();
	}
}

void Rbt::insert(int value)
{
	auto node_to_fix{ add_node(root_, value) };
	balance(node_to_fix);
}

Rbt_Node * Rbt::add_node(Rbt_Node * node, const int value)
{
	auto parent{ sentinel_ };

	for(auto tree_it{node};;)
	{
		if(tree_it == sentinel_)
		{
			tree_it = new Rbt_Node(value, 'R', parent, sentinel_, sentinel_);
			if(root_ == sentinel_)
			{
				root_ = tree_it;
				root_->color_ = 'B';
			}
			reattach_parent(parent, tree_it);
			return tree_it;
		}

		parent = tree_it;

		if (value > tree_it->value_)
			tree_it = tree_it->right_;
		else if (value < tree_it->value_)
			tree_it = tree_it->left_;
		
	}
}

void Rbt::balance(Rbt_Node * node)
{
	if (node->up_->color_ != 'B')
	{
		auto uncle{ get_uncle(node) };

		if (uncle->color_ == 'R')
			red_uncle_fix(node, uncle);
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

void Rbt::red_uncle_fix(Rbt_Node* node, Rbt_Node* uncle)
{
	auto parent{ node->up_ };
	auto grandparent{ parent->up_ };
	
	parent->color_ = 'B';
	uncle->color_ = 'B';

	if(grandparent != root_)
		grandparent->color_ = 'R';
}

void Rbt::black_uncle_fix(Rbt_Node* node, Rbt_Node* uncle)
{
	auto parent{ node->up_ };
	
	if(parent->value_ > uncle->value_ && uncle != sentinel_)
		fix_right(node);
	else
		fix_left(node);
}

void Rbt::swap_colors(Rbt_Node* node1, Rbt_Node* node2)
{
	char tmp_color{ node1->color_ };
	node1->color_ = node2->color_;
	node2->color_ = tmp_color;
}

void Rbt::fix_right(Rbt_Node* node)
{
	auto parent{ node->up_};
	auto grandparent{ parent->up_};
	auto sub_root{ grandparent->up_ };

	Rbt_Node* output;

	if(node->value_ > parent->value_)
		output = rot_left(grandparent);
	else 
		output = rot_right_left(grandparent);
		
	swap_colors(grandparent, output);
	reattach_parent(sub_root, output);
}

Rbt_Node * Rbt::rot_left(Rbt_Node * node)
{
	auto right_child{ node->right_ };

	if (node->up_ != sentinel_)
		right_child->up_ = node->up_;
	else
	{
		root_ = right_child;
		right_child->up_ = sentinel_;
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

void Rbt::reattach_parent(Rbt_Node* parent, Rbt_Node* child)
{
	if(parent != sentinel_)
	{
		if(child->value_ > parent->value_)
			parent->right_ = child;
		else
			parent->left_ = child;
	}
	else
		root_ = child;
}

void Rbt::fix_left(Rbt_Node* node)
{
	auto parent{ node->up_};
	auto grandparent{ parent->up_};
	auto sub_root{ grandparent->up_};

	Rbt_Node* output;

	if(node->value_ < parent->value_)
		output = rot_right(grandparent);
	else 
		output = rot_left_right(grandparent);
		
	swap_colors(grandparent, output);
	reattach_parent(sub_root, output);
}

Rbt_Node * Rbt::rot_right(Rbt_Node * node)
{
	auto left_child{ node->left_ };

	if (node->up_ != sentinel_)
		left_child->up_ = node->up_;
	else
	{
		root_ = left_child;
		left_child->up_ = sentinel_;
	}
	node->up_ = left_child;

	node->left_ = left_child->right_;
	if (left_child->right_ != sentinel_)
		left_child->right_->up_ = node;

	left_child->right_ = node;

	return left_child;
}

Rbt_Node * Rbt::rot_left_right(Rbt_Node * node)
{
	auto left_child{ node->left_ };
	node->left_ = rot_left(left_child);
	return rot_right(node);
}
