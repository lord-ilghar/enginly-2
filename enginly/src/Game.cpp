#include "../eng/Game.h"
#include "../debugTools/debug.h"
#include "../eng/Input.h"
#include "../eng/Rand.h"
#include "../eng/Time.h"

#include <ctime>
#include <stdlib.h>

using namespace eng;

void eng::Game::Update()
{
    m_manger->Update(deltaTime);
}

void eng::Game::Start()
{
    m_manger->Start();
}

void eng::Game::Init()
{
    m_window = new  sf::RenderWindow(sf::VideoMode(m_windowW, m_windowH), m_title);
    m_manger = new ObjectManer(&getWindow());
}

void eng::Game::run()
{
    // init
    srand((unsigned)time(NULL));
    ImGui::SFML::Init(getWindow());

    //delta time calculation
    sf::Clock deltaClock_Imgui;
    sf::Clock deltaClock;
    float time[2] = { 0.f , 0.f };

    // showing fps
    sf::Font f;
    sf::Text fpsText;
    sf::RectangleShape textBack;

    if (!f.loadFromFile("C:/Users/HP/Downloads/Compressed/imgui-master/imgui-master/misc/fonts/Roboto-Medium.ttf")) throw;
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(0, 0);
    fpsText.setCharacterSize(20);
    fpsText.setFont(f);
    textBack.setFillColor(sf::Color::Black);


    // end init
    Start();
    while (getWindow().isOpen())
    {
    textBack.setPosition(fpsText.getGlobalBounds().left, fpsText.getGlobalBounds().top);
    textBack.setSize(sf::Vector2f(
        fpsText.getGlobalBounds().width,
        fpsText.getGlobalBounds().height));
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
        fpsText.setString("FPS:" + std::to_string((int)fps));
        deltaTime = (time[1] - time[0]);

        Update();
        m_manger->Draw();
        getWindow().draw(textBack);
        getWindow().draw(fpsText);
        ImGui::SFML::Render(getWindow());
        getWindow().display();
        time[0] = time[1];
    }
    
    ImGui::SFML::Shutdown();
	}
