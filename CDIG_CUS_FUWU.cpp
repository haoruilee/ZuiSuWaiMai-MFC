// CDIG_CUS_FUWU.cpp: 实现文件
//

#include "pch.h"
#include "ZSWM.h"
#include "CDIG_CUS_FUWU.h"
#include "afxdialogex.h"
#include "CDIG_CUS_DIANCAN.h"
#include "CDLG_CUS_LISHIDINGDAN.h"

// CDIG_CUS_FUWU 对话框

IMPLEMENT_DYNAMIC(CDIG_CUS_FUWU, CDialogEx)

CDIG_CUS_FUWU::CDIG_CUS_FUWU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUS_FUWU, pParent)
{

}

CDIG_CUS_FUWU::~CDIG_CUS_FUWU()
{
}

void CDIG_CUS_FUWU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FUWU_TABSHEET, m_cus_tabsheet);
}


BEGIN_MESSAGE_MAP(CDIG_CUS_FUWU, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_FUWU_TABSHEET, &CDIG_CUS_FUWU::OnTcnSelchangeFuwuTabsheet)
END_MESSAGE_MAP()


// CDIG_CUS_FUWU 消息处理程序


void CDIG_CUS_FUWU::OnTcnSelchangeFuwuTabsheet(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CDIG_CUS_FUWU::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	
	//添加标签页
	m_cus_tabsheet.AddPage(TEXT("点餐"),&m_diancan, IDD_CUS_DIANCAN);
	m_cus_tabsheet.AddPage(TEXT("历史订单"), &m_lishidingdan, IDD_CUS_LISHIDINGDAN);
	m_cus_tabsheet.AddPage(TEXT("个人信息"), &m_information, IDD_CUS_INFORMATION);
	//显示
	m_cus_tabsheet.Show();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDIG_CUS_FUWU::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CDIG_CUS_FUWU::OnClose()
{
	exit(0);
}
