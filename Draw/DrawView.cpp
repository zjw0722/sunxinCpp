// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
	m_stringin = 0;
	m_bDraw = FALSE;
	m_ptOld = 0;
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptOld = m_stringin = point;
	m_bDraw = TRUE;
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw = FALSE;
	// TODO: Add your message handler code here and/or call default
// 	HDC hdc;
// 	hdc = ::GetDC(m_hWnd);
// 	MoveToEx(hdc, m_stringin.x, m_stringin.y, NULL);
// 	LineTo(hdc, point.x, point.y);
// 	::ReleaseDC(m_hWnd, hdc);

// 	CDC *pCdc = GetDC();
// 	pCdc->MoveTo(m_stringin);
// 	pCdc->LineTo(point);
// 	ReleaseDC(pCdc);

// 	CClientDC dc(this);
// //	CClientDC dc(GetParent());
// 	dc.MoveTo(m_stringin);
// 	dc.LineTo(point);

/*	CWindowDC dc(this);*/
// 	CWindowDC dc(GetDesktopWindow());
// 	dc.MoveTo(m_stringin);
// 	dc.LineTo(point);
	// 画笔
// 	CPen pen(PS_DOT, 1, RGB(0, 255, 0));
// 	CClientDC dc(this);
// 	CPen *pOldPen = dc.SelectObject(&pen);
// 	dc.MoveTo(m_stringin);
// 	dc.LineTo(point);
// 	dc.SelectObject(pOldPen);
	// 画刷
// 	CBrush brush(RGB(255, 0, 0));
// 	CClientDC dc(this);
// 	dc.FillRect(CRect(m_stringin, point), &brush);
	// 用位图填充
// 	CBitmap bitmap;
// 	bitmap.LoadBitmap(IDB_BITMAP1);
// 	CBrush brush(&bitmap);
// 	CClientDC dc(this);
// 	dc.FillRect(CRect(m_stringin, point), &brush);
	// 创建透明画刷
// 	CClientDC dc(this);
// 	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
// 	CBrush *pOldBrush = dc.SelectObject(pBrush);
// 	dc.Rectangle(CRect(m_stringin, point));
// 	dc.SelectObject(pOldBrush);
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *OldPen = dc.SelectObject(&pen);

	if(m_bDraw == TRUE)
	{
		dc.SetROP2(R2_BLACK);
		// 画连续线条
// 		dc.MoveTo(m_ptOld);
// 		dc.LineTo(point);
		// 画扇形
// 		dc.MoveTo(m_stringin);
// 		dc.LineTo(point);
		// 画带有边线的扇形
		dc.MoveTo(m_stringin);
		dc.LineTo(m_ptOld);
		dc.MoveTo(m_ptOld);
		dc.LineTo(point);

		m_ptOld = point;
	}
	dc.SelectObject(OldPen);
	CView::OnMouseMove(nFlags, point);
}
