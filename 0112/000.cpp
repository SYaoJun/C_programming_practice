#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include<cstring>
#include <string.h> 
#include<iomanip>
using namespace std;
struct flightnode {
	char flight_num[10];
	char time[10];
	char Etime[10];
	char start_place[20];
	char end_place[20];
	int left;
	float price;
	float discount;
	int isFull;
	struct flightnode *next;
}flightnode;
typedef struct passengernode {
	char name[20];
	char ID_num[20];
	char flight_num[10];
	int order_num;
	int ticket_num;
	struct passengernode *next;
}passengernode;
typedef struct passengerList
{
	passengernode *head;
	passengernode *rear;
}passengerList;
void init_flight(flightnode *&h)
{
	h = (flightnode *)malloc(sizeof(flightnode));//建立一个以h为头结点的空链表，录入航班信息和增加航班后将航班结点插入该链表
	if (h == NULL) exit(0);
	h->next = NULL;
}
void init_passengerList(passengerList *&pList)//建立一个带有头结点和尾结点的空链表，存储带有顾客信息的结点
{
	pList = (passengerList *)malloc(sizeof(passengerList));
	pList->head = (passengernode *)malloc(sizeof(passengernode));
	pList->rear = pList->head;
	pList->rear->order_num = 0;
	pList->head->next = NULL;
}
void save_passenger(passengerList *PList)
{
	FILE* fp = fopen("passenger.dat", "wb");
	if (fp == NULL)
		return;
	passengernode *temp = PList->head->next;
	while (temp != NULL)
	{
		fwrite(temp, sizeof(passengernode), 1, fp);
		temp = temp->next;
	};
	fclose(fp);
}
void load_passenger(passengerList *PList)
{
	FILE* fp = fopen("passenger.dat", "rb");
	if (fp == NULL)
		return;
	passengernode *q;
	int n;
	while (!feof(fp))
	{
		q = (passengernode *)malloc(sizeof(passengernode));
		n = fread(q, sizeof(passengernode), 1, fp);
		if (n != 1)
			break;
		PList->rear->next = q;
		PList->rear = q;
	}
	PList->rear->next = NULL;
	fclose(fp);
}
void save_flight(flightnode *h)
{
	FILE* fp = fopen("flightList.dat", "wb");
	if (fp == NULL)
		return;
	flightnode *temp = h->next;
	while (temp != NULL)
	{
		fwrite(temp, sizeof(flightnode), 1, fp);
		temp = temp->next;
	};
	fclose(fp);
}
void load_flight(flightnode *&h)
{
	flightnode *pt = h;
	FILE* fp = fopen("flightList.dat", "rb");
	if (fp == NULL)
		return;
	flightnode *q;
	int n;
	while (!feof(fp))
	{
		q = (flightnode *)malloc(sizeof(flightnode));
		n = fread(q, sizeof(flightnode), 1, fp);
		if (n != 1)
			break;
		pt->next = q;
		pt = q;
	}
	pt->next = NULL;
	fclose(fp);
}
int find_same_flight(flightnode *h, char *flight_num)
{
	flightnode *t = h->next, *p = h->next;
	int mark = 0;
	cout << setw(10) << "航班号" << setw(10) << "起飞日期" << setw(10) << "到达日期" << setw(10) << "出发地" << setw(10) << "目的地" << setw(10) << "价格" << setw(10) << "折扣" << setw(10) << "是否满仓" << setw(10) << "余票" << endl;
	while (t != NULL && strcmp(t->flight_num, flight_num) != 0) t = t->next;
	while (p != NULL) {
		if ((strcmp(t->start_place, p->start_place) == 0) && (strcmp(t->end_place, p->end_place) == 0) && (strcmp(t->flight_num, p->flight_num) != 0))
		{
			cout << setw(10) << p->flight_num << setw(10) << p->time << setw(10) << p->Etime << setw(10) << p->start_place << setw(10) << p->end_place << setw(10) << p->price << setw(10) << p->discount << setw(10) << p->isFull << setw(10) << p->left << endl;
			mark = 1;
		}
		p = p->next;
	}
	if (mark == 0)
	{
		cout << " 抱歉，没有可选的航班!" << endl;
		return 0;
	}
	return 1;
}
void insert_flight(flightnode *&h, char* flight_num, char* start_place, char* end_place, char* time, char*
	Etime, int left, float price, float discount, int isFull)

