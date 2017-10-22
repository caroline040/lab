#ifndef __TREE_MAP_H__
#define __TREE_MAP_H__

#include <stddef.h>

/*
 * tree_map.h	 Draw the map for any B-tree
 * If you have any question, you can mail me.
 *
 * Authors:	xuediao, <xuediao@eyou.com>
 *
 */

/*
print_node: print out the node object as string. Just like obj.tostring() in java or C#
This function should malloc the memory for the returned value.
And the returned value will be released in do_tree_map function
*/
typedef char* (*print_node)(void *node);

/*
You can use this macro to draw the map
parameters description:
root: pointer of the root node of your tree;
structure: the structure of your tree node;
lfield: the field name in structure, points to left sub tree
rfield: the field name in structure, points to right sub tree
print_func: The function address, which implemented print_node interface. If not set, system will print out the address of the node.
*/
#define DO_TREE_MAP(root, structure, lfield, rfield, print_func) do_tree_map(root, offsetof(structure, lfield), offsetof(structure, rfield), print_func)
void do_tree_map(void *root, long offset_left, long offset_right, print_node fun);

#endif

