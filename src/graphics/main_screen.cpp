#include "graphics/main_screen.h"

MainScreen::MainScreen()
    : Screen(m_NullScreen),
      m_Camera(GetCameraDefaultSettings())
{
    constexpr float c_SideLength = 1.0f;
    SearchAndSetResourceDir("resources");
}

void MainScreen::LoadScreenData(const float c_SideLength)
{
    m_CubeMesh = GenMeshCube(c_SideLength, c_SideLength, c_SideLength);

    m_InstancingMaterial = LoadMaterialDefault();
    m_InstancingMaterial.maps[MATERIAL_MAP_ALBEDO].color = BLUE;
    m_InstancingShader = LoadShader("shader.vs", "shader.fs");
    m_InstancingMaterial.shader = m_InstancingShader;

    constexpr int transformCount = 1000;
    m_Transforms.reserve(transformCount);

    for (int i = 0; i < transformCount; i++)
    {
        Vector3 rand = {
            ((float)GetRandomValue(-500, 500)) / 10.0f,
            ((float)GetRandomValue(-500, 500)) / 10.0f,
            ((float)GetRandomValue(-500, 500)) / 10.0f,
        };

        m_Transforms.push_back(MatrixTranslate(rand.x, rand.y, rand.z));
    }

}
void MainScreen::Update()
{
    int timeLoc = GetShaderLocation(m_InstancingShader, "time");

    float time =  (float)GetTime();
    SetShaderValue(m_InstancingShader, timeLoc, &time, SHADER_UNIFORM_FLOAT);

    UpdateCamera(&m_Camera, CAMERA_ORBITAL);
}

void MainScreen::Draw()
{
    BeginMode3D(m_Camera);
    DrawGrid(10, 1.0f);

    DrawMeshInstanced(
        m_CubeMesh, m_InstancingMaterial, m_Transforms.data(), m_Transforms.size()
    );
    EndMode3D();
}

MainScreen::~MainScreen()
{
    UnloadMesh(m_CubeMesh);
    UnloadMaterial(m_InstancingMaterial);
}