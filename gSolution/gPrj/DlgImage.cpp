// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARRENT, &CDlgImage::OnBnClickedBtnUpParrent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParrent()
{
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->CallFunc(n++);
}

BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//AfxMessageBox(_T("ready?"));
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage()
{
	int nWidth = 4096*8;
	int nHeight = 4096*8;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	//0부터 2^8승 크기의 숫자 unsigned char 메모리에 byte(=8bit) 단위로	접근하거나, 문자에 접근하는 경우 unsigned char를 사용
	memset(fm, 0xff, nWidth*nHeight);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	DrawData(&dc);
}


void CDlgImage::DrawData(CDC* pDC)
{
	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, COLOR_RED);
	CPen* pOldPen = pDC->SelectObject(&pen);

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(1, 1);
		pDC->Ellipse(rect);
	}

	pDC->SelectObject(pOldPen);
}