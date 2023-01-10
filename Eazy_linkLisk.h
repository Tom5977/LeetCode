#pragma once
#include"Header.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode() = default;
	
};

class solution_linkLisk
{
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode* d = node->next;
		node->next = d->next;
		delete d;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL)
		{
			return NULL;
		}
		ListNode* p = head;
		for (int i = 0; i < n - 1; i++)
		{
			p = p->next;
		}
		ListNode* q = head;
		ListNode* r = head;
		if (p->next == NULL)
		{
			return head->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
		while (p->next != NULL)
		{
			p = p->next;
			q = q->next;
			r = r->next;
		}
		r->next = q->next;
		return head;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		ListNode* Head = new ListNode(0);
		ListNode* p = head->next;
		ListNode* q = head;
		while (p != NULL)
		{
			q->next = Head->next;
			Head->next = q;
			q = p;
			p = p->next;
		}
		q->next = Head->next;
		Head->next = q;
		return Head->next;
	}
};