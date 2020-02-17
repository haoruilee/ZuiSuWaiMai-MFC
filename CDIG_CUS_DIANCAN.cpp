// CDIG_CUS_DIANCAN.cpp: 实现文件
//
#include <string>
#include "pch.h"
#include "ZSWM.h"
#include "CDIG_CUS_DIANCAN.h"
#include "afxdialogex.h"
#include"Cus_dishinformation.h"
#include "InfoFile.h"
#include "CDLG_CUS_LISHIDINGDAN.h"

// CDIG_CUS_DIANCAN 对话框

IMPLEMENT_DYNAMIC(CDIG_CUS_DIANCAN, CDialogEx)

CDIG_CUS_DIANCAN::CDIG_CUS_DIANCAN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUS_DIANCAN, pParent)
{
	costofallselected = 0;
}

CDIG_CUS_DIANCAN::~CDIG_CUS_DIANCAN()
{
}

void CDIG_CUS_DIANCAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUS_CAI, m_cus_caidan);
	DDX_Control(pDX, IDC_CUS_DIANDECAI, m_cus_yidiancai);
	DDX_Control(pDX, IDC_SHOUHUODIZHIXUANZE, m_xuanzeshouhuodizhi);
	DDX_Control(pDX, IDC_PIC_YUMMMYFOOD, m_yummyfood);
}


BEGIN_MESSAGE_MAP(CDIG_CUS_DIANCAN, CDialogEx)
	ON_BN_CLICKED(IDC_CUS_JIARUGOUWUCHE, &CDIG_CUS_DIANCAN::OnBnClickedCusJiarugouwuche)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_CUS_CAI, &CDIG_CUS_DIANCAN::OnLvnItemchangedCusCai)
	ON_BN_CLICKED(IDC_CUS_JIEZHANG, &CDIG_CUS_DIANCAN::OnBnClickedCusJiezhang)
	ON_CBN_SELCHANGE(IDC_SHOUHUODIZHIXUANZE, &CDIG_CUS_DIANCAN::OnCbnSelchangeShouhuodizhixuanze)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_PIC_YUMMMYFOOD, &CDIG_CUS_DIANCAN::OnStnClickedPicYummmyfood)
END_MESSAGE_MAP()


// CDIG_CUS_DIANCAN 消息处理程序


