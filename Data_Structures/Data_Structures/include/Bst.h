#pragma once
#include "Bst_Node.h"
#include <string>

class Bst
{
public:
	
	Bst() : root_{ nullptr } {};

	Bst(Bst_Node* root) : root_{ root } {};

	Bst& operator=(Bst& rhs) { this->root_ = rhs.root_; };

	virtual ~Bst();

	virtual std::string to_string();

	virtual void insert(int value);

	virtual bool popRoot();

	void remove(int value);

	void inorder(Bst_Node* node, std::string& output);

	void preorder(Bst_Node* node, std::string& output);
	
	void postorder(Bst_Node* node, std::string& output);

	Bst_Node* get_root() const { return root_; };

	bool load_from_file(const std::string& filepath);
	
	bool save_to_file(const std::string& filepath);

protected:
	Bst_Node* root_;

private:

	Bst_Node* find_insert_spot(int value, Bst_Node* node) const;

	void remove(Bst_Node* node);

	// Removal methods handling three seperate cases:	--------------------------

	void remove_leaf(Bst_Node* node);			// -> Node doesn't have children.

	void remove_single_child(Bst_Node* node);	// -> Node has one child.

	void remove_with_children(Bst_Node* node);	// -> Node has both children.
	// ---------------------------------------------------------------------------

	Bst_Node* find_value(int value) const;

	Bst_Node* find_min(Bst_Node* node) const;

	Bst_Node* find_max(Bst_Node* node) const;

	Bst_Node* find_successor(Bst_Node* node) const;

	void prep_for_saving(std::string& toSave);
};