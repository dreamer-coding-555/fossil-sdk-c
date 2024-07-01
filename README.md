# ***Fossil SDK Software Development Kit created by Fossil Logic*** `C, C++`

The Fossil SDK is a robust, platform-independent suite of components written in C and C++ designed to streamline the development of high-performance, cross-platform applications. Built using the Meson build system, the Fossil SDK leverages Meson's speed, flexibility, and simplicity to facilitate seamless compilation across various operating systems and architectures.

Key features of the Fossil SDK include:

1. **Cross-Platform Compatibility**: Ensures consistent performance and functionality on Windows, macOS, Linux, and other platforms.
2. **Modular Design**: Offers a collection of modular components that can be easily integrated and customized to meet specific project requirements.
3. **Efficient Build System**: Utilizes Meson, a modern build system known for its fast build times and user-friendly syntax, which simplifies the configuration and maintenance of build environments.
4. **High Performance**: Written in C, C++ to provide optimal performance and resource efficiency, making it suitable for both desktop and embedded applications.
5. **Extensive Documentation and Examples**: Comes with comprehensive documentation and sample code to aid developers in getting started quickly and effectively.

The Fossil SDK is ideal for developers seeking a reliable and flexible foundation for creating high-quality software that needs to run efficiently across multiple platforms.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Adding dependency

1. **Install Meson Build System**: Before integrating the dependency, ensure you have Meson `1.2` or newer installed on your host system. You can install it with this command.

   ```ini
   python -m pip install meson           # to install Meson
   python -m pip install --upgrade meson # to upgrade Meson
   ```

2. **Adding Wrap File**: You can add a `.wrap`, first go into `subprojects` directory and create `fossil-sdk.wrap` next copy the defintion into the file:

   ```ini
   # ======================
   # Git Wrap package definition
   # ======================
   [wrap-git]
   url = https://github.com/dreamer-coding-555/fossil-sdk.git
   revision = v1.0.2

   [provide]
   fossil-sdk           = fossil_sdk_dep
   fossil-sdk-io        = fossil_sdk_io_dep
   fossil-sdk-core      = fossil_sdk_core_dep
   fossil-sdk-strings   = fossil_sdk_strings_dep
   fossil-sdk-structure = fossil_sdk_structure_dep
   fossil-sdk-threads   = fossil_sdk_threads_dep
   fossil-sdk-generic   = fossil_sdk_generic_dep
   ```

3. **Integrate the New Dependency**: After creating the dependency `.wrap` file, you need to integrate it into your Meson project. This typically involves adding the dependency to your `meson.build` file. Here's an example of how you might do that:

   ```ini
   dep = dependency('fossil-sdk') # includes everything
   ```

   This line retrieves the `fossil-sdk` dependency, allowing you to use it in your project.
   
## Configure Options

You have options when configuring the build, each serving a different purpose:

- **Running Tests**: To enable running tests, use `-Dwith_test=enabled` when configuring the build.

Example:

```python
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

If you're interested in contributing to this project, encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information.
