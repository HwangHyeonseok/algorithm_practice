// Win32API_Lecture_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32_MovingSquare.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// APIENTRY,_In_ => _~_은 약속된 주석 키워드 (SAL) , 데이터가 이 함수에 입력된다는 의미 | _In_opt_ => 딱히 필요 없는데 들어온 부가적인 데이터다.
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 실행된 프로세스의 시작 주소를 저장하는 변수
    _In_opt_ HINSTANCE hPrevInstance, //[이전 ver에서는 사용했었으나 지금 ver에서는 의미 없음] hPrevInstance 변수는 이전에 실행된 프로세스의 시작 주소 (이전에 킨 그림판 메모리 주소)
    _In_ LPWSTR    lpCmdLine, // Cmd 추가 명령어를 문자열 주소를 받아오는 변수 (게임에서는 크게 의미 없음)
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // 아무 의미 없는 코드 (참조 되지 않는 변수라는 것을 알려줌)
    UNREFERENCED_PARAMETER(lpCmdLine); // 아무 의미 없는 코드 (참조 되지 않는 변수라는 것을 알려줌)

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // 윈도우 창 제목 값 세팅 (szTitle 변수 => 제목 이름)
    LoadStringW(hInstance, IDC_WIN32MOVINGSQUARE, szWindowClass, MAX_LOADSTRING); // 창의 키 값을 세팅
    MyRegisterClass(hInstance); // 윈도우 정보 등록 (윈도우를 어떤 형식으로 띄울지 정보를 세팅한다.)

    // 윈도우 생성 (MyRegisterClass(hInstance) 에서 등록한 정보대로 윈도우를 생성시킨다.)
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE; // 윈도우 생성에 실패했다면 main 함수를 종료한다. (예외처리)
    }
    // 단축키 테이블 정보 로딩 (단축키 테이블에 담아놓는 변수 hAccelTable) | (리소스 뷰 -> Accelerator)
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32MOVINGSQUARE));

    MSG msg; // 메세지 구조체 변수 (메세지 정보들을 담는 통)
    // ex ) msg.message / msg.hwnd 등...

    // 핸들? (hwnd) => [아이디 값을 받아오는 자료형] window(hwnd 윈도우 관련 id값을 가져오는 자료형), device context(hdc 그리기 관련 id값을 받아오는 자료형), pen(hpen), brush(hbrush)
    // 프로시저? => 메시지가 발생한 윈도우의 소유하고 있는 함수가 메시지에 대한 역할을 하는데 이를 프로시저(처리기) 함수라고 한다.
    // (= 이벤트가 발생하면 처리해주는 함수 = 프로시저 함수)

    //GetMessage 함수 특징 
    // 메세지 큐에서 메시지를 확인할 때까지 대기 (메시지가 들어올 때까지 기다린다. 메시지가 들어오지 않으면 GetMessage의 반환값은 존재하지 않는다.) 
    // GetMessage 함수의 반환값이 false를 반환할 때 => msg.message == WM_QUIT 이 발생했을 때 ==> 프로그램 종료
    while (GetMessage(&msg, nullptr, 0, 0)) // 해당 프로그램에 발생하는 메시지들이 메시지 큐에 담겨 있을텐데 그 메세지들을 꺼내는 작업
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // hAccelTable 단축키 정보를 불러와서 단축키를 눌렀는지 검사해주는 곳
        {
            TranslateMessage(&msg); // 메시지 분석
            DispatchMessage(&msg); // 메시지를 발생시킨 윈도우의 관련 처리기(프로시저 함수) 쪽으로 보낸다.
        }
    }

    return (int)msg.wParam; // 윈도우 프로그램이 종료된다.
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//  용도 : 윈도우 정보 등록 (윈도우를 어떤 형식으로 띄울지 정보를 세팅한다.)
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex; // 윈도우에 대한 정보를 담는 클래스 변수 선언

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc; // 메시지가 발생한 윈도우에 대한 함수의 주소값을 세팅한다.
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WIN32MOVINGSQUARE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32MOVINGSQUARE);
    wcex.lpszClassName = szWindowClass; // 창의 키 값 등록
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) // 윈도우 생성 함수
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, // 윈도우의 고유의 ID를 반환해서 hWnd 변수로 전달
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow); // 윈도우를 보이게/보이지 않게 해주는 함수
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM) - 프로시저 함수
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

POINT g_ptObjpos = { 500, 300 }; // POINT는 그냥 정수 두 개 있는 구조체이다. 접근은 g_ptObjpos.x , g_ptObjpos.y 이런식으로 접근
POINT g_ptObjscale = { 100, 100 };

