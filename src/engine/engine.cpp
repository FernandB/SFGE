/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include <engine/engine.h>
#include <engine/scene.h>
#include <graphics/graphics.h>
#include <input/input.h>
#include <python/python_engine.h>
#include <engine/config.h>
#include <audio/audio.h>
#include <engine/editor.h>
#include <graphics/sprite.h>
#include <engine/log.h>


namespace sfge
{


void Engine::Init(bool windowless)
{
	m_GraphicsManager = std::make_shared<GraphicsManager>(windowless);
	m_AudioManager = std::make_shared<AudioManager>();
	m_SceneManager = std::make_shared<SceneManager>();
	m_InputManager = std::make_shared<InputManager>();
	m_PythonManager = std::make_shared<PythonManager>();
	m_Editor = std::make_shared<Editor>();
	modules =
	{
		std::dynamic_pointer_cast<Module>(m_GraphicsManager),
		std::dynamic_pointer_cast<Module>(m_AudioManager),
		std::dynamic_pointer_cast<Module>(m_InputManager),
		std::dynamic_pointer_cast<Module>(m_PythonManager),
		std::dynamic_pointer_cast<Module>(m_SceneManager),
		std::dynamic_pointer_cast<Module>(m_Editor)
	};
	m_Config = std::move(Configuration::LoadConfig());
	
	for (auto module : modules)
	{	
		module->Init();
	}

	m_Window = m_GraphicsManager->GetWindow();
	running = true;


}

void Engine::Start()
{
	sf::Clock clock;
	while (running)
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
			{
				running = false;
				m_Window->close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::E)
				{

				}
			}
		}
		m_InputManager->Update(dt);
		m_PythonManager->Update(dt);
		m_GraphicsManager->Update(dt);
	}
	for (auto module : modules)
	{
		module->Destroy();
	}
}

Engine::~Engine()
{
}

std::shared_ptr<Configuration> Engine::GetConfig()
{
	return m_Config;
}

std::shared_ptr<Module> Engine::GetModule(EngineModule engineModule)
{
	return modules[(int)engineModule];
}

Module::Module() 
{
}


}