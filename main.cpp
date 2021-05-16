//----------------------------------------------------------------------------------------------
//----------------------------------------头文件区----------------------------------------------
//----------------------------------------------------------------------------------------------

#include <time.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>//包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>
using namespace std;

//----------------------------------------------------------------------------------------------
//----------------------------------------结构体区----------------------------------------------
//----------------------------------------------------------------------------------------------

typedef struct user
{
    char user_wechat[40]; //用户微信
    char user_bir[30]; //用户生日
    char user_email[30];//用户电子邮箱
    char user_name[20]; //用户名
    char user_sex[10]; //用户性别
    char user_phone[100];  //用户手机
    char user_esp[30];  //用户个性签名
    double user_ppprice=0; //用户出价
    char account[20]; //用户账号
    char password[20]; //用户密码
    int id;
    struct user *next;
}user,*list,user_[100];

typedef struct User_Goods
{
    int G_ppprice=0;
    char G_auc_measure[20]; //拍卖方式
    char G_condition[100]; //物品情况
    char account_data[20]; //对应账号
    char G_name[100]; //商品名
    int G_id=0;        //商品编号
    char new_or_old[10];  //商品新旧情况
    double G_price;   //商品起拍价
    double G_pprice=0; //商品当前最高出价
    char G_dec[80]; //商品描述
    char G_class[80]; //商品种类
    int G_time=0; //拍卖时间
    time_t G_t=0; //设置拍卖起始时间
    struct User_Goods *next;
}*Goods,User_Goods;

typedef struct User_info //用户个人信息
{
    char accountdata[20]; //对应账号
    char user_name[20]; //用户名
    char user_sex[10]; //用户性别
    char user_phone[10];  //用户手机
    char user_esp[30];  //用户个性签名
    double user_ppprice=0; //用户出价
    struct User_info *next;
}*Goodsk,User_info;

//----------------------------------------------------------------------------------------------
//----------------------------------------函数区----------------------------------------------
//----------------------------------------------------------------------------------------------

void statistics1(); //统计信息
int binary(User_Goods thing[],int n,int target);//二分查找
void quicksort(User_Goods thing[], int low, int high);//快速排序
void userself_amend(); //用户修改个人信息
void user_self_menu(); //个人中心界面
void password_amend(); //修改密码
void user_amend(); //修改用户信息
void user_oversee(); // 查看当前所有注册用户
void user_display1(); //用户显示个人信息
void usersave();//把用户得到的物品存到文件中
void goodsdel1(Goods head1,int n); //用户删除指定编号物品
void goodsdelete1();//用户删除物品
void password_(char arr[]); //隐藏密码函数
void load_goods();//将物品信息存入结构体数组
void user_pricesearch();//管理员输入起拍价区间查询物品
void user_pricesearch1();//用户输入起拍价区间查询物品
void statistics();//统计信息
void goodsdelete();//删除物品
//void goods_selfdel(int n);
void user_bags();//查看用户拍到的物品
void user_display();//显示个人信息
void system_loginchoice(list head);//选择登陆身份
//void user_tips1();
void user_namesearch1();//用户输入物品名称查询物品
void user_idsearch1();//用户输入编号查询对应物品
void user_selfsearch1();//用户查看当前拍卖物品
void user_classsearch1();//用户输入物品种类查询物品
void user_overseechoice1();//用户查询方式选择
void user_auction();//用户出价竞拍
void user_auc();//用户功能选择
void login_choicemenu();//登录方式界面
void user_goodsamend();//修改物品信息
void user_classsearch();//管理员输入物品种类查询物品
void user_namesearch();//管理员输入物品名称查询物品
void user_idsearch();//管理员输入编号查询对应物品
void user_selfsearch();//管理员查看当前拍卖物品
void user_goodscharge();//管理员物品管理
void addgoods();//增添拍卖物品
void user_choicemenu();//管理员功能选择
void auc_menu();//竞拍功能界面
void userself_menu();//管理员物品管理界面
void user_tips();//用户使用手册
void user_menu();//管理员主界面
void login_menu();//用户登录界面
int account_create(list head);//新建账户密码
void system_login();//登录功能函数
int system_Lojin1(list head);//管理员登录
int system_Lojin2(list head);//用户登录
list account_load();//读取存储用户账号密码文件
Goods data_load(); //读取物品数据文件
void oversee_menu();//查询功能界面
void user_overseechoice();//管理员查询方式选择
void goodsdel(Goods headl,int n);//删除指定编号物品

Goods head1=data_load();
list head=account_load();

User_info Use[500];
User_Goods thing[500];
char a[20]; //保存当前登录账号
char b[20];
char a1[20];
char o1[]="明拍";
char o2[]="暗拍";
char o3[]="对拍";
char c2[]="结束拍卖";
char o4[]="new";
char o5[]="old";
char highest[20];
int number=1;
int hug;//物品总数
int umu[1000]={0};//将物品编号作为下标，将值置为1，若为0，表示不存在该编号物品

void login_menu() //用户登录界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t\t 欢迎使用物品竞拍管理系统\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t  1.登录\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t  2.注册\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t  3.用户使用手册\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t  4.退出\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
    return ;
}

void login_choicemenu() //登录方式界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t1.管理员登录\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t2.用户登录\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t3.返回\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
}

void user_tips() //用户使用手册
{
    system("cls");
    cout << "\t\t\t\t**********************************************************\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t1.每个拍卖物品都有一定的拍卖时间，在拍卖时间可出价\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t2.用户可查看和删除自己的拍卖所得\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t3.管理员可添加,修改,删除,查询拍卖物品\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t4.拍卖方式分为明拍和暗拍，明拍可见最高出价，暗拍不可见，价高者得\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t5.祝使用愉快！\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t**********************************************************\n";
    cout << "\t\t\t\t\t\t\t\n按任意键返回......\n";
    char hit=getch();
    system("cls");
    system_login();
}

void user_menu() //管理员主界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t1.物品管理\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t2.查看个人信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t3.查看注册用户情况\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t4.修改用户信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t5.退出登录\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
    return ;
}

void user_self_menu() //个人中心界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t1.个人信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t2.修改个人信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t3.修改密码\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t4.返回\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
    return ;
}

void userself_menu() //管理员物品管理界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    1.增加拍卖物品\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    2.删除拍卖物品\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    3.修改拍卖物品信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    4.查看拍卖物品\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    5.查看物品统计\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t    6.返回主页\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
    return ;
}

void auc_menu() //竞拍功能界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t1.竞拍\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t2.统计\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t3.查询物品信息\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t4.查看个人竞拍所得物品\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t5.删除个人竞拍所得物品\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t6.个人中心\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t7.退出登录\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
    return ;
}

void system_loginchoice(list head) //选择登陆身份
{
    system("cls");
    char p;
    login_choicemenu(); //登录界面
    cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:";
    cin >> p;
    if(p>'3'||p<='0')
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        system_login();
    }
    switch(p)//功能函数
    {
	  case'1':
	    system_Lojin1(head); //管理员登录
	    break;
	  case'2':
	  	system_Lojin2(head); //用户登录
	  	break;
      case'3':
        system_login();//返回
	  	break;
    }
}

void system_login()//登录功能函数
{
    list head;
    head=account_load();
	char choose,p;
	login_menu();
	cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:";
	scanf(" %c",&choose);
	if(choose>'4'||choose<='0')
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        system_login();
    }
	switch(choose)//功能函数
    {
	  case'1':
        system_loginchoice(head); //登录
	    break;
	  case'2':
	  	account_create(head); //创建账号
	  	break;
      case'3':
        user_tips(); //用户手则
	  	break;
	  case'4'://退出
	  	system("cls");
	  	cout << "\n";
	  	cout << "\n";
	  	cout << "\n";
	  	cout << "\t\t\t\t\t\t感谢您的使用！\n";
	  	cout << "\n";
	  	cout << "\n";
	  	cout << "\n";
  	exit(0);
	break;
  }
}

