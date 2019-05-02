/* Copyright (C) 2016, Nikolai Wuttke. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "base/color.hpp"
#include "base/warnings.hpp"
#include "engine/texture.hpp"
#include "engine/tile_renderer.hpp"
#include "loader/palette.hpp"

RIGEL_DISABLE_WARNINGS
#include <SDL.h>
RIGEL_RESTORE_WARNINGS

#include <optional>
#include <string>


namespace rigel { namespace loader {
  class ResourceLoader;
}}


namespace rigel { namespace ui {

constexpr auto NUM_MENU_INDICATOR_STATES = 8;


class MenuElementRenderer {
public:
  MenuElementRenderer(
    engine::TileRenderer* pSpriteSheetRenderer,
    engine::Renderer* pRenderer,
    const loader::ResourceLoader& resources);

  // Stateless API
  // --------------------------------------------------------------------------
  void drawText(int x, int y, const std::string& text) const;
  void drawSmallWhiteText(int x, int y, const std::string& text) const;
  void drawMultiLineText(int x, int y, const std::string& text) const;
  void drawBigText(
    int x,
    int y,
    const std::string& text,
    const base::Color& color) const;
  void drawMessageBox(int x, int y, int width, int height) const;

  void drawCheckBox(int x, int y, bool isChecked) const;

  void drawBonusScreenText(int x, int y, const std::string& text) const;

  /** Draw text entry cursor icon at given position/state.
   *
   * Valid range for state: 0..3 (will be clamped automatically)
   */
  void drawTextEntryCursor(int x, int y, int state) const;

  /** Draw menu selection indicator (spinning arrow) at given position.
   *
   * Valid range for state: 0..7
   */
  void drawSelectionIndicator(int x, int y, int state) const;

  /** Draws a black rectangle at given position.
   *
   * Meant to erase a previously drawn menu selection indicator.
   */
  void clearSelectionIndicator(int x, int y);

private:

  void drawMessageBoxRow(
    int x,
    int y,
    int width,
    int leftIndex,
    int middleIndex,
    int rightIndex) const;

private:
  engine::Renderer* mpRenderer;
  engine::TileRenderer* mpSpriteSheetRenderer;
  engine::TileRenderer mBigTextRenderer;
};

}}
