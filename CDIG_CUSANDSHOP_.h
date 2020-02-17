#pragma once


// CDIG_CUSANDSHOP_ 对话框

class CDIG_CUSANDSHOP_ : public CDialogEx
{
	DECLARE_DYNAMIC(CDIG_CUSANDSHOP_)

public:
	CDIG_CUSANDSHOP_(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIG_CUSANDSHOP_();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSANDSHOP_XUANZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();

public:
	//afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCusandshopShop();
	afx_msg void OnBnClickedCusandshopcustomer();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	CStatic m_Backpicinselect;
	afx_msg void OnStnClickedBackpicinselect();
};
