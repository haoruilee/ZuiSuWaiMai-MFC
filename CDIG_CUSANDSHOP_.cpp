// CDIG_CUSANDSHOP_.cpp: 实现文件
//

#include "pch.h"
#include "ZSWM.h"
#include "CDIG_CUSANDSHOP_.h"
#include "afxdialogex.h"
#include "CDLG_LOGIN.h"
#include "CDIG_CUS_FUWU.h"


// CDIG_CUSANDSHOP_ 对话框

IMPLEMENT_DYNAMIC(CDIG_CUSANDSHOP_, CDialogEx)

CDIG_CUSANDSHOP_::CDIG_CUSANDSHOP_(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUSANDSHOP_XUANZE, pParent)
{

}

CDIG_CUSANDSHOP_::~CDIG_CUSANDSHOP_()
{
}

void CDIG_CUSANDSHOP_::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BACKPICINSELECT, m_Backpicinselect);
}


BEGIN_MESSAGE_MAP(CDIG_CUSANDSHOP_, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON2, &CDIG_CUSANDSHOP_::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_CUSANDSHOP_SHOP, &CDIG_CUSANDSHOP_::OnBnClickedCusandshopShop)
	ON_BN_CLICKED(IDC_CUSANDSHOP_customer, &CDIG_CUSANDSHOP_::OnBnClickedCusandshopcustomer)
	ON_WM_CLOSE()
	ON_STN_CLICKED(IDC_BACKPICINSELECT, &CDIG_CUSANDSHOP_::OnStnClickedBackpicinselect)
END_MESSAGE_MAP()


// CDIG_CUSANDSHOP_ 消息处理程序


void CDIG_CUSANDSHOP_::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}




// void CDIG_CUSANDSHOP_::OnBnClickedButton2()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// 
// }


void CDIG_CUSANDSHOP_::OnBnClickedCusandshopShop()
{
	// TODO: 在此添加控件通知处理程序代码
	CDLG_LOGIN LOG;
	LOG.DoModal();
	CDIG_CUS_FUWU FUWU;
	FUWU.DoModal();
	exit(0);
}


void CDIG_CUSANDSHOP_::OnBnClickedCusandshopcustomer()
{
	// TODO: 在此添加控件通知处理程序代码
		// TODO: 在此添加控件通知处理程序代码
	CDLG_LOGIN LOG;
	LOG.DoModal();
	CDIG_CUS_FUWU FUWU;
	FUWU.DoModal();
	exit(0);
}


void CDIG_CUSANDSHOP_::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}


BOOL CDIG_CUSANDSHOP_::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Backpicinselect.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	m_Backpicinselect.GetWindowRect(rect);
	//（4）设置图片
	m_Backpicinselect.SetBitmap(HBMP(TEXT("./backinselect.bmp"), rect.Width(), rect.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDIG_CUSANDSHOP_::OnStnClickedBackpicinselect()
{
	// TODO: 在此添加控件通知处理程序代码
}
