//订单信息总表
//本文件由李浩瑞编写于2019/9/1

#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <afxdisp.h>

#define Cus_F_LOGIN "./Cus_login.ini"
#define _F_DISINFO "./cus_dishinformation.txt"
#define _F_STOCK "./stock.txt"

using namespace std;

struct msgoforder
{
	//订单ID|买家名|商家名|菜名（x几份）|价格|下单时间|发货时间|收货时间

	int idoforder;			//订单id
	string nameofshop;	//订单商家名
	string nameofcustomer;//订单买家名
	string nameofalldish;//订单的全部菜名
	int priceoforder;		//订单价格
	string purchasetime;//下单时间
	string delievertime;//发货时间
	string receivingtime;//收货时间
	int locationofcus;//收货地址
};

struct msgofstock
{
	int idofstock;			//商品id
	string nameofstock;	//商品名
	int priceofstock;		//商品价格
	int numofonestock;		//商品个数
};

class CCus_dishinformation
{

public:


	//读取登录信息
	void ReadLogin(CString& name, CString& pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);

	//读取订单数据
	void ReadOrderDocline();

	//将订单数据写入文件
	void WriteOrderDocline();

	//订单ID|买家名|商家名|菜名（x几份）|价格|下单时间|发货时间|收货时间
	//添加新订单

	void AddOrderline(string nameofshop,	//订单商家名
		string nameofcustomer,//订单买家名
		string nameofalldish,//订单的全部菜名
		int price,		//订单价格
		string purchasetime,//下单时间
		string delievertime,//发货时间
		string receivingtime,//收货时间
		int locationofcus//收货地点
	);

		//读取商品数据
	void ReadstockDocline();

	//商品写入文件
	void WritestockDocline();

	//添加新商品
	void Addstockline(CString name, int num, int price);

	list<msgofstock> lsstock;	//存储商品容器
	int numofallstock;			//用来记录商品个数


	list<msgoforder> lsorder;	//存储商品容器
	int numoforder;			//用来记录商品个数

	int flagofcusloction;//存储买家位置
};

#pragma once