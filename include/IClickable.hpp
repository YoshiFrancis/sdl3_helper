#ifndef SDL3HELPER_ICLICKABLE_HPP
#define SDL3HELPER_ICLICKABLE_HPP

#include "Transform.hpp"

namespace sdl3_helper {

class IClickable {



    public:
        virtual bool clicked(float mx, float my) = 0;
        virtual bool hovered(float mx, float my) = 0;

    private:
        bool clicked(const Transform& transform, float mx, float my);
        bool hovered(const Transform& transform, float mx, float my);
};
    
}

#endif
