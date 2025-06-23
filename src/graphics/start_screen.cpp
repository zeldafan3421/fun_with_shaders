#include "graphics/start_screen.h"

StartScreen::StartScreen()
    : Screen(MainScreen::Create()), 
    m_ContinueKey(KEY_ENTER),
    m_TextPosition{20.0f, 20.0f},
    m_TextFontSize(30),
    m_TextColor(BLACK)
{
    DisableCursor();

    TraceLog(LOG_DEBUG, "Loading start screen.");
    TraceLog(LOG_DEBUG, "Start Screen size : %llu bytes", sizeof(*this));
}

void StartScreen::Update()
{
    if (IsKeyPressed(m_ContinueKey))
        m_Finished = true;
    
}

void StartScreen::Draw()
{
    DrawText(
        c_StartMessage,
        static_cast<int>(m_TextPosition.x), 
        static_cast<int>(m_TextPosition.y),
        m_TextFontSize, 
        m_TextColor
    );
}

std::unique_ptr<Screen> StartScreen::Create()
{
    return std::make_unique<StartScreen>();
}

StartScreen::~StartScreen()
{
    TraceLog(LOG_DEBUG, "Unloading start screen.");
}