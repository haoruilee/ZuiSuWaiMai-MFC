#pragma once


// Cus_SelectView 视图

class Cus_SelectView : public CTreeView
{
	DECLARE_DYNCREATE(Cus_SelectView)

protected:
	Cus_SelectView();           // 动态创建所使用的受保护的构造函数
	virtual ~Cus_SelectView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};


