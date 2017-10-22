#include "head4tree.h"

#define QUEUE_NODE_DATATYPE linktree
#include "head4queue.h"

int main(void)
{
	linktree root = NULL;
	srand(time(NULL));

	int i;
	for(i=0; i<10; i++)
		root = AVL_insert(root, rand()%100);

	DO_TREE_MAP(root, treenode, lchild, rchild, draw);

	linkqueue q;
	q = init_queue();

	en_queue(q, root);
	linktree m;
	while(1)
	{
		if(!out_queue(q, &m))
			break;
		printf("%d\t", m->data);
		if(m->lchild)
			en_queue(q, m->lchild);
		if(m->rchild)
			en_queue(q, m->rchild);
	}
	printf("\n");

	while(1)
	{
		scanf("%d", &i);
		root = AVL_remove(root, i);
		DO_TREE_MAP(root, treenode, lchild, rchild, draw);
	}
	return 0;
}
