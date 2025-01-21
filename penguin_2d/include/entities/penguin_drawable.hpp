#ifndef PENGUIN_DRAWABLE_HPP
#define PENGUIN_DRAWABLE_HPP

#include "penguin_transformable.hpp"
#include "vect2.hpp"

namespace Penguin2D {
    class PenguinDrawable : public PenguinTransformable {
    public:
        virtual PenguinDrawable(float x = 0.0f, float y = 0.0f, float rot = 0.0f)
            : PenguinTransformable(x, y, rot) {}

        virtual void draw(float alpha) = 0;
    };

}

#endif // PENGUIN_DRAWABLE_HPP