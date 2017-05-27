
// MidasUMLDoc.cpp : CMidasUMLDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MidasUML.h"
#endif

#include "MidasUMLDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMidasUMLDoc

IMPLEMENT_DYNCREATE(CMidasUMLDoc, CDocument)

BEGIN_MESSAGE_MAP(CMidasUMLDoc, CDocument)
END_MESSAGE_MAP()


// CMidasUMLDoc ����/�Ҹ�

CMidasUMLDoc::CMidasUMLDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	key = 0;
}

CMidasUMLDoc::~CMidasUMLDoc()
{
}

BOOL CMidasUMLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}


// CMidasUMLDoc serialization

void CMidasUMLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

void CMidasUMLDoc::addClass(CString name, POINT point, std::vector<Var> var, std::vector<Function> function)
{
	classes.push_back(Class(name, point, var, function, key));
	key++;
	UpdateAllViews(NULL);
}

Class CMidasUMLDoc::getAssociationClass(int key)
{
	for (int i = 0;i < classes.size();i++) {
		if (key == classes[i].getKey()) return classes[i];
	}
}

void CMidasUMLDoc::addAssociation(int mainkey, int subKey, ASSOCIATION_TYPE at)
{
	associations.push_back(Association(at, mainkey, subKey));
	UpdateAllViews(NULL);
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMidasUMLDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMidasUMLDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMidasUMLDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMidasUMLDoc ����

#ifdef _DEBUG
void CMidasUMLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMidasUMLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

