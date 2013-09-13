// MenuView.cpp : implementation of the CMenuView class
//

#include "stdafx.h"
#include "Menu.h"

#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuView

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	//{{AFX_MSG_MAP(CMenuView)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_SHOW, OnShow)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuView construction/destruction

CMenuView::CMenuView()
{
	// TODO: add construction code here

}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView drawing

void CMenuView::OnDraw(CDC* pDC)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView printing

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView diagnostics

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuView message handlers

//DEL void CMenuView::OnTest() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	MessageBox("View clicked");
//DEL }

void CMenuView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
//	if(2 == pCmdUI->m_nIndex) // 根据索引判断
	if(ID_EDIT_CUT == pCmdUI->m_nID) // 注意索引和id的差别
		pCmdUI->Enable();
}

void CMenuView::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
//	if(ID_FILE_NEW == pCmdUI->m_nID) // 保存了关联菜单的id
//		pCmdUI->Enable(FALSE);
//	if(ID_FILE_NEW == pCmdUI->m_nIndex) // 保存了关联菜单的索引
//		pCmdUI->Enable(FALSE);
	
}

void CMenuView::OnRButtonDown(UINT nFlags, CPoint point)  // point 得到的是客户区的坐标，而不是屏幕坐标
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu *pPopup = menu.GetSubMenu(0);
	ClientToScreen(&point); // 将客户区坐标转变为屏幕坐标
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, GetParent());
	CView::OnRButtonDown(nFlags, point);
}

//DEL void CMenuView::OnShow() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	MessageBox("MainView show");
//DEL }

void CMenuView::OnShow() 
{
	// TODO: Add your command handler code here
	MessageBox("View show");
}
