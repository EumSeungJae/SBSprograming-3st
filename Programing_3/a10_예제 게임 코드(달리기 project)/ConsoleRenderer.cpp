
#include "ConsoleRenderer.h"
#include <cstdio>
#include <cstdarg>

ConsoleRenderer::ConsoleRenderer(int width, int height)
    : m_nScreenIndex(0), m_width(width), m_height(height) {
    Init();
}

ConsoleRenderer::~ConsoleRenderer() {
    CloseHandle(m_hScreen[0]);
    CloseHandle(m_hScreen[1]);
}

void ConsoleRenderer::Init() {
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;

    for (int i = 0; i < 2; ++i) {
        m_hScreen[i] = CreateConsoleScreenBuffer(
            GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleCursorInfo(m_hScreen[i], &cci);

        // 버퍼 사이즈 설정 (선택 사항)
        COORD size = { static_cast<SHORT>(m_width), static_cast<SHORT>(m_height) };
        SetConsoleScreenBufferSize(m_hScreen[i], size);
    }
}

void ConsoleRenderer::Clear() {
    COORD coor = { 0, 0 };
    DWORD dw;
    // 설정된 너비와 높이만큼 공백으로 채움
    FillConsoleOutputCharacter(m_hScreen[m_nScreenIndex], ' ', m_width * m_height, coor, &dw);
}

void ConsoleRenderer::Flipping() {
    SetConsoleActiveScreenBuffer(m_hScreen[m_nScreenIndex]);
    m_nScreenIndex = !m_nScreenIndex;
}

void ConsoleRenderer::Print(int x, int y, const std::string& str) {
    DWORD dw;
    COORD cursorPosition = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(m_hScreen[m_nScreenIndex], cursorPosition);
    WriteFile(m_hScreen[m_nScreenIndex], str.c_str(), static_cast<DWORD>(str.length()), &dw, NULL);
}

void ConsoleRenderer::Printf(int x, int y, const char* format, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, format, args);
    va_end(args);

    Print(x, y, buffer);
}