list account_load()//读取存储用户账号密码文件
{
    FILE *fp;
    list p1=NULL,key_head=NULL,p2=NULL;
    int i;
    if((fp=fopen("account.txt","r"))==NULL) //打开账号文件
    {
        printf("\n 打开文件失败\n");
        return 0;
    }
    for(i=1; !feof(fp); i++) //将文件中账号密码存到链表
    {
        p1=(list)malloc(sizeof(user));
        fscanf(fp,"%s %s %s %s %s %s %s %s %s",p1->account,p1->password,p1->user_name,p1->user_sex,p1->user_phone,p1->user_esp,p1->user_wechat,p1->user_bir,p1->user_email);
        p1->next=NULL;
        if(i==1)
            key_head=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    return(key_head);
}

int account_create(list head)//新建账户密码
{
	FILE *fp;
	char hit=0;
	char a1[20],p1[20],p2[20];
	list q1=NULL,q2=NULL,q3=NULL;
	q1=(list)malloc(sizeof(user));
	q2=head;
	if ((fp=fopen("account.txt","r"))==NULL) //打开文件
	{
      fp=fopen("account.txt","w");
      fclose(fp);
    }
	fp=fopen("account.txt","a");
	system("cls");
	cout << "\t\t\t\t******************************************************\n";
	cout << "\t\t\t\t\t账号和密码不能超过20个字符哦！\n";
	for(;;){
	   printf("\t\t\t\t\t请输入账号:\t");
	   scanf("%s",a1);
	   cout << "\n";
	   printf("\t\t\t\t\t请输入密码:\t");
	   scanf("%s",p1);
	   cout << "\n";
       printf("\t\t\t\t\t再次输入密码:\t");
       scanf("%s",p2);
        while(q2)
        {
            if(strcmp(a1,q2->account)==0) //判断账号是否被注册
            {
                cout << "\t\t\t\t\t该账号已被注册！\n";
                cout << "\t\t\t\t\t按回车继续创建，按ESC返回登录界面！\n";
                hit=getch();
                if(hit==27)
                    {
                        system("cls");
                        system_login();
                    }
                else if(hit==13)
                {
                    system("cls");
                    account_create(head);
                }
            }
            q2=q2->next;
        }
            if(strcmp(p1,p2)==0) //判断两次输入密码是否一致
            {
                    q3=(list)malloc(sizeof(user));
                    q2=q3;
                    cout << "\n";
                    cout << "\t\t\t\t\t创建成功!";
                    cout << "\n";
                    cout << "\t\t\t\t\t请完善个人信息!";//填写个人信息
                    cout << "\n";
                    strcpy(q3->account,a1);
                    strcpy(q3->password,p1);
                    cout << "\t\t\t\t\t请输入用户名(不能超过十个汉字):\t";
                    scanf("%s",q3->user_name);
                    cout << "\t\t\t\t\t请输入您的性别:\t";
                    scanf("%s",q3->user_sex);
                    cout << "\t\t\t\t\t请输入手机号:\t";
                    scanf("%s",q3->user_phone);
                    cout << "\t\t\t\t\t请输入个性签名(不能超过十五个汉字):\t";
                    scanf("%s",q3->user_esp);
                    cout << "\t\t\t\t\t请输入微信号:\t";
                    scanf("%s",q3->user_wechat);
                    cout << "\t\t\t\t\t请输入您的生日:\t";
                    scanf("%s",q3->user_bir);
                    cout << "\t\t\t\t\t请输入电子邮箱:\t";
                    scanf("%s",q3->user_email);
                    fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",q3->account,q3->password,q3->user_name,q3->user_sex,q3->user_phone,q3->user_esp,q3->user_wechat,q3->user_bir,q3->user_email);
                    break;
            }
            else
            {
                printf("\t\t\t\t\t两次输入密码不一致，继续创建按回车，退出按ESC");
                hit=getch();
                if(hit==27)
                {
                    system("cls");
                    system_login();
                }
                else if(hit==13)
                {
                    system("cls");
                    account_create(head);
                }
            }
        }
    fclose(fp);
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    printf("\t\t\t\t\t创建成功，按任意键返回");
    getch();
    system("cls");
    system_login();//返回
    return 1;
}

void user_display() //管理员显示个人信息
{
    system("cls");
    char z1[100],z2[100],z3[100],z4[100],z5[100],z6[100],z7[100],z8[100],z9[100];
    FILE *fp;
    fp=fopen("account.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %s\n",z1,z2,z3,z4,z5,z6,z7,z8,z9);//读取文件
        if(strcmp(z1,a)==0)//判断登录用户与物品主人是否一致
        {
            cout << "\t\t\t\t******************************************************\n";
            cout << "\n";
            cout << "\t\t\t\t\t用户名:\t\t";
            printf("%s\n",z3);
            cout << "\t\t\t\t\t用户性别:\t";
            printf("%s\n",z4);
            cout << "\t\t\t\t\t用户手机:\t";
            printf("%s\n",z5);
            cout << "\t\t\t\t\t用户个性签名:\t";
            printf("%s\n",z6);
            cout << "\t\t\t\t\t用户微信号:\t";
            printf("%s\n",z7);
            cout << "\t\t\t\t\t用户生日:\t";
            printf("%s\n",z8);
            cout << "\t\t\t\t\t用户电子邮箱:\t";
            printf("%s\n",z9);
        }
    }
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    cout << "\t\t\t\t\t按任意键返回!";
    getch();
    system("cls");
    user_choicemenu();
}

void user_display1() //用户个人中心
{
    system("cls");
    user_self_menu();//个人中心界面
    char z1[100],z2[100],z3[100],z4[100],z5[100],z6[100],z7[100],z8[100],z9[100];
    char p;
    FILE *fp;
    cout << "\t\t\t\t\t\t请输入您的选择:";
	scanf(" %c",&p);
	if(p>'4'||p<='0')
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_display1();
    }
	switch(p)//功能函数
    {
	  case'1':
	    system("cls");
        fp=fopen("account.txt","r");
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %s %s %s %s %s %s\n",z1,z2,z3,z4,z5,z6,z7,z8,z9);//读取文件
            if(strcmp(z1,a)==0)//判断登录用户与物品主人是否一致
            {
                cout << "\t\t\t\t******************************************************\n";
                cout << "\n";
                cout << "\t\t\t\t\t用户名:\t\t";
                printf("%s\n",z3);
                cout << "\t\t\t\t\t用户性别:\t";
                printf("%s\n",z4);
                cout << "\t\t\t\t\t用户手机:\t";
                printf("%s\n",z5);
                cout << "\t\t\t\t\t用户个性签名:\t";
                printf("%s\n",z6);
                cout << "\t\t\t\t\t用户微信号:\t";
                printf("%s\n",z7);
                cout << "\t\t\t\t\t用户生日:\t";
                printf("%s\n",z8);
                cout << "\t\t\t\t\t用户电子邮箱:\t";
                printf("%s\n",z9);
            }
        }
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n";
        cout << "\n";
        cout << "\t\t\t\t\t按任意键返回!";
        getch();
        system("cls");
        user_display1();
	    break;
	  case'2':
        userself_amend(); //用户修改个人信息
	  	break;
      case'3':
        password_amend(); //修改密码
	  	break;
      case'4':
        user_auc(); //返回
	  	break;
    }
}

int system_Lojin1(list head)//管理员登录
{
	FILE*fp;
	list p1=head;
	char hit=0;
	char p[20];
	if ((fp=fopen("account.txt","r"))==NULL) //打开文件
	  {
         system ("cls");
		 printf("\t\t\t\t还未存在用户!请新建账户\n");
		 getch();
	 	system("cls");
		system_login();
	  }
    system ("cls");
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t请输入账号:\t";
    scanf("%s",a);
    cout << "\n";
    printf("\t\t\t\t\t请输入密码:\t");
    password_(p);
    while(p1) //判断是否存在账号
    {
        if(strcmp(a,p1->account)==0) //判断账号密码是否匹配
        {
            if(strcmp(p,p1->password)!=0)//判断密码是否匹配
            {
                cout << "\n";
                printf("\t\t\t\t\t密码错误！！！\n");
                cout << "\n";
                cout << "\t\t\t\t\t按ESC键返回登录界面，按回车键继续";
                hit=getch();
                if(hit==27) {
                    system("cls");
                    system_login();
                }
                else system_Lojin1(head);
            }
            else {
                    user_choicemenu();
                    break;
                 }
        }
        p1=p1->next;
    }
    if(!p1)//未找到账号
    {
        cout << "\n";
        printf("\t\t\t\t\t该用户名不存在！！！\n");
        cout << "\n";
        cout << "\t\t\t\t\t按ESC键返回登录界面，按回车键重新进行登录";
        hit=getch();
        if(hit==27) {
            system("cls");
            system_login();
            }
        else system_Lojin1(head);
    }
    return 0;
}

int system_Lojin2(list head)//用户登录
{
	FILE*fp;
	list p1=head;
	char hit=0;
	char p[20];
	if ((fp=fopen("account.txt","r"))==NULL)//打开文件
	  {
         system ("cls");
		 printf("\t\t\t\t还未存在用户!请新建账户\n");
		 getch();
	 	system("cls");
		system_login();
	  }
    system ("cls");
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t请输入账号:\t";
    scanf("%s",a);
    cout << "\n";
    printf("\t\t\t\t\t请输入密码:\t");
    password_(p);
    while(p1)
    {
        if(strcmp(a,p1->account)==0) //判断账号密码是否一致
        {
            if(strcmp(p,p1->password)!=0)//判断密码是否匹配
            {
                cout << "\n";
                printf("\t\t\t\t\t密码错误！！！\n");
                cout << "\n";
                cout << "\t\t\t\t\t按ESC键返回登录界面，按回车键继续";
                hit=getch();
                if(hit==27) {
                    system("cls");
                    system_login();
                }
                else system_Lojin2(head);
            }
            else {
                    user_auc();
                    break;
                 }
        }
        p1=p1->next;
    }
    if(!p1)
    {
        cout << "\n";
        printf("\t\t\t\t\t该用户名不存在！！！\n");
        cout << "\n";
        cout << "\t\t\t\t\t按ESC键返回登录界面，按回车键重新进行登录";
        hit=getch();
        if(hit==27) {
            system("cls");
            system_login();
            }
        else system_Lojin2(head);
    }
    return 0;
}

