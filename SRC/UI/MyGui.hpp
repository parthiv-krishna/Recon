#pragma once

//System Includes
#include <tuple>
#include <vector>

//Eigen Includes
#include "../../../eigen/Eigen/Core"

//External Includes
#include "../HandyImGuiInclude.hpp"

//Project Includes
#include "../Colormaps.hpp"
#include "../Journal.h"

namespace MyGui {
	class DummyButtonStyle {
		public:
			ImExt::Style m_style;
			
			DummyButtonStyle() {
				Math::Vector4 dummyButtonColor = ImGui::GetStyle().Colors[ImGuiCol_Button];
				dummyButtonColor.x = 0.3f*dummyButtonColor.x + 0.2f;
				dummyButtonColor.y = 0.3f*dummyButtonColor.y + 0.2f;
				dummyButtonColor.z = 0.3f*dummyButtonColor.z + 0.2f;
				m_style(StyleCol::Button,        dummyButtonColor);
				m_style(StyleCol::ButtonHovered, dummyButtonColor);
				m_style(StyleCol::ButtonActive,  dummyButtonColor);
			}
	};

	class RedButtonStyle {
		public:
			ImExt::Style m_style;
			
			RedButtonStyle() {
				m_style(StyleCol::Button,        Math::Vector4(0.9f, 0.2f, 0.2f, 1.0f));
				m_style(StyleCol::ButtonHovered, Math::Vector4(1.0f, 0.3f, 0.3f, 1.0f));
				m_style(StyleCol::ButtonActive,  Math::Vector4(1.0f, 0.4f, 0.4f, 1.0f));
			}
	};
	
	//A non-selectable label with a header-colored background
	inline void HeaderLabel(const char * UnformattedText) {
		//Draw Queue Label with a header-colored background
		auto style = ImGui::GetStyle();
		ImDrawList * draw_list = ImGui::GetWindowDrawList();
		Math::Vector2 CursorStartPos = ImGui::GetCursorScreenPos();
		float availWidth = ImGui::GetContentRegionAvail().x;
		float xWinPadding = style.WindowPadding.x;
		Math::Vector2 RectULCorner = CursorStartPos - Math::Vector2(xWinPadding, 0.0f);
		Math::Vector2 RectLRCorner = CursorStartPos + Math::Vector2(availWidth + xWinPadding, ImGui::GetFontSize() + 2.0f*style.ItemInnerSpacing.y);
		draw_list->AddRectFilled(RectULCorner, RectLRCorner, ImColor(style.Colors[ImGuiCol_Header]), 0.0f);
		ImGui::SetCursorScreenPos(CursorStartPos + style.ItemInnerSpacing);
		ImGui::TextUnformatted(UnformattedText);
		ImGui::SetCursorScreenPos(Math::Vector2(CursorStartPos.x, RectLRCorner.y + style.ItemSpacing.y));
	}
	
	//Version of BeginMenu() that has a column for icons
	inline bool BeginMenu(const char* txticon, float XMargin, const char* label, bool enabled = true) {
		Math::Vector2 curPos = ImGui::GetCursorScreenPos();
		std::string spaces((size_t)std::ceil(XMargin / ImGui::CalcTextSize(" ").x), ' ');
		spaces += std::string(label);
		ImDrawList * winDrawList = ImGui::GetWindowDrawList();
		bool ret = ImGui::BeginMenu(spaces.c_str(), enabled);
		winDrawList->AddText(curPos, ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), txticon);
		return ret;
	}
	
	//Version of MenuItem() that has a column for icons
	inline bool MenuItem(const char* txticon, float XMargin, const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true) {
		Math::Vector2 curPos = ImGui::GetCursorScreenPos();
		std::string spaces((size_t)std::ceil(XMargin / ImGui::CalcTextSize(" ").x), ' ');
		spaces += std::string(label);
		bool ret = ImGui::MenuItem(spaces.c_str(), shortcut, selected, enabled);
		ImGui::GetWindowDrawList()->AddText(curPos, ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), txticon);
		return ret;
	}
	
	//Add text to Draw list with support for centering in X and/or Y
	inline void AddText(ImDrawList * DrawList, ImVec2 const & pos, ImU32 col, const char * text_begin, const char* text_end = NULL,
	                    bool CenterX = false, bool CenterY = false) {
		if (CenterX || CenterY) {
			ImVec2 textSize = ImGui::CalcTextSize(text_begin, text_end);
			if (CenterX && (! CenterY))
				DrawList->AddText(ImVec2(pos.x - textSize.x/2.0f, pos.y), col, text_begin, text_end);
			else if ((! CenterX) && CenterY)
				DrawList->AddText(ImVec2(pos.x, pos.y - textSize.y/2.0f), col, text_begin, text_end);
			else
				DrawList->AddText(ImVec2(pos.x - textSize.x/2.0f, pos.y - textSize.y/2.0f), col, text_begin, text_end);
		}
		else
			DrawList->AddText(pos, col, text_begin, text_end);
	}
}


