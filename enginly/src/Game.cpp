#include "../eng/Game.h"
#include "../debugTools/debug.h"
#include "../eng/Input.h"
#include "../eng/Rand.h"
#include "../eng/Time.h"

#include <ctime>
#include <stdlib.h>
#include <sstream>
#include "json.hpp"

using namespace eng;

std::vector <std::string>  eng::split_str(const std::string& str, const char delim)
{
    // create a stream from the string  
    std::vector <std::string> out;
    std::stringstream s(str);

    std::string s2;
    while (std::getline(s, s2, delim))
    {
        out.push_back(s2); // store the string in s2  
    }
    return out;
}

void eng::Game::Update()
{
    m_manger->Update(deltaTime);
}

void eng::Game::Start()
{
    if (OutSideLoop) {
        (m_outSideStart)();
    }
    m_manger->Start();
}

void eng::Game::Init()
{
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowW, m_windowH), m_title);
    m_manger = new ObjectManager(&getWindow());
}

void eng::Game::run()
{
    // init
    eng::Rand::SetSeed((unsigned)time(NULL));
    ImGui::SFML::Init(getWindow());

    //delta time calculation
    sf::Clock deltaClock_Imgui;
    sf::Clock deltaClock;
    sf::Clock FixedTimeclock;

    float time[2] = { 0.f , 0.f };


    // end init
    Start();
#ifdef __DEBUG__
    int deltaTimeArrayIndex = 0;
    constexpr int deltaTimeArraySize = 100;
    float deltaTimeGraph[deltaTimeArraySize];

#endif // __DEBUG__
    //TODO: Add Lowest FPS Saver
    //TODO: Add Console

    while (getWindow().isOpen())
    {
        if (FixedTimeclock.getElapsedTime().asSeconds() > 1 / 300) {
           //TODO : add FIXED_Update
           //m_manger->();

        }

        sf::Event event;
        while (getWindow().pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                getWindow().close();
        }

        ImGui::SFML::Update(getWindow(), deltaClock_Imgui.restart());
        getWindow().clear(sf::Color::Black); // Color background
        time[1] = deltaClock.getElapsedTime().asSeconds();
        float fps = (1.f / ( time[1] - time[0]));
        deltaTime = (time[1] - time[0]);
        Update();
#ifdef __DEBUG__
        // Delta time Graph
        if (!(deltaTimeArrayIndex >= deltaTimeArraySize)) deltaTimeGraph[deltaTimeArrayIndex] = deltaTime;
        else deltaTimeArrayIndex = 0;
        deltaTimeArrayIndex++;
        

        ImGui::BeginMainMenuBar();

        if (ImGui::BeginMenu("Performances")) {
            ImGui::Text("FPS: %d" , (int)(1.f / (time[1] - time[0])));
            ImGui::Text("DeltaTime: %f", deltaTime);
            ImGui::PlotLines("Delta Time graph:", deltaTimeGraph , IM_ARRAYSIZE(deltaTimeGraph));
            ImGui::Text("Objects Amount: %d", m_manger->ObjectsAmount());
            ImGui::EndMenu();
        }
#ifdef _WIN64
//#include "windows.h"
//#include "psapi.h"
            //DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
            //ImGui::Text


#endif //_WIN64

        ImGui::EndMainMenuBar();
#endif // __DEBUG__
        if (OutSideLoop) {
            (m_outSideDraw)(m_window);
        }
        ImGui::SFML::Render(getWindow());
        getWindow().display();
        time[0] = time[1];
    }    
}


eng::Game::~Game()
{
    getWindow().close();
    ImGui::SFML::Shutdown();
    delete m_manger;
    delete m_window;
}
