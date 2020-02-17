// CDLG_CUS_LISHIDINGDAN.cpp: 实现文件
//本文件由李浩瑞编写于2019年9月8日

#include "pch.h"
#include "ZSWM.h"
#include "CDLG_CUS_LISHIDINGDAN.h"
#include "afxdialogex.h"
#include"CZSWMMAP.h"
#include "Cus_dishinformation.h"

#include <time.h>
// CDLG_CUS_LISHIDINGDAN 对话框

IMPLEMENT_DYNAMIC(CDLG_CUS_LISHIDINGDAN, CDialogEx)

CDLG_CUS_LISHIDINGDAN::CDLG_CUS_LISHIDINGDAN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUS_LISHIDINGDAN, pParent)
{

}

CDLG_CUS_LISHIDINGDAN::~CDLG_CUS_LISHIDINGDAN()
{
}

void CDLG_CUS_LISHIDINGDAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_Listofdish, m_list);
	DDX_Control(pDX, IDC_CUS_XIALALISHIDINGDAN, m_cus_xialadingdan);
	DDX_Control(pDX, IDC_BACKGROUNDINORDER, m_BACKINORDER);
}


BEGIN_MESSAGE_MAP(CDLG_CUS_LISHIDINGDAN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CDLG_CUS_LISHIDINGDAN::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDLG_CUS_LISHIDINGDAN::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_CUS_QUERENSHOUHUO, &CDLG_CUS_LISHIDINGDAN::OnBnClickedCusQuerenshouhuo)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_Listofdish, &CDLG_CUS_LISHIDINGDAN::OnLvnItemchangedListofdish)
	ON_CBN_SELCHANGE(IDC_CUS_XIALALISHIDINGDAN, &CDLG_CUS_LISHIDINGDAN::OnCbnSelchangeCusXialalishidingdan)
	ON_BN_CLICKED(IDC_CUS_XIANSHIDITU, &CDLG_CUS_LISHIDINGDAN::OnBnClickedCusXianshiditu)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CUS_GENGXINDINGDAN, &CDLG_CUS_LISHIDINGDAN::OnBnClickedCusGengxindingdan)
	ON_STN_CLICKED(IDC_BACKGROUNDINORDER, &CDLG_CUS_LISHIDINGDAN::OnStnClickedBackgroundinorder)
END_MESSAGE_MAP()


// CDLG_CUS_LISHIDINGDAN 消息处理程序


void CDLG_CUS_LISHIDINGDAN::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

}


BOOL CDLG_CUS_LISHIDINGDAN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	////////////////初始化列表///////////////////


		
//订单总表：订单ID|买家名|商家名|菜名（x几份）|价格|下单时间|发货时间|收货时间


// 	int id;			//订单id
// 	string nameofshop;	//订单商家名
// 	string nameofcustomer;//订单买家名
// 	string nameofalldish;//订单的全部菜名
// 	int price;		//订单价格
// 	string purchasetime;//下单时间
// 	string delievertime;//发货时间
// 	string receivingtime;//收货时间
	// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃12"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃34"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃56"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆北门"));

