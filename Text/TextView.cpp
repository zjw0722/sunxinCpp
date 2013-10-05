// TextView.cpp : implementation of the CTextView class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	//{{AFX_MSG_MAP(CTextView)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView construction/destruction

CTextView::CTextView()
{
	// TODO: add construction code here
	m_strline = "";
	m_ptOrigin = 0;
	m_nWidth = 0;
	// 记得一定要初始化
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//CString str("维新科学技术培训中心");
	CString str = "维新科学技术培训中心";
	pDC->TextOut(50, 50, str);
	
	CSize sz = pDC->GetTextExtent(str);// 获取字符串在屏幕中占得宽度

	str.LoadString(IDS_WEIXIN);	
	pDC->TextOut(0, 200, str);

	pDC->BeginPath(); // 路径层

	pDC->Rectangle(50, 50, 50 + sz.cx, 50 + sz.cy);

	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);
	for(int i = 0; i < 300;i += 10)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(300, i);

		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 300);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTextView printing

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers

int CTextView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetOutputTextMetrics(&tm);

	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);

	// 以位图作为光标
	//bitmap.LoadBitmap(IDB_BITMAP2);
	//CreateCaret(&bitmap);
	ShowCaret();

	// 设置定时器
	SetTimer(1, 100, NULL);
	return 0;
}

void CTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	// 创建字体
	CFont font;
	font.CreatePointFont(300, "仿宋", NULL);
	CFont *pOldFont = dc.SelectObject(&font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	// 处理回车键
	if(0x0d == nChar)
	{
		m_strline.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
	// 处理退格键
	else if(0x08 == nChar)
	{	// 把字体的颜色设置为背景色，重新输出字符
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strline);
		m_strline = m_strline.Left(m_strline.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	// 普通字符
	else
	{
		m_strline += nChar;
	}
	// 使光标跟随输入一起移动
	CSize sz = dc.GetTextExtent(m_strline);

	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;

	SetCaretPos(pt);

	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strline);
	dc.SelectObject(pOldFont); // 更改会原来的字体
	CView::OnChar(nChar, nRepCnt, nFlags);
	

}

void CTextView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point);
	m_strline.Empty();
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}

void CTextView::OnTimer(UINT nIDEvent) // 可以根据nIDEvent来判断是哪个定时器的消息
{
	// TODO: Add your message handler code here and/or call default
	m_nWidth += 5;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadString(IDS_WEIXIN);
	dc.DrawText(str, &rect, DT_LEFT);

	rect.top = 150;
	rect.bottom = rect.top + tm.tmHeight;
	dc.DrawText(str, &rect, DT_RIGHT);

	CSize sz = dc.GetTextExtent(str);
	if(m_nWidth > sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0, 255, 0));
		dc.TextOut(0, 200, str);
	}
	CView::OnTimer(nIDEvent);
}