BOOL CDIG_CUS_DIANCAN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
		// 设置扩展风格/////|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES,整行选中，网格
	m_cus_caidan.SetExtendedStyle(m_cus_caidan.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	DWORD dwStyle = m_cus_caidan.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	//初始化表头
	
	CString field[] = {TEXT("ID"), TEXT("菜名"),TEXT("价格") };

	for (int i = 0; i < sizeof(field) / sizeof(field[0]);++i)
	{
		m_cus_caidan.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	CCus_dishinformation file;

	file.ReadstockDocline();	//读取商品信息
	// 添加数据

	int i = 0;
	CString str;


	for (list<msgofstock>::iterator it = file.lsstock.begin(); it != file.lsstock.end(); it++)
	{
		str.Format(TEXT("%d"), it->idofstock);
		
		m_cus_caidan.InsertItem(i, str);
		
		int column = 1;

		m_cus_caidan.SetItemText(i, column++, (CString)it->nameofstock.c_str());

		str.Format(TEXT("%d"), it->priceofstock);
		m_cus_caidan.SetItemText(i, column++, str);

		m_cus_caidan.SetItemData(i, i);//用于存储排序关键字
		i++;
	}
	
	UpdateData(TRUE);
	

	//已经点的菜
		//显示在已点菜单中
	// 设置扩展风格/////|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES,整行选中，网格
	m_cus_yidiancai.SetExtendedStyle(m_cus_yidiancai.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	DWORD dwStyle2 = m_cus_yidiancai.GetExtendedStyle();
	dwStyle2 |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	//初始化表头

	CString field2[] = { TEXT("ID"), TEXT("菜名"),TEXT("价格") };

	for (int i = 0; i < sizeof(field2) / sizeof(field2[0]);++i)
	{
		m_cus_yidiancai.InsertColumn(i, field2[i], LVCFMT_CENTER, 90);
	}

	m_xuanzeshouhuodizhi.AddString(TEXT("桃12"));
	m_xuanzeshouhuodizhi.AddString(TEXT("桃34"));
	m_xuanzeshouhuodizhi.AddString(TEXT("桃56"));
	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆北门"));
	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆南门"));
	m_xuanzeshouhuodizhi.AddString(TEXT("梅园宿舍"));
	m_xuanzeshouhuodizhi.AddString(TEXT("橘园操场"));
	m_xuanzeshouhuodizhi.AddString(TEXT("图书馆南门"));
	m_xuanzeshouhuodizhi.AddString(TEXT("图书馆北门"));

	m_xuanzeshouhuodizhi.SetCurSel(7);

	//设置背景
	m_yummyfood.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	m_yummyfood.GetWindowRect(rect);
	//（4）设置图片
	m_yummyfood.SetBitmap(HBMP(TEXT("./pic_yummyfood.bmp"), rect.Width(), rect.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDIG_CUS_DIANCAN::OnBnClickedCusJiarugouwuche()
{
	// TODO: 在此添加控件通知处理程序代码
	

	CCus_dishinformation file;

	file.ReadstockDocline();	//读取商品信息
	// 添加数据

	int i = 0;
	CString str;


	for (list<msgofstock>::iterator it = file.lsstock.begin(); it != file.lsstock.end(); it++)
	{

		int totalcul = 0;//储存当前是第几行

		if (i==currentselectcul)
		{

			str.Format(TEXT("%d"), it->idofstock);

			m_cus_yidiancai.InsertItem(totalcul, str);
			
			int column = 1;

			m_cus_yidiancai.SetItemText(totalcul, column++, (CString)it->nameofstock.c_str());
			
			//将点菜写入所点菜名
			strofselectname=strofselectname + it->nameofstock+"x1  ";
			
			str.Format(TEXT("%d"), it->priceofstock);
			//计算已点价格
			costofallselected += it->priceofstock;

			m_cus_yidiancai.SetItemText(totalcul, column++, str);

			totalcul++;

			m_cus_yidiancai.SetItemData(i, i);//储存排序关键字
		}

		i++;
	}

	UpdateData(TRUE);


	int caidanindex = 0;
	
}


void CDIG_CUS_DIANCAN::OnLvnItemchangedCusCai(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	CString strofmesbox;
	for (int i = 0; i < m_cus_caidan.GetItemCount(); i++)
	{
		if (m_cus_caidan.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			currentselectcul = i;
		}
	}

	*pResult = 0;
}


void CDIG_CUS_DIANCAN::OnBnClickedCusJiezhang()
{
	// TODO: 在此添加控件通知处理程序代码
		//将点菜内容写入txt文本
	//订单ID|买家名|商家名|菜名(x几份)|价格|下单时间|发货时间|收货时间

	//读取商家名

	CInfoFile shopfile;
	CString nameofshopinorder, shopspsw, nameofcusinorder, cuspsw;
	shopfile.ReadLogin(nameofshopinorder, shopspsw);
	CT2CA shopName(nameofshopinorder);

	CCus_dishinformation file;

	//读取买家名
	file.ReadLogin(nameofcusinorder, cuspsw);
	CT2CA cusName(nameofcusinorder);

	file.ReadOrderDocline();
	//获取下单时间
	struct tm* newtime;
	char tmpbuf[128];
	time_t lt1;
	time(&lt1);
	newtime = localtime(&lt1);
	strftime(tmpbuf, 128, "%X, %d %B", newtime);

	//初始化发货时间和收货时间
	string delievertime = "暂未发货";
	string receivingtime = "暂未收货";
	
	//获取顾客选择的收货位置
	int readloctionofcus = m_xuanzeshouhuodizhi.GetCurSel();

	// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃12"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃34"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("桃56"));
// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆北门"));

	switch (readloctionofcus)
	{
	case 0:
		readloctionofcus = 7;
		break;
	case 1:
		readloctionofcus = 5;
		break;
	case 2:
		readloctionofcus = 3;
		break;
	case 3:
		readloctionofcus = 14;
		break;
		// 	m_xuanzeshouhuodizhi.AddString(TEXT("体育馆南门"));
		// 	m_xuanzeshouhuodizhi.AddString(TEXT("梅园宿舍"));
	case 4:
		readloctionofcus = 17;
		break;
	case 5:
		readloctionofcus = 19;
		break;
		// 		m_xuanzeshouhuodizhi.AddString(TEXT("橘园操场"));
		// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆南门"));
		// 		m_xuanzeshouhuodizhi.AddString(TEXT("图书馆北门"));
	case 6:
		readloctionofcus = 30;
		break;
	case 7:
		readloctionofcus = 33;
		break;
	case 8:
		readloctionofcus = 40;
		break;
	}

	file.AddOrderline((string)shopName,	//订单商家名
		(string)cusName,//订单买家名
		strofselectname,//订单的全部菜名
		costofallselected,		//订单价格
		tmpbuf,//下单时间
		delievertime,//发货时间
		receivingtime,
		readloctionofcus);

	file.WriteOrderDocline();

	if (costofallselected)
	{
		CString coststring;
		coststring.Format(_T("订单价格为%d，现在您可以在历史订单中查看地图"), costofallselected);
		MessageBox(coststring);
	}
	else
	{
		MessageBox(TEXT("请先点餐"));
	}

	


	UpdateData(TRUE);


}


void CDIG_CUS_DIANCAN::OnCbnSelchangeShouhuodizhixuanze()
{
	// TODO: 在此添加控件通知处理程序代码
	//桃12;桃34;桃56;体育馆北门;体育馆南门;梅园宿舍;金智楼;计算机学院;图书馆南门;图书馆北门
	

}


void CDIG_CUS_DIANCAN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


HBRUSH CDIG_CUS_DIANCAN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here   

	//设置static控件透明
// 	switch (pWnd->GetDlgCtrlID())
// 	{
// 	case IDC_STATIC:
// 		pDC->SetBkMode(TRANSPARENT);
// 		pDC->SetTextColor(RGB(0, 0, 0));
// 		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
// 	default:
// 		break;
// 	}

	// TODO: Return a different brush if the default is not desired   
	return hbr;
}


void CDIG_CUS_DIANCAN::OnStnClickedPicYummmyfood()
{
	// TODO: 在此添加控件通知处理程序代码
}