void oversee_menu() //查询功能界面
{
    system("cls");
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t#****************--*****************-$-****************--***************#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   1.查看全部拍卖物品\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   2.输入编号查询物品\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   3.输入物品名称查询物品\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   4.输入物品种类查询物品\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   5.输入物品起拍价区间查询物品\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t   6.返回\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#\t\t\t\t\t\t\t\t\t#\n";
    cout << "\t\t\t#***********************************---*********************************#\n";
    cout << "\t\t\t#***********************************-$-*********************************#\n";
}

void user_auc() //用户功能选择
{
    system("cls");
//    usersave();
    load_goods();//将物品信息存入结构体数组
    auc_menu(); //调用界面函数
    char p;
    cout << "\n";
    cout << "\t\t\t\t\t\t请输入您的选择:";
    scanf(" %c",&p);
	if(p>'7|'|p<='0')//判断输入是否符合条件
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_auc();
    }
	switch(p)//功能函数
    {
	  case '1':
        user_auction();//参加竞拍
	    break;
	  case '2':
        statistics();//统计情况
	  	break;
      case '3':
        user_overseechoice1();//查询物品
	  	break;
      case '4':
        user_bags();//查看背包
	  	break;
      case '5':
        goodsdelete1();//删除物品
	  	break;
      case '6':
        user_display1();//个人中心
	  	break;
      case '7':
        system_login();//退出登录
	  	break;
    }
}

void user_choicemenu()//管理员功能选择
{
    Goods head1=data_load();//将物品信息存到链表里
    system("cls");
    user_menu(); //调用界面函数
	char p;
	cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:";
	scanf(" %c",&p);
	if(p>'5'||p<='0')
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_choicemenu();
    }
	switch(p)//功能函数
    {
	  case '1':
        user_goodscharge(); //物品管理
	    break;
	  case '2':
        user_display(); //个人信息
	  	break;
      case '3':
        user_oversee(); //查看已注册的用户
	  	break;
      case '4':
        user_amend(); //修改用户信息
	  	break;
      case '5':
        system_login(); //退出登录
	  	break;
    }
}

void user_goodscharge()//管理员物品管理
{
    FILE *fp;
    if ((fp=fopen("goods.txt","r"))==NULL)//判断goods文件是否存在，若不存在，则新建
	{
      fp=fopen("goods.txt","w");
    }
    fclose(fp);
    system("cls");
    load_goods();
    userself_menu();
	char p;
	cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:";
	scanf(" %c",&p);
	if(p>'6'||p<='0')
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_goodscharge();
    }
	switch(p)//功能函数
    {
	  case'1':
        addgoods(); //添加物品
	    break;
	  case'2':
        goodsdelete(); //删除物品
	  	break;
      case'3':
        user_goodsamend(); //修改物品
	  	break;
      case'4':
        user_overseechoice(); //查询物品
	  	break;
      case'5':
        statistics1(); //物品统计
	  	break;
      case'6':
        user_choicemenu(); //返回
	  	break;
    }
}

Goods data_load()//读取物品数据文件
{
    FILE *fp;
    Goods p1=NULL,head1=NULL,p2=NULL;
    int i;
    if((fp=fopen("goods.txt","r"))==NULL)
    {
        printf("\n 打开文件失败\n");
        return 0;
    }
    for(i=1; !feof(fp); i++) //将物品文件读到链表
    {
        p1=(Goods)malloc(sizeof(User_Goods));
        fscanf(fp,"%s %s %d %s %lf %s %s %s %f",p1->account_data,p1->G_name,&p1->G_id,p1->new_or_old,&p1->G_price,p1->G_class,p1->G_dec,p1->G_condition,&p1->G_pprice);
        p1->next=NULL;
        if(i==1)
            head1=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    return (head1);
}

void usersave()//把用户得到的物品存到文件中
{
    system("cls");
    FILE *fp;
    int flag=0,i=1;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b3==0) continue;
        if(strcmp(a1,a)==0)//判断物品主人是否与登录用户一致
        {
            if(b4-(b6-b5)<=0)//判断物品拍卖是否结束
            {
                p1=(Goods)malloc(sizeof(User_Goods));
                strcpy(p1->account_data,a1);
                strcpy(p1->G_name,a2);
                p1->G_id=b3;
                p1->G_price=b1;
                strcpy(p1->new_or_old,a3);
                strcpy(p1->G_class,a4);
                strcpy(p1->G_dec,a5);
                strcpy(p1->G_condition,a6);
                p1->G_pprice=b2;
                p1->G_time=b4;
                p1->G_t=b5;
                strcpy(p1->G_auc_measure,a7);
                p1->G_ppprice=b7;
                p1->next=NULL;
                if(i==1)
                head1=p1;
                else
                    p2->next=p1;
                p2=p1;
                i++;
            }
        }
    }
    fclose(fp);
	fp=fopen("usergoods.txt","w");
    Goods p3=NULL;
    p3=head1;
    while(p3){
        fprintf(fp,"%s %s %d %s %f %s %s %s %f %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
        p3=p3->next;
    }
    fclose(fp);
}

void goodsdelete1()//用户删除物品
{
    system("cls");
    int n;
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t\t请输入您要删除的物品编号:\t";
    cin >> n;
    FILE *fp;
    Goods p1=NULL,head11=NULL,p2=NULL,p3=NULL;
    int i,flag=1;
    char hit=0;
    if ((fp=fopen("goods.txt","r"))==NULL)
	{
      cout << "文件打开失败！按任意键返回。";
      hit=getch();
      user_goodscharge();
    }
    for(i=1; !feof(fp); i++)//把物品信息存到链表
    {
        p1=(Goods)malloc(sizeof(User_Goods));
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p1->account_data,p1->G_name,&p1->G_id,p1->new_or_old,&p1->G_price,p1->G_class,p1->G_dec,p1->G_condition,&p1->G_pprice,&p1->G_time,&p1->G_t,p1->G_auc_measure,&p1->G_ppprice);
        if(p1->G_id==n&&strcmp(p1->account_data,a)==0) flag=0;//找到符合条件的物品
        p1->next=NULL;
        if(i==1)
            head11=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    if(flag)
    {
            cout << "\n";
            cout << "\t\t\t\t\t该物品编号不存在，请重新输入!\n";
            cout << "\t\t\t\t\t按回车键重新输入，按ESC返回!\n";
            cout << "\n\t\t\t\t******************************************************\n\n";
            hit=getch();
            system("cls");
            if(hit==27)
            {
                user_auc();
            }
            else if(hit==13)
            {
                goodsdelete1();
            }
    }
    goodsdel1(head11,n);
}

void goodsdel1(Goods head1,int n) //用户删除指定编号物品
{
    FILE *fp;
    Goods p1=NULL,p2=NULL,p3=NULL;
    int i,flag=1;
    char hit=0;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    p2=NULL;
    p1=head1;
    if(p1->G_id==n)//删除物品在首位时
    {
            cout << "\n";
            cout << "\t\t\t\t\t按回车确认删除，其他任意键返回！\n";
            hit=getch();
            if(hit==13){
                umu[n]=0;
                head1=head1->next;
                free(p1);
            }
            else user_auc();
    }
    else
    {
    while(p1->next->G_id!=n)
    {
        if(p1->next->next==NULL){//将p1定位到目标物品的前一个物品
            break;
        }
        p1=p1->next;
    }
        p2=p1->next;//p2指向目标物品
            cout << "\n";
            cout << "\t\t\t\t\t按回车确认删除，其他任意键返回！\n";
            hit=getch();
            if(hit==13){
            umu[n]=0;
            p1->next=p2->next;
            free(p2);
            }
            else user_auc();
    }
        p3=head1;
        fp=fopen("goods.txt","w");
        while(p3)
        {
            fprintf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
            p3=p3->next;
        }
        fclose(fp);
        cout << "\n";
        cout << "\t\t\t\t\t该物品已成功删除!\n";
        cout << "\t\t\t\t\t按任意键返回!\n";
        cout << "\n\t\t\t\t******************************************************\n\n";
        hit=getch();
        system("cls");
        user_auc();
}