{
	flightnode *q;
	flightnode *p = h;
	q = (flightnode *)malloc(sizeof(flightnode));
	strcpy(q->flight_num, flight_num);
	strcpy(q->start_place, start_place);
	strcpy(q->end_place, end_place);
	strcpy(q->time, time);
	strcpy(q->Etime, Etime);
	q->left = left;
	q->price = price;
	q->discount = discount;
	q->isFull = isFull;
	q->next = p->next;
	p->next = q;
	p = p->next;
}
void insert_passengerList(flightnode *&h, passengerList *&PList, char *name, char *ID_num, char *flight_num, int ticket_num)
{
	flightnode *p = h->next;
	for (; p != NULL; p = p->next)
		if (strcmp(p->flight_num, flight_num) == 0)
		{
			p->left = p->left - ticket_num;
			if (p->left == 0)
				p->isFull = 1;
		}
	passengernode *q = (passengernode *)malloc(sizeof(passengernode));//新建结点，存放新的客户订单信息 
	strcpy(q->name, name);
	strcpy(q->ID_num, ID_num);
	strcpy(q->flight_num, flight_num);
	q->ticket_num = ticket_num;
	q->next = NULL;
	PList->rear->next = q;
	q->order_num = PList->rear->order_num + 1;
	PList->rear = q;
}

void delete_flight(flightnode *&h, passengerList *&PList)
{
	flightnode *p, *pr;
	passengernode *q, *qr;
	char flight_num[10];
	int mark = 1;
	qr = PList->head;
	q = qr->next;
	pr = h;
	p = pr->next;
	cout << " 请输入你要删除的航班号:";
	cin >> flight_num;
	while (p != NULL)
	{
		if (strcmp(flight_num, p->flight_num) == 0)
		{
			pr->next = p->next;
			free(p);
			cout << " 删除,航班成功!" << flight_num << endl;
			mark = 0;
			p = NULL;
		}
		if (pr->next != NULL)
		{
			pr = pr->next;
			p = pr->next;
		}
	}
	if (mark == 1)
		cout << " 无此航班,无法删除!" << endl;
	else
	{
		while (q != NULL)
		{
			if (strcmp(flight_num, q->flight_num) == 0)
			{
				qr->next = q->next;
				free(q);
				q = NULL;
			}
			if (qr->next != NULL)
			{
				qr = qr->next;
				q = qr->next;
			}
		}
	}
}
int delete_passenger(passengerList *&PList, flightnode *&h, char *name, char *ID_num)

