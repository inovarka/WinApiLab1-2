#include "framework.h"
#include "Module1.h"
#include "resource1.h"
#include "Lab1.h"
#include <string>
#pragma warning(disable : 4996)
//#include "Lab1.cpp"

static int pos = 1;
char buffer[4];





//Callback-функція вікна
static BOOL CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	
	
	SetScrollRange(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, 1, 100, TRUE);

	switch (iMessage) {
	case WM_INITDIALOG:
		sprintf(buffer, "%d", pos);
		
		SetDlgItemText(hDlg, IDC_TEXT1, buffer);

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL) {
			flag = FALSE;
			EndDialog(hDlg, 0);
			break;
		}

		if (LOWORD(wParam) == IDOK) {
			flag = true;
			InvalidateRect(FindWindow(NULL, "Lab1"), NULL, TRUE);
			UpdateWindow(FindWindow(NULL, "Lab1"));
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}

	case WM_HSCROLL:
		pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL);
		switch (LOWORD(wParam)) {
		case SB_LINELEFT:
			pos--;
			break;
		case SB_LINERIGHT:
			pos++;
			break;
		case SB_THUMBPOSITION: //фіксована позиція повзуна
		case SB_THUMBTRACK: //поточна позиція повзуна
			pos = HIWORD(wParam);
			break;
		}
		SetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, pos, TRUE);
		result = pos;
		sprintf(buffer, "%d", result);
								  
		SetDlgItemText(hDlg, IDC_TEXT1, buffer);
		break;
	default: break;
	}
	return FALSE;
}


int Func_MOD1(HINSTANCE hInst, HWND hWnd )
{
	
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}


