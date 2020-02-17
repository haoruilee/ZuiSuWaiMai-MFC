// CDIG_CUS_INFORMATION.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "ZSWM.h"
#include "CDIG_CUS_INFORMATION.h"
#include "afxdialogex.h"
#include "Cus_dishinformation.h"
#include "stdafx.h"

// CDIG_CUS_INFORMATION 对话框

IMPLEMENT_DYNAMIC(CDIG_CUS_INFORMATION, CDialogEx)

CDIG_CUS_INFORMATION::CDIG_CUS_INFORMATION(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUS_INFORMATION, pParent)
	, m_username(_T(""))
	, m_cus_newpsw(_T(""))
	, m_cus_againnewpsw(_T(""))
	, m_cus_status(_T(""))
	, m_cus_username(_T(""))
{

}

CDIG_CUS_INFORMATION::~CDIG_CUS_INFORMATION()
{
}

void CDIG_CUS_INFORMATION::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//	DDX_Text(pDX, IDC_CUS_USERNAME, m_username);
	//	DDX_Control(pDX, IDC_CUS_status, m_cus_status);
	DDX_Text(pDX, IDC_CUS_NEWPSW, m_cus_newpsw);
	DDX_Text(pDX, IDC_CUS_AGAINNEWPSW, m_cus_againnewpsw);
	DDX_Text(pDX, IDC_CUS_status, m_cus_status);
	DDX_Text(pDX, IDC_CUS_username, m_cus_username);
	DDX_Control(pDX, IDC_BACKINCUSINFO, m_backincusinfo);
}


BEGIN_MESSAGE_MAP(CDIG_CUS_INFORMATION, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON1, &CDIG_CUS_INFORMATION::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CUS_SURETOCHANGEPSW, &CDIG_CUS_INFORMATION::OnBnClickedCusSuretochangepsw)
	ON_EN_CHANGE(IDC_CUS_username, &CDIG_CUS_INFORMATION::OnEnChangeCususername)
END_MESSAGE_MAP()


// CDIG_CUS_INFORMATION 消息处理程序


BOOL CDIG_CUS_INFORMATION::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CCus_dishinformation file;
	CString name, psw;
	CString locationofcus;
	file.ReadLogin(name,psw);

	m_cus_status = TEXT("顾客");
	m_cus_username = name;
	
	//设置背景
	m_backincusinfo.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	m_backincusinfo.GetWindowRect(rect);
	//（4）设置图片
	m_backincusinfo.SetBitmap(HBMP(TEXT("./pic_cusinfo.bmp"), rect.Width(), rect.Height()));
	
	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


// void CDIG_CUS_INFORMATION::OnBnClickedButton1()
// {
// 
// 	// TODO: 在此添加控件通知处理程序代码
// 
// }


void CDIG_CUS_INFORMATION::OnBnClickedCusSuretochangepsw()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//拿到最新的值
	if (m_cus_newpsw.IsEmpty()||m_cus_againnewpsw.IsEmpty())
	{
		MessageBox(TEXT("输入内容为空"));
		return;
	}
	if (m_cus_newpsw!=m_cus_againnewpsw)
	{
		MessageBox(TEXT("两次密码不一致？"));
		return;
	}

	//同步新密码
	CCus_dishinformation file;
	CString name, psw;
	CString locationofcus;
	file.ReadLogin(name, psw);

	//先Cstring转Char*
	CStringA temp1;
	CStringA temp2;
	temp1 = name;
	temp2 = m_cus_newpsw;
	file.WritePwd((temp1.GetBuffer()), (temp2.GetBuffer()));
	MessageBox(TEXT("修改成功"));

	//清空内容
	m_cus_newpsw.Empty();
	m_cus_againnewpsw.Empty();
	UpdateData(FALSE);
}


void CDIG_CUS_INFORMATION::OnEnChangeCususername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
