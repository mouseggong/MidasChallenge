#pragma once
#include "afxwin.h"


// CAddAccDlg ��ȭ �����Դϴ�.

class CAddAccDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAccDlg)

public:
	CAddAccDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddAccDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_ACCOS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_mainBox;
	CComboBox m_subBox;
	CComboBox m_accBox;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