void user_auction() //用户出价竞拍
{
    system("cls");
    FILE *fp;
    char hit=0;
    int n,flag=0;
    int i;
    double b3;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    Goods p1=NULL,head1=NULL,p2=NULL,p3=NULL;
    if((fp=fopen("goods.txt","r"))==NULL)
	{
      cout << "文件打开失败！按任意键返回。";
      hit=getch();
      user_goodscharge();
    }
    for(i=1; !feof(fp); i++)
    {
        p1=(Goods)malloc(sizeof(User_Goods));
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p1->account_data,p1->G_name,&p1->G_id,p1->new_or_old,&p1->G_price,p1->G_class,p1->G_dec,p1->G_condition,&p1->G_pprice,&p1->G_time,&p1->G_t,p1->G_auc_measure,&p1->G_ppprice);
        p1->next=NULL;
        if(i==1)
            head1=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    cout << "\t\t\t\t请输入您要竞拍的物品编号:\t";
    cin >> n;
    p3=head1;
    while(p3)
    {
        if(p3->G_id==n)//找到该物品
        {
            flag=1;
            break;
        }
        p3=p3->next;
    }
    if(flag)
    {
        cout << "\n";
        cout << "\t\t\t\t物品名称:  ";
        printf("%s\n",p3->G_name);
        cout << "\t\t\t\t物品拍卖方式:  ";
        printf("%s\n",p3->G_auc_measure);
        cout << "\t\t\t\t物品编号:  ";
        printf("%d\n",p3->G_id);
        cout << "\t\t\t\t物品新旧情况:  ";
        printf("%s\n",p3->new_or_old);
        cout << "\t\t\t\t物品起拍价:  ";
        printf("%f\n",p3->G_price);
        cout << "\t\t\t\t物品种类:  ";
        printf("%s\n",p3->G_class);
        cout << "\t\t\t\t物品描述:  ";
        printf("%s\n",p3->G_dec);
        cout << "\t\t\t\t物品状态:  ";
        if(p3->G_time-(b6-(p3->G_t))<=0)//拍卖剩余时间
        {
            strcpy(p3->G_condition,c2);
            printf("%s\n",p3->G_condition);
        }
        else
        {
            printf("%s\n",p3->G_condition);
        }
        if(strcmp(o1,p3->G_auc_measure)==0)//o1为明拍
        {
            cout << "\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",p3->G_pprice);
        }
        cout << "\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(p3->G_time-(b6-(p3->G_t))<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",p3->G_time-(b6-(p3->G_t)));
            }
        if(strcmp(p3->G_condition,c2)==0)//c2为结束拍卖
        {
            cout << "\n";
            cout << "\t\t\t\t该物品已结束拍卖!";
            cout << "\n";
            printf("\t\t\t\t该物品被用户%s拍中!\n",p3->account_data);
            cout << "\n";
            cout << "\t\t\t\t按任意键返回";
            getch();
            user_auc();
        }
        else
        {
        if(strcmp(o3,p3->G_auc_measure)!=0)
        {
        cout << "\n";
        cout << "\t\t\t\t请输入你的出价(出价不可低于起拍价):\t";
        scanf("%lf",&b3);
        if(b3 < p3->G_price)
        {
            cout << "\n";
            cout << "\t\t\t\t出价小于起拍价!按回车重新出价，按ESC返回!\n";
            hit=getch();
            if(hit==27)
            {
                user_auc();
            }
            else
            {
                user_auction();
            }
        }
        if(b3 > p3->G_pprice)
        {
            p3->G_pprice=b3;
            strcpy(p3->account_data,a);
        }
        }
        }
        cout << "\n";
        fp=fopen("goods.txt","w");
        p3=head1;
        while(p3)
        {
            fprintf(fp,"%s %s %d %s %f %s %s %s %f %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
            p3=p3->next;
        }
        fclose(fp);
        cout << "\t\t\t\t您已出价成功!\n";
        cout << "\t\t\t\t按任意键返回\n";
        getch();
        system("cls");
        user_auc();
        }
    else
    {
        cout << "\t\t\t\t该物品不存在哦!\n";
        cout << "\t\t\t\t按回车键重新输入，按ESC返回!\n";
        hit=getch();
        if(hit==27)
        {
            system("cls");
            user_auc();
        }
        else
        {
            user_auction();
        }
    }
}

void user_bags() //查看用户拍到的物品
{
    system("cls");
    FILE *fp;
    int flag=0;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b3==0) continue;
        if(strcmp(a1,a)==0)//判断物品主人与登录用户是否一致
        {
            if(b4-(b6-b5)<=0)//判断拍卖是否结束
            {
                cout << "\n";
                cout << "\t\t\t\t物品名称:  ";
                printf("%s\n",a2);
                cout << "\t\t\t\t物品拍卖方式:  ";
                printf("%s\n",a7);
                cout << "\t\t\t\t物品编号:  ";
                printf("%d\n",b3);
                cout << "\t\t\t\t物品新旧情况:  ";
                printf("%s\n",a3);
                cout << "\t\t\t\t物品起拍价:  ";
                printf("%f\n",b1);
                cout << "\t\t\t\t物品种类:  ";
                printf("%s\n",a4);
                cout << "\t\t\t\t物品描述:  ";
                printf("%s\n",a5);
                cout << "\t\t\t\t物品最终成交价:  ";
                printf("%f\n",b2);
                cout << "\n";
                cout << "--------------------------------------------------------------------------";
            }
        }
    }
    fclose(fp);
    cout << "\n";
    cout << "\t\t\t\t已经到底了哦，按任意键返回!\n";
    getch();
    user_auc();//返回
}

void load_goods()//将物品信息存入结构体数组
{
    system("cls");
    FILE *fp;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,flag=0,num=0,j=0,b4,b7;
    int number=-1,i;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        number++;
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b1==0) break;
        thing[number].G_id=b3;
        strcpy(thing[number].G_name,a2);
        strcpy(thing[number].account_data,a1);
        strcpy(thing[number].new_or_old,a3);
        thing[number].G_price=b1;
        strcpy(thing[number].G_class,a4);
        strcpy(thing[number].G_dec,a5);
        strcpy(thing[number].G_condition,a6);
        thing[number].G_pprice=b2;
        thing[number].G_time=b4;
        thing[number].G_t=b5;
        strcpy(thing[number].G_auc_measure,a7);
        thing[number].G_ppprice=b7;
    }
    if(b1!=0){
    hug=number;//物品总数
    quicksort(thing,0,number);
    fclose(fp);
    fp=fopen("goods.txt","w");
    for(i=0;i<=hug;i++)
    {
//        fprintf(fp,"%s %s %d %s %f %s %s %s %f %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
        fprintf(fp,"%s %s %d %s %f %s %s %s %f %d %ld %s %d\n",thing[i].account_data,thing[i].G_name,thing[i].G_id,thing[i].new_or_old,thing[i].G_price,thing[i].G_class,thing[i].G_dec,thing[i].G_condition,thing[i].G_pprice,thing[i].G_time,thing[i].G_t,thing[i].G_auc_measure,thing[i].G_ppprice);
    }
    fclose(fp);
    }
}

void user_overseechoice1()//用户查询方式选择
{
    system("cls");
    load_goods();
    oversee_menu();
	char p;
	cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:"; //输入选项
	scanf(" %c",&p);
	if(p>'6'||p<='0') //输入选项不合要求
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_overseechoice1(); //返回
    }
    else{
	switch(p)//功能函数
    {
	  case '1':
        user_selfsearch1();//查看全部物品
	    break;
	  case '2':
        user_idsearch1();//输入编号查询物品
	  	break;
      case '3':
        user_namesearch1();//输入名称查询物品
        break;
      case '4':
        user_classsearch1();//输入物品种类查询物品
        break;
      case '5':
        user_pricesearch1();//输入物品价格区间查询物品
        break;
      case '6':
        user_auc(); //返回用户主界面
	  	break;
    }
    }
}

void user_overseechoice()//管理员查询方式选择
{
    system("cls");
    load_goods();
    oversee_menu();
	char p;
	cout << '\n';
	cout << "\t\t\t\t\t\t请输入您的选择:"; //输入选项
	scanf(" %c",&p);
	if(p>'6'||p<='0') //输入选项不合要求
    {
        cout << "\t\t\t\t选项输入错误!按任意键重新输入\n";
        getch();
        system("cls");
        user_overseechoice();
    }
	switch(p)//功能函数
    {
	  case '1':
        user_selfsearch(); //查看全部物品
	    break;
	  case '2':
        user_idsearch(); //输入编号查询物品
	  	break;
      case '3':
        user_namesearch();//输入名称查询物品
        break;
      case '4':
        user_classsearch();//输入物品种类查询物品
        break;
      case '5':
        user_pricesearch();//输入物品价格区间查询物品
        break;
      case '6':
        user_goodscharge(); //返回管理员主界面
	  	break;
    }
}

void user_namesearch() //管理员输入物品名称查询物品
{
    system("cls");
    FILE *fp;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,flag=0,num=0,j=0,i,b4,b7;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    char s[100];
    cout << "\t\t\t\t\t\t请输入物品名称:\t";
    scanf("%s",s);
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        num=0;
        j=0;
        i=0;
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7); //读取文件内容
        for(i=0;i<strlen(a2);i+=2) //比较物品名称和输入的字符串，若相同，计数加2
        {
            if(s[j]==a2[i])
            {
                num+=2;
                j+=2;
            }
        }
        if(num==strlen(s)||strstr(a2,s)!=NULL) //输入的字符串为物品名称的子串或者计数值等于输入的字符串
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0) //若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",b2);
            cout << "\t\t\t\t\t\t出价最高用户: ";
            printf("%s\n",a1);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0) //拍卖结束，拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1; //找到符合条件的物品
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\t\t\t\t\t\n";
    }
    else
    {
        cout << "\t\t\t\t\t该物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_namesearch();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice();//返回
    }
}

