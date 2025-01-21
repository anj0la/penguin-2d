#ifndef PENGUIN_ENTITY_HPP
#define PENGUIN_ENTITY_HPP

namespace Penguin2D {
	class PenguinEntity {
	public:
		virtual ~PenguinEntity() {}
		virtual void init() = 0;
		virtual void update(float delta_time) = 0;
	};
}

#endif // PENGUIN_ENTITY_HPP
