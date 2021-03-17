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
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		int i = 0,flag = 0;
		ListNode *pcur = head, *head_temp= nullptr, *tail_temp=nullptr,*p_pre = head;

		while(pcur)
		{
			head_temp = pcur;

			for (i=1;i<k;i++)
			{
				pcur = pcur->next;

				if (pcur==nullptr)
				{
					tail_temp = nullptr;
					break;
				}
			}

			tail_temp = pcur;

			pair<ListNode*,ListNode* > ret = reverseList(head_temp,tail_temp);

			if (flag == 0)
			{
				head = ret.first;
				p_pre = ret.second;
				flag = 1;
			} 
			else
			{
				p_pre->next = ret.first;
				p_pre = ret.second;
			}

			if (pcur)
			{
				pcur = ret.second->next;
			}
			else
			{
				break;
			}
		}

		return head;

	}

	pair<ListNode*,ListNode*>reverseList(ListNode* head,ListNode* tail)
	{
		if (head == NULL || tail == NULL)
			return pair<ListNode*,ListNode*>(head,tail);

		ListNode *pre=tail->next,*pcur= head;

		while (pre != tail)
		{
			ListNode *next = pcur->next;
			pcur->next = pre;

			pre = pcur;
			pcur = next;
		}

		return  pair<ListNode*,ListNode*>(tail,head);
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

int main()
{
	int a[4] = {1,2,3,4};

	Solution s;
	ListNode *list_a = s.creatList(a,4);
//	s.printList(s.swapPairs_1(list_a));

	//pair<ListNode*,ListNode*> ret = s.reverseList(list_a,list_a->next->next);

	s.printList(s.reverseKGroup(list_a,1));

	system("pause");

	return 0;
}

