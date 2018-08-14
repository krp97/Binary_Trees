

# Data_Structures
## Tools used 

* Miscrosoft Visual Studio 2017 
* [Visual Leak Detector ](https://archive.codeplex.com/?p=vld)
VLD header file has been left included in the main handler class, as it does not affect the release version. 

## Project description

**Data Structures** is a follow up project to **[Basic Data Structures](https://github.com/krp97/Basic-Data-Structures)** which complements the implementation with Binary Trees:
* Binary Search Tree
* AVL Tree (Adelson-Velskii and Landis)
* Red and Black Tree

Each binary tree is represented by a similar API consisting of following functionalities:
* Preorder, Inorder and Postorder traversal.
* Insertion/ Deletion.
* Loading a structure from and saving to a file.
* Finding the max/min keys in the tree.

Avl tree notation is represented as follows:
* Top node of each subtree contains a height of the whole subtree.
* Tree fixing occurs, when the difference between a right and left child is bigger than 2 levels.

Example:

		    5:2
		   /   \
		 2:1   8:0
		 /
	      1:0

---
