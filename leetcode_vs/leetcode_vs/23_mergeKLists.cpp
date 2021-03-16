#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
		{
			return NULL;
		}

		ListNode *head = nullptr;

		for (int i = 0;i<lists.size();i++)
		{
			head = mergeTwoLists(head,lists[i]);
		}
		
		return head;

    }

	ListNode* merge(vector<ListNode*>& lists,int l,int r)
	{
		if (l == r)
		{
			return lists[l];
		}

		if (l > r)
			return NULL;

		return mergeTwoLists(merge(lists,l,(l+r)/2),merge(lists,(l+r)/2 +1,r));

	}

	ListNode* mergeKLists_1(vector<ListNode*>& lists) 
	{
		return merge(lists,0,lists.size()-1);
	}

	ListNode* mergeTwoLists(ListNode *a, ListNode *b)
	{
		ListNode head;
		ListNode *tail = &head, *aPtr = a,*bPtr = b;

		if (a == nullptr || b == nullptr)
		{
			return (a==nullptr)?b:a;
		}

		while (aPtr && bPtr)
		{
			if (aPtr->val <= bPtr->val)
			{
				tail->next = aPtr;
				aPtr = aPtr->next;
			}else
			{
				tail->next = bPtr;
				bPtr = bPtr->next;
			}

			tail = tail->next;
		}

		tail->next = (aPtr==nullptr)?bPtr:aPtr;		
		return head.next;
	}

	ListNode* creatList(int nums[],int len)
	{
		ListNode head,*pCur = &head;

		if(sizeof(nums) == 0)
			return nullptr;

		for (int i = 0;i<len;i++)
		{
			ListNode *node = new ListNode(nums[i]);
			pCur ->next = node;
			pCur = node;
		}

		return head.next;
	}

	void printList(ListNode *list)
	{
		if (list== nullptr)
		{
			cout << ""<<endl;
			return;
		}

		while (list)
		{
			printf("%d->",list->val);
			list = list->next;
		}

		cout <<endl;
	}
};
#if 0
int main()
{
	int a[3] = {1,4,5}, b[3] = {1,3,4}, c[2] = {2,6};

	Solution s;
	ListNode *list_a = s.creatList(a,3);
	ListNode *list_b = s.creatList(b,3);
	ListNode *list_c = s.creatList(c,2);

	s.printList(list_a);
	s.printList(list_b);
	s.printList(list_c);

	vector<ListNode *> vector;
	vector.push_back(list_a);
	vector.push_back(list_b);
	vector.push_back(list_c);

	//s.printList(s.mergeKLists(vector));

	//s.printList(s.mergeKLists_1(vector));

	//s.printList(s.mergeTwoLists(list_a,list_b));

	system("pause");

	return 0;
}
#endif