void user_namesearch1() //用户输入物品名称查询物品
{
    system("cls");
    FILE *fp;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,flag=0,num=0,j=0,i,b4,b7;
    long b5;
    time_t b6=time(NULL);
    char s[100];
    cout << "\t\t\t\t\t\t请输入物品名称:\t";
    scanf("%s",s);
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        num=0;
        j=0;
        i=0;
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件内容
        for(i=0;i<strlen(a2);i+=2)//比较物品名称和输入的字符串，若相同，计数加2
        {
            if(s[j]==a2[i])
            {
                num+=2;
                j+=2;
            }
        }
        if(num==strlen(s)||strstr(a2,s)!=NULL)//输入的字符串为物品名称的子串或者计数值等于输入的字符串
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            if(strcmp(c2,a6)==0)//拍卖结束后判断最高价是否为当前用户
            {
                printf("\t\t\t\t\t\t该物品被用户%s拍中!\n",a1);
            }
            if(strcmp(o1,a7)==0)//判断拍卖是否结束
            {
                cout << "\t\t\t\t\t\t物品当前最高出价:  ";
                printf("%f\n",b2);
            }
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//拍卖结束，拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_namesearch1();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice1();//返回
    }
}

void user_classsearch() //管理员输入物品种类查询物品
{
    system("cls");
    FILE *fp;
    int n,flag=0;
    char hit=0;
    char s[100],a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    cout << "\t\t\t\t\t\t请输入物品种类:\t";
    scanf("%s",s);
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(strcmp(a4,s)==NULL)//在文件中找到种类与输入字符串相同的物品
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",b2);
            cout << "\t\t\t\t\t\t出价最高用户: ";
            printf("%s\n",a1);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//拍卖结束，拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\t\t\t\t\t\n";
    }
    else
    {
        cout << "\t\t\t\t\t该种类物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_classsearch();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice();//返回
    }
}

void user_classsearch1() //用户输入物品种类查询物品
{
    system("cls");
    FILE *fp;
    int n,flag=0;
    char hit=0;
    char s[100],a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    cout << "\t\t\t\t\t\t请输入物品种类:\t";
    scanf("%s",s);
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(strcmp(a4,s)==NULL)//在文件中找到种类与输入字符串相同的物品
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            if(strcmp(c2,a6)==0)//拍卖结束后判断最高价是否为当前用户
            {
                printf("\t\t\t\t\t\t该物品被用户%s拍中!\n",a1);
            }
            if(strcmp(o1,a7)==0)//判断拍卖是否结束
            {
                cout << "\t\t\t\t\t\t物品当前最高出价:  ";
                printf("%f\n",b2);
            }
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//拍卖结束，拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该种类物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_classsearch1();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice1();//返回
    }
}

void user_pricesearch() //管理员输入起拍价区间查询物品
{
    system("cls");
    FILE *fp;
    int n,flag=0;
    char hit=0;
    char s[100],a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    double n1,n2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    cout << "\t\t\t请输入想查询的起拍价区间(两个价格之间用空格隔开):\t";
    scanf("%lf%lf",&n1,&n2);
    if(n1>n2)//判断价格区间是否输入正确
    {
        cout << "\t\t\t\t\t价格区间输入错误!起始价格要大于末尾价格!\n";
        cout << "\t\t\t\t\t按回车键重新输入，按ESC键返回!\n";
        hit=getch();
        if(hit==27)
        {
            user_overseechoice();
        }
        else
        {
            user_pricesearch();//返回
        }
    }
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b1>=n1&&b1<=n2)//判断物品价格是否落在价格区间内
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将物品状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",b2);
            cout << "\t\t\t\t\t\t出价最高用户: ";
            printf("%s\n",a1);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该起拍价区间物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_pricesearch();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice();//返回
    }
}

void user_pricesearch1() //用户输入起拍价区间查询物品
{
    system("cls");
    FILE *fp;
    int n,flag=0;
    char hit=0;
    char s[100],a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    double n1,n2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    cout << "\t\t\t请输入想查询的起拍价区间(两个价格之间用空格隔开):\t";
    scanf("%lf%lf",&n1,&n2);
    if(n1>n2)//判断价格区间是否输入正确
    {
        cout << "\t\t\t\t\t价格区间输入错误!起始价格要大于末尾价格!\n";
        cout << "\t\t\t\t\t按回车键重新输入，按ESC键返回!\n";
        hit=getch();
        if(hit==27)
        {
            user_overseechoice1();
        }
        else
        {
            user_pricesearch1();//返回
        }
    }
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b1>=n1&&b1<=n2)//判断物品价格是否落在价格区间内
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将物品状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            if(strcmp(c2,a6)==0)//拍卖结束后判断最高价是否为当前用户
            {
                printf("\t\t\t\t\t\t该物品被用户%s拍中!\n",a1);
            }
            if(strcmp(o1,a7)==0)//判断拍卖是否结束
            {
                cout << "\t\t\t\t\t\t物品当前最高出价:  ";
                printf("%f\n",b2);
            }
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;
        }
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该起拍价区间物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_pricesearch1();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice1();//返回
    }
}

void user_idsearch() //管理员输入编号查询对应物品
{
    system("cls");
    FILE *fp;
    int target,flag=0,n;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    cout << "\t\t\t\t\t\t请输入物品编号:\t";
    cin >> target;
    n=binary(thing,hug,target);
    if(n==-1){
        flag=0;
    }
    else{
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",thing[n].G_name);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",thing[n].G_auc_measure);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",thing[n].G_id);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",thing[n].new_or_old);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",thing[n].G_price);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",thing[n].G_class);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",thing[n].G_dec);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(thing[n].G_time-(b6-thing[n].G_t)<=0)//若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(thing[n].G_condition,c2);
                printf("%s\n",thing[n].G_condition);
            }
            else
            {
                printf("%s\n",thing[n].G_condition);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",thing[n].G_pprice);
            cout << "\t\t\t\t\t\t出价最高用户:  ";
            printf("%s\n",thing[n].account_data);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(thing[n].G_time-(b6-thing[n].G_t)<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",thing[n].G_time-(b6-thing[n].G_t));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该编号物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_idsearch();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice();//返回
    }
}

void user_idsearch1() //用户输入编号查询对应物品
{
    system("cls");
    FILE *fp;
    int target,flag=0,n;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    cout << "\t\t\t\t\t\t请输入物品编号:\t";
    cin >> target;
    n=binary(thing,hug,target);
    if(n==-1){
        flag=0;
    }
    else{
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",thing[n].G_name);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",thing[n].G_auc_measure);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",thing[n].G_id);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",thing[n].new_or_old);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",thing[n].G_price);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",thing[n].G_class);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",thing[n].G_dec);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(thing[n].G_time-(b6-thing[n].G_t)<=0)//若拍卖结束，则将状态变为结束拍卖
            {
                strcpy(thing[n].G_condition,c2);
                printf("%s\n",thing[n].G_condition);
            }
            else
            {
                printf("%s\n",thing[n].G_condition);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",thing[n].G_pprice);
            cout << "\t\t\t\t\t\t出价最高用户:  ";
            printf("%s\n",thing[n].account_data);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(thing[n].G_time-(b6-thing[n].G_t)<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",thing[n].G_time-(b6-thing[n].G_t));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t该编号物品不存在哦!\n";
        cout << "\t\t\t\t\t按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    if(hit==13)
    {
        system("cls");
        user_idsearch1();//继续搜索
    }
    else
    {
        system("cls");
        user_overseechoice1();//返回
    }
}

void quicksort(User_Goods thing[], int low, int high)//快速排序
{
    int first = low;
    int last  = high;
    User_Goods key = thing[first];//取出key作为基准值
    if(low >= high)//结束
        return;
    while(first < last)
    {
        while(first < last && thing[last].G_id > key.G_id)//从后往前遍历,找第一个小于key.G_id的值
        {
            last--;
        }
        thing[first] = thing[last];//将从前往后未比较过的第一个位置即fisrt位置替换为该数据
        while(first < last && thing[first].G_id < key.G_id)//然后从前往后遍历,找第一个大于key.G_id的值
        {
            first++;
        }
        thing[last] = thing[first];//将从后往前的第一个比较过数据位置替换
    }
    thing[first] = key;
    quicksort(thing, low, first-1);//左递归
    quicksort(thing, first+1, high);//右递归
}

int binary(User_Goods thing[],int n,int target)//二分查找
{
    int left=0,right=n,mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(thing[mid].G_id==target){
            return mid;
        }
        else if(thing[mid].G_id<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

void password_(char arr[]) //隐藏密码函数
{
	int i=0;
	while((arr[i]=getch())!='\r')//'\r'是回车键
	{
		if(arr[i]=='\b')//'\b'是退格键
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	arr[i]='\0';//’\0’是判定字符数组结束的标识，表示这串字符到结尾了('\0'是占有位置的的)
}

void user_selfsearch() //管理员查看当前拍卖物品
{
    system("cls");
    FILE *fp;
    int flag=0;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b3==0) continue;
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将物品状态变为结束拍卖
            {
                strcpy(a6,c2);
                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            cout << "\t\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",b2);
            cout << "\t\t\t\t\t\t出价最高用户: ";
            printf("%s\n",a1);
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t暂时没有物品在拍卖哦!\n";
        cout << "\t\t\t\t\t按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    system("cls");
    user_overseechoice();//返回
}

void user_selfsearch1() //用户查看当前拍卖物品
{
    system("cls");
    FILE *fp;
    int flag=0;
    char hit=0;
    char a1[100]={'\0'},a2[100]={'\0'},a3[100]={'\0'},a4[100]={'\0'},a5[100]={'\0'},a6[100]={'\0'},a7[100]={'\0'};
    double b1,b2;
    int b3,b4,b7;
    long b5;
    time_t b6=time(NULL);
    Goods p1=NULL,head1=NULL,p2=NULL;
    fp=fopen("goods.txt","r");
    for(;!feof(fp);)
    {
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",a1,a2,&b3,a3,&b1,a4,a5,a6,&b2,&b4,&b5,a7,&b7);//读取文件
        if(b3==0) continue;
            cout << "\n";
            cout << "\t\t\t\t\t\t物品名称:  ";
            printf("%s\n",a2);
            cout << "\t\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",a7);
            cout << "\t\t\t\t\t\t物品编号:  ";
            printf("%d\n",b3);
            cout << "\t\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",a3);
            cout << "\t\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",b1);
            cout << "\t\t\t\t\t\t物品种类:  ";
            printf("%s\n",a4);
            cout << "\t\t\t\t\t\t物品描述:  ";
            printf("%s\n",a5);
            cout << "\t\t\t\t\t\t物品状态:  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将物品状态变为结束拍卖
            {
                strcpy(a6,c2);

                printf("%s\n",a6);
            }
            else
            {
                printf("%s\n",a6);
            }
            if(strcmp(c2,a6)==0)//拍卖结束后判断最高价是否为当前用户
            {
                printf("\t\t\t\t\t\t该物品被用户%s拍中!\n",a1);
            }
            if(strcmp(o1,a7)==0)//判断匹拍卖是否结束
            {
                cout << "\t\t\t\t\t\t物品当前最高出价:  ";
                printf("%f\n",b2);
            }
            cout << "\t\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(b4-(b6-b5)<=0)//若拍卖结束，将拍卖时间置为0
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",b4-(b6-b5));
            }
            cout << "\n";
            cout << "\t\t\t----------------------------------------------------------------------";
            cout << "\n";
            flag=1;//找到符合条件的物品
    }
    if(flag)
    {
        cout << "\t\t\t\t\t物品搜索成功!按回车键继续搜索，按ESC返回\n";
        cout << "\n";
    }
    else
    {
        cout << "\t\t\t\t\t暂时没有物品在拍卖哦!\n";
        cout << "\t\t\t\t\t按ESC返回\n";
        cout << "\n";
    }
    hit=getch();
    system("cls");
    user_overseechoice1();//返回
}

