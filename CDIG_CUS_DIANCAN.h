//
#pragma once

#include <string>
using namespace std;
// CDIG_CUS_DIANCAN 对话框

class CDIG_CUS_DIANCAN : public CDialogEx
{
	DECLARE_DYNAMIC(CDIG_CUS_DIANCAN)

public:
	CDIG_CUS_DIANCAN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIG_CUS_DIANCAN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUS_DIANCAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_cus_caidan;
	virtual BOOL OnInitDialog();
	CListCtrl m_cus_yidiancai;
	afx_msg void OnBnClickedCusJiarugouwuche();
	afx_msg void OnLvnItemchangedCusCai(NMHDR* pNMHDR, LRESULT* pResult);

protected:

	 int costofallselected;//选中的菜价格
	string strofselectname;//选中的菜名
	int currentselectcul;//选中的行（从0开始）

public:
	afx_msg void OnBnClickedCusJiezhang();
	CComboBox m_xuanzeshouhuodizhi;
	afx_msg void OnCbnSelchangeShouhuodizhixuanze();
	afx_msg void OnClose();
	CStatic m_yummyfood;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedPicYummmyfood();
};
