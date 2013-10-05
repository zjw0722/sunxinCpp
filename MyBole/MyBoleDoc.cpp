// MyBoleDoc.cpp : implementation of the CMyBoleDoc class
//

#include "stdafx.h"
#include "MyBole.h"

#include "MyBoleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyBoleDoc

IMPLEMENT_DYNCREATE(CMyBoleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyBoleDoc, CDocument)
	//{{AFX_MSG_MAP(CMyBoleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyBoleDoc construction/destruction

CMyBoleDoc::CMyBoleDoc()
{
	// TODO: add one-time construction code here

}

CMyBoleDoc::~CMyBoleDoc()
{
}

BOOL CMyBoleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyBoleDoc serialization

void CMyBoleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyBoleDoc diagnostics

#ifdef _DEBUG
void CMyBoleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyBoleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyBoleDoc commands