void user_oversee() // 查看当前所有注册用户
{
    system("cls");
    list p1=account_load();
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t用户基本信息（账号 密码 用户名 性别 手机号 个性签名 微信号 生日 电子邮箱）\n";
    cout << "\n";
    while(p1->next){
        printf("\t\t\t\t%s %s %s %s %s %s %s %s %s",p1->account,p1->password,p1->user_name,p1->user_sex,p1->user_phone,p1->user_esp,p1->user_wechat,p1->user_bir,p1->user_email);
        cout << "\n";
        p1=p1->next;
    }
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n";
    cout << "\t\t\t\t\t按任意键返回!";
    getch();
    user_choicemenu();
}

void addgoods() //增添拍卖物品
{
    FILE *fp;
    char hit=0;
    char hub[]="noaccount";
    char hub1[]="正在拍卖";
    Goods p1=NULL,head1=NULL,p2=NULL;
    int i;
    if ((fp=fopen("goods.txt","r"))==NULL)
	{
	    cout << "打开文件失败!";
	    system("cls");
        fp=fopen("goods.txt","w");
        fclose(fp);
    }
    for(i=1; !feof(fp); i++)
    {
        p1=(Goods)malloc(sizeof(User_Goods));
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p1->account_data,p1->G_name,&p1->G_id,p1->new_or_old,&p1->G_price,p1->G_class,p1->G_dec,p1->G_condition,&p1->G_pprice,&p1->G_time,&p1->G_t,p1->G_auc_measure,&p1->G_ppprice);
        p1->next=NULL;
        if(i==1)
            head1=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    system("cls");
    if ((fp=fopen("goods.txt","r"))==NULL)//if语句：打开物品文件，不存在此文件则新建
	{
      fp=fopen("goods.txt","w");
      fclose(fp);
    }
	fp=fopen("goods.txt","a");
    Goods p3=NULL;
    p2=head1;
    p3=(Goods)malloc(sizeof(User_Goods));
    while(p2)
    {
        umu[p2->G_id]=p2->G_id;//存在物品数组值置为1
        p2=p2->next;
    }
    p2=p3;
    p3->next=NULL;
    strcpy(p3->account_data,hub);
	fp=fopen("goods.txt","a");
	cout << "\t\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t请输入物品名称:  ";
	scanf("%s",p3->G_name);
	cout << "\t\t\t\t\t请输入物品拍卖方式(明拍或暗拍):  ";
	scanf("%s",p3->G_auc_measure);
	if(strcmp(p3->G_auc_measure,o1)&&strcmp(p3->G_auc_measure,o2)&&strcmp(p3->G_auc_measure,o3))
    {
        cout << "\n";
        cout << "\t\t\t\t拍卖方式输入错误!请按提示重新输入!\n";
        cout << "\t\t\t\t按任意键继续!";
        getch();
        addgoods();
    }
	cout << "\t\t\t\t\t请输入物品编号:  ";
	scanf("%d",&p3->G_id);
	if(umu[p3->G_id])
    {
        cout << "\n";
        cout << "\t\t\t\t该物品编号已存在!请按提示重新输入!\n";
        cout << "\t\t\t\t按任意键继续!";
        getch();
        addgoods();
    }
	cout << "\t\t\t\t\t请输入物品新旧情况(old or new):  ";
	scanf("%s",p3->new_or_old);
	if(strcmp(p3->new_or_old,o4)&&strcmp(p3->new_or_old,o5))
    {
        cout << "\n";
        cout << "\t\t\t\t物品新旧情况输入错误!请按提示重新输入!\n";
        cout << "\t\t\t\t按任意键继续!";
        getch();
        addgoods();
    }
	cout << "\t\t\t\t\t请输入物品起拍价:  ";
	scanf("%lf",&p3->G_price);
	cout << "\t\t\t\t\t请输入物品种类:  ";
	scanf("%s",p3->G_class);
	cout << "\t\t\t\t\t请输入物品描述:  ";
	scanf("%s",p3->G_dec);
	strcpy(p3->G_condition,hub1);
	cout << "\t\t\t\t\t请输入物品拍卖时间(秒): ";
	scanf("%d",&p3->G_time);
	if(strcmp(o3,p3->G_auc_measure)==0)
    {
        cout << "\t\t\t\t\t请输入卖家出价(用户出价最接近此价者得):  ";
        scanf("%d",&p3->G_ppprice);
    }
    else p3->G_ppprice=0;
	p3->G_t=time(NULL);// timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数）
	fprintf(fp,"%s %s %d %s %f %s %s %s %f %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
	fclose(fp);
	cout << "\n";
	cout << "\t\t\t\t该物品已成功投放到竞拍市场！按回车继续添加，按ESC返回！";
	cout << "\n";
	cout << "\n\t\t\t\t******************************************************\n\n";
	hit=getch();
	if(hit==13)
    {
        system("cls");
        addgoods();
    }
    else
    {
        system("cls");
        user_goodscharge();
    }
	system("cls");
}

void goodsdelete()//删除物品
{
    system("cls");
    int n;
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t\t请输入您要删除的物品编号:\t";
    cin >> n;
    FILE *fp;
    Goods p1=NULL,head1=NULL,p2=NULL,p3=NULL;
    int i,flag=1;
    char hit=0;
    if ((fp=fopen("goods.txt","r"))==NULL)
	{
      cout << "文件打开失败！按任意键返回。";
      hit=getch();
      user_goodscharge();
    }
    for(i=1; !feof(fp); i++)
    {
        p1=(Goods)malloc(sizeof(User_Goods));
        fscanf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p1->account_data,p1->G_name,&p1->G_id,p1->new_or_old,&p1->G_price,p1->G_class,p1->G_dec,p1->G_condition,&p1->G_pprice,&p1->G_time,&p1->G_t,p1->G_auc_measure,&p1->G_ppprice);
        if(p1->G_id==n) flag=0;
        p1->next=NULL;
        if(i==1)
            head1=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    fclose(fp);
    if(flag)
    {
            cout << "\n";
            cout << "\t\t\t\t\t该物品编号不存在，请重新输入!\n";
            cout << "\t\t\t\t\t按回车键重新输入，按ESC返回!\n";
//            cout << "\n";
            cout << "\n\t\t\t\t******************************************************\n\n";
            hit=getch();
            system("cls");
            if(hit==27)
            {
                user_goodscharge();
            }
            else if(hit==13)
            {
                goodsdelete();
            }
    }
    goodsdel(head1,n);
}

void goodsdel(Goods head1,int n) //删除指定编号物品
{
    FILE *fp;
    Goods p1=NULL,p2=NULL,p3=NULL;
    int i,flag=1;
    char hit=0;
    time_t b6=time(NULL);
    p2=NULL;
    p1=head1;
    if(p1->G_id==n)
    {
            cout << "\n";
            cout << "\t\t\t\t\t物品名称:  ";
            printf("%s\n",head1->G_name);
            cout << "\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",head1->G_auc_measure);
            cout << "\t\t\t\t\t物品编号:  ";
            printf("%d\n",head1->G_id);
            cout << "\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",head1->new_or_old);
            cout << "\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",head1->G_price);
            cout << "\t\t\t\t\t物品种类:  ";
            printf("%s\n",head1->G_class);
            cout << "\t\t\t\t\t物品描述:  ";
            printf("%s\n",head1->G_dec);
            cout << "\t\t\t\t\t物品状态:  ";
            if(head1->G_time-(b6-(head1->G_t))<=0)
            {
                strcpy(head1->G_condition,c2);
                printf("%s\n",head1->G_condition);
            }
            else
            {
                printf("%s\n",head1->G_condition);
            }
            if(strcmp(o1,head1->G_auc_measure)==0)
            {
                cout << "\t\t\t\t\t物品当前最高出价:  ";
                printf("%f\n",head1->G_pprice);
            }
            cout << "\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(head1->G_time-(b6-(head1->G_t))<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",head1->G_time-(b6-(head1->G_t)));
            }
            printf("\n");
            cout << "\n\t\t\t\t\t按回车确认删除，其他任意键返回！\n";
            hit=getch();
            if(hit==13){
                umu[n]=0;
                head1=head1->next;
                free(p1);
            }
            else user_goodscharge();
    }
    else
    {
    while(p1->next->G_id!=n)
    {
        if(p1->next->next==NULL){
            break;
        }
        p1=p1->next;
    }
        p2=p1->next;
            cout << "\n";
            cout << "\t\t\t\t\t物品名称:  ";
            printf("%s\n",p2->G_name);
            cout << "\t\t\t\t\t物品拍卖方式:  ";
            printf("%s\n",p2->G_auc_measure);
            cout << "\t\t\t\t\t物品编号:  ";
            printf("%d\n",p2->G_id);
            cout << "\t\t\t\t\t物品新旧情况:  ";
            printf("%s\n",p2->new_or_old);
            cout << "\t\t\t\t\t物品起拍价:  ";
            printf("%f\n",p2->G_price);
            cout << "\t\t\t\t\t物品种类:  ";
            printf("%s\n",p2->G_class);
            cout << "\t\t\t\t\t物品描述:  ";
            printf("%s\n",p2->G_dec);
            cout << "\t\t\t\t\t物品状态:  ";
            if(p2->G_time-(b6-(p2->G_t))<=0)
            {
                strcpy(p2->G_condition,c2);
                printf("%s\n",p2->G_condition);
            }
        else
        {
            printf("%s\n",p2->G_condition);
        }
        if(strcmp(o1,p2->G_auc_measure)==0)
        {
            cout << "\t\t\t\t\t物品当前最高出价:  ";
            printf("%f\n",p2->G_pprice);
        }
        cout << "\t\t\t\t\t物品当前剩余拍卖时间(秒):  ";
            if(p2->G_time-(b6-(p2->G_t))<=0)
            {
                printf("0");
            }
            else
            {
                printf("%ld\n",p2->G_time-(b6-(p2->G_t)));
            }
            cout << "\n";
            cout << "\n";
            cout << "\t\t\t\t\t按回车确认删除，其他任意键返回！\n";
            hit=getch();
            if(hit==13){
                umu[p2->G_id]=0;
                p1->next=p2->next;
                free(p2);
            }
            else user_goodscharge();
    }
        p3=head1;
        fp=fopen("goods.txt","w");
        while(p3)
        {
            fprintf(fp,"%s %s %d %s %lf %s %s %s %lf %d %ld %s %d\n",p3->account_data,p3->G_name,p3->G_id,p3->new_or_old,p3->G_price,p3->G_class,p3->G_dec,p3->G_condition,p3->G_pprice,p3->G_time,p3->G_t,p3->G_auc_measure,p3->G_ppprice);
            p3=p3->next;
        }
        fclose(fp);
        cout << "\n";
        cout << "\t\t\t\t\t该物品已成功删除!\n";
        cout << "\t\t\t\t\t按任意键返回!\n";
        cout << "\n\t\t\t\t******************************************************\n\n";
        hit=getch();
        system("cls");
        user_goodscharge();
}

