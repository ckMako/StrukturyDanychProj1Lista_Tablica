#pragma once

#include "interface.h"
#include <filesystem>

namespace fs = std::filesystem;

void fromFile(Interface<int>* str);