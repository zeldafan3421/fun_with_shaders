#include "graphics/start_screen.h"

StartScreen::StartScreen()
    : Screen(m_MainScreen)
{
}

void StartScreen::Update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        m_Finished = true;
    }
}

void StartScreen::Draw()
{
    DrawText("Press enter to continue.", 10, 10, 20, BLACK);
}