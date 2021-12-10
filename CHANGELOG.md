# Manipulate-Memory Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.1/), and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.1.html).

## [Unreleased](https://github.com/KumarjitDas/Manipulate-Memory/compare/v0.1.0...HEAD)

- *CPack* packaging support
- *vcpkg* packaging support

## [0.1.0](https://github.com/KumarjitDas/Manipulate-Memory/releases/tag/v0.1.0) - 2021-12-10

### Added

- [Git Attributes](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/.gitattributes) file
- [Changelog](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CHANGELOG.md) file
- [License](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/LICENSE.txt) file
- [Readme](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/README.md) file
- Root [CMake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMakeLists.txt) file
- [CMake](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/CMake) directory
  - [add_sources_to_target.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/add_sources_to_target.cmake)
  - [configure_project_version.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/configure_project_version.cmake)
  - [create_library.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/create_library.cmake)
  - [export_rules.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/export_rules.cmake)
  - [generate_export_header.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/generate_export_header.cmake)
  - [include_tests.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/include_tests.cmake)
  - [package_configuration.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/package_configuration.cmake)
  - [set_build_output_directories.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_build_output_directories.cmake)
  - [set_build_postfixes.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_build_postfixes.cmake)
  - [set_c_standard.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_c_standard.cmake)
  - [set_compiler_warnings.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_compiler_warnings.cmake)
  - [set_include_directories.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_include_directories.cmake)
  - [set_install_directories.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/set_install_directories.cmake)
  - [setup_project.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/setup_project.cmake)
  - [validate_build_config.cmake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/CMake/validate_build_config.cmake)
- [Configuration](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Configuration) directory
  - [config-shared.cmake.in](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Configuration/config-shared.cmake.in)
  - [config-static.cmake.in](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Configuration/config-static.cmake.in)
  - [configure_version.h.in](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Configuration/configure_version.h.in)
- [Scripts](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Scripts) directory
  - [configure.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/configure.bat)
  - [configure-all.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/configure-all.bat)
  - [clean.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/clean.bat)
  - [clean-all.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/clean-all.bat)
  - [build.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/build.bat)
  - [build-all.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/build-all.bat)
  - [build-configs.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/build-configs.bat)
  - [build-all-configs.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/build-all-configs.bat)
  - [test.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/test.bat)
  - [test-all.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/test-all.bat)
  - [test-configs.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/test-configs.bat)
  - [test-all-configs.bat](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Scripts/test-all-configs.bat)
- [Sources](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Sources) directory
  - [include](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Sources/include) subdirectory
    - [manipulate_memory](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Sources/include/manipulate_memory) subdirectory
      - [manipulate_memory.h](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/include/manipulate_memory/manipulate_memory.h)
        file
  - [src](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Sources/src) subdirectory
    - [manipulate_memory](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Sources/src/manipulate_memory) subdirectory
      - [utility.h](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/utility.h)
        file
      - [manipulate_memory.c](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/manipulate_memory.c)
        file
      - [alignment.h](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/alignment.h)
        file
      - [alignment.c](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/alignment.c)
        file
      - [copy.h](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/copy.h)
        file
      - [copy.c](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Sources/src/manipulate_memory/copy.c)
        file
- [Tests](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Tests) directory
  - [CMake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Tests/CMakeLists.txt) file
  - [kdi_manipulate_memory_copy](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Tests/kdi_manipulate_memory_copy.c) file
- [Examples](https://github.com/KumarjitDas/Manipulate-Memory/tree/v0.1.0/Examples) directory
  - [CMake](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Examples/CMakeLists.txt) file
  - [example-001-copy](https://github.com/KumarjitDas/Manipulate-Memory/blob/v0.1.0/Examples/example-001-copy.c) file
- `KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT` public macro definition
- `_KDI_ARCHITECTURE_64_BIT` private macro definition
- `_KDI_MEMORY_COPY_SIZE_FOR_WHEN_TO_ALIGN` private macro definition
- All possible public function declarations and their dummy implementations
- Actual implementation of `kdi_manipulate_memory_copy` function
- Tests for `kdi_manipulate_memory_copy` function
- Example for `kdi_manipulate_memory_copy` function
