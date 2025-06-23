#include "graphics/main_screen.h"

MainScreen::MainScreen()
    : Screen(std::make_unique<NullScreen>()),
    m_Camera(GetCameraDefaultSettings()),
    m_Cube(GenDefaultCube()),
    m_Sphere(GenMeshSphere(1.0f, 10, 10)),
    m_CubeInstances(),
    m_SphereInstances()
{  
    TraceLog(LOG_DEBUG, "Loading main screen.");
    TraceLog(LOG_DEBUG, "Main Screen size : %llu bytes", sizeof(*this));

    class : public Builder<Matrix>
    {
    public:
        Matrix Build() override
        {
            return m_Current;
        }

        void Reset() override
        {
            m_Current = MatrixIdentity();
            m_Current *= MatrixTranslate(
                Random::GetRandomFloat(5.0f),
                Random::GetRandomFloat(5.0f),
                Random::GetRandomFloat(5.0f)
            );
        }
    private:
        Matrix m_Current;
    } m_Builder;

    m_CubeInstances = Instances(
        c_InstanceCount, 
        m_Cube, 
        m_Builder
    );

    m_Cube.SetMaterialColor(BLUE);
    m_Sphere.SetMaterialColor(PINK);
}

void MainScreen::Update()
{
    m_CubeInstances.Update();
    UpdateCamera(&m_Camera, CAMERA_FREE);
}

void MainScreen::Draw()
{
    constexpr float c_GridSpacing = 1.0f;
    constexpr int c_GridSlices = 10;

    BeginMode3D(m_Camera);
        DrawGrid(10, 1.0f);
        m_CubeInstances.Draw();
        m_SphereInstances.Draw();
        DrawGrid(c_GridSlices, c_GridSpacing);
    EndMode3D();

#if defined(DEBUG)
    DrawFPS(10, 10);
#endif
}

MainScreen::~MainScreen()
{
    TraceLog(LOG_DEBUG, "Unloading main screen.");
}
