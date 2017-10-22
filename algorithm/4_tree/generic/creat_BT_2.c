
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//#include <errno.h>

#include "head.h"

#define TREE_LEN 64
#define SUCCESS true

void rebuild(char *pre_order, char *in_order, int len, root *p2root)
{
	if(pre_order==NULL || in_order==NULL)
		return;

	/* get the first node of pre_order */
	root ptmp = (root)malloc(sizeof(treenode));
	ptmp->ch = *pre_order;
	ptmp->lchild = NULL;
	ptmp->rchild = NULL;

	*p2root = ptmp;

	/* if tree's length equals to 1, then it's the last node */
	if(len == 1)
		return;

	/* find the end of the left child-tree, and its length */
	char *in_order_tmp = in_order;
	char *p2left_end = in_order;
	int tmp_len = 0;

	while(*pre_order != *p2left_end){

		if(in_order_tmp==NULL || p2left_end==NULL)
			return;
		
		tmp_len++;

		/* record the temperate length, avoiding overflow */
		if(tmp_len > len)
			break;

		p2left_end++;
	}

	/* get the length of child trees */
	int left_len = 0, right_len = 0;
	left_len = (int)(p2left_end - in_order_tmp);
	right_len = (int)(len - left_len - 1);

	/*********************************
		rebuild child trees
	**********************************/
	if(left_len > 0)
		rebuild(pre_order + 1, in_order, left_len, &((*p2root)->lchild));
	if(right_len > 0)
		rebuild(pre_order + left_len + 1, in_order + left_len + 1, \
			right_len, &((*p2root)->rchild));
}

void get_infos(char pre_order[], char in_order[])
{
	printf("input nodes in pre-order: ");
	fgets(pre_order, TREE_LEN, stdin);

	printf("input nodes in in-order : ");
	fgets(in_order, TREE_LEN, stdin);
}

int main(int argc, char **argv)
{
	char pre_order[TREE_LEN];
	char in_order[TREE_LEN];

	while(1){
		memset(pre_order, 0, TREE_LEN);
		memset(in_order, 0, TREE_LEN);

		get_infos(pre_order, in_order);
		if(strlen(pre_order) == strlen(in_order))
			break;
		else
			fprintf(stderr, "different length.\n");
	}

	root t = NULL;
	rebuild(pre_order, in_order, strlen(pre_order)-1, &t);


	/**********************************
		travel in varous means
	**********************************/
	travel("Traverse in pre_order:   ", travel_pre, t);
	travel("Traverse in in_order:    ", travel_center, t);
	travel("Traverse in post_order:  ", travel_post, t);
	travel("Traverse in level_order: ", travel_level, t);

	return 0;
}