{
	passengernode *p, *pr = PList->head;
	p = pr->next;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0 && strcmp(ID_num, p->ID_num) == 0)
		{
			for (flightnode *f = h->next; f != NULL; f = f->next)
				if (strcmp(p->flight_num, f->flight_num) == 0)
				{
					f->left = f->left + p->ticket_num;
					f->isFull = 0;
					break;
				}
			pr->next = p->next;
			free(p);
			cout << " 顾客" << name << " 退票成功!" << ID_num << endl;
			return 1;
		}
		pr = pr->next;
		p = pr->next;
	}
	cout << " 无此顾客,无法退票!" << endl;
	return 0;
}
void add_flight(flightnode *&h)
{
	flightnode *p = h;
	char flight_num[10], time[10], Etime[10], start_place[20], end_place[20];
	int left, isFull, mark = 1;
	float price, discount;
	for (; p->next != NULL; p = p->next) {}
	while (mark == 1)
	{
		cout << "                  请输入航班号：";
		cin >> p->flight_num;
		cout << "                  请输入起飞时间：";
		cin >> p->time;
		cout << "                  请输入到达时间：";
		cin >> p->Etime;
		cout << "                  请输入出发地:";
		cin >> p->start_place;
		cout << "                  请输入目的地：";
		cin >> p->end_place;
		cout << "                  请输入价格：";
		cin >> p->price;
		cout << "                  请输入折扣：";
		cin >> p->discount;
		cout << "                  请输入余票：";
		cin >> p->left;
		cout << "                 请输入是否满仓(0 表示没有满仓 1 已经满仓）：";
		cin >> p->isFull;
		insert_flight(p, flight_num, start_place, end_place, time, Etime, left, price, discount, isFull);
		cout << " 增加航班, 成功!" << endl;
		cout << "                  添加成功！" << endl;
		cout << "                  是否继续添加？(1 表示继续录入;0 表示停止录入)：";
		cin >> mark;
	}
}
int flight_num_check(flightnode *h, char *flight_num)
{
	flightnode *p = h;
	cout << setw(10) << "航班号" << setw(10) << "起飞日期" << setw(10) << "到达日期" << setw(10) << "出发地" << setw(10) << "目的地" << setw(10) << "价格" << setw(10) << "折扣" << setw(10) << "是否满仓" << setw(10) << "余票" << endl;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->flight_num, flight_num) == 0)
		{
			cout << setw(10) << p->flight_num << setw(10) << p->time << setw(10) << p->Etime << setw(10) << p->start_place << setw(10) << p->end_place << setw(10) << p->price << setw(10) << p->discount << setw(10) << p->isFull << setw(10) << p->left << endl;
			return 1;
		}
	}
	cout << " 抱歉,没有航班号为"<< flight_num <<" 的航班信息!"  << endl;
	return 0;
}
int place_check(flightnode *h, char *start_place, char *end_place)
{
	flightnode *p = h;
	int mark = 0;
	cout << setw(10) << "航班号" << setw(10) << "起飞日期" << setw(10) << "到达日期" << setw(10) << "出发地" << setw(10) << "目的地" << setw(10) << "价格" << setw(10) << "折扣" << setw(10) << "是否满仓" << setw(10) << "余票" << endl;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->start_place, start_place) == 0 && strcmp(p->end_place, end_place) == 0)
		{
			cout << setw(10) << p->flight_num << setw(10) << p->time << setw(10) << p->Etime << setw(10) << p->start_place << setw(10) << p->end_place << setw(10) << p->price << setw(10) << p->discount << setw(10) << p->isFull << setw(10) << p->left << endl;
			mark = 1;
		}
	}
	if (mark == 0)
	{
		cout << " 抱歉,没有从" << start_place << " 到" << end_place << "的航班信息!" << endl;
		return 0;
	}
	return 1;
}
void check_all_flight(flightnode *h)
{
	flightnode *p = h;
	int m = 0;
	cout << setw(10) << "航班号" << setw(10) << "起飞日期" << setw(10) << "到达日期" << setw(10) << "出发地" << setw(10) << "目的地" << setw(10) << "价格" << setw(10) << "折扣" << setw(10) << "是否满仓" << setw(10) << "余票" << endl;
	for (; p != NULL; p = p->next)
	{
		cout << setw(10) << p->flight_num << setw(10) << p->time << setw(10) << p->Etime << setw(10) << p->start_place << setw(10) << p->end_place << setw(10) << p->price << setw(10) << p->discount << setw(10) << p->isFull << setw(10) << p->left << endl;
		m = 1;
	}
	if (m == 0)
		cout << " 航班信息为空!" << endl;
}
void flight_check(flightnode *h)
{
	flightnode *p = h->next;
	char flight_num[10], start_place[20], end_place[20];
	char a;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                            ┇    ≡ 查找方式 ≡    ┇ " << endl;
	cout << "                 ┇                                        ┇ " << endl;
	cout << "                            ┇     1.航班查找       ┇ " << endl;
	cout << "                 ┇                                        ┇ " << endl;
	cout << "                            ┇    2.起始地查找      ┇ " << endl;
	cout << "                 ┇                                        ┇ " << endl;
	cout << "                            ┇   3.浏览全部航班     ┇ " << endl;
	cout << "                 ┇                                        ┇ " << endl;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                  请输入查找方式：";
	a = getchar();
	cout << a << endl;
	if (a == '1')
	{
		cout << " 请输入航班号:";
		cin >> flight_num;
		flight_num_check(p, flight_num);
	}
	else if (a == '2')
	{
		cout << "请输入起飞城市:";
		cin >> start_place;
		cout << " 请输入抵达城市:";
		cin >> end_place;
		place_check(p, start_place, end_place);
	}
	else if (a == '3')
		check_all_flight(p);
	else
		return;
}

