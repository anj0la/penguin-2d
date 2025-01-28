#ifndef PENGUIN_TIMER_HPP
#define PENGUIN_TIMER_HPP

#include <chrono>
#include <thread>

#include <SDL3/SDL_timer.h>

namespace Penguin2D {

	class PenguinTimer {
	public:
		PenguinTimer(double dt = 1.0 / 60.0, bool p_cap_fps = false, double p_target_fps = 60.0)
			: delta_time(dt), cap_fps(p_cap_fps), target_fps(p_target_fps) {}
		~PenguinTimer() = default;

		void update_frame_time();
		void update_fps();
		void consume_time();
		void set_fps_cap(bool enable, double fps = 60.0);
		void cap_frame_rate() const;                         
		bool should_update() const;
		double get_alpha() const;
		double get_delta_time() const;
		double get_fps() const;
		void delay(double ms);
	private:
		using penguin_clock = std::chrono::steady_clock;
		double delta_time;
		bool cap_fps;
		double target_fps;  
		double target_frame_time = 1.0 / target_fps; 
		double running_time = 0.0;
		double accumulator = 0.0;
		int frame_count = 0;
		double fps = 0.0;
		penguin_clock::time_point prev_time = penguin_clock::now();
		penguin_clock::time_point fps_start_time = prev_time;

	};
}

#endif // PENGUIN_TIMER_HPP