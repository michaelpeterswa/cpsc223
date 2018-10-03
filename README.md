[![Awesome](https://awesome.re/badge-flat.svg)](https://michaelpeterswa.com)

# CPSC223

> Repository for CPSC223 at Gonzaga University (Fall 2018)

## Installation

```
git clone https://github.com/michaelpeterswa/cpsc223.git
```
Or download the file manually.

## Compilation for each program

KEYPROG1
```
g++ testingclient.cpp key.cpp -o mytester
```
ABBREVSPROG2
```
g++ client.cpp key.cpp item.cpp –o mytester
```
DICTIONARYHASH
```
g++ client.cpp dictionary.cpp key.cpp item.cpp –o gohash
```
DICTIONARYCHAINING
```
clang++ -std=c++11 client.cpp dictionary.cpp item.cpp key.cpp stack.cpp -o gochain
```

## Release History

* 0.1
    * Opened Repository (08.27.18)

## Meta

Michael Peters – michael@michaelpeterswa.com

Distributed under the MIT license. See ``LICENSE`` for more information.

[https://github.com/michaelpeterswa](https://github.com/michaelpeterswa)
