#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "head.h"

#define TREE_LEN 64

void rebuild(char *pre_order, char *in_order, int len, root *p2root)
{
	if(pre_order==NULL || in_order==NULL)
		return;

	/* get the first node of pre_order */
	root ptmp = (root)malloc(sizeof(treenode));
	ptmp->ch = *pre_order;
	ptmp->lchild = NULL;
	ptmp->rchild = NULL;

	/* if root is NULL, then copy ptmp as the root*/
	if(*p2root == NULL)
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

	/* rebuild child trees */
	if(left_len > 0)
		rebuild(pre_order + 1, in_order, left_len, &((*p2root)->lchild));
	if(right_len > 0)
		rebuild(pre_order + left_len + 1, in_order + left_len + 1, \
			right_len, &((*p2root)->rchild));
}

void pre_travel(root t)
{
	if(t != NULL){
		printf("%c", t->ch);
		pre_travel(t->lchild);
		pre_travel(t->rchild);
	}
	return;
}

void in_travel(root t)
{
	if(t != NULL){
		in_travel(t->lchild);
		printf("%c", t->ch);
		in_travel(t->rchild);
	}
	return;
}

void post_travel(root t)
{
	if(t != NULL){
		post_travel(t->lchild);
		post_travel(t->rchild);
		printf("%c", t->ch);
	}
	return;
}

void level_travel(root t)
{
	linkqueue q;
	queue_init(&q);

	while(t != NULL){
		printf("%c", t->ch);

		if(t->lchild != NULL)
			en_queue(q, t->lchild);
		if(t->rchild != NULL)
			en_queue(q, t->rchild);

		if(!out_queue(q, &t))
			return;
	}
}

void get_infos(char pre_order[], char in_order[])
{
	printf("input nodes in pre-order: ");
	fgets(pre_order, TREE_LEN, stdin);

	printf("input nodes in in-order : ");
	fgets(in_order, TREE_LEN, stdin);
}

void p_exit(const char *info)
{
	puts(info);
	exit(-1);
}

bool each_letter_matched(const char *s1, const char *s2)
{
	int i, j;
	int len = strlen(s1);
	bool flag;

	for(i=0; i<len; i++){
		flag = false;
		for(j=0; j<len; j++){
			if(s1[i] == s2[j]){
				flag = true;
				break;
			}
		}
		/*** got a lonely letter ***/
		if(!flag)
			return false;
	}
	return true;
}

bool check(const char *pre, const char *in)
{
	/********* check the length *********/
	if(strlen(pre)!= strlen(in)){
		fprintf(stderr, "different length.\n");
		return false;
	}

	int i, j;
	/****** check any non-letters ******/
	for(i=0; i<strlen(pre)-1; i++)
		if((pre[i] < 'A') || (pre[i] > 'z') || ((pre[i]>'Z')&&(pre[i]<'a')) ||
			(in[i] < 'A') || (in[i] > 'z') || ((in[i]>'Z')&&(in[i]<'a'))){

			fprintf(stderr, "accept letter only.\n");
			return false;
		}

	/***** check any identical name *****/
	for(i=0; i<strlen(pre)-1; i++)
		for(j=i+1; j<strlen(pre); j++){
			if((pre[i] == pre[j]) || (in[i] == in[j])){

				fprintf(stderr, "identical letters found.\n");
				return false;
			}
		}

	/***** check logical error *****/
	if(!each_letter_matched(pre, in)){
		fprintf(stderr, "don't match.\n");
		return false;
	}

	return true;
}

int main(int argc, char **argv)
{
	char pre_order[TREE_LEN];
	char in_order[TREE_LEN];

	while(1){
		memset(pre_order, 0, TREE_LEN);
		memset(in_order, 0, TREE_LEN);

		get_infos(pre_order, in_order);

		if(check(pre_order, in_order))
			break;
	}

	root t = NULL;
	rebuild(pre_order, in_order, strlen(pre_order)-1, &t);

	/***********************************
		travel in varous means
	************************************/
	travel("Traverse in pre_order:   ", travel_pre, t);
	travel("Traverse in in_order:    ", travel_center, t);
	travel("Traverse in post_order:  ", travel_post, t);
	travel("Traverse in level_order: ", travel_level, t);

	return 0;
}
