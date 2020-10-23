#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch(msg)
	{
	case WM_CLOSE:
		PostQuitMessage(97);
		break;
	case WM_KEYDOWN:
		if(wParam == 'F')
		{
			SetWindowText(hWnd, "F Pressed");
		}
		break;
	case WM_KEYUP:
		if(wParam == 'F')
		{
			SetWindowText(hWnd, "F Released");
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = "Hardware3D";

	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	// create window instance
	HWND hWnd = CreateWindowEx(0, pClassName, "Happy Hardware Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		1200, 200, 640, 480, 
		nullptr, nullptr, hInstance, nullptr
	);

	// show window
	ShowWindow(hWnd, SW_SHOW);

	// message pump
	MSG msg;
	BOOL gResult;
	
	while((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	return msg.wParam;
}
