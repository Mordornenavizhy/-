
// laba2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "laba2.h"
#include "laba2Dlg.h"
#include "afxdialogex.h"
#include "CalculatingMetod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно Claba2Dlg



Claba2Dlg::Claba2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LABA2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Claba2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_MethodSlider);  // Исправлено на IDC_SLIDER1
}

BEGIN_MESSAGE_MAP(Claba2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Claba2Dlg::OnClickedButton1)
	
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Claba2Dlg::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// Обработчики сообщений Claba2Dlg

BOOL Claba2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	m_MethodSlider.SetRange(0, 3); 
	m_MethodSlider.SetPos(0);      
	m_MethodSlider.SetTicFreq(1);  
	m_nSelectedMethod = 0;         

	// Инициализация списка
	CListCtrl* listIntegral = (CListCtrl*)GetDlgItem(IDC_LIST1);
	CRect rect;
	listIntegral->GetClientRect(rect);
	listIntegral->InsertColumn(0, L"Метод", 0, rect.Width() / 2);
	listIntegral->InsertColumn(1, L"Ответ", 0, rect.Width() / 2);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Claba2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Claba2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Claba2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Claba2Dlg::OnClickedButton1()
{
	CalculatingMetod m;
	CString msg;
	CListCtrl* listIntegral = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int nitem;

	double result = 0.0;
	CString methodName;

	switch (m_nSelectedMethod) {
	case 0:
		result = m.metodNewton();
		methodName = L"Метод Ньютона";
		break;
	case 1:
		result = m.metodIteraciy();
		methodName = L"Метод Итераций";
		break;
	case 2:
		result = m.metodHord();
		methodName = L"Метод Хорд";
		break;
	case 3:
		result = m.metodDihotomii();
		methodName = L"Метод Дихотомии";
		break;
	default:
		return;
	}

	if (_isnan(result)) {
		msg = L"Корень не найден";
	}
	else {
		msg.Format(L"%.6f", result);
	}

	nitem = listIntegral->InsertItem(0, methodName);
	listIntegral->SetItemText(nitem, 1, msg);
}

void Claba2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar && pScrollBar->GetDlgCtrlID() == IDC_SLIDER1)
	{
		m_nSelectedMethod = m_MethodSlider.GetPos();
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void Claba2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}
