#include "Transform.hpp"

using namespace sdl3_helper;

Transform::Transform(position _pos, Vec2f _scale, float _angle) 
    : pos(_pos), scale(_scale), angle(_angle)
{ }

Transform::Transform(float x, float y, Vec2f _scale, float _angle) 
    : Transform({x,y}, _scale, _angle) {}

void Transform::transform(float x, float y) {
    pos.x += x;
    pos.y += y;
}

void Transform::transform(Vec2f offset) {
    transform(offset.x, offset.y);
}

void Transform::rotate(float a) {
    angle += a;
}

void Transform::scaleX(float amount) {
    scale.x += amount;
}

void Transform::scaleY(float amount) {
    scale.y += amount;
}

void Transform::scaleXY(Vec2f amount) {
    scaleX(amount.x);
    scaleY(amount.y);
}