// 	switch (readloctionofcus)
// 	{
// 	case 0:
// 		readloctionofcus = 7;
// 		break;
// 	case 1:
// 		readloctionofcus = 5;
// 		break;
// 	case 2:
// 		readloctionofcus = 3;
// 		break;
// 	case 3:
// 		readloctionofcus = 14;
// 		break;
// 		// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆南门"));
// 		// 	m_xuanzeshouhuodizhi.AddString(TEXT("梅园宿舍"));
// 	case 4:
// 		readloctionofcus = 17;
// 		break;
// 	case 5:
// 		readloctionofcus = 19;
// 		break;
// 		// 		m_xuanzeshouhuodizhi.AddString(TEXT("橘园操场"));
// 		// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆南门"));
// 		// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆北门"));
// 	case 6:
// 		readloctionofcus = 30;
// 		break;
// 	case 7:
// 		readloctionofcus = 33;
// 		break;
// 	case 8:
// 		readloctionofcus = 40;
// 		break;
// 	}


	// 设置扩展风格/////|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES,整行选中，网格
		m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//初始化表头
	CString field[] = { TEXT("订单ID"),TEXT("店名"),TEXT("菜名"),TEXT("订单价格"),TEXT("下单时间"),TEXT("发货时间"),TEXT("收货时间"),TEXT("收货地址")};

	for (int i = 0; i < sizeof(field) / sizeof(field[0]);++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	CCus_dishinformation file;
	file.ReadOrderDocline();	//读取商品信息
	// 添加数据
	int i = 0;
	CString str;

	CString locationofcusreceive;


	for (list<msgoforder>::iterator it = file.lsorder.begin(); it != file.lsorder.end(); it++)
	{
		str.Format(TEXT("%d"), it->idoforder);
		m_list.InsertItem(i, str);
		int column = 1;

		m_list.SetItemText(i, column++, (CString)it->nameofshop.c_str());

		m_list.SetItemText(i, column++, (CString)it->nameofalldish.c_str());
		
		str.Format(TEXT("%d"), it->priceoforder);
		m_list.SetItemText(i, column++, str);

		m_list.SetItemText(i, column++, (CString)it->purchasetime.c_str());
		m_list.SetItemText(i, column++, (CString)it->delievertime.c_str());
		m_list.SetItemText(i, column++, (CString)it->receivingtime.c_str());

		////////写入地址///////
		// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃12"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃34"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃56"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆北门"));

		switch (it->locationofcus)
		{
		case 7:
			locationofcusreceive = "桃12";
			break;
		case 5:
			locationofcusreceive = "桃34";
			break;
		case 3:
			locationofcusreceive = "桃56";
			break;
		case 14:
			locationofcusreceive = "体育馆北门";
			break;
			// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆南门"));
			// 	m_xuanzeshouhuodizhi.AddString(TEXT("梅园宿舍"));
		case 17:
			locationofcusreceive = "体育馆南门";
			break;
		case 19:
			locationofcusreceive = "梅园宿舍";
			break;
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("橘园操场"));
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆南门"));
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆北门"));
		case 30:
			locationofcusreceive = "橘园操场";
			break;
		case 33:
			locationofcusreceive = "图书馆南门";
			break;
		case 40:
			locationofcusreceive = "图书馆北门";
			break;
		}

		m_list.SetItemText(i, column++, locationofcusreceive);

		/////////////////////


		m_list.SetItemData(i, i);//用于存储排序关键字
		i++;
	}

	UpdateData(TRUE);
	////////////////////初始化下拉框///////////////////////////////////
	
	CCus_dishinformation dishfile;

	dishfile.ReadOrderDocline();//必须先读取数据

	int numberofdish = dishfile.numoforder;
	for (list<msgoforder>::iterator it = file.lsorder.begin(); it != file.lsorder.end(); it++)
	{
		CString str;
		str.Format(_T("%d"), it->idoforder);
		
		LPCTSTR pStr = LPCTSTR(str);
		m_cus_xialadingdan.AddString(pStr);
	}

	//默认选择最后一个

	m_cus_xialadingdan.SetCurSel((numberofdish-2));
	UpdateData(TRUE);

	//设置背景图片
	
//设置背景
	m_BACKINORDER.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	m_BACKINORDER.GetWindowRect(rect);
