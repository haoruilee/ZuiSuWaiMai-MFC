//本文件由李浩瑞编写于2019.9.9

#include "pch.h"
#include <cstringt.h>
#include <iostream>
#include "Cus_dishinformation.h"
#include "stdafx.h"
#include <fstream>
using namespace std;


// int id;			    //订单id
// string nameofshop;	//订单商家名
// string nameofcustomer;//订单买家名
// string nameofalldish;//订单的全部菜名
// int price;		    //订单价格
// string purchasetime; //下单时间
// string delievertime; //发货时间
// string receivingtime;//收货时间


//读取登录信息
void CCus_dishinformation::ReadLogin(CString& name, CString& pwd)
{

	ifstream ifs;	//创建文件输入对象
	ifs.open(Cus_F_LOGIN);
	
	char buf[1024] = { 0 };
	
	ifs.getline(buf, sizeof(buf));	//读取一行内容
	
	name = CString(buf);	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	
	pwd = CString(buf);	//将char* 转换为CString
	ifs.close();	//关闭文件
}

//修改密码
void CCus_dishinformation::WritePwd(char* name, char* pwd)
{
	ofstream ofs;	//创建文件输出对象
	ofs.open(Cus_F_LOGIN); //打开文件

	ofs << name << endl;	//name写入文件
	ofs << pwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}

//读取订单的信息 
void CCus_dishinformation::ReadOrderDocline()
{
	ifstream ifs(_F_DISINFO);	//输入方式打开文件

	char buf[1024] = { 0 };

	numoforder = 0;	//初始化订单数量为0
	
	lsorder.clear();

	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//没到文件结尾
	{
		msgoforder tmporder;

		ifs.getline(buf, sizeof(buf));	//读取一行
		numoforder++;	//订单数量加一

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//以"|"分隔
		if (sst != NULL)
		{
			tmporder.idoforder = atoi(sst);	//订单id
		}
		else
		{
			break;
		}

// string nameofshop;	//订单商家名
// string nameofcustomer;//订单买家名

		sst = strtok(NULL, "|");
		tmporder.nameofshop = sst;	//商家名

		sst = strtok(NULL, "|");
		tmporder.nameofcustomer = sst;	//买家名

		sst = strtok(NULL, "|");
		tmporder.nameofalldish = sst;	//订单的全部菜名

		sst = strtok(NULL, "|");
		tmporder.priceoforder = atoi(sst);	     //订单价格


// string purchasetime;//下单时间
// string delievertime;//发货时间
// string receivingtime;//收货时间
		
		sst = strtok(NULL, "|");
		tmporder.purchasetime = sst;	//下单时间

		sst = strtok(NULL, "|");
		tmporder.delievertime = sst;	//发货时间

		sst = strtok(NULL, "|");
		tmporder.receivingtime = sst;  //收货时间

		sst = strtok(NULL, "|");
		tmporder.locationofcus = atoi(sst);	     //订单价格

		lsorder.push_back(tmporder);	//放在链表的后面
	
	}

	ifs.close();	//关闭文件
}

//订单写入文件

void CCus_dishinformation::WriteOrderDocline()
{

	ofstream ofs(_F_DISINFO);	//输出方式打开文件
	//订单ID|买家名|商家名|菜名（x几份）|价格|下单时间|发货时间|收货时间
	
	string bt = "订单ID|买家名|商家名|菜名(x几份)|价格|下单时间|发货时间|收货时间|买家位置";

	if (lsorder.size() > 0)	//订单链表有内容才执行
	{
		ofs << bt << endl;	//写入表头

		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<msgoforder>::iterator it = lsorder.begin(); it != lsorder.end(); it++)
		{


// string nameofalldish;//订单的全部菜名
// int price;		//订单价格
// string purchasetime;//下单时间
// string delievertime;//发货时间
// string receivingtime;//收货时间

			ofs << it->idoforder << "|";

			ofs << it->nameofcustomer << "|";

			ofs << it->nameofshop << "|";
			
			ofs << it->nameofalldish << "|";

			ofs << it->priceoforder << "|";
			
			ofs << it->purchasetime << "|";

			ofs << it->delievertime << "|";

			ofs << it->receivingtime  << "|";

			ofs << it->locationofcus << endl;
		}
	}
	ofs.close();
}

