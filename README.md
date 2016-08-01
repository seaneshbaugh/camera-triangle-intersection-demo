# Camera Triangle Intersection Demo

This is a simple demonstration of [Dan Sunday's algorithm for finding the intersection of rays and triangles](http://geomalgorithms.com/a06-_intersect-2.html) using a typical camera object as the source of the ray/line segment. The intent is to provide a complete and self-contained example that uses his algorithm in a semi-realistic context. The camera class used in this demo is taken from an actual game engine with little modification. There is, however, no graphical output. Given the purpose of this demo, any platform specific code needed to generate graphical output would only obscure the math being done. [GLM](glm.g-truc.net/) is used for all vector calculations since it's easy to install and use.

## Setup

    brew install glm

## Building

    make

## Running

    ./build/c-int
