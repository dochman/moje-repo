#ifndef _DYNAMICZNE_H
#define _DYNAMICZNE_H
#include <string>
#include "MemCheck.h"

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

struct ListNode
{
	int val;
	ListNode* next;
	TreeNode* root;
};


ListNode* Build(const std::string& file_name);

int FindDeepestTree(ListNode* head);

void FreeMem(ListNode*&head);

#endif 