#ifndef DEFS_HPP
#define DEFS_HPP

#include <cstddef>
#include <string>


/// Dimention/size type , 32 or 64 bit
typedef std::size_t							dim_t;

/// Character
typedef char								char_t;

/// Bool type
typedef bool								bool_t;

/// Byte , signed 8 bit
typedef int8_t								sbyte_t;

/// Byte , unsigned 8 bit
typedef uint8_t								byte_t;

/// Word , unsigned 16 bit
typedef uint16_t							word_t;

/// Double word , unsigned 32 bit
typedef uint32_t							dword_t;

/// Quad word , unsigned 64 bit
typedef uint64_t							qword_t;

/// Integer , signed 16 bit
typedef int16_t								short_t;

/// Integer , unsigned 16 bit
typedef uint16_t							ushort_t;

/// Integer , signed 32 bit
typedef int32_t								int_t;

/// Integer , unsigned 32 bit
typedef uint32_t							uint_t;

/// Integer , signed 64 bit
typedef int64_t								long_t;

/// Integer , unsigned 64 bit
typedef uint64_t							ulong_t;

/// Floating type
typedef float								float_t;

/// Double floating type
typedef double								double_t;

/// Long double floating type
typedef long double							ldouble_t;

/// String
typedef std::string							string_t;


#endif // TYPEDEFS_HPP
