
// MidasUMLDoc.h : CMidasUMLDoc Ŭ������ �������̽�
//


#pragma once

#include "Class.h"
class CMidasUMLDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMidasUMLDoc();
	DECLARE_DYNCREATE(CMidasUMLDoc)

// Ư���Դϴ�.
private:
	std::vector<Class> classes;
public:
	Class getClass(int id) { return classes[id]; }
	Class getClass(CString string);
	void addClass(CString name, POINT point, std::vector<Var> var, std::vector<Function> function) {
		classes.push_back(Class(name, point,var,function));
		UpdateAllViews(NULL);
	}
	void deleteClass(int id) {
		classes.erase(classes.begin() + id);
	}
	int getSize() { return classes.size(); }
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMidasUMLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
};
