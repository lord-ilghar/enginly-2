#pragma once
#include <iostream>
#include <imgui.h>
#ifdef __DEBUG__

#define CPRINT(x) std::cout << x << '\n'
#define CERR(x) std::cout << "[ERROR] [on-line]: " << __LINE__ << " [MESSAGE]: " << x << '\n' << "Press Any Key to Continue ..."; std::getchar()
#define SHOWSTR(x) ImGui::Begin("debug"); ImGui::Text(x); ImGui::End()
#define SHOWINT(x) ImGui::Begin("debug"); ImGui::Text((const char*)x); ImGui::End()

#endif // __DEBUG__