void user_goodsamend() //修改物品信息
{
    system("cls");
    FILE *fp;
    char num[30];
    char p,hit;
    time_t b6=time(NULL);
    int flag=1,n,target;
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    cout << "\t\t\t\t\t请输入要修改的物品编号：";
    cin >> target;
    n=binary(thing,hug,target);
    if(n==-1){
        flag=0;
    }
    if(flag){
        if(thing[n].G_time-(b6-thing[n].G_t)<=0){
            cout << "\t\t\t\t\t该物品已结束拍卖！按按回车键请重新输入，按ESC返回\n";
            hit=getch();
            if(hit==27){
                user_goodscharge();//返回
            }
            else{
                user_goodsamend();
            }
        }
        else{
        cout << "\t\t\t\t\t你要修改哪些信息？\n";
        cout << "\t\t0.全部 1.物品名称 2.物品拍卖方式 3.物品新旧情况 4.物品起拍价 5.物品种类 6.物品描述\n";
        cout << "\t\t\t\t\t请输入你的选择：";
        scanf(" %c",&p);
        if(p>'6'||p<'0'){
            cout << "\t\t\t\t输入错误，按回车键请重新输入，按ESC返回！";
            hit=getch();
            if(hit==27){
                user_goodscharge();//返回
            }
            else{
                user_goodsamend();
            }
        }
        switch(p)//功能函数
        {
          case '0':
            cout << "\t\t\t\t\t请输入修改后的物品名称：";
            scanf("%s",thing[n].G_name);
            cout << "\t\t\t\t\t请输入修改后的物品拍卖方式(明拍或暗拍)：";
            scanf("%s",thing[n].G_auc_measure);
            cout << "\t\t\t\t\t请输入修改后的物品编号：";
            scanf("%d",&thing[n].G_id);
            cout << "\t\t\t\t\t请输入修改后的物品新旧情况(old或new)：";
            scanf("%s",thing[n].new_or_old);
            cout << "\t\t\t\t\t请输入修改后的物品起拍价：";
            scanf("%lf",&thing[n].G_price);
            cout << "\t\t\t\t\t请输入修改后的物品种类：";
            scanf("%s",thing[n].G_class);
            cout << "\t\t\t\t\t请输入修改后的物品描述：";
            scanf("%s",thing[n].G_dec);
            break;
          case '1':
            cout << "\t\t\t\t\t请输入修改后的物品名称：";
            scanf("%s",thing[n].G_name);
            break;
          case '2':
            cout << "\t\t\t\t\t请输入修改后的物品拍卖方式(明拍或暗拍)：";
            scanf("%s",thing[n].G_auc_measure);
            break;
          case '3':
            cout << "\t\t\t\t\t请输入修改后的物品新旧情况(old or new)：";
            scanf("%s",thing[n].new_or_old);
            break;
          case '4':
            cout << "\t\t\t\t\t请输入修改后的物品起拍价：";
            scanf("%lf",&thing[n].G_price);
            break;
          case '5':
            cout << "\t\t\t\t\t请输入修改后的物品种类：";
            scanf("%s",thing[n].G_class);
            break;
          case '6':
            cout << "\t\t\t\t\t请输入修改后的物品描述：";
            scanf("%s",thing[n].G_dec);
            break;
          default:
            break;
        }
        fp=fopen("goods.txt","w");
        for(int i=0;i<=hug;i++)
        {
            fprintf(fp,"%s %s %d %s %lf %s %s %s %f %d %ld %s %d\n",thing[i].account_data,thing[i].G_name,thing[i].G_id,thing[i].new_or_old,thing[i].G_price,thing[i].G_class,thing[i].G_dec,thing[i].G_condition,thing[i].G_pprice,thing[i].G_time,thing[i].G_t,thing[i].G_auc_measure,thing[i].G_ppprice);
        }
        fclose(fp);
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n\n";
        cout << "\t\t\t\t\t修改成功！按回车键继续，按esc返回！";
        hit=getch();
        if(hit==27){
                user_goodscharge();//返回
            }
            else{
                user_goodsamend();
            }
    }
    }
    else{
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n\n";
        cout << "\t\t\t\t\t该编号物品不存在，按回车键继续，按esc返回！";
        hit=getch();
        if(hit==27){
                user_goodscharge();//返回
            }
            else{
                user_goodsamend();
            }
    }
}

void statistics() //统计信息
{
    system("cls");
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    FILE *fp;
    int flag=0;
    char hit=0;
    int i=0,number=0,j,k,w;
    double hig=0;
    fp=fopen("goods.txt","r");
    cout << "\t\t\t\t\t当前存在的所有物品种类:\n";
    for(j=0;j<=hug;j++){
        for(k=0;k<j;k++){
            if(strcmp(thing[j].G_class,thing[k].G_class)==0) break;
        }
        if(k==j) printf("\t\t\t\t\t%d.%s\n",++i,thing[j].G_class);
    }
    cout << "\n";
    cout << "\t\t\t\t\t当前市场上物品总数: ";
    printf("%d\n",hug+1);
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t\t按任意键返回!\n";
    getch();
    user_auc();
}

