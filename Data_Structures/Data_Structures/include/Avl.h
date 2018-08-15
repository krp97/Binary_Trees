
#include "Bst.h"
#include "Avl_Node.h"
#include <string>

class Avl
{

public:
	Avl();

	Avl(Avl_Node& root);

	Avl& operator=(Avl& rhs) { this->root_ = rhs.root_; };

	virtual ~Avl();

	void insert(const int value);

	void remove(const int value);

	void inorder(Avl_Node* node, std::string& output);

	void preorder(Avl_Node* node, std::string& output);

	void postorder(Avl_Node* node, std::string& output);

	Avl_Node* get_root() { return root_; };

	std::string to_string();

private:

	Avl_Node * root_;

	int max(const int value1, const int value2) const;

	int get_height(Avl_Node const* node) const;
	
	void update_height(Avl_Node* node);

	Avl_Node* remove_node(Avl_Node* node, const int value);

	Avl_Node* remove_case(Avl_Node* node);

	Avl_Node* remove_leaf(Avl_Node* node_to_remove);

	Avl_Node* remove_with_single_child(Avl_Node* node_to_remove);

	Avl_Node* remove_with_children(Avl_Node* node_to_remove);

	Avl_Node* find_successor(Avl_Node* node);

	Avl_Node* find_min(Avl_Node* node);

	Avl_Node* add_node(Avl_Node * leaf, Avl_Node* leaf_parent, const int value);

	Avl_Node* retrace(Avl_Node* leaf, const int value);

	Avl_Node* fix_right(Avl_Node* node, const int value);

	Avl_Node* fix_left(Avl_Node* node, const int value);

	void reattach_parent(Avl_Node* parent, Avl_Node* child);

	Avl_Node* rot_left(Avl_Node* node);

	Avl_Node* rot_right_left(Avl_Node* node);

	Avl_Node* rot_right(Avl_Node* node);

	Avl_Node* rot_left_right(Avl_Node* node);

};
