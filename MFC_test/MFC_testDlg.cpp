
// MFC_testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_test.h"
#include "MFC_testDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMFC_testDlg �Ի���



CMFC_testDlg::CMFC_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_testDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOW, m_winShow);
	DDX_Control(pDX, IDC_STATIC_SHOW_REMOTE, m_winShowRemote);
}

BEGIN_MESSAGE_MAP(CMFC_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_testDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_testDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_testDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFC_testDlg ��Ϣ�������

BOOL CMFC_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CFile file(TEXT("MFCfile.mpg"), CFile::modeWrite | CFile::typeBinary | CFile::modeCreate);

static void msg_cb(MyMSG* msg, void* userdata)
{
	file.Write(msg->body.sample.buf, msg->body.sample.len);
}

void CMFC_testDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	cc_userinfo_t info;
	strcpy(info.ip, "120.199.202.36");
	//strcpy(info.ip, "192.168.1.101");
	info.port = 5566;
#ifdef DEBUG
	info.userid = 104;
#else
	info.userid = 103;
#endif
	info.roomid = 24;
	startpreview(m_winShow.GetSafeHwnd(), 1, &info, 0, NULL);
	setmsgcallback(this, OnMsg);
	//startcapture(NULL, NULL, NULL);
	//setmsgcallback(0, msg_cb);
	//startpreview(m_winShow.GetSafeHwnd(), 1, 0, NULL);
	//startremotepreview("192.168.1.101", 0, 0, 0);
}


void CMFC_testDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	stoppreview(NULL, NULL);
	//stopremotepreview(1, 0, 0);
	//resizewindow();
	//stopsendsample(0, 0);
}


void CMFC_testDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//setmsgcallback(this, OnMsg);
	//startremotepreview(3, m_winShowRemote.GetSafeHwnd(), 0, 0);
	//startcapture(NULL, NULL, NULL);
	startsendsample(0, 0);
}

void CMFC_testDlg::OnMsg(MyMSG* msg, void* userdata)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMFC_testDlg* dlg = (CMFC_testDlg*)userdata;
	switch (msg->code){
	case CODE_NEWUSER:
		dlg->do_newuser(msg);
		break;
	case CODE_USERLOGOUT:
		dlg->do_userlogout(msg);
		break;
	case CODE_SOCKETERROR:
		dlg->do_socket_error(msg);
		break;
	default:
		break;
	}
}

void CMFC_testDlg::do_newuser(MyMSG* msg)
{
	startcapture(NULL, NULL, NULL);
	startremotepreview(msg->body.userinfo.userid, m_winShowRemote.GetSafeHwnd(), 0, 0);
}

void CMFC_testDlg::do_userlogout(MyMSG* msg)
{
	AfxMessageBox(_T("received user logout!"));
	stopremotepreview(msg->body.userinfo.userid, 0, 0);
}

void CMFC_testDlg::do_socket_error(MyMSG* msg)
{
	AfxMessageBox(_T("received error!"));
	stoppreview(NULL, NULL);
	stopremotepreview(msg->body.userinfo.userid, 0, 0);
}
