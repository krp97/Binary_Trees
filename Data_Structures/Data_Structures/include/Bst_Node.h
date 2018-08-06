#pragma once
#include <string>
class Bst_Node
{
	friend class Bst;
public:
	Bst_Node() : value_{ 0 }, up_{ nullptr }, left_{ nullptr }, right_{ nullptr } {};

	Bst_Node(int value, Bst_Node* up, Bst_Node* left, Bst_Node* right)		
		: value_{ value }, up_{ up }, left_{ left }, right_{ right } {};

	virtual ~Bst_Node();

	virtual std::string to_string();

	void operator=(Bst_Node& rhs);

protected:
	int value_;
	Bst_Node* up_;
	Bst_Node* left_;
	Bst_Node* right_;
};
