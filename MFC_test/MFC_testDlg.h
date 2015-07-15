
// MFC_testDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_testDlg �Ի���
class CMFC_testDlg : public CDialogEx
{
// ����
public:
	CMFC_testDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	void do_newuser(MyMSG* msg);
	void do_socket_error(MyMSG* msg);
	void do_userlogout(MyMSG* msg);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// show window
	CStatic m_winShow;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	static void OnMsg(MyMSG* msg, void* userdata);
	CStatic m_winShowRemote;
};
