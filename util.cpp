#include "util.h"

Vector2 add(Vector2 one, Vector2 two) {
    return {one.x + two.x, one.y + two.y};
}

Vector2 sub(Vector2 one, Vector2 two) {
    return {one.x - two.x, one.y - two.y};
}

Vector2 scale(Vector2 one, float factor) {
    return {one.x * factor, one.y * factor};
}

float squared_magnitude(Vector2 v) {
    return v.x * v.x + v.y * v.y;
}

float squared_distance(Vector2 v1, Vector2 v2) {
    return squared_magnitude(sub(v1, v2));
}

float distance(Vector2 v1, Vector2 v2) {
    return sqrt(squared_distance(v1, v2));
}
