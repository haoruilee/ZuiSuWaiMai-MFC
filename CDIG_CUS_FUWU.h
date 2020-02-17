#pragma once
#include "TabSheet.h"
#include "CDIG_CUS_DIANCAN.h"
#include "CDLG_CUS_LISHIDINGDAN.h"
#include "CDIG_CUS_INFORMATION.h"

// CDIG_CUS_FUWU 对话框

class CDIG_CUS_FUWU : public CDialogEx
{
	DECLARE_DYNAMIC(CDIG_CUS_FUWU)

public:
	CDIG_CUS_FUWU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIG_CUS_FUWU();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUS_FUWU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 服务界面的tabsheet控件，继承于tabsheet.h
	CTabSheet m_cus_tabsheet;
	afx_msg void OnTcnSelchangeFuwuTabsheet(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();

	CDIG_CUS_DIANCAN m_diancan;
	CDLG_CUS_LISHIDINGDAN m_lishidingdan;
	CDIG_CUS_INFORMATION m_information;

	virtual void OnOK();
	void OnClose();
};