//（4）设置图片
	m_BACKINORDER.SetBitmap(HBMP(TEXT("./pic_seu.bmp"), rect.Width(), rect.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDLG_CUS_LISHIDINGDAN::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDLG_CUS_LISHIDINGDAN::OnBnClickedCusQuerenshouhuo()
{
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	
	//确认收货
	int index = m_cus_xialadingdan.GetCurSel();
	
	CCus_dishinformation dishfile;
	dishfile.ReadOrderDocline();//必须先读取数据
	int numberofdish = dishfile.numoforder;

	CCus_dishinformation file1;
	file1.ReadOrderDocline();

	//把receivingtime设置成当前时间
	for (list<msgoforder>::iterator it = file1.lsorder.begin(); it != file1.lsorder.end(); it++)
	{
		if ((it->idoforder-1)==index)
		{
			if (it->receivingtime=="暂未收货")
			{
				struct tm* newtime;
				char tmpbuf[128];
				time_t lt1;
				time(&lt1);
				newtime = localtime(&lt1);
				strftime(tmpbuf, 128, "%X, %d %B", newtime);
				it->receivingtime = tmpbuf;
				MessageBox(TEXT("确认收货成功"));
			}

			else
			{
				MessageBox(TEXT("该订单已经收货啦~请勿重复操作"));
			}
		}
	}

	file1.WriteOrderDocline();


	//更新listcontrol

	m_list.DeleteAllItems();//清空除表头外的所有内容


	// 设置扩展风格/////|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES,整行选中，网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	//不需要再初始化表头
	//CString field[] = { TEXT("订单ID"),TEXT("店名"),TEXT("菜名"),TEXT("订单价格"),TEXT("下单时间"),TEXT("发货时间",TEXT("收货时间")) };

// 	for (int i = 0; i < sizeof(field) / sizeof(field[0]);++i)
// 	{
// 		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
// 	}

	CCus_dishinformation file;
	file.ReadOrderDocline();	//读取商品信息
	// 添加数据
	int i = 0;
	CString str;


	for (list<msgoforder>::iterator it = file.lsorder.begin(); it != file.lsorder.end(); it++)
	{
		str.Format(TEXT("%d"), it->idoforder);
		m_list.InsertItem(i, str);
		int column = 1;

		m_list.SetItemText(i, column++, (CString)it->nameofshop.c_str());

		m_list.SetItemText(i, column++, (CString)it->nameofalldish.c_str());
		str.Format(TEXT("%d"), it->priceoforder);
		m_list.SetItemText(i, column++, str);
		m_list.SetItemText(i, column++, (CString)it->purchasetime.c_str());
		m_list.SetItemText(i, column++, (CString)it->delievertime.c_str());
		m_list.SetItemText(i, column++, (CString)it->receivingtime.c_str());

		m_list.SetItemData(i, i);//用于存储排序关键字
		i++;
	}

	UpdateData(TRUE);

}


void CDLG_CUS_LISHIDINGDAN::OnLvnItemchangedListofdish(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDLG_CUS_LISHIDINGDAN::OnCbnSelchangeCusXialalishidingdan()
{
	// TODO: 在此添加控件通知处理程序代码
	//切换商品触发的事件
}


void CDLG_CUS_LISHIDINGDAN::OnBnClickedCusXianshiditu()
{
	// TODO: 在此添加控件通知处理程序代码
	///
	//显示地图
	int index = m_cus_xialadingdan.GetCurSel();

	CCus_dishinformation dishfile;
	dishfile.ReadOrderDocline();//必须先读取数据

	int numberofdish = dishfile.numoforder;

	CCus_dishinformation file1;
	file1.ReadOrderDocline();

	//读取当前订单的位置

	int readloctionofcus;

	for (list<msgoforder>::iterator it = file1.lsorder.begin(); it != file1.lsorder.end(); it++)
	{
		if ((it->idoforder - 1) == index)
		{
			readloctionofcus=it->locationofcus;
		}
	}


	file1.flagofcusloction = readloctionofcus;
	
	CZSWMMAP MAPSHOW;
	MAPSHOW.startpoint = file1.flagofcusloction;

	MAPSHOW.DoModal();

}


HBRUSH CDLG_CUS_LISHIDINGDAN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here   
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}

	// TODO: Return a different brush if the default is not desired   
	return hbr;
}


void CDLG_CUS_LISHIDINGDAN::OnBnClickedCusGengxindingdan()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//更新历史订单

	m_list.DeleteAllItems();//清空除表头外的所有内容

	CCus_dishinformation file;
	file.ReadOrderDocline();	//读取商品信息
	// 添加数据
	int i = 0;
	CString str;
	CString locationofcusreceive;
	for (list<msgoforder>::iterator it = file.lsorder.begin(); it != file.lsorder.end(); it++)
	{
		str.Format(TEXT("%d"), it->idoforder);
		m_list.InsertItem(i, str);
		int column = 1;

		m_list.SetItemText(i, column++, (CString)it->nameofshop.c_str());

		m_list.SetItemText(i, column++, (CString)it->nameofalldish.c_str());

		str.Format(TEXT("%d"), it->priceoforder);
		m_list.SetItemText(i, column++, str);

		m_list.SetItemText(i, column++, (CString)it->purchasetime.c_str());
		m_list.SetItemText(i, column++, (CString)it->delievertime.c_str());
		m_list.SetItemText(i, column++, (CString)it->receivingtime.c_str());

		switch (it->locationofcus)
		{
		case 7:
			locationofcusreceive = "桃12";
			break;
		case 5:
			locationofcusreceive = "桃34";
			break;
		case 3:
			locationofcusreceive = "桃56";
			break;
		case 14:
			locationofcusreceive = "体育馆北门";
			break;
			// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆南门"));
			// 	m_xuanzeshouhuodizhi.AddString(TEXT("梅园宿舍"));
		case 17:
			locationofcusreceive = "体育馆南门";
			break;
		case 19:
			locationofcusreceive = "梅园宿舍";
			break;
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("橘园操场"));
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆南门"));
			// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆北门"));
		case 30:
			locationofcusreceive = "橘园操场";
			break;
		case 33:
			locationofcusreceive = "图书馆南门";
			break;
		case 40:
			locationofcusreceive = "图书馆北门";
			break;
		}

		m_list.SetItemText(i, column++, locationofcusreceive);
		m_list.SetItemData(i, i);//用于存储排序关键字
		i++;
	}

	////////////////////更新化下拉框///////////////////////////////////

	CCus_dishinformation dishfile;

	dishfile.ReadOrderDocline();//必须先读取数据

	int numberofdish = dishfile.numoforder;

	m_cus_xialadingdan.ResetContent();

	for (list<msgoforder>::iterator it = file.lsorder.begin(); it != file.lsorder.end(); it++)
	{
		CString str;
		str.Format(_T("%d"), it->idoforder);
		LPCTSTR pStr = LPCTSTR(str);
		m_cus_xialadingdan.AddString(pStr);
	}

	//默认选择最后一个

	m_cus_xialadingdan.SetCurSel((numberofdish - 2));
	UpdateData(TRUE);
}


void CDLG_CUS_LISHIDINGDAN::OnStnClickedBackgroundinorder()
{
	// TODO: 在此添加控件通知处理程序代码
}
