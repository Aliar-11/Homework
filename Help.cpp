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
	cout<<"请输入命令："<<endl;
	cout<<"添加物品请输入1"<<endl;
	cout<<"删除物品请输入2"<<endl;
	cout<<"显示当前物品列表请输入3"<<endl;
	cout<<"查找所需物品请输入4"<<endl;
	cout<<"操作完毕请输入0"<<endl;
	int x;
	cin>>x;
	return x;
}

//初始化物品列表 
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

//显示物品列表
void show(){
	if (head->next==NULL){
		cout<<"当前没有物品"<<endl;
		return; 
	}
	item *p;
	for (p=head->next;p!=NULL;p=p->next){
		cout<< setw(21) << left << p->name << setw(21) << left << p->owner << setw(21) << left << p->tel << endl; 
	}
} 

//查找物品
void search(){
	item *p,*pre;
	char name[20],owner[20],tel[20];
	cout<<"请输入您要查找的物品名称"<<endl;
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
	if (!flag) cout<<"不存在您要查找的物品"<<endl; 
} 

//添加物品 
void add(){
	item *p;
	int x;
	cout<<"请输入您要添加的物品数量"<<endl;
	cin>>x; 
	if (x==0){
		cout<<"不允许添加0件物品，请检查输入是否错误" <<endl; 
		return;
	} 
	cout<<"请输入您要添加的物品名称、提供者、电话号码"<<endl;
	for (int i=1;i<=x;i++){	
		p=new item;
		cin>> p->name >> p->owner >> p->tel;
		end->next=p;
		end=p;
	}
	end->next=NULL;
}

//删除物品
void del(){
	item *p,*pre;
	char name[20],owner[20],tel[20];
	cout<<"请输入您要删除的物品名称、提供者、电话号码"<<endl;
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
	if (!flag) cout<<"您要删除的物品不存在，请检查是否输入错误";
} 

int main(){
	freopen("物品清单.txt","r",stdin);
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
				cout<<"输入不符合规范，请重新输入"<<endl; 
				cin.sync();
				num++;
		}	
		if (num==3) break;
	}
	
	freopen("物品清单.txt","w",stdout);
	show();
	fclose(stdout);
	
	return 0;
} 


