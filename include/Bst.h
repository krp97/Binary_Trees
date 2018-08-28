#include "Bst_Node.h"
#include <string>

class Bst
{
public:
	
	Bst() : root_{ nullptr } {};

	Bst(Bst_Node* root) : root_{ root } {};

	Bst& operator=(Bst& rhs) { this->root_ = rhs.root_; return *this; };

	virtual ~Bst();

	std::string preorder();

	std::string inorder();

	std::string postorder();

	virtual void insert(int value);

	virtual bool pop_root();

	void remove(int value);

	int find_max() const;

	int find_min() const;

private:

	Bst_Node * root_;

	Bst_Node* add_node(Bst_Node* node, Bst_Node* parent, int value);


	void remove(Bst_Node* node);

	void remove_leaf(Bst_Node* node);			

	void remove_single_child(Bst_Node* node);

	void remove_with_children(Bst_Node* node);	


	Bst_Node* find_value(int value) const;

	Bst_Node* find_min(Bst_Node* node) const;

	Bst_Node* find_max(Bst_Node* node) const;

	Bst_Node* find_successor(Bst_Node* node) const;

	void inorder(Bst_Node* node, std::string& output);
	
	void preorder(Bst_Node* node, std::string& output);
	
	void postorder(Bst_Node* node, std::string& output);

};