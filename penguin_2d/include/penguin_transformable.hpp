#ifndef PENGUIN_TRANSFORMABLE_HPP
#define PENGUIN_TRANSFORMABLE_HPP

#include "penguin_entity.hpp"
#include "vect2.hpp"

namespace Penguin2D {
	class PenguinTransformable : public PenguinEntity {
	public:
		virtual PenguinTransformable(float x = 0.0f, float y = 0.0f, float rot = 0.0f) 
        : position(Vector2<float>(x, y)), rotation(rot) {}

        virtual void init() override {};
        virtual void update(float delta_time) override {};
    protected:
        Vector2<float> position;
        float rotation; 
	};

}

#endif // PENGUIN_TRANSFORMABLE_HPP