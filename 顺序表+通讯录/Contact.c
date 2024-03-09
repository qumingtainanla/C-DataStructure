#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "list.h"

void InitContact(contact* con) {
	SLInit(con);
}
void AddContact(contact* con) {
	PeoInfo info;
	printf("请输入联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入联系人的性别：\n");
	scanf("%s", info.sex);
	printf("请输入联系人的年龄：\n");
	scanf("%d", &info.age);
	printf("请输入联系人的电话：\n");
	scanf("%s", info.tel);
	printf("请输入联系人的住址：\n");
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
	printf("请输入要删除的联系人：\n");
	scanf("%s", delname);
	int find = FindByName(con, delname);
	if (find < 0)
	printf("要删除的联系人不存在: \n");
	SLErase(con,find);
}
void ShowContact(contact* con) {
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i < con->size; i++)
		printf("%-4s %-4s %-4d %-4s %-4s\n", con->a[i].name, con->a[i].sex, con->a[i].age, con->a[i].tel, con->a[i].addr);
}
void FindContact(contact* con) {
	char findname[NAME_MAX];
	printf("请输入要查找的联系人：\n");
	scanf("%s", findname);
	int find = FindByName(con, findname);
	if (find < 0) {
		printf("联系人不存在！\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%-4s %-4s %-4d %-4s %-4s\n", con->a[find].name, con->a[find].sex, con->a[find].age, con->a[find].tel, con->a[find].addr);
}
void ModifyContact(contact* con) {
	char modifyname[NAME_MAX];
	printf("请输入要修改的联系人：\n");
	scanf("%s", modifyname);
	int find = FindByName(con, modifyname);
	if (find < 0) {
		printf("联系人不存在！\n");
		return;
	}
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", con->a[find].name);
	printf("请输入要修改的联系人的性别：\n");
	scanf("%s", con->a[find].sex);
	printf("请输入要修改的联系人的年龄：\n");
	scanf("%d", &con->a[find].age);
	printf("请输入要修改的联系人的电话：\n");
	scanf("%s", con->a[find].tel);
	printf("请输入要修改的联系人的住址：\n");
	scanf("%s", con->a[find].addr);

	printf("修改成功\n");
}
void DestroyContact(contact* con) {
	SLDestroy(con);
}