int ID_name_check(passengerList *PList, char *name, char *ID_num)
{
	passengernode *p = PList->head->next;
	int mark = 0;
	cout << setw(10) << "订单号" << setw(10) << "姓名" << setw(10) << "证件号" << setw(10) << "航班号" << setw(10) << "订单数量" << endl;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->ID_num, ID_num) == 0 && strcmp(p->name, name) == 0)
		{
			cout << setw(10) << p->order_num << setw(10) << p->name << setw(10) << p->ID_num << setw(10) << p->flight_num << setw(10) << p->ticket_num << endl;
			mark = 1;
		}
	}
	if (mark == 0)
	{
		cout << "抱歉,没有" << name << ID_num << " 的订单信息!" << endl;
		return 0;
	}
	return 1;
}
int order_num_check(passengerList *PList, int order_num)
{
	passengernode *p = PList->head->next;
	cout << setw(10) << "订单号" << setw(10) << "姓名" << setw(10) << "证件号" << setw(10) << "航班号" << setw(10) << "订单数量" << endl;
	for (; p != NULL; p = p->next)
	{
		if (p->order_num == order_num)
		{
			cout << setw(10) << p->order_num << setw(10) << p->name << setw(10) << p->ID_num << setw(10) << p->flight_num << setw(10) << p->ticket_num << endl;
			return 1;
		}
	}
	cout << " 抱歉,没有订单号为" << order_num << "的订单信息!" << endl;
	return 0;
}
void check_all_passenger(passengerList *PList)
{
	passengernode *p = PList->head->next;
	int m = 0;
	cout << setw(10) << "订单号" << setw(10) << "姓名" << setw(10) << "证件号" << setw(10) << "航班号" << setw(10) << "订单数量" << endl;
	for (; p != NULL; p = p->next)
	{
		cout << setw(10) << p->order_num << setw(10) << p->name << setw(10) << p->ID_num << setw(10) << p->flight_num << setw(10) << p->ticket_num << endl;
		m = 1;
	}
	if (m == 0)
		cout << " 订单信息为空!" << endl;
}
void passenger_check(passengerList *PList)
{
	char name[20], ID_num[15];
	int order_num;
	char a;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                 ┇           ≡ 请选择订单查询方式: ≡     ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇        1. 表示按客户姓名和证件号进行查询    ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇            2.表示按订单号进行查询           ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇             3. 表示查看全部订单信息         ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                  请输入查找方式：" << endl;
	a = getchar();
	cout << a;
	if (a == '1')
	{
		cout << " 请输入客户姓名:";
		cin >> name;
		cout << " 请输入证件号:";
		cin >> ID_num;
		ID_name_check(PList, name, ID_num);
	}
	else if (a == '2')
	{
		cout << "请输入订单号:";
		cin >> order_num;
		order_num_check(PList, order_num);
	}
	else if (a == '3')
		check_all_passenger(PList);
	else
		return;
}

void modify_flight(flightnode *&h, passengerList *&PList)
{
	flightnode *p = h->next;
	char flight_num[10], time[10], Etime[10];
	char a;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                 ┇               ≡ 航线信息修改: ≡           ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇               增加航班-------1              ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇               删除航班-------2              ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                 ┇               修改航班时间---3              ┇ " << endl;
	cout << "                 ┇                                             ┇ " << endl;
	cout << "                  ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ " << endl;
	cout << "                 请选择：";
	a = getchar();
	cin >> a;
	if (a == '1')
		add_flight(h);
	else if (a == '2')
		delete_flight(h, PList);
	else if (a == '3')
	{
		cout << "请输入要修改的航班的航班号:";
		cin >> flight_num;
		if (flight_num_check(p, flight_num) == 1)
		{
			cout << "请输入修改后的起飞时间:";
			cin >> time;
			cout << "请输入修改后的抵达时间:";
			cin >> Etime;
			for (; p != NULL; p = p->next)
				if (strcmp(flight_num, p->flight_num) == 0)
				{
					strcpy(p->time, time);
					strcpy(p->Etime, Etime);
					cout << "航班" << flight_num << "时间修改成功!" << endl;
				}
		}
	}
	else
		return;
}

