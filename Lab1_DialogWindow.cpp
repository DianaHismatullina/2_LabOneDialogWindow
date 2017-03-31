#include <stdio.h>
#include <Windows.h>
#include "resource.h"
#include "stdafx"
#include <math.h>


BOOL CALLBACK DialogFun(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	char Text[128];
	double S1, S2, h, V;
	switch (message)
	{
	case WM_COMMAND:
		switch (message)
		{
		case WM_INITDIALOG:
			return TRUE;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDOK:
			case IDCANCEL:
				EndDialog(hwnd, 0);
				return TRUE;
			case IDC_BUTTON1:
			case IDC_CHECK1:
				SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 127, (LPARAM)Text);
				if (sscanf(Text, "%lf", &S1)<1)
				{
					MessageBox(hwnd,"Error:", "Invalid value of the first parameter", MB_OK | MB_ICONHAND);
					SendDlgItemMessage(hwnd, IDC_EDIT1, WM_SETTEXT, 0, (LPARAM)"");
					return TRUE;
				}

				SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 127, (LPARAM)Text);
				if (sscanf(Text, "%lf", &S2)<1)
				{
					MessageBox(hwnd, "Error:", "Invalid value of the second parameter", MB_OK | MB_ICONHAND);
					SendDlgItemMessage(hwnd, IDC_EDIT2, WM_SETTEXT, 0, (LPARAM)"");
					return TRUE;
				}
				SendDlgItemMessage(hwnd, IDC_EDIT3, WM_GETTEXT, 100, (LPARAM)Text);
				if (sscanf(Text, "%lf", &h)<1)
				{
					MessageBox(hwnd, "Error:", "Invalid value of the third parameter", MB_OK | MB_ICONHAND);
					SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)"");
					return TRUE;
				}
				V = 1./3*h*(S1+sqrt(S1*S2)+S2);
				sprintf(Text, "%lf", V);
				SendDlgItemMessage(hwnd, IDC_EDIT4, WM_SETTEXT, 0, (LPARAM)Text);
			}
		}
		return FALSE;
	}
	int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
	{
		DialogBox(hIns, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogFun);
		return 0;
	}

