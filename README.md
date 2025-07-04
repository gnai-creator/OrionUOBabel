# Notes

The public version in all repositories of the project is temporarily not updated.

[New Launcher (x32 or x64) can be downloaded from here](http://orionuo.online)

# To fix missing api-ms-win-crt-runtime-l1-1-0.dll errors on Win 7 SP 1:

Download and install update: KB2999226

# OrionUO Client

[![Travis Build Status](https://travis-ci.org/Hotride/OrionUO.svg?branch=master)](https://travis-ci.org/Hotride/OrionUO)
[![Build status](https://ci.appveyor.com/api/projects/status/qmd3795itrkiwnr3?svg=true)](https://ci.appveyor.com/project/Hotride/orionuo)


* OrionUO Client - is an alternative, open source Ultima Online graphic client.

* Platforms: Windows and Linux (in progress)

* Rendering: OpenGL 2.0 and higher

## Orion Community

[Discord](https://discord.gg/xSnqcBU8a8)

[WIKI](https://github.com/Hotride/OrionUO/wiki)

[github issue tracking](https://github.com/Hotride/OrionUO/issues)

## Download

* Download [Orion Launcher](http://orionuo.online/Launcher.html) to set everything up and play right away!

### Other Orion Projects

* [Orion.dll](https://github.com/Hotride/OrionDLL) protocol cryptography
* [Orion Launcher](https://github.com/Hotride/OrionLauncher)

--------------

## Building OrionUO

This project requires CMake 3.7 to build. It currently supports Visual Studio 2015, 2017, GCC 7.0 and Clang 6.

### Windows

On Windows, to generate the Visual Studio solution, go inside your cloned OrionUO folder and do:

```bat
md build
cd build
cmake -G "Visual Studio 2017" ..
```

  > This will build a 32bits executable. If you do want 64bits, you can do `cmake -G "Visual Studio 2017 Win64" ..` instead. Note that plugins are still unsupported in the 64bits client.

Or, you can use CMake-GUI to configure and generate the solution.

* If you want to help converting OrionUO to SDL, you can disable `ORION_WISP` option in CMake. This option enables the original client implementation in pure win32 API and is kept as a reference implementation to use during the client conversion to SDL.

### Linux (in progress)

```bash
$ mkdir build
$ cd build
$ cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Release
$ ninja OrionUO_unity -j8
$ ./OrionUO/unity/OrionUO
```

  > You'll need a `Client.cuo` and a `uo_debug.cfg` in the working directory. Inside `uo_debug.cfg` you can add a line `CustomPath=/path/to/uo/data`, so Orion will be able to find your original client data files. If you want to generate a `Client.cuo` that supports up to 127 maps, set the environment variable `ORION_FORCE_MAPS_COUNT=127` before running the configuration tool.



--------------

## Contributing

See the project planning [here](https://github.com/Hotride/OrionUO/projects) to find tasks on which you can help.

  > More detailed contribution documentation soon

## Contributors

[Hotride](https://github.com/Hotride/) (Author)

[AimedNuu](https://github.com/AimedNuu)

and [Others](https://github.com/Hotride/OrionUO/graphs/contributors)

--------------
## Support this project, make a donation!

[PayPal](https://www.paypal.me/Hotride)

WebMoney: R644829964694 Z983232789532 E400319624386

Patreon: https://www.patreon.com/hotride
