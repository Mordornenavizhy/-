



#pragma once



class Claba2Dlg : public CDialogEx
{

public:
	Claba2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABA2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


private:
	
	CSliderCtrl m_MethodSlider;  // Изменил на объект вместо указателя
	int m_nSelectedMethod;
protected:
	HICON m_hIcon;

	
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	afx_msg void OnClickedButton1();
	CComboBox kakoi_metod;
	
	CSliderCtrl m_pMetodBySlider;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
};
