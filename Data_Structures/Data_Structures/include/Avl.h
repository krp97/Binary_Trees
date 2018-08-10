
#include "Bst.h"
#include "Avl_Node.h"
#include <string>

class Avl : public Bst
{

public:
	Avl();

	Avl(Avl_Node& root);

	Avl(Avl& avl_tree);

	virtual ~Avl();

	std::string to_string() override;

	void insert(int value) override;

	bool pop_root() override;

	Avl_Node* get_root() const override { return root_; };

private:

	Avl_Node * root_;

	void add_node(Avl_Node* leaf);

	Avl_Node* find_insert_spot(int value, Avl_Node* root);

	Avl_Node* find_unbalanced_node(Avl_Node* leaf);

	void update_heights(Avl_Node* leaf);

	void balance_tree(Avl_Node* node);

	void right_rot(Avl_Node* node);

	void left_rot(Avl_Node* node);

	void swap_child(Avl_Node* parent, Avl_Node* new_child);

	void assign_as_right_child(Avl_Node* parent, Avl_Node* child);

	void assign_as_left_child(Avl_Node* parent, Avl_Node* child);

	void right_left_rot(Avl_Node* node);

	void left_right_rot(Avl_Node* node);
};
