// MyBoleView.cpp : implementation of the CMyBoleView class
//

#include "stdafx.h"
#include "MyBole.h"

#include "MyBoleDoc.h"
#include "MyBoleView.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView

IMPLEMENT_DYNCREATE(CMyBoleView, CView)

BEGIN_MESSAGE_MAP(CMyBoleView, CView)
	//{{AFX_MSG_MAP(CMyBoleView)
	ON_COMMAND(IDM_DIG, OnDig)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView construction/destruction

CMyBoleView::CMyBoleView()
{
	// TODO: add construction code here

}

CMyBoleView::~CMyBoleView()
{
}

BOOL CMyBoleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView drawing

void CMyBoleView::OnDraw(CDC* pDC)
{
	CMyBoleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView printing

BOOL CMyBoleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyBoleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyBoleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView diagnostics

#ifdef _DEBUG
void CMyBoleView::AssertValid() const
{
	CView::AssertValid();
}

void CMyBoleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyBoleDoc* CMyBoleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBoleDoc)));
	return (CMyBoleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyBoleView message handlers

void CMyBoleView::OnDig() 
{
	// TODO: Add your command handler code here
	CTestDlg dlg;
	dlg.DoModal();

/*	CTestDlg *pDlg = new CTestDlg();
	pDlg->Create(IDD_DIALOG1, this);
	pDlg->ShowWindow(SW_SHOW);
*/
 }
