// MyBoleDoc.h : interface of the CMyBoleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBOLEDOC_H__A298BCC6_534F_451D_A5D5_7156A890850D__INCLUDED_)
#define AFX_MYBOLEDOC_H__A298BCC6_534F_451D_A5D5_7156A890850D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyBoleDoc : public CDocument
{
protected: // create from serialization only
	CMyBoleDoc();
	DECLARE_DYNCREATE(CMyBoleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyBoleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyBoleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyBoleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBOLEDOC_H__A298BCC6_534F_451D_A5D5_7156A890850D__INCLUDED_)
