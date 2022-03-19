#include "../eng/Game.h"
#include "../debugTools/debug.h"
#include "../eng/Input.h"
#include "../eng/Rand.h"
#include <ctime>
#include <stdlib.h>

using namespace eng;

void eng::Game::Update()
{
    /*for (size_t i = 0; i < rainsAmount; i++)
    {
        rains[i].setPosition(rains[i].getPosition().x, rains[i].getPosition().y + vlocity.y);
        m_window->draw(rains[i]);
        if (rains[i].getPosition().y > m_window->getSize().y) {
            rains[i].setPosition(
                (float)eng::Rand::randInt(1,
                    (float)m_window->getSize().x),
                0 - Rand::randInt(rains[i].getSize().y, 21)
            );
        }
    }
    */

    m_manger->Update();
}

void eng::Game::Start()
{
    vlocity.y = 4;
    /*for (size_t i = 0; i < rainsAmount; i++)
    {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(4, Rand::randInt(5 , 15)));
        shape.setPosition(
            (float)eng::Rand::randInt(1 , 
            (float)m_window->getSize().x) , 
            (float)eng::Rand::randInt(0,
            (float)m_window->getSize().y)
            );
        int randInt = Rand::randInt(0, 7);
        if(randInt == 1) shape.setFillColor(sf::Color::Magenta);
        else if(randInt == 2) shape.setFillColor(sf::Color::Red);
        else if(randInt == 3) shape.setFillColor(sf::Color::Green);
        else if(randInt == 4) shape.setFillColor(sf::Color::Blue);
        else if(randInt == 5) shape.setFillColor(sf::Color::Cyan);
        else if(randInt == 6) shape.setFillColor(sf::Color::Yellow);
        else shape.setFillColor(sf::Color::White);
        rains[i] = shape;
    }*/
    m_manger->Start();
}

void eng::Game::Init()
{
    m_window = new  sf::RenderWindow(sf::VideoMode(m_windowW, m_windowH), m_title);
    m_manger = new ObjectManer(&getWindow());
}

void eng::Game::run(uint8_t fpsLimit)
{
    // init
    srand((unsigned)time(NULL));
    ImGui::SFML::Init(getWindow());
    sf::Clock deltaClock;
    getWindow().setFramerateLimit(fpsLimit);
    // end init
    Start();
    while (getWindow().isOpen())
    {
        sf::Event event;
        while (getWindow().pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                getWindow().close();
        }
        ImGui::SFML::Update(getWindow(), deltaClock.restart());
        ImGui::Begin("Rect properties");
        ImGui::SliderInt("Velocity Y", &vlocity.y ,1 , 10);
        ImGui::End();
        getWindow().clear(sf::Color::Black); // Color background
        Update();
        m_manger->Draw();
        ImGui::SFML::Render(getWindow());
        getWindow().display();
    }
    
    ImGui::SFML::Shutdown();
	}
