#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
//void SLtest() {
//	SL sl;
//	SLInit(&sl);
//	SLCheckCapacity(&sl);
//	//β��
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPrint(&sl);
//	//βɾ
//	SLPopBack(&sl);	
//	SLPrint(&sl);
//	//ͷ��
//	SLPushFront(&sl, 1);
//	SLPushFront(&sl, 2);
//	SLPushFront(&sl, 3);
//	SLPrint(&sl);
//	//ͷɾ
//	SLPopFront(&sl);
//	SLPrint(&sl);
//	//����
//	SLInsert(&sl, 2, 5);
//	SLPrint(&sl);
//	SLInsert(&sl, 2, 6);
//	SLPrint(&sl);
//	//ɾ��
//	SLErase(&sl, 4);
//	SLPrint(&sl);
//	//����
//	printf("%d", SLFind(&sl, 6));
//	SLDestroy(&sl);
//}
void menu() {
	printf("****************ͨѶ¼********************\n");
	printf("******1�������ϵ��    2��ɾ����ϵ��******\n");
	printf("******3���޸���ϵ��    4��������ϵ��******\n");
	printf("******5���鿴ͨѶ¼    0��  ��  ��  ******\n");
	printf("******************************************\n");
}
int main() {
	//SLtest();
	int option = -1;
	PeoInfo con;
	InitContact(&con);
	do {
		menu();
		printf("��ѡ�����Ĳ�����\n");
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
			printf("����������������������\n");
			break;
		}
	} while (option != 0);
	DestroyContact(&con);
	return 0;
}