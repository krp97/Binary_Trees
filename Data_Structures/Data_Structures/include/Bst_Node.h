#pragma once

class Bst_Node
{
public:
	Bst_Node(int value, Bst_Node* up, Bst_Node* left, Bst_Node* right)		
		: value_{ value }, up_{ up }, left_{ left }, right_{ right } {};

	virtual ~Bst_Node();

	virtual std::string to_string();

protected:
	int value_;
	Bst_Node* up_;
	Bst_Node* left_;
	Bst_Node* right_;
};
