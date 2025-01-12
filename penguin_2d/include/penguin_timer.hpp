#ifndef PENGUIN_TIMER_HPP
#define PENGUIN_TIMER_HPP

#include <chrono>

namespace Penguin2D {

	class PenguinTimer {
	public:
		// PenguinTimer() : running_time(0.0), delta_time(1.0 / 60.0), prev_time(penguin_clock::now()), accumulator(0.0) {}
		PenguinTimer(double dt = 1.0 / 60.0)
			: running_time(0.0), delta_time(dt), prev_time(penguin_clock::now()), accumulator(0.0) {}
		~PenguinTimer() = default;

		void update_frame_time();
		void consume_time();
		bool should_update() const;
		double get_alpha() const;
		double get_delta_time() const;
	private:
		using penguin_clock = std::chrono::steady_clock;
		double running_time;
		double delta_time;
		penguin_clock::time_point prev_time;
		double accumulator;
	};
}

#endif // PENGUIN_TIMER_HPP