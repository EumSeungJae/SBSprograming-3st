
#pragma once
#include <Windows.h>
#include <string>

class ConsoleRenderer {
private:
    HANDLE m_hScreen[2];
    int m_nScreenIndex;
    int m_width;
    int m_height;

public:
    ConsoleRenderer(int width = 80, int height = 25);
    ~ConsoleRenderer();

    void Clear();
    void Flipping();
    void Print(int x, int y, const std::string& str);

    // 편의를 위한 가변 인자 출력 (printf 스타일)
    void Printf(int x, int y, const char* format, ...);

private:
    void Init();
};
