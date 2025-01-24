#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

// Used as a reference to build the exception class: https://github.com/aardhyn/sdl3-template-project/blob/main/include/exception.h

#include <exception>
#include <string>
#include <utility>

namespace Penguin2D {

	enum PenguinError {
		UNKNOWN_ERROR = -1,
		RENDERER_ERROR,
		WINDOW_ERROR,
		APPLICATION_ERROR,
		INIT_ERROR,
		INPUT_ERROR,
		TEXT_ERROR,
		RUNTIME_ERROR
	};

	class Exception final : public std::exception {
		PenguinError error_val;
		std::string message; // Update message as we expect a string, but we are taking in a const char*

	public:
		Exception(std::string message, PenguinError error) : message{ message }, error_val{ error } {}
		explicit Exception(std::string message) : message{ message }, error_val{ UNKNOWN_ERROR } {}

		// Return value of the function should not be ignored
		[[nodiscard]] const char* what() const noexcept override { return message.c_str(); }

		// Throws error based on condition
		inline static void throw_if(bool condition, std::string message, PenguinError error) {
			if (condition)
				throw Exception{ message, error };
		}

	};
}

#endif // EXCEPTION_HPP