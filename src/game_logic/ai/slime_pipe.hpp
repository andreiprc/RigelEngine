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

#include "game_logic/global_dependencies.hpp"

namespace rigel { namespace engine { namespace events {
  struct CollidedWithWorld;
}}}


namespace rigel { namespace game_logic { namespace behaviors {

struct SlimePipe {
  int mGameFramesSinceLastDrop = 0;

  void update(
    GlobalDependencies& dependencies,
    GlobalState& state,
    bool isOnScreen,
    entityx::Entity entity);
};


struct SlimeDrop {
  void update(
    GlobalDependencies&,
    GlobalState&,
    bool,
    entityx::Entity
  ) {
  }

  void onCollision(
    GlobalDependencies& dependencies,
    GlobalState& state,
    const engine::events::CollidedWithWorld& event,
    entityx::Entity entity);
};

}}}
