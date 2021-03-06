// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "SetupMakerHelper.h"
extern HMODULE g_hModule;
extern BOOL g_bNeedHook;
//extern DWORD g_dwSetupPID;

#include <atlfile.h>
//#include "../SetupMakerHelperProxy/SetupMakerHelperProxy.h"
#include <ftlSystem.h>

//struct SetupFileMonitorInfo
//{
//    DWORD dwSetupFilePID;
//};
//SetupFileMonitorInfo    g_SetupFileMonitorInfo;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        {
            DisableThreadLibraryCalls((HINSTANCE)hModule);
            TCHAR szModuleName[MAX_PATH] = {0};
            GetModuleFileName(NULL, szModuleName, _countof(szModuleName));
            LPCTSTR pszFileName = PathFindFileName(szModuleName);
            if (pszFileName)
            {
                FTLTRACE(TEXT("DllMain in SetupMakerHelper[%s], ul_reason_for_call=%d\n"), 
                    pszFileName, ul_reason_for_call);

                //HRESULT hr = E_FAIL;

                //CAtlFileMapping<ProtectWndInfoFileMap32> fileMap;
                //COM_VERIFY_EXCEPT1(fileMap.OpenMapping(COMIC_PROTECT_WND_FILE_MAP_NAME, 
                //    sizeof(ProtectWndInfoFileMap32), 0, FILE_MAP_READ), 0x80070002);
                //if (SUCCEEDED(hr))
                {
                    //ProtectWndInfoFileMap32* pProtectWndInfoFileMap = (ProtectWndInfoFileMap32*)fileMap.GetData();
                    //if (pProtectWndInfoFileMap)
                    {
                        //FTLTRACE(TEXT("pProtectWndInfoFileMap->dwSetupFilePID=%d, CurPID=%d\n"),
                        //    pProtectWndInfoFileMap->dwSetupFilePID, GetCurrentProcessId());
                        BOOL bWillHook = (g_dwSetupPID == GetCurrentProcessId());
                        if (!bWillHook)
                        {
                            //check parent PID
                            DWORD dwParentPid = CFSystemUtil::GetParentProcessId(GetCurrentProcessId(), TRUE);
                            while (dwParentPid != (DWORD)(-1))
                            {
                                if (dwParentPid == g_dwSetupPID)
                                {
                                    bWillHook = TRUE;
                                    break;
                                }
                                dwParentPid = CFSystemUtil::GetParentProcessId(dwParentPid);
                            }
                        }
                        
                        if (bWillHook
                            //StrStrI(pszFileName, TEXT("HookTargetDemo.exe")) != NULL
                            //|| StrStrI(szModuleName, TEXT("NComic.exe")) != NULL
                            )
                        {
                            FTLTRACE(TEXT(">>> Will Hook %s\n"), pszFileName);
                            g_bNeedHook = TRUE;
                        }
                    }
                }
            }
        }
		g_hModule = hModule;
		break;
	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		UnHookApi();
		break;
	}
	return TRUE;
}

