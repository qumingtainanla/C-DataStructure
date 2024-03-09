#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "list.h"
void Test() {
	ListNode* plist = NULL;
	plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 5);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist, 6);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListNode* pos = ListFind(plist,3);
	ListInsert(pos,7);
	ListPrint(plist);

	ListErase(pos);
	ListPrint(plist);
}
int main() {
	Test();
	return 0;
}