#ifndef SDL3HELPER_TRANSFORM_HPP
#define SDL3HELPER_TRANSFORM_HPP

#include "structs.hpp"

namespace sdl3_helper {

class Transform {

    public:
        position pos = {0,0};
        Vec2f scale = {0,0};
        float angle = 0;

        Transform(position _pos, Vec2f _scale={0,0}, float _angle=0);
        Transform(float x=0, float y=0, Vec2f _scale={0,0}, float _angle=0);

        void transform(float x, float y);
        void transform(Vec2f offset);

        void rotate(float a);
        void scaleX(float amount);
        void scaleY(float amount);
        void scaleXY(Vec2f amount);
};

};

#endif
