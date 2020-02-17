#pragma once


// CZSWMMAP 对话框

class CZSWMMAP : public CDialogEx
{
	DECLARE_DYNAMIC(CZSWMMAP)

public:
	CZSWMMAP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CZSWMMAP();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic mappic;
	afx_msg void OnBnClickedSuretoshowmap();
	CPoint posi[41];
	int startpoint;
};
