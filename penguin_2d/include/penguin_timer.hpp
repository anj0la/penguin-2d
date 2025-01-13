#ifndef PENGUIN_TIMER_HPP
#define PENGUIN_TIMER_HPP

#include <chrono>

namespace Penguin2D {

	class PenguinTimer {
	public:
		// PenguinTimer() : running_time(0.0), delta_time(1.0 / 60.0), prev_time(penguin_clock::now()), accumulator(0.0) {}
		PenguinTimer(double dt = 1.0 / 60.0)
			: delta_time(dt), running_time(0.0), accumulator(0.0), frame_count(0), fps(0.0), prev_time(penguin_clock::now()), fps_start_time(prev_time) {}
		~PenguinTimer() = default;

		void update_frame_time();
		void consume_time();
		bool should_update() const;
		double get_alpha() const;
		double get_delta_time() const;
		double get_fps() const;
	private:
		using penguin_clock = std::chrono::steady_clock;
		double delta_time;
		double running_time;
		double accumulator;
		int frame_count;
		double fps;
		penguin_clock::time_point prev_time;
		penguin_clock::time_point fps_start_time;

	};
}

#endif // PENGUIN_TIMER_HPP