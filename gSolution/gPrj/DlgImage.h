#pragma once

#define MAX_POINT	1000
// CDlgImage 대화 상자입니다.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParrent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

private:
	void InitImage();
	void DrawData(CDC* pDC);
};
