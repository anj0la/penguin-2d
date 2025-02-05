///////////////////////////////////////////////////////////////////////////////////
/// File name: exception.hpp                                                    ///
///                                                                             ///
/// Defines an Exception class for error handling in the Penguin2D engine.		///
///																				///
/// This file introduces the Exception class, inheriting from std::exception,	///
/// which allows for structured error handling using predefined error codes.	///
///																				///
/// Reference: https://github.com/aardhyn/sdl3-template-project/blob/main       ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>

namespace Penguin2D {

	/// @brief Represents various error types that can occur in the engine.
	///
	/// This enum defines specific error categories to classify exceptions 
	/// that might arise during the execution of the game engine.
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

	/// @brief Custom exception class for handling engine-related errors.
	///
	/// This class extends std::exception and provides a structured 
	/// way to handle errors using predefined error codes (PenguinError) and messages.
	/// It supports both general and specific error reporting mechanisms.
	class Exception final : public std::exception {
		PenguinError error_val; /// The error code associated with this exception.
		std::string message; /// The descriptive error message.

	public:
		/// @brief Constructs an Exception with a specific error message and error code.
		/// @param message: The error message.
		/// @param error: The associated `PenguinError` code.
		Exception(std::string message, PenguinError error) : message{ message }, error_val{ error } {}

		/// @brief Constructs an Exception with only an error message (defaults to UNKNOWN_ERROR).
		/// @param message: The error message.
		explicit Exception(std::string message) : message{ message }, error_val{ UNKNOWN_ERROR } {}

		/// @brief Retrieves the error message describing the exception.
		/// @return A C-string containing the error message.
		[[nodiscard]] const char* what() const noexcept override { return message.c_str(); }

		/// @brief Throws an exception if the specified condition is met.
		///
		/// This function simplifies error handling by allowing conditional 
		/// exception throwing with a custom message and error code.
		///
		/// @param condition: If true, an exception is thrown.
		/// @param message: The error message.
		/// @param error: The associated PenguinError.
		inline static void throw_if(bool condition, std::string message, PenguinError error) {
			if (condition)
				throw Exception{ message, error };
		}
	};
}

#endif // EXCEPTION_HPP