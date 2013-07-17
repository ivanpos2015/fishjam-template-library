// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../ComicService/ComicService_i.h"

class CMainDlg : public CDialogImpl<CMainDlg>
{
public:
	CMainDlg();

	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)

		COMMAND_ID_HANDLER_EX(IDC_BTN_INIT_SERVICE, OnBtnInitService)
		COMMAND_ID_HANDLER_EX(IDC_BTN_SERVICE_HOOK, OnBtnServiceHook)
		COMMAND_ID_HANDLER_EX(IDC_BTN_SERVICE_UNHOOK, OnBtnServiceUnHook)
		COMMAND_ID_HANDLER_EX(IDC_BTN_FIN_SERVICE, OnBtnFinService)

		COMMAND_ID_HANDLER_EX(IDC_BTN_DLL_HOOK, OnBtnDllHook)
		COMMAND_ID_HANDLER_EX(IDC_BTN_DLL_UNHOOK, OnBtnDllUnHook)

		MSG_WM_DESTROY(OnDestroy)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	void OnBtnInitService(UINT uNotifyCode, int nID, CWindow wndCtl);
	void OnBtnServiceHook(UINT uNotifyCode, int nID, CWindow wndCtl);
	void OnBtnServiceUnHook(UINT uNotifyCode, int nID, CWindow wndCtl);
	void OnBtnFinService(UINT uNotifyCode, int nID, CWindow wndCtl);

	void OnBtnDllHook(UINT uNotifyCode, int nID, CWindow wndCtl);
	void OnBtnDllUnHook(UINT uNotifyCode, int nID, CWindow wndCtl);

	void OnDestroy();
private:
	CComPtr<IComicServiceObj>	m_spComicService;
	BOOL	m_bHookInDll;
};