#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "Class.h"
// CAddDlg ��ȭ �����Դϴ�.

class CAddDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_varAcc;
	CComboBox m_funcAcc;
	virtual BOOL OnInitDialog();
	CString m_name;
	CString m_varName;
	CString m_varType;
	CString m_funcName;
	CString m_funcParam;
	CString m_funcType;
	CListBox m_varAccessLIST;
	CListBox m_varNameList;
	CListBox m_varTypeList;
	afx_msg void OnBnClickedVarButton();
	afx_msg void OnBnClickedButton2();
	CListBox m_funcAccList;
	CListBox m_funcNameList;
	CListBox m_funcParamList;
	CListBox m_funcTypeList;
	afx_msg void OnBnClickedOk();

	POINT m_point;
};
