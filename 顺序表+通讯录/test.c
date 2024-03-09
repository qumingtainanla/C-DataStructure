#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
//void SLtest() {
//	SL sl;
//	SLInit(&sl);
//	SLCheckCapacity(&sl);
//	//尾插
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPrint(&sl);
//	//尾删
//	SLPopBack(&sl);	
//	SLPrint(&sl);
//	//头插
//	SLPushFront(&sl, 1);
//	SLPushFront(&sl, 2);
//	SLPushFront(&sl, 3);
//	SLPrint(&sl);
//	//头删
//	SLPopFront(&sl);
//	SLPrint(&sl);
//	//插入
//	SLInsert(&sl, 2, 5);
//	SLPrint(&sl);
//	SLInsert(&sl, 2, 6);
//	SLPrint(&sl);
//	//删除
//	SLErase(&sl, 4);
//	SLPrint(&sl);
//	//查找
//	printf("%d", SLFind(&sl, 6));
//	SLDestroy(&sl);
//}
void menu() {
	printf("****************通讯录********************\n");
	printf("******1、添加联系人    2、删除联系人******\n");
	printf("******3、修改联系人    4、查找联系人******\n");
	printf("******5、查看通讯录    0、  退  出  ******\n");
	printf("******************************************\n");
}
int main() {
	//SLtest();
	int option = -1;
	PeoInfo con;
	InitContact(&con);
	do {
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			ModifyContact(&con);
			break;
		case 4:
			FindContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			printf("goodbye~\n");
			break;
		default:
			printf("您的输入有误，请重新输入\n");
			break;
		}
	} while (option != 0);
	DestroyContact(&con);
	return 0;
}