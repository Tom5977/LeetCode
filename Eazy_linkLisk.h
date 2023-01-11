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

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head = new ListNode();
		ListNode* r = head;
		head->next = NULL;
		while (list1 != NULL && list2 != NULL)
		{
			if (list1->val < list2->val)
			{
				ListNode* tmp = list1->next;
				r->next = list1;
				list1->next = NULL;
				r = list1;
				list1 = tmp;
			}
			else
			{
				ListNode* tmp = list2->next;
				r->next = list2;
				list2->next = NULL;
				r = list2;
				list2 = tmp;
			}
		}
		if (list1 == NULL)
		{
			r->next = list2;
		}
		else
		{
			r->next = list1;
		}
		return head->next;
	}

	bool isPalindrome(ListNode* head) {
		vector<int> copy;
		while (head != NULL)
		{
			copy.push_back(head->val);
			head = head->next;
		}
		for (int i = 0; i < copy.size() / 2; i++)
		{
			if (copy[i] != copy[copy.size() - 1 - i])
			{
				return false;
			}
		}
		return true;
	}

	bool hasCycle(ListNode* head) {
		if (head == NULL)
		{
			return false;
		}
		ListNode* p = head;
		while (p->next != NULL && p->next->next != NULL)
		{
			p = p->next->next;
			head = head->next;
			if (p == head)
			{
				return true;
			}
		}
		return false;
	}
};