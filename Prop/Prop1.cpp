// Prop1.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop1.h"
#include "PropSheet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProp1 property page

IMPLEMENT_DYNCREATE(CProp1, CPropertyPage)

CProp1::CProp1() : CPropertyPage(CProp1::IDD)
{
	//{{AFX_DATA_INIT(CProp1)
	m_occuption = -1;
	m_workAddr = _T("");
	//}}AFX_DATA_INIT
}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProp1)
	DDX_Radio(pDX, IDC_RADIO1, m_occuption);
	DDX_LBString(pDX, IDC_LIST1, m_workAddr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
	//{{AFX_MSG_MAP(CProp1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProp1 message handlers

BOOL CProp1::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropSheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

LRESULT CProp1::OnWizardNext() // 返回0进入下一页面，返回-1阻止进入下一页面
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData();
	if(m_occuption == -1)
	{
		MessageBox("请选择你的职业！");
		return -1;
	}
	if(m_workAddr == "")
	{
		MessageBox("请选择你的工作地点！");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}

BOOL CProp1::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("北京");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("上海");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("深圳");
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
