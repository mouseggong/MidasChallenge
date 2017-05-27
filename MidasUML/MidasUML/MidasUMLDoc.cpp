
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
	key = 0;
	std::vector<Class> temp_class;
	classes = temp_class;
	std::vector<Association> temp_assoc;
	associations = temp_assoc;
	return TRUE;
}


// CMidasUMLDoc serialization

void CMidasUMLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << key;
		int classSize = classes.size();
		ar << classSize;
		for (int i = 0;i < classSize;i++)
			classes[i].Serialize(ar);
		int assocSize = associations.size();
		ar << assocSize;
		for (int i = 0;i < assocSize;i++)
			associations[i].Serialize(ar);
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> key;
		int class_size;
		ar >> class_size;
		
		std::vector<Class> temp_class(class_size);
		classes = temp_class;
		for (int i = 0;i < class_size;i++) {
		/*	Class _class;
			_class.Serialize(ar);
			classes.push_back(_class);*/
			classes[i].Serialize(ar);
		}
		int associations_size;
		ar >> associations_size;
		std::vector<Association> temp_accos(associations_size);
		associations = temp_accos;
		for (int i = 0;i < associations_size;i++) {
			/*Association assoc;
			assoc.Serialize(ar);
			associations.push_back(assoc);*/
			associations[i].Serialize(ar);
		}
	}
}

void CMidasUMLDoc::addClass(CString name, POINT point, std::vector<Var> var, std::vector<Function> function)
{
	classes.push_back(Class(name, point, var, function, key));
	key++;
	UpdateAllViews(NULL);
	SetModifiedFlag();
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
	SetModifiedFlag();
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

