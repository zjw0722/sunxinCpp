// MyBole.h : main header file for the MYBOLE application
//

#if !defined(AFX_MYBOLE_H__B96615E7_67B1_4071_965D_CDC4CD6E941B__INCLUDED_)
#define AFX_MYBOLE_H__B96615E7_67B1_4071_965D_CDC4CD6E941B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyBoleApp:
// See MyBole.cpp for the implementation of this class
//

class CMyBoleApp : public CWinApp
{
public:
	CMyBoleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyBoleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyBoleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBOLE_H__B96615E7_67B1_4071_965D_CDC4CD6E941B__INCLUDED_)
