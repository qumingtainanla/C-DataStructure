#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "list.h"

void InitContact(contact* con) {
	SLInit(con);
}
void AddContact(contact* con) {
	PeoInfo info;
	printf("��������ϵ��������\n");
	scanf("%s", info.name);
	printf("��������ϵ�˵��Ա�\n");
	scanf("%s", info.sex);
	printf("��������ϵ�˵����䣺\n");
	scanf("%d", &info.age);
	printf("��������ϵ�˵ĵ绰��\n");
	scanf("%s", info.tel);
	printf("��������ϵ�˵�סַ��\n");
	scanf("%s", info.addr);
	SLPushBack(con, info);
}
int FindByName(contact* con,char name[]) {
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->a[i].name,name)==0)
			return i;
	}
	return -1;
}
void DelContact(contact* con) {
	char delname[NAME_MAX];
	printf("������Ҫɾ������ϵ�ˣ�\n");
	scanf("%s", delname);
	int find = FindByName(con, delname);
	if (find < 0)
	printf("Ҫɾ������ϵ�˲�����: \n");
	SLErase(con,find);
}
void ShowContact(contact* con) {
	printf("%s %s %s %s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
	for (int i = 0; i < con->size; i++)
		printf("%-4s %-4s %-4d %-4s %-4s\n", con->a[i].name, con->a[i].sex, con->a[i].age, con->a[i].tel, con->a[i].addr);
}
void FindContact(contact* con) {
	char findname[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ�ˣ�\n");
	scanf("%s", findname);
	int find = FindByName(con, findname);
	if (find < 0) {
		printf("��ϵ�˲����ڣ�\n");
		return;
	}
	printf("%s %s %s %s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%-4s %-4s %-4d %-4s %-4s\n", con->a[find].name, con->a[find].sex, con->a[find].age, con->a[find].tel, con->a[find].addr);
}
void ModifyContact(contact* con) {
	char modifyname[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ�ˣ�\n");
	scanf("%s", modifyname);
	int find = FindByName(con, modifyname);
	if (find < 0) {
		printf("��ϵ�˲����ڣ�\n");
		return;
	}
	printf("������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s", con->a[find].name);
	printf("������Ҫ�޸ĵ���ϵ�˵��Ա�\n");
	scanf("%s", con->a[find].sex);
	printf("������Ҫ�޸ĵ���ϵ�˵����䣺\n");
	scanf("%d", &con->a[find].age);
	printf("������Ҫ�޸ĵ���ϵ�˵ĵ绰��\n");
	scanf("%s", con->a[find].tel);
	printf("������Ҫ�޸ĵ���ϵ�˵�סַ��\n");
	scanf("%s", con->a[find].addr);

	printf("�޸ĳɹ�\n");
}
void DestroyContact(contact* con) {
	SLDestroy(con);
}