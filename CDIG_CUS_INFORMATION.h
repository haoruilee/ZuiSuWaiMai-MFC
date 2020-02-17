#pragma once


// CDIG_CUS_INFORMATION 对话框

class CDIG_CUS_INFORMATION : public CDialogEx
{
	DECLARE_DYNAMIC(CDIG_CUS_INFORMATION)

public:
	CDIG_CUS_INFORMATION(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIG_CUS_INFORMATION();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUS_INFORMATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
//	CEdit m_cus_status;
	CString m_cus_newpsw;
	CString m_cus_againnewpsw;
	CString m_cus_status;
	CString m_cus_username;
	virtual BOOL OnInitDialog();
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCusSuretochangepsw();
	afx_msg void OnEnChangeCususername();
	CStatic m_backincusinfo;
};