//添加新订单


void CCus_dishinformation::AddOrderline(string nameofshop,	//订单商家名
	string nameofcustomer,//订单买家名
	string nameofalldish,//订单的全部菜名
	int price,		//订单价格
	string purchasetime,//下单时间
	string delievertime,//发货时间
	string receivingtime,
	int locationofcus)
{
	msgoforder tmpoforder;

	if (lsorder.size() > 0)
	{
		//价格有效且已经付款

		if ( price > 0 && (!purchasetime.empty()))
		{

			tmpoforder.idoforder = lsorder.size() + 1;	//id自动加1
	
			tmpoforder.nameofshop = nameofshop;

			tmpoforder.nameofcustomer = nameofcustomer;

			tmpoforder.nameofalldish = nameofalldish;

			tmpoforder.priceoforder = price;		//价格

			tmpoforder.purchasetime = purchasetime;


			if (!delievertime.empty()&&delievertime!=("暂未发货"))
			{
				tmpoforder.delievertime = delievertime;
			}

			else
			{
				tmpoforder.delievertime = "暂未发货";
			}


			if (!receivingtime.empty() && receivingtime != ("暂未收货"))
			{
				tmpoforder.receivingtime = receivingtime;
			}
			else
			{
				tmpoforder.receivingtime = "暂未收货";
			}

			if (locationofcus<0)
			{
				locationofcus = 20;//默认从20开始
			}

			tmpoforder.locationofcus = locationofcus;

			lsorder.push_back(tmpoforder);			//放在链表的后面
		}
	}
}

void CCus_dishinformation::ReadstockDocline()
{
	ifstream ifs(_F_STOCK);	//输入方式打开文件

	char buf[1024] = { 0 };
	numofallstock = 0;	//初始化商品数量为0
	lsstock.clear();
	//取出表头

	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//没到文件结尾
	{
		msgofstock stocktmp;

		ifs.getline(buf, sizeof(buf));	//读取一行
		numofallstock++;	//商品数量加一

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//以"|"分隔
		if (sst != NULL)
		{
			stocktmp.idofstock = atoi(sst);	//商品id
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		stocktmp.nameofstock = sst;	//商品名称

		sst = strtok(NULL, "|");
		stocktmp.priceofstock = atoi(sst);	//商品价格

		sst = strtok(NULL, "|");
		stocktmp.numofonestock = atoi(sst);	//商品数目

		lsstock.push_back(stocktmp);	//放在链表的后面
	}
	ifs.close();	//关闭文件
}

void CCus_dishinformation::WritestockDocline()
{
	ofstream ofs(_F_STOCK);	//输出方式打开文件
	string bt = "商品ID|商品名|单价|库存";

	if (lsstock.size() > 0)	//商品链表有内容才执行
	{
		ofs << bt << endl;	//写入表头

		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<msgofstock>::iterator it = lsstock.begin(); it != lsstock.end(); it++)
		{
			ofs << it->idofstock << "|";
			ofs << it->nameofstock << "|";
			ofs << it->priceofstock << "|";
			ofs << it->numofonestock << endl;
		}
	}
	ofs.close();
}

void CCus_dishinformation::Addstockline(CString name, int num, int price)
{
	msgofstock tmpofstock;

	if (lsstock.size() > 0)
	{
		//商品名称，库存，价格有效
		if (!name.IsEmpty() && num > 0 && price > 0)
		{
			tmpofstock.idofstock = lsstock.size() + 1;	//id自动加1
			CStringA str;
			str = name;					//CString 转CStringA
			tmpofstock.nameofstock = str.GetBuffer();//CString 转为char *, 商品名称
			tmpofstock.numofonestock = num;			//库存
			tmpofstock.priceofstock = price;		//价格

			lsstock.push_back(tmpofstock);			//放在链表的后面
		}
	}
}


