// MenuDoc.cpp : CMenuDoc 类的实现
//

#include "stdafx.h"
#include "Menu.h"

#include "MenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenuDoc

IMPLEMENT_DYNCREATE(CMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenuDoc, CDocument)
END_MESSAGE_MAP()


// CMenuDoc 构造/析构

CMenuDoc::CMenuDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMenuDoc::~CMenuDoc()
{
}

BOOL CMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMenuDoc 序列化

void CMenuDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMenuDoc 诊断

#ifdef _DEBUG
void CMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMenuDoc 命令
