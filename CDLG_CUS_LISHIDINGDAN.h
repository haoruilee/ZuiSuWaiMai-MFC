#pragma once


// CDLG_CUS_LISHIDINGDAN 对话框

class CDLG_CUS_LISHIDINGDAN : public CDialogEx
{
	DECLARE_DYNAMIC(CDLG_CUS_LISHIDINGDAN)

public:
	CDLG_CUS_LISHIDINGDAN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDLG_CUS_LISHIDINGDAN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUS_LISHIDINGDAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
//	CListBox m_list;
	CListCtrl m_list;
	afx_msg void OnBnClickedCusQuerenshouhuo();
	afx_msg void OnLvnItemchangedListofdish(NMHDR* pNMHDR, LRESULT* pResult);
	CComboBox m_cus_xialadingdan;
	afx_msg void OnCbnSelchangeCusXialalishidingdan();
	afx_msg void OnBnClickedCusXianshiditu();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_BACKINORDER;
	afx_msg void OnBnClickedCusGengxindingdan();
	afx_msg void OnStnClickedBackgroundinorder();
};
