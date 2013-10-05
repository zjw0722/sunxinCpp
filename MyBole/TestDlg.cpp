// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyBole.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	m_num1 = 0;
	m_num2 = 0;
	m_num3 = 0;
	//}}AFX_DATA_INIT
	m_bisCreate = FALSE;
}


void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDV_MinMaxInt(pDX, m_num1, 10, 100);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDV_MinMaxInt(pDX, m_num2, 10, 100);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_NUMBER1, OnNumber1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

void CTestDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
/*	static BOOL bisCreate = False; // 相应的后面改为bisCreate
	if(m_bisCreate == FALSE)
	{
		m_btn.Create("维新", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, 
		CRect(0, 0, 100, 100), this, 123);
		m_bisCreate = TRUE;
	}
	else
	{
		m_btn.DestroyWindow();
		m_bisCreate = FALSE;
	}
*/
/*	动态创建按钮
	if(!m_btn.m_hWnd)
	{
		m_btn.Create("维新", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, 
			CRect(0, 0, 30, 20), this, 123);
	}
	else
	{
		m_btn.DestroyWindow();
	}
*/
	// 实现编辑框1+编辑框2送到编辑框3中去。
	int num1, num2, num3;
	char ch1[10] = "", ch2[10] = "", ch3[10] = "";

/*	// 访问控件方法1
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 10);
	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	itoa(num3, ch3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3); */

/*	// 访问控件方法2
	GetDlgItemText(IDC_EDIT1, ch1, 10);
	// GetDlgItemText相当于GetDlgItem()->GetWindowText();
	GetDlgItemText(IDC_EDIT2, ch2, 10);
	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	itoa(num3, ch3, 10);
	SetDlgItemText(IDC_EDIT3, ch3); */

/*	// 访问控件方法3
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);

	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3); */

/*	// 访问控件方法4   定义成员变量
	UpdateData();
	m_num3 = m_num1 + m_num2;
	UpdateData(false); */

/*	// 访问控件的方法5  定义控件变量
	m_edit1.GetWindowText(ch1, 10);
	m_edit2.GetWindowText(ch2, 10);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	itoa(num3, ch3, 10);

	m_edit3.SetWindowText(ch3); */

/*	// 访问控件的第六种方法
	// 前面加上::表示这是SDK的函数。
	//::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//::SendMessage(m_edit1.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	GetDlgItem(IDC_EDIT1)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit1.SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit2.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	
	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	itoa(num3, ch3, 10);

	m_edit3.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3); */

	// 访问控件的第七种方法
	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	itoa(num3, ch3, 10);

	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
	// 给子控件发送消息
	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1);
	// 设定选定的文本，第三个参数表示开始位置，第四个参数表示结束位置。
	m_edit3.SetFocus();
	// 将焦点转移到编辑框3
}

void CTestDlg::OnNumber1() 
{
	// TODO: Add your control notification handler code here

	CString str;
	if(GetDlgItem(IDC_NUMBER1)->GetWindowText(str), str == "Number1")
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowText("数值1");
	}
	else
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowText("Number1");
	}
}

void CTestDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString str;
	if(GetDlgItemText(IDC_BUTTON2, str), str == "收缩<<")
	{
		SetDlgItemText(IDC_BUTTON2, "扩展>>");
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, "收缩<<");
	}

	static CRect rectLarge;
	// 静态的，创建之后直到程序结束被销毁
	static CRect rectSmall;

	if(rectLarge.IsRectNull())
	{
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		// 获取对话框的尺寸
		GetDlgItem(IDC_SEPARTOR)->GetWindowRect(&rectSeparator);
		// 获取分隔符的尺寸

		rectSmall.left = rectLarge.left;
		rectSmall.top = rectLarge.top;
		rectSmall.right = rectLarge.right;
		rectSmall.bottom = rectSeparator.bottom;
	}
	if(str == "收缩<<")
	{
		SetWindowPos(NULL, 0, 0, rectSmall.Width(), rectSmall.Height(), 
			SWP_NOMOVE | SWP_NOZORDER);
	}
	else
	{
		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), 
			SWP_NOMOVE | SWP_NOZORDER);
	}
}

void CTestDlg::OnOK() 
{
	// TODO: Add extra validation here
	// 先获取当前具有焦点的窗口的指针，再根据这个指针来转移焦点到下一个窗口
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();
	//GetFocus()->GetNextWindow()->SetFocus();
	//GetFocus()->GetWindow(GW_HWNDNEXT)->SetFocus();
	GetNextDlgTabItem(GetFocus())->SetFocus();
	//CDialog::OnOK();

}
// 记录先前的窗口过程
WNDPROC prevProc;
// 写新的窗口过程
LRESULT CALLBACK WinSunProc(
							HWND hwnd,      // handle to window
							UINT uMsg,      // message identifier
							WPARAM wParam,  // first message parameter
							LPARAM lParam   // second message parameter
)
{
	// 传给窗口过程的第一个参数就是属于该窗口的句柄
	if(uMsg == WM_CHAR && wParam == 0x0d)
	{
		//::SetFocus(::GetNextWindow(hwnd, GW_HWNDNEXT));
		// 另外一个获取窗口句柄的方法
		//::SetFocus(::GetWindow(hwnd, GW_HWNDNEXT));
		// 第三种获取句柄的方法
		::SetFocus(::GetNextDlgTabItem(::GetParent(hwnd), hwnd, FALSE));
		
		return 1;
	}
	else
	{
		return prevProc(hwnd, uMsg, wParam, lParam);
	}
}

// 窗口创建完成各种控件之后被调用
BOOL CTestDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	// 更改窗口的默认窗口过程函数
	prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, 
		(LONG)WinSunProc);
	
	// 函数名可以表示函数代码的入口地址
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
