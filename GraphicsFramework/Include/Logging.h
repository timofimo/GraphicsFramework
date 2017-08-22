#pragma once
#include <assert.h>

#ifndef NDEBUG
#define GFW_ASSERT(statement) assert(statement);
#else
#define GFW_ASSERT(statement)
#endif