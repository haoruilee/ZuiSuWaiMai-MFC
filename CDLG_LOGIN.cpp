// CDLG_LOGIN.cpp: 实现文件
#pragma once

#include "pch.h"
#include "ZSWM.h"
#include "CDLG_LOGIN.h"
#include "afxdialogex.h"
#include "Cus_dishinformation.h"


// CDLG_LOGIN 对话框

IMPLEMENT_DYNAMIC(CDLG_LOGIN, CDialogEx)

CDLG_LOGIN::CDLG_LOGIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_user1(_T(""))
	, m_psw1(_T(""))
{

}

CDLG_LOGIN::~CDLG_LOGIN()
{
}

void CDLG_LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
// 	DDX_Control(pDX, IDC_EDIT3, BIANLIANG_YONGHUMING);
// 	DDX_Control(pDX, IDC_EDIT4, BIANLIANG_MIMA);
	DDX_Text(pDX, IDC_EDIT1, m_user1);
	DDX_Text(pDX, IDC_EDIT2, m_psw1);
	DDV_MaxChars(pDX, m_psw1, 6);
}


BEGIN_MESSAGE_MAP(CDLG_LOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDLG_LOGIN::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CDLG_LOGIN::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDLG_LOGIN::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDLG_LOGIN 消息处理程序


void CDLG_LOGIN::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	CCus_dishinformation file;
	CString name, psw;
	CString locationofcus;
	file.ReadLogin(name, psw);

	if (m_user1.IsEmpty()|| m_psw1.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}

	if (m_user1 == name)
	{
		if (m_psw1 == psw)
		{
			CDLG_LOGIN::OnCancel();//关闭窗口
		}
		else
		{
			MessageBox(TEXT("密码错误"));
		}
	}
// 	else if (m_user1!=name)
// 	{
// 		MessageBox(TEXT("Oh,我们还不认识你，请注册"));
// 		return;
// 	}
// 	else if (m_psw1 != psw)
// 	{
// 		MessageBox(TEXT("密码记错了？好好想想"));
// 		return;
// 	}
}


void CDLG_LOGIN::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDLG_LOGIN::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CDLG_LOGIN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//登录时默认填写了用户名和密码
	CCus_dishinformation file;
	CString name, psw;
	
	CString locationofcus;

	file.ReadLogin(name, psw);

	m_user1 = name;
	m_psw1 = psw;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDLG_LOGIN::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CDLG_LOGIN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}
