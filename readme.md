# [WIP - testing examples] C++ 20 Module handling with C++, CPP2, and Cmake

Nothing to see here unless you know why you are here.
There is nothing grand here, just cruft that shows some minimal examples of using modules in C++ and CPP2.  It's a "simple" concept that is hard to actually get going.

These are working (or broken, but in a way to consider) examples for those I'm discussing with, but there is **no** expectation of general value to a wider audience, and it is not written with any wider audience or value in mind.

Notes from the bleeding edge:

* On MacOS 26 beta (but tested with prior release)
* llvm with clang-scan-deps is needed, or figure out how to get cmake and Apple's clang to scan for dependencies.  I'm using a current-ish release or head from LLVM.
* For the moment, cmake head because import std magic code didn't match
* cppfront cmake from modern cmake, with PR #145 applied for module set errors.
* cppfront module patch from Johel brought current but not yet fully reviewed nor broken into minimal PRs

```zsh
# get, cd into base proj dir where this readme is, then
cmake -B build -G Ninja src
# and assuming that is good
cmake --build build
```
to make the example executables.

Side comment:  The filename conventions don't quite work out right now.
Cppfront checks for a `2` at the end of the suffix and just pulls it off for the default output file in some places, but checks to see if the extension is specifically `.cpp2` or `.h2` in others.  Meanwhile, modules with interface parts are .cppm in Clang, so .cppm2 would otherwise make sense for cpp2 files. It's not necessary though, and there are IXX extension, etc. so not sure if there's anything to really do or improve on with filename handling.
