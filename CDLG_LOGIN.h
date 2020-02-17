#pragma once


// CDLG_LOGIN 对话框

class CDLG_LOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(CDLG_LOGIN)

public:
	CDLG_LOGIN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDLG_LOGIN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit BIANLIANG_YONGHUMING;
	CEdit BIANLIANG_MIMA;
	CString m_user1;
	CString m_psw1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClose();
};
