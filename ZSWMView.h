
// ZSWMView.h: CZSWMView 类的接口
//

#pragma once


class CZSWMView : public CView
{
protected: // 仅从序列化创建
	CZSWMView() noexcept;
	DECLARE_DYNCREATE(CZSWMView)

// 特性
public:
	CZSWMDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZSWMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // ZSWMView.cpp 中的调试版本
inline CZSWMDoc* CZSWMView::GetDocument() const
   { return reinterpret_cast<CZSWMDoc*>(m_pDocument); }
#endif

