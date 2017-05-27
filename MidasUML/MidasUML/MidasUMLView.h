
// MidasUMLView.h : CMidasUMLView Ŭ������ �������̽�
//

#pragma once

#include "Class.h"
#include "AddDlg.h"
#include "AddAccDlg.h"

class CMidasUMLView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMidasUMLView();
	DECLARE_DYNCREATE(CMidasUMLView)

// Ư���Դϴ�.
public:
	CMidasUMLDoc* GetDocument() const;
	POINT m_point;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMidasUMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddClass();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnAddAccos();
	afx_msg void OnButtonBmpSave();
};

#ifndef _DEBUG  // MidasUMLView.cpp�� ����� ����
inline CMidasUMLDoc* CMidasUMLView::GetDocument() const
   { return reinterpret_cast<CMidasUMLDoc*>(m_pDocument); }
#endif

