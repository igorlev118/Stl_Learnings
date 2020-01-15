# README #

With this project, I try to experiment with the implementation of my own STL-like types.
My goal is to face challenges and think about how the STL types work internally.
Besides that, I use this project as a chance to experiment with combining unit testing with AppVeyor for continuous integration.

## Current features

* String
* Containers: Vector, Map, HashMap, Array
* Smart Pointers: Unique/Shared/Weak Pointer
* Iterators
* Sorting
* Misc utilities

## Goals

The idea started off with wanting to try to create a Vector and String class to begin with an think about optimizations specifically to games.
The goal is to expand to some more interesting containers like hashmaps, linked lists, ...

* Learning the workings of STL types
* Experimenting with running unit tests on AppVeyor


## External libraries

* [Catch2](https://github.com/catchorg/Catch2)