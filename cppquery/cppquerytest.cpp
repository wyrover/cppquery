// cppquery.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "cppquerytest.h"
#include "api/cppquery.h"
using namespace cppquery;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text

void demo_dialog_get_int_values(HINSTANCE, HWND);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);

    static WindowFrontPeer::MessageHandle about_handles[] = {
        WindowFrontPeer::Command(IDOK, MK_FUNC(FUNC(EndDialog), _1, 0)),
        WindowFrontPeer::Command(IDCANCEL, MK_FUNC(FUNC(EndDialog), _1, 0)),
        NULL,
    };
	
    Window window = Window::Create(hInstance, 0, 0, 0, 600, 400, szTitle, WS_OVERLAPPEDWINDOW);

    window.loadMenu(hInstance, MAKEINTRESOURCE(IDC_CPPQUERY))
        .onCommand(IDM_EXIT, BIND(DestroyWindow, window.hwnd()))
        .onDestroy(BIND(PostQuitMessage, 0))
        .onCommand(IDM_ABOUT, BIND(DoDialogModel,hInstance, window.hwnd(), IDD_ABOUTBOX, about_handles))
        //for demos
        //for dialog demos
        .onCommand(ID_DIALOG_GETINTVALUES, BIND(demo_dialog_get_int_values, hInstance, window.hwnd()))
        //end demos
        .show(nCmdShow)
        .update()
        .doModel();          
}

