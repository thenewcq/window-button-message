#include <windows.h>

#define ID_BUTTON1 1     // I could just put the number 1 or 2 in the create window instead of this
#define ID_BUTTON2 2

// didn't use a prototype foe WindowProc, WinMain is below
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch(msg)
	{
		case WM_CREATE:
		{
			CreateWindow(TEXT("BUTTON"),TEXT("button 1"), WS_CHILD | WS_VISIBLE, 10,10,80,20,
			hwnd, (HMENU) ID_BUTTON1, NULL, NULL);

			CreateWindow(TEXT("BUTTON"),TEXT("button 2"), WS_CHILD | WS_VISIBLE, 10,40,80,20,
			hwnd, (HMENU) ID_BUTTON2, NULL, NULL);

			break;
		}

		case WM_COMMAND:

		if( LOWORD(wParam) == 1)
		{
			MessageBox(hwnd,"You pressed button #1","Button 1",MB_OK | MB_ICONINFORMATION);
		}

		if( LOWORD(wParam) == 2)
		{
			MessageBox(hwnd,"You pressed button #2","Button 2",MB_OK | MB_ICONINFORMATION);
		}

		break;

		case WM_DESTROY:
		PostQuitMessage(0);
		break;

		default:
		return DefWindowProcW( hwnd,msg,wParam,lParam);
	}

	return 0;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR lpCmdLine, int nCmdShow)
{
   
	WNDCLASSW wc = {0};

	wc.lpfnWndProc   = WindowProc;
	wc.hInstance     = hInstance;
	wc.lpszClassName =  L"Sample Window Class";
//	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
//wc.hbrBackground =(HBRUSH)GetStockObject(4);
wc.hbrBackground =(HBRUSH)(COLOR_BACKGROUND+2);
//wc.hbrBackground =(HBRUSH)(COLOR_WINDOWFRAME+1);
//wc.hbrBackground =(HBRUSH)(COLOR_BTNTEXT+2);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassW(&wc);

	HWND hwnd = CreateWindowW(L"Sample Window Class", L"Window With Buttons", WS_OVERLAPPEDWINDOW,   CW_USEDEFAULT, 
		CW_USEDEFAULT, 500,500,  NULL,  NULL, hInstance, NULL );

	if (hwnd == NULL)
	{
		 return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {0};

	while( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}
