// CZSWMMAP.cpp: 实现文件
//

#include "pch.h"
#include <cstringt.h>
#include "ZSWM.h"
#include "CZSWMMAP.h"
#include "afxdialogex.h"
#include "path.h"

// CZSWMMAP 对话框

IMPLEMENT_DYNAMIC(CZSWMMAP, CDialogEx)

CZSWMMAP::CZSWMMAP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAP_DIALOG, pParent)
{

}

CZSWMMAP::~CZSWMMAP()
{
}

void CZSWMMAP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_mappic, mappic);
}


BEGIN_MESSAGE_MAP(CZSWMMAP, CDialogEx)
	ON_BN_CLICKED(IDC_SURETOSHOWMAP, &CZSWMMAP::OnBnClickedSuretoshowmap)
END_MESSAGE_MAP()


// CZSWMMAP 消息处理程序


BOOL CZSWMMAP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	mappic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//（2）获取bitmap句柄
#define HBMP(filePath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(), filePath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)
//（3）获取控件大小
	CRect rect;
	mappic.GetWindowRect(rect);
	//（4）设置图片
	mappic.SetBitmap(HBMP(TEXT("./Map.bmp"), rect.Width(), rect.Height()));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CZSWMMAP::OnBnClickedSuretoshowmap()
{
	// TODO: 在此添加控件通知处理程序代码
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
	
	//这里传入用户收货位置

	finish = startpoint;
	
	Spath = Dijkstra(South, finish, Path);
	Npath = Dijkstra(North, finish, Path);
	Epath = Dijkstra(East, finish, Path);
	Wpath = Dijkstra(West, finish, Path);
	start = Spath > Npath ? (Npath > Wpath ? (Wpath > Epath ? East : West) : (Npath > Epath ? East : North)) : (Spath > Wpath ? (Wpath > Epath ? East : West) : (Spath > Epath) ? East : South);
	
	double timeofdeliever;

	timeofdeliever=(Dijkstra(start, finish, Path));
	
	float f_time;
	
	f_time = (5+timeofdeliever/4);
	
	CString strMsg;

	strMsg.Format(_T("运输需要%f分钟"), f_time);
	
	MessageBox(strMsg);
	
	CDC* pDC;
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
