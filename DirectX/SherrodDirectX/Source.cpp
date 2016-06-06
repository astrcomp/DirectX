#include"Header.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR cmdLine, int CMDshow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	WNDCLASSEX wndClass = { sizeof(wndClass),CS_HREDRAW | CS_VREDRAW,WndProc,0,0,hInstance,NULL,LoadCursor(NULL,IDC_ARROW),(HBRUSH)(COLOR_WINDOW + 1),NULL,"Dx11" };
	RegisterClassEx(&wndClass);
	RECT rc = {0,0,640,480};
	AdjustWindowRect(&rc, WS_OVERLAPPED, FALSE);
	HWND hwnd = CreateWindowA("Dx11", "Blank Win32", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, CMDshow);

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//UPDATE
			//Draw
		}
	}

	return static_cast <int> (msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT paintStruct;
	HDC hDC;

	switch (msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &paintStruct);
		EndPaint(hWnd, &paintStruct);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}