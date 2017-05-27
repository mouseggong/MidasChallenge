
// MidasUMLDoc.h : CMidasUMLDoc Ŭ������ �������̽�
//


#pragma once

#include "Class.h"
#include "Association.h"

class CMidasUMLDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMidasUMLDoc();
	DECLARE_DYNCREATE(CMidasUMLDoc)

// Ư���Դϴ�.
private:
	std::vector<Class> classes;
	std::vector<Association> associations;
	int key;
public:
	Class getClass(int id) { return classes[id]; }
	Class getAssociationClass(int key);
	void addClass(CString name, POINT point, std::vector<Var> var, std::vector<Function> function);
	void deleteClass(int id) {
		classes.erase(classes.begin() + id);
		SetModifiedFlag();
	}
	int getSize() { return classes.size(); }

	Association getAssociation(int id) { return associations[id]; }
	void addAssociation(int mainkey, int subKey, ASSOCIATION_TYPE at);
	void deleteAssociation(int id) { 
		associations.erase(associations.begin() + id);
		SetModifiedFlag();
	}
	int getAssocSize() { return associations.size(); }
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
