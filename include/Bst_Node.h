#pragma once
#include <string>
class Bst_Node
{
	friend class Bst;

public:

	Bst_Node();

	Bst_Node(int value, Bst_Node* up, Bst_Node* left, Bst_Node* right);

	virtual ~Bst_Node();

	virtual std::string to_string();

	Bst_Node& operator=(Bst_Node& rhs);

	int get_value() { return this->value_; };

protected:
	Bst_Node(int value);

	int value_;

private:

	Bst_Node* up_;
	Bst_Node* left_;
	Bst_Node* right_;
};
