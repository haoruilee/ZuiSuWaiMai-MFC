#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <afxdisp.h>

#define SHOP_LOGIN "./login.ini"

using namespace std;



class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);


};

