#pragma once
#include "headers.h"

const float pi = 3.14159;

Vector2 add(Vector2 one, Vector2 two);

Vector2 sub(Vector2 one, Vector2 two);

Vector2 scale(Vector2 one, float factor);

float squared_magnitude(Vector2 v);

float squared_distance(Vector2 v1, Vector2 v2);

float distance(Vector2 v1, Vector2 v2);