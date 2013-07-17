// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMICHELPER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMICHELPER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMICHELPER_EXPORTS
#define COMICHELPER_API __declspec(dllexport)
#else
#define COMICHELPER_API __declspec(dllimport)
#endif

extern COMICHELPER_API BOOL SetApiHook(HWND hWndFilter, COLORREF clrDisabled = RGB(127, 127, 127));
extern COMICHELPER_API BOOL SetApiUnHook();

extern COMICHELPER_API BOOL UnHookApi();