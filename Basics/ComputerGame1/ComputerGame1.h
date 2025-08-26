#pragma once
#include <cstdint>

// Globale Spielfiguren
std::uint32_t playerPosition = 0;
std::uint32_t enemyPosition = FIELD_SIZE;
constexpr static std::uint32_t FIELD_SIZE = 100U;
constexpr static char MOVE_LEFT = 'a';
constexpr static char MOVE_RIGHT = 'd';
constexpr static char JUMP = 'w';


int init();