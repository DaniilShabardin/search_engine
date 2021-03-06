# Macros

Some aspects of the library can be configured by defining preprocessor macros **before** including the `json.hpp`
header. See also the [macro overview page](../../features/macros.md).

## Runtime assertions

- [**JSON_ASSERT(x)**](json_assert.md) - control behavior of runtime assertions

## Exceptions

- [**JSON_CATCH_USER(exception)**<br>**JSON_THROW_USER(exception)**<br>**JSON_TRY_USER**](json_throw_user.md) - control exceptions
- [**JSON_DIAGNOSTICS**](json_diagnostics.md) - control extended diagnostics
- [**JSON_NOEXCEPTION**](json_noexception.md) - switch off exceptions

## Language support

- [**JSON_HAS_CPP_11**<br>**JSON_HAS_CPP_14**<br>**JSON_HAS_CPP_17**<br>**JSON_HAS_CPP_20**](json_has_cpp_11.md) - set supported C++ standard
- [**JSON_HAS_FILESYSTEM**<br>**JSON_HAS_EXPERIMENTAL_FILESYSTEM**](json_has_filesystem.md) - control `std::filesystem` support
- [**JSON_NO_IO**](json_no_io.md) - switch off functions relying on certain C++ I/O headers
- [**JSON_SKIP_UNSUPPORTED_COMPILER_CHECK**](json_skip_unsupported_compiler_check.md) - do not warn about unsupported compilers

## Library version

- [**JSON_SKIP_LIBRARY_VERSION_CHECK**](json_skip_library_version_check.md) - skip library version check
- [**NLOHMANN_JSON_VERSION_MAJOR**<br>**NLOHMANN_JSON_VERSION_MINOR**<br>**NLOHMANN_JSON_VERSION_PATCH**](nlohmann_json_version_major.md) - library version information

## Type conversions

- [**JSON_USE_IMPLICIT_CONVERSIONS**](json_use_implicit_conversions.md) - control implicit conversions

## Serialization/deserialization macros

- [**NLOHMANN_DEFINE_TYPE_INTRUSIVE(type, member...)**<br>**NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(type, member...)**](nlohmann_define_type_intrusive.md) - serialization/deserialization of types _with_ access to private variables
- [**NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(type, member...)**<br>**NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(type, member...)**](nlohmann_define_type_non_intrusive.md) - serialization/deserialization of types _without_ access to private variables
- [**NLOHMANN_JSON_SERIALIZE_ENUM(type, ...)**](nlohmann_json_serialize_enum.md) - serialization/deserialization of enum
  types