int book(flightnode *&h, passengerList *&PList)
{
	char name[20];
	char ID_num[20];
	char flight_num[10];
	char start_place[20];
	char end_place[20];
	int ticket_num;
	int k;
	flightnode *p = h->next;
	cout << "请输入信息:" << endl;
	cout << " 请输入起飞城市:";
	cin >> start_place;
	cout << " 请输入抵达城市:" << endl;
	cin >> end_place;
	if (place_check(h, start_place, end_place) == 1)
	{
		cout << " 航班号:";
		cin >> flight_num;
		while (flight_num == NULL) {
			cout << "航班号不能为空!" << endl;
			cout << " 航班号:";
			cin >> flight_num;
		}
		while (p != NULL) {
			if (strcmp(p->flight_num, flight_num) == 0)
			{
				cout << "姓名:";
				cin >> name;
				cout << "证件号码:";
				cin >> ID_num;
				cout << "订票数量:";
				cin >> ticket_num;
				while (name == NULL) {
					cout << "客户姓名不能为空!" << endl;
					cout << "姓名:";
					cin >> name;
				}
				while (ID_num == NULL) {
					cout << "客户证件号码不能为空!" << endl;
					cout << "证件号码:";
					cin >> ID_num;
				}
				while (ticket_num == 0) {
					cout << "客户订票数量不能为空!" << endl;
					cout << "订票数量:";
					cin >> ticket_num;
				}
				if (p->left > 0 && p->left >= ticket_num)
				{
					insert_passengerList(h, PList, name, ID_num, flight_num, ticket_num);
					cout << " 你应付金额￥" << p->price*p->discount* ticket_num << endl;
					getchar();
					cout << "恭喜您,订票成功!" << endl;
					return 1;
				}
				else
				{
					cout << "***很遗憾，该航班已满!***" << endl;
					cout << "***如选择其他航班请输入-----1" << endl;
					cout << "***不选则输入-----0***" << endl;
					cout << " 输入数字进行选择:";
					cin >> k;
					if (k == 1)
					{
						cout << "此航线上的其他航班有:" << endl;
						if (find_same_flight(h, flight_num) == 1)
						{
							cout << " 请输入您选的航班:";
							cin >> flight_num;
							insert_passengerList(h, PList, name, ID_num, flight_num, ticket_num);
							cout << "恭喜您,订票成功!" << endl;
							return 1;
						}
					}
				}
			}
			else
				p = p->next;
		}
		if (p == NULL)
			cout << "对不起,您输入的航班不存在!" << endl;
	}
	return 0;
}void cancel(passengerList *&PList, flightnode *&h)
{
	char name[20], ID_num[20];
	cout << "请输入你的姓名:";
	cin >> name;
	cout << "请输入你的证件号:";
	cin >> ID_num;
	delete_passenger(PList, h, name, ID_num);
}


int main()
{
	char choice;
	int t = 1;
	flightnode *flight;
	passengerList *PList;
	init_flight(flight);
	init_passengerList(PList);
	load_flight(flight);
	load_passenger(PList);
	while (t == 1)
	{
		cout << "-----------------------------------------------------------------------" << endl;;
		cout << "*****************************飞机订票系统菜单**************************" << endl;;
		cout << "***********************************************************************" << endl;;
		cout << "***********                 录入信息----------1                       *" << endl;;
		cout << "***********                 订    票----------2                       *" << endl;;
		cout << "***********                 退    票----------3                       *" << endl;;
		cout << "***********                 查询航班----------4                       *" << endl;;
		cout << "***********                 查询订单----------5                       *" << endl;;
		cout << "***********                 修改航线----------6                       *" << endl;;
		cout << "***********                 退    出----------0                       *" << endl;;
		cout << "**************************************************************************" << endl;;
		cout << " 请选择服务:";
		choice = getchar();
		cout << choice << endl;
		
		if (choice == '1') {
			add_flight(flight);
			getchar();
			
		}
		else if (choice == '2')
		{
			book(flight, PList);
			getchar();
			
		}
		else if (choice == '3')
		{
			cancel(PList, flight);
			getchar();
			
		}
		else if (choice == '4')
		{
			flight_check(flight);
			getchar();
			
		}
		else if (choice == '5')
		{
			passenger_check(PList);
			getchar();
			
		}
		else if (choice == '6')
		{
			modify_flight(flight, PList);
			getchar();
			
		}
		else if (choice == '0')
		{
			cout << "再见!" << endl;
			t = 0;
		}
	}
	save_flight(flight);
	save_passenger(PList);
	return 0;
}

