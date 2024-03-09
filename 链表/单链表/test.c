#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "slist.h"
void TestSLT() {
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListNode*pos =SListFind(plist,2);
	SListInsertAfter(pos, 5);
	SListPrint(plist);

	SListEraseAfter(pos);
	SListPrint(plist);

	SLTInsert(&plist, pos,6);
	SListPrint(plist);

	SLTErase(&plist,pos);
	SListPrint(plist);

	SLTDestroy(&plist);
	SListPrint(plist);
}
int main() {
	TestSLT();
	return 0;
}