// 어떤 윈도우 메시지냐에 따라서 케이스를 나누어서 메시지를 처리해준다. [윈도우 프로시저 함수]
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// message : 메시지 값(이벤트 값, 무슨 이벤트인지) // hWnd : 윈도우 핸들 (아이디 값, 메시지(이벤트)가 어느 윈도우에서 발생했는지)
// wParam, IParam : message의 부가 인자값, 즉, 메시지를 부연 설명(키를 누르는 것 관련 메시지(message) -> 마우스 좌표 정보 lParam, 어떤 키가 눌렸는지 정보 wParam)
{
    switch (message) // 윈도우 메시지(이벤트)에 따라 처리가 다르다.
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam); // 윈도우 기본 프로시저(처리기)로 처리
        }
    }
    break;

    case WM_KEYDOWN: // 아무 키가 눌렸을 때(메시지) 최초 1회 바로 실행 + 1초 후 연속적으로 누르면 쭉 실행
    {
        switch (wParam) // 어떤 키를 눌렀느냐의 값이 wParam에 들어감 (메시지를 부연 설명해주는 매개변수)
        {
        case VK_UP: // 위(↑)키를 누르면
            g_ptObjpos.y -= 10;
            InvalidateRect(hWnd, NULL, true); // 무효화 영역을 내가 임의로 정한다. (갱신할 윈도우 핸들 값, 갱신하고 싶은 영역 좌표, 이전 그린 영역 삭제할지 여부) 
            break;

        case VK_DOWN: // 아래(↓)키를 누르면
            g_ptObjpos.y += 10;
            InvalidateRect(hWnd, NULL, true);
            break;

        case VK_RIGHT: // 오른쪽(→)키를 누르면
            g_ptObjpos.x += 10;
            InvalidateRect(hWnd, NULL, true);
            break;

        case VK_LEFT: // 왼쪽(←)키를 누르면
            g_ptObjpos.x -= 10;
            InvalidateRect(hWnd, NULL, true);
            break;

        case 'W': // W 키를 누르면 (case 'w': 는 작동이 안됨)
            break;
        }
    }

    break;

    case WM_LBUTTONDOWN: // 마우스 왼쪽 버튼을 눌렸을 때 ( LParam 자료형은 마우스 좌표, wParam 자료형에는 어떤 키를 눌렀는지가 들어감 )
    {
        LOWORD(lParam); // 마우스 x좌표
        HIWORD(lParam); // 마우스 y좌표
    }

    case WM_PAINT: // 무효화 영역(Invalidate)이 발생한 경우
    { // case 문 안에 지역 변수를 만들고 싶다면 중괄호로 묶어주어야 된다.
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);         // BeginPaint 함수는 Device Context 만들어서 id를 hdc 변수에 넘겨주는 함수이다. (목적지 : hWnd의 값)
        // Device Context(dc) : 그리기 작업을 수행하기 위해 필요한 데이타의 집합이다.(미술 주머니) (펜 정보 hpen,브러쉬 정보 hbrush 등등)
        // DC의 목적지는 hWnd
        // DC의 기본 펜 색은 (Black)
        // DC의 기본 브러쉬 색은 (White)
        // 
        //직접 펜을 만들어서 DC에 지급 (브러쉬도 가능)
        HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // 직접 펜을 만들어서 hRedPen 변수에 저장
        HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));

        // 기본 펜 ID 값을 받아 둔다.
        HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen); // dc 오브젝트에게 hRedPen을 선택하라고 쥐어주는데,
        // hDefaultPen 변수에 반환되어 들어오는 값은 바뀌고 이제는 dc 오브젝트가 쥐고 있지 않은 펜 값이 반환되어 hDefaultPen 변수에 저장된다. (검정색)
        HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hGreenBrush);

        // 변경된 펜을 가지고 사각형을 그린다.
        //Rectangle(hdc, 0, 0, 150, 150); // 사각형 그리기 함수 | hdc에서 아이디값을 가져와서 거기에 그림을 그린다.
        Rectangle(hdc, g_ptObjpos.x - g_ptObjscale.x / 2, g_ptObjpos.y - g_ptObjscale.y / 2,
            g_ptObjpos.x + g_ptObjscale.x / 2, g_ptObjpos.y + g_ptObjscale.y / 2);

        // DC 의 펜을 원래 펜으로 되돌린다.
        SelectObject(hdc, hDefaultPen);
        SelectObject(hdc, hDefaultBrush);

        // 다 쓴 Red펜을 삭제 요청한다.
        DeleteObject(hRedPen);
        DeleteObject(hGreenBrush);

        // 그리기 종료
        EndPaint(hWnd, &ps);
        break;

        //hbrush hredbrush = createsolidbrush( rgb(255, 0, 0) ); // 빨강색 브러쉬를 만들어서 dc에 저장한다.
        //hbrush hdefaultbrush = (hbrush) selectobject(hdc, hredbrush); // 기본 브러쉬의 id 값을 받아놓는다.
        //selectobject(hdc, hdefaultbrush); // dc의 브러쉬를 디폴트 브러쉬로 돌려놓는다.
        //deleteobject(hdefaultbrush); // 다 쓴 브러쉬를 삭제 요청한다.

    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam); // 윈도우 기본 프로시저(처리기)로 처리
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
//