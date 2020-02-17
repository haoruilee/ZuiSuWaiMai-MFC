// Cus_SelectView.cpp: 实现文件
//

#include "pch.h"
#include "ZSWM.h"
#include "Cus_SelectView.h"


// Cus_SelectView

IMPLEMENT_DYNCREATE(Cus_SelectView, CTreeView)

Cus_SelectView::Cus_SelectView()
{

}

Cus_SelectView::~Cus_SelectView()
{
}

BEGIN_MESSAGE_MAP(Cus_SelectView, CTreeView)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// Cus_SelectView 诊断

#ifdef _DEBUG
void Cus_SelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void Cus_SelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Cus_SelectView 消息处理程序


void Cus_SelectView::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CTreeView::OnClose();
	exit(1);
}
