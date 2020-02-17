
// ZSWMView.cpp: CZSWMView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZSWM.h"
#endif

#include "ZSWMDoc.h"
#include "ZSWMView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZSWMView

IMPLEMENT_DYNCREATE(CZSWMView, CView)

BEGIN_MESSAGE_MAP(CZSWMView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZSWMView 构造/析构

CZSWMView::CZSWMView() noexcept
{
	// TODO: 在此处添加构造代码

}

CZSWMView::~CZSWMView()
{
}

BOOL CZSWMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZSWMView 绘图

void CZSWMView::OnDraw(CDC* /*pDC*/)
{
	CZSWMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CZSWMView 打印

BOOL CZSWMView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZSWMView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZSWMView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZSWMView 诊断

#ifdef _DEBUG
void CZSWMView::AssertValid() const
{
	CView::AssertValid();
}

void CZSWMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZSWMDoc* CZSWMView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZSWMDoc)));
	return (CZSWMDoc*)m_pDocument;
}
#endif //_DEBUG


// CZSWMView 消息处理程序


void CZSWMView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
}
