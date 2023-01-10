#include "Eazy_array.h"
#include "Eazy_string.h"
#include "Eazy_linkLisk.h"

int main()
{
	solution_string test;
	vector<int> v = { 4,5,1,9 };
	ListNode* head = new ListNode(0);
	for (int i = 0; i < v.size(); i++)
	{
		ListNode* p = new ListNode(v[i]);
		p->next = head->next;
		head->next = p;
	}
}