void statistics1() //管理员统计信息
{
    system("cls");
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    FILE *fp;
    int flag=0;
    char hit=0;
    int i=0,number=0,j,k,w;
    double hig=0;
    fp=fopen("goods.txt","r");
    cout << "\t\t\t\t\t当前存在的所有物品种类:\n";
    for(j=0;j<=hug;j++){
        for(k=0;k<j;k++){
            if(strcmp(thing[j].G_class,thing[k].G_class)==0) break;
        }
        if(k==j) printf("\t\t\t\t\t%d.%s\n",++i,thing[j].G_class);
    }
    cout << "\n";
    cout << "\t\t\t\t\t当前市场上物品总数: ";
    printf("%d\n",hug+1);
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t\t按任意键返回!\n";
    getch();
    user_goodscharge();
}

void password_amend() //修改密码
{
    system("cls");
    FILE *fp;
    list p2=account_load();
    list p1=p2;
    char hit;
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    while(p1){
            if(strcmp(p1->account,a)==0){
                    break;
            }
        p1=p1->next;
    }
    cout << "\t\t\t\t\t请输入要修改后的密码：";
    scanf("%s",p1->password);
    p1=p2;
    fp=fopen("account.txt","w");
    while(p1){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p1->account,p1->password,p1->user_name,p1->user_sex,p1->user_phone,p1->user_esp,p1->user_wechat,p1->user_bir,p1->user_email);
        p1=p1->next;
    }
    fclose(fp);
    cout << "\n";
    cout << "\t\t\t\t******************************************************\n\n";
    cout << "\t\t\t\t\t修改成功！按回车键继续，按esc返回！";
    hit=getch();
    if(hit==27){
        user_display1();//返回
    }
    else{
        user_amend(); //修改用户信息
    }
}

void user_amend() //管理员修改用户信息
{
    system("cls");
    FILE *fp;
    list p2=account_load();
    list p1=p2;
    char num[30];
    char p,hit;
    int flag=0;
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    cout << "\t\t\t\t\t请输入要修改的用户账号：";
    scanf("%s",num);
    while(p1){
            if(strcmp(p1->account,num)==0){
                    flag=1;
                    break;
            }
        p1=p1->next;
    }
    if(flag){
        cout << "\t\t\t\t\t你要修改哪些信息？\n";
        cout << "\t\t\t0.全部 1.密码 2.用户名 3.性别 4.手机号 5.个性签名 6.微信号 7.生日 8.电子邮箱\n";
        cout << "\t\t\t\t\t请输入你的选择：";
        scanf(" %c",&p);
        if(p>'8'||p<'0'){
            cout << "\t\t\t\t输入错误，按回车键请重新输入，按ESC返回！";
            hit=getch();
            if(hit==27){
                user_choicemenu();//返回
            }
            else{
                user_amend(); //修改用户信息
            }
        }
        switch(p)//功能函数
        {
          case '0':
            cout << "\t\t\t\t\t请输入修改后的密码：";
            scanf("%s",p1->password);
            cout << "\t\t\t\t\t请输入修改后的用户名：";
            scanf("%s",p1->user_name);
            cout << "\t\t\t\t\t请输入修改后的性别：";
            scanf("%s",p1->user_sex);
            cout << "\t\t\t\t\t请输入修改后的手机号：";
            scanf("%s",p1->user_phone);
            cout << "\t\t\t\t\t请输入修改后的个性签名：";
            scanf("%s",p1->user_esp);
            cout << "\t\t\t\t\t请输入修改后的微信号：";
            scanf("%s",p1->user_wechat);
            cout << "\t\t\t\t\t请输入修改后的生日：";
            scanf("%s",p1->user_bir);
            cout << "\t\t\t\t\t请输入修改后的电子邮箱：";
            scanf("%s",p1->user_email);
            break;
          case '1':
            cout << "\t\t\t\t\t请输入修改后的密码：";
            scanf("%s",p1->password);
            break;
          case '2':
            cout << "\t\t\t\t\t请输入修改后的用户名：";
            scanf("%s",p1->user_name);
            break;
          case '3':
            cout << "\t\t\t\t\t请输入修改后的性别：";
            scanf("%s",p1->user_sex);
            break;
          case '4':
            cout << "\t\t\t\t\t请输入修改后的手机号：";
            scanf("%s",p1->user_phone);
            break;
          case '5':
            cout << "\t\t\t\t\t请输入修改后的个性签名：";
            scanf("%s",p1->user_esp);
            break;
          case '6':
            cout << "\t\t\t\t\t请输入修改后的微信号：";
            scanf("%s",p1->user_wechat);
            break;
          case '7':
            cout << "\t\t\t\t\t请输入修改后的生日：";
            scanf("%s",p1->user_bir);
            break;
          case '8':
            cout << "\t\t\t\t\t请输入修改后的电子邮箱：";
            scanf("%s",p1->user_email);
            break;
          default:
            break;
        }
        p1=p2;
        fp=fopen("account.txt","w");
        while(p1){
            fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p1->account,p1->password,p1->user_name,p1->user_sex,p1->user_phone,p1->user_esp,p1->user_wechat,p1->user_bir,p1->user_email);
            p1=p1->next;
        }
        fclose(fp);
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n\n";
        cout << "\t\t\t\t\t修改成功！按回车键继续，按esc返回！";
        hit=getch();
        if(hit==27){
            user_choicemenu();//返回
        }
        else{
            user_amend(); //修改用户信息
        }
    }
    else{
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n\n";
        cout << "\t\t\t\t\t该用户账号不存在，按回车键继续，按esc返回！";
        hit=getch();
        if(hit==27){
            user_choicemenu();//返回
        }
        else{
            user_amend(); //修改用户信息
        }
    }
}

void userself_amend() //用户修改个人信息
{
    system("cls");
    FILE *fp;
    list p2=account_load();
    list p1=p2;
    char num[30];
    char p,hit;
    int flag=0;
    cout << "\t\t\t\t******************************************************\n";
    cout << "\n";
    while(p1){
            if(strcmp(p1->account,a)==0){//当前登录账号匹配
                    flag=1;
                    break;
            }
        p1=p1->next;
    }
    if(flag){
        cout << "\t\t\t\t\t你要修改哪些信息？\n";
        cout << "\t\t\t0.全部 1.用户名 2.性别 3.手机号 4.个性签名 5.微信号 6.生日 7.电子邮箱\n";
        cout << "\t\t\t\t\t请输入你的选择：";
        scanf(" %c",&p);
        if(p>'7'||p<'0'){
            cout << "\t\t\t\t输入错误，按回车键请重新输入，按ESC返回！";
            hit=getch();
            if(hit==27){
                user_choicemenu();//返回
            }
            else{
                user_amend(); //修改用户信息
            }
        }
        switch(p)//功能函数
        {
          case '0':
            cout << "\t\t\t\t\t请输入修改后的用户名：";
            scanf("%s",p1->user_name);
            cout << "\t\t\t\t\t请输入修改后的性别：";
            scanf("%s",p1->user_sex);
            cout << "\t\t\t\t\t请输入修改后的手机号：";
            scanf("%s",p1->user_phone);
            cout << "\t\t\t\t\t请输入修改后的个性签名：";
            scanf("%s",p1->user_esp);
            cout << "\t\t\t\t\t请输入修改后的微信号：";
            scanf("%s",p1->user_wechat);
            cout << "\t\t\t\t\t请输入修改后的生日：";
            scanf("%s",p1->user_bir);
            cout << "\t\t\t\t\t请输入修改后的电子邮箱：";
            scanf("%s",p1->user_email);
            break;
          case '1':
            cout << "\t\t\t\t\t请输入修改后的用户名：";
            scanf("%s",p1->user_name);
            break;
          case '2':
            cout << "\t\t\t\t\t请输入修改后的性别：";
            scanf("%s",p1->user_sex);
            break;
          case '3':
            cout << "\t\t\t\t\t请输入修改后的手机号：";
            scanf("%s",p1->user_phone);
            break;
          case '4':
            cout << "\t\t\t\t\t请输入修改后的个性签名：";
            scanf("%s",p1->user_esp);
            break;
          case '5':
            cout << "\t\t\t\t\t请输入修改后的微信号：";
            scanf("%s",p1->user_wechat);
            break;
          case '6':
            cout << "\t\t\t\t\t请输入修改后的生日：";
            scanf("%s",p1->user_bir);
            break;
          case '7':
            cout << "\t\t\t\t\t请输入修改后的电子邮箱：";
            scanf("%s",p1->user_email);
            break;
          default:
            break;
        }
        p1=p2;
        fp=fopen("account.txt","w");
        while(p1){
            fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p1->account,p1->password,p1->user_name,p1->user_sex,p1->user_phone,p1->user_esp,p1->user_wechat,p1->user_bir,p1->user_email);
            p1=p1->next;
        }
        fclose(fp);
        cout << "\n";
        cout << "\t\t\t\t******************************************************\n\n";
        cout << "\t\t\t\t\t修改成功！按回车键继续，按esc返回！";
        hit=getch();
        if(hit==27){
            user_display1();//返回
        }
        else{
            userself_amend(); //修改用户信息
        }
    }
}

//----------------------------------------------------------------------------------------------
//----------------------------------------主函数------------------------------------------------
//----------------------------------------------------------------------------------------------

int main()
{
	system_login(); //调用登录函数
	return 0;
}
