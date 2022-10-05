#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef struct node{
	char name[22];
	char owner[22];
	char tel[22];
	struct node *next;
}item; 

item *head,*end;

int request(){
	cout<<"���������"<<endl;
	cout<<"�����Ʒ������1"<<endl;
	cout<<"ɾ����Ʒ������2"<<endl;
	cout<<"��ʾ��ǰ��Ʒ�б�������3"<<endl;
	cout<<"����������Ʒ������4"<<endl;
	cout<<"�������������0"<<endl;
	int x;
	cin>>x;
	return x;
}

//��ʼ����Ʒ�б� 
void init(){
	head=new item;
	end=head;
	end->next=NULL;
	char name[22],owner[22],tel[22];
	item *p;
	p=new item;
	while (cin>> p->name){
		cin>> p->owner >> p->tel;
		end->next=p;
		end=p;
		p=new item;
	}
	end->next=NULL; 
}

//��ʾ��Ʒ�б�
void show(){
	if (head->next==NULL){
		cout<<"��ǰû����Ʒ"<<endl;
		return; 
	}
	item *p;
	for (p=head->next;p!=NULL;p=p->next){
		cout<< setw(21) << left << p->name << setw(21) << left << p->owner << setw(21) << left << p->tel << endl; 
	}
} 

//������Ʒ
void search(){
	item *p,*pre;
	char name[20],owner[20],tel[20];
	cout<<"��������Ҫ���ҵ���Ʒ����"<<endl;
	cin>>name; 
	pre=head;
	bool flag=false;
	for (p=head->next;p!=NULL;p=p->next){
		if (strstr(p->name,name)){
			cout<< setw(21) << left << p->name << setw(21) << left << p->owner << setw(21) << left << p->tel << endl; 
			flag=true;
		}
		pre=p; 
	}
	if (!flag) cout<<"��������Ҫ���ҵ���Ʒ"<<endl; 
} 

//�����Ʒ 
void add(){
	item *p;
	int x;
	cout<<"��������Ҫ��ӵ���Ʒ����"<<endl;
	cin>>x; 
	if (x==0){
		cout<<"���������0����Ʒ�����������Ƿ����" <<endl; 
		return;
	} 
	cout<<"��������Ҫ��ӵ���Ʒ���ơ��ṩ�ߡ��绰����"<<endl;
	for (int i=1;i<=x;i++){	
		p=new item;
		cin>> p->name >> p->owner >> p->tel;
		end->next=p;
		end=p;
	}
	end->next=NULL;
}

//ɾ����Ʒ
void del(){
	item *p,*pre;
	char name[20],owner[20],tel[20];
	cout<<"��������Ҫɾ������Ʒ���ơ��ṩ�ߡ��绰����"<<endl;
	cin>>name>>owner>>tel; 
	pre=head;
	bool flag=false;
	for (p=head->next;p!=NULL;p=p->next){
		if (strcmp(p->name,name)==0 && strcmp(p->owner,owner)==0 && strcmp(p->tel,tel)==0){
			pre->next=p->next;
			delete p;
			flag=true;
		}
		pre=p; 
	}
	if (!flag) cout<<"��Ҫɾ������Ʒ�����ڣ������Ƿ��������";
} 

int main(){
	freopen("��Ʒ�嵥.txt","r",stdin);
	init();
	fclose(stdin);
	freopen("CON","r",stdin);cin.clear();
	bool flag=true;
	int num=0;
	while (flag){
		cout<< "*********************************************************" <<endl;
		switch (request()){
			case 1:
				add();
				continue;
			case 2:
				del();
				continue;
			case 3:
				show();
				continue;
			case 4:
				search();
				continue;
			case 0:
				flag=false;
				continue;
			default:
				cout<<"���벻���Ϲ淶������������"<<endl; 
				cin.sync();
				num++;
		}	
		if (num==3) break;
	}
	
	freopen("��Ʒ�嵥.txt","w",stdout);
	show();
	fclose(stdout);
	
	return 0;
} 


