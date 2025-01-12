#ifndef PENGUIN_TIMER_HPP
#define PENGUIN_TIMER_HPP

#include <chrono>

namespace Penguin2D {

	class PenguinTimer {
		// PenguinTimer() : running_time(0.0), delta_time(0.0), curr_time(penguin_clock::now()), accumulator(0.0) {}
		PenguinTimer(double dt = 1.0 / 60.0)
			: delta_time(dt), accumulator(0.0), curr_time(penguin_clock::now()) {
		}
		~PenguinTimer() = default;

		void start_time();
		void update_frame_time();
		void consume_time();
		bool should_update() const;
		double get_alpha() const;
	private:
		using penguin_clock = std::chrono::steady_clock;
		double running_time;
		const double delta_time;
		penguin_clock::time_point prev_time;
		double accumulator;
	};
}

#endif // PENGUIN_TIMER_HPP