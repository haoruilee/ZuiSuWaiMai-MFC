
// ZSWM_MAPDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "pch.h"
#include "ZSWM_MAP.h"
#include "ZSWM_MAPDlg.h"
#include "afxdialogex.h"
#include "Path.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CZSWMMAPDlg 对话框



CZSWMMAPDlg::CZSWMMAPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ZSWM_MAP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZSWMMAPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_mappic, mappic);
}

BEGIN_MESSAGE_MAP(CZSWMMAPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CZSWMMAPDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_mappic, &CZSWMMAPDlg::OnStnClickedmappic)
END_MESSAGE_MAP()


// CZSWMMAPDlg 消息处理程序

BOOL CZSWMMAPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	mappic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	mappic.GetWindowRect(rect);
	//（4）设置图片
	mappic.SetBitmap(HBMP(TEXT("./Map.bmp"), rect.Width(), rect.Height()));
	// TODO: 在此添加额外的初始化代码



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CZSWMMAPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CZSWMMAPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CZSWMMAPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CZSWMMAPDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	posi[0].x = 40;
	posi[0].y = 350;
	posi[1].x = 715;
	posi[1].y = 100;
	posi[2].x = 780;
	posi[2].y = 100;
	posi[3].x = 720;
	posi[3].y = 135;
	posi[4].x = 785;
	posi[4].y = 131;
	posi[5].x = 720;
	posi[5].y = 165;
	posi[6].x = 780;
	posi[6].y = 163;
	posi[7].x = 721;
	posi[7].y = 190;
	posi[8].x = 782;
	posi[8].y = 189;
	posi[9].x = 720;
	posi[9].y = 220;
	posi[10].x = 785;
	posi[10].y = 218;
	posi[11].x = 720;
	posi[11].y = 249;
	posi[12].x = 786;
	posi[12].y = 247;
	posi[13].x = 786;
	posi[13].y = 305;
	posi[14].x = 721;
	posi[14].y = 275;
	posi[15].x = 785;
	posi[15].y = 274;
	posi[16].x = 786;
	posi[16].y = 350;
	posi[17].x = 716;
	posi[17].y = 354;
	posi[18].x = 787;
	posi[18].y = 450;
	posi[19].x = 720;
	posi[19].y = 450;
	posi[20].x = 720;
	posi[20].y = 480;
	posi[21].x = 787;
	posi[21].y = 480;
	posi[22].x = 787;
	posi[22].y = 568;
	posi[23].x = 721;
	posi[23].y = 568;
	posi[24].x = 622;
	posi[24].y = 568;
	posi[25].x = 655;
	posi[25].y = 485;
	posi[26].x = 460;
	posi[26].y = 520;
	posi[27].x = 380;
	posi[27].y = 523;
	posi[28].x = 400;
	posi[28].y = 580;
	posi[29].x = 180;
	posi[29].y = 520;
	posi[30].x = 183;
	posi[30].y = 600;
	posi[31].x = 255;
	posi[31].y = 340;
	posi[32].x = 500;
	posi[32].y = 330;
	posi[33].x = 400;
	posi[33].y = 335;
	posi[34].x = 148;
	posi[34].y = 342;
	posi[35].x = 148;
	posi[35].y = 400;
	posi[36].x = 100;
	posi[36].y = 400;
	posi[37].x = 580;
	posi[37].y = 100;
	posi[38].x = 448;
	posi[38].y = 120;
	posi[39].x = 412;
	posi[39].y = 226;
	posi[40].x = 340;
	posi[40].y = 229;
	const int South = 28;
	const int North = 37;
	const int East = 13;
	const int West = 0;
	int Spath, Wpath, Epath, Npath;
	int Path[41];
	int start, finish;
	finish =27;
	Spath = Dijkstra(South, finish, Path);
	Npath = Dijkstra(North, finish, Path);
	Epath = Dijkstra(East, finish, Path);
	Wpath = Dijkstra(West, finish, Path);
	start = Spath > Npath ? (Npath > Wpath ? (Wpath > Epath ? East : West) : (Npath > Epath? East : North) ): (Spath > Wpath ? (Wpath > Epath ? East : West) : (Spath > Epath) ? East : South);
	Dijkstra(start,finish, Path);
	pDC = mappic.GetDC();
	CPen pen, * ppen;
	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	ppen = pDC->SelectObject(&pen);
	pDC->MoveTo(posi[finish]);
	int i;
	i = 0;
	while (Path[i] != start)
	{
		pDC->LineTo(posi[Path[i]]);
		i++;
	}
	pDC->LineTo(posi[start]);
	pDC->SelectObject(ppen);
}


void CZSWMMAPDlg::OnStnClickedmappic()
{
	// TODO: 在此添加控件通知处理程序代码
}
