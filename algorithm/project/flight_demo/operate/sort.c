#include <stdio.h>
#include "../include/flight.h"

#if 0
void sort_type(linklist head)
{
	linklist pos, q, tmp;

	list_for_each_entry(pos, &head->list, list)
	{
		list_for_each_entry(q, &head->list, list)
		{
			if(q == pos)
				break;

			if(q->info.type > pos->info.type)
			{
				list_move_tail(&pos->list, &q->list);
				tmp = pos;
				pos = q;
				q = tmp;
			}
		}
	}

	show_all(head);
}

void sort_price(linklist head)
{
	linklist pos, q, tmp;

	list_for_each_entry(pos, &head->list, list)
	{
		list_for_each_entry(q, &head->list, list)
		{
			if(q == pos)
				break;

			double price1 = atof(q->info.price + 1); // "+1" in order to omit prefix '$'
			double price2 = atof(pos->info.price + 1);

			if(price1 > price2)
			{
				list_move_tail(&pos->list, &q->list);
				tmp = pos;
				pos = q;
				q = tmp;
			}
		}
	}

	show_all(head);
}
#endif

void sort(linklist head)
{
	if(head == NULL)
	{
		printf("\tNo Info.\n");
		return;
	}

	printf("\n======================"
		"===================\n");
	printf("[1]By Addr. [2]By Date. [3]By Type.\n");
	printf("========================"
		"================\n");

	int choice;
	Scanf("%d", &choice, 1, 7);

	switch(choice)
	{
	case 1:
		SORT(head, depart_address);
		break;
	case 2:
		SORT(head, date);
		break;
	case 3:
		//sort_type(head);
		SORT_TYPE(head);
		break;
	default:
		printf("invalid input.");
	}
}
