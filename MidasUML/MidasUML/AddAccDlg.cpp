// AddAccDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MidasUML.h"
#include "AddAccDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "MidasUMLDoc.h"
#include "MidasUMLView.h"

// CAddAccDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddAccDlg, CDialogEx)

CAddAccDlg::CAddAccDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_ACCOS, pParent)
{

}

CAddAccDlg::~CAddAccDlg()
{
}

void CAddAccDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_mainBox);
	DDX_Control(pDX, IDC_COMBO2, m_subBox);
	DDX_Control(pDX, IDC_COMBO3, m_accBox);
}


BEGIN_MESSAGE_MAP(CAddAccDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddAccDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddAccDlg �޽��� ó�����Դϴ�.


BOOL CAddAccDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_accBox.AddString(_T("���"));
	m_accBox.AddString(_T("����"));
	m_accBox.SetCurSel(0);

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CChildFrame *pChild = (CChildFrame *)pFrame->GetActiveFrame();
	CMidasUMLDoc *pDoc = (CMidasUMLDoc *)pChild->GetActiveDocument();

	for (int i = 0;i < pDoc->getSize();i++) {
		CString name = pDoc->getClass(i).getName();
		m_mainBox.AddString(name);
		m_subBox.AddString(name);
	}
	m_mainBox.SetCurSel(0);
	m_subBox.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CAddAccDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
	UpdateData(TRUE);
	int mainId = m_mainBox.GetCurSel();
	int subId = m_subBox.GetCurSel();

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CChildFrame *pChild = (CChildFrame *)pFrame->GetActiveFrame();
	CMidasUMLDoc *pDoc = (CMidasUMLDoc *)pChild->GetActiveDocument();

	int mainKey = pDoc->getClass(mainId).getKey();
	int subKey = pDoc->getClass(subId).getKey();
	ASSOCIATION_TYPE at = (ASSOCIATION_TYPE)m_accBox.GetCurSel();

	pDoc->addAssociation(mainKey, subKey, at);
}
