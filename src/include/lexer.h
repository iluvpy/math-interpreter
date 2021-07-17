#pragma once

#include "cstr.h"


// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by spaces
cstr *get_tokens(cstr *m_expression);