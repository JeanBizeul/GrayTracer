# Raytracer !

This project is an Epitech school project made with the collaboration of 4 second year students:

- [Noah Auroy](https://github.com/ChifuyuOnWish)
- [Jean Bizeul](https://github.com/JeanBizeul)
- [Jocelyn Jean-Elie](https://github.com/Jocelyn-JE)
- [Ester Ngindu mubiala](https://github.com/MsteR7)

## What is it ?

The Raytracer project is, well... A raytracer !

It aims to be as modular as possible to allow easy addition / upgrade of different features that composes it.

You can take a look at the newcomers documentation we wrote which explains why we took certain decisions and how to add your own models, lights, materials, ...

The raytracer also features a fully scipted scene manager using libconfig++ file format and C++ library.

**You can find the documentation under the [doc folder](<doc/How to read.md>) located at the root of the repository.**

## Developpement environment

This project uses a modified version of [**Google's coding style**](https://google.github.io/styleguide/cppguide.html) and is verified by using the tool [cpplint](https://github.com/cpplint/cpplint). Thus it must be installed beforehand if you want to check if your code complies with the coding style.

A [.clang-format](https://clang.llvm.org/docs/ClangFormat.html) is present to format all .cpp and .hpp files to our specified coding style. It is possible to auto-format all files by using the [`format` Makefile](Makefile#L75) rule.

The following rules are ommited when checking the style with the  [`linter` Makefile](Makefile#L72) rule:

- `legal/copyright` | We're students we don't need no copyright notice on our code...
- `build/c++17` | We use C++20
- `build/c++11` | Same reason
- `runtime/references` | This disables forced const references
- `build/include_subdir` | Straight up annoying

## Installation & usage

> [!WARNING]  
> TODO
