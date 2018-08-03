#pragma once
#include "Bst_Node.h"
#include <string>

class Bst
{
public:
	
	Bst() : root_{ nullptr } {};
	Bst(Bst_Node* root) : root_{ root } {};

	virtual ~Bst();

	virtual std::string to_string();

	virtual void insert(int value);

	virtual void popRoot();

	void remove(int value);

	std::string inorder(Bst_Node* node, std::string& output);

	std::string preorder(Bst_Node* node, std::string& output);
	
	std::string postorder(Bst_Node* node, std::string& output);

	Bst_Node* get_root() { return root_; };

protected:
	Bst_Node* root_;

private:

	Bst_Node * find_insert_spot(int value, Bst_Node* node) const;

	void remove(Bst_Node* node);

	// Removal methods handling three seperate cases:	--------------------------

	void remove_leaf(Bst_Node* node);			// -> Node doesn't have children.

	void remove_single_child(Bst_Node* node);	// -> Node has one child.

	void remove_with_children(Bst_Node* node);	// -> Node has both children.
	// ---------------------------------------------------------------------------

	Bst_Node* find_value(int value);

	Bst_Node* find_min(Bst_Node* node) const;

	Bst_Node* find_max(Bst_Node* node) const;

	Bst_Node* find_successor(Bst_Node* node);
};