#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    ListNode* swapPairs(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *pre=nullptr, *p_cur = head;
		head = head->next;

		while (p_cur != nullptr && p_cur->next != nullptr)
		{
			ListNode *temp = p_cur->next->next;

			if (pre == nullptr)
			{
				p_cur->next->next = p_cur;
				p_cur->next = temp;

				pre = p_cur;
				p_cur = p_cur->next;
			}
			else
			{
				pre->next = p_cur->next;
				p_cur->next->next = p_cur;
				p_cur->next = temp;

				pre = p_cur;
				p_cur = p_cur->next;
			}
		}

		return head;
    }

	ListNode* swapPairs_1(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *temp = head->next->next,*pre = head;

		head = head->next;
		head->next = pre;
		pre->next = swapPairs_1(temp);
		
		return head;
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
	int a[5] = {1,2,3,4,5};

	Solution s;
	ListNode *list_a = s.creatList(a,5);
	s.printList(s.swapPairs_1(list_a));

	system("pause");

	return 0;
}
#endif

