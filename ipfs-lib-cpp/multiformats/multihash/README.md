# multihash

[multihash](//github.com/jbenet/multihash) Implementation in c++.

Multihash is delivered as

1. A library: libmultihash
2. An executable: [bin/multihash](multihash/main.cpp)

## Build

#### Installing Prerequisites

Multihash requires some dependencies to be met before building, which are provided via vcpkg as follows:

```bash
 git clone https://github.com/lockblox/vcpkg.git \
 cd vcpkg \
 ./bootstrap-vcpkg.sh \
 ./vcpkg integrate install \
 ./vcpkg install gtest cryptopp ms-gsl varint
```

#### Building with CMake

Multihash uses cmake for builds. In order for cmake to find the required dependencies, the `-DCMAKE_TOOLCHAIN_FILE` option should be supplied, for example:

```bash
 cmake -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake" ../multihash
 cmake --build .
 ```

## Usage

### Algorithm

At the lowest level, there is the abstract type `multihash::algorithm`.

A `multihash::algorithm` defines the steps required to compute a hash from
input data.

`multihash::algorithm` instances are created by a factory and each factory is
registered under a unique hash code identifier.

```cpp
auto code = multihash::code::sha3_256;
auto algorithm = multihash::algorithm::create(code);
auto buffer = std::string{"hello, world"};
algorithm->update(buffer);
auto result = std::string(256, '=');
algorithm->digest(result);
```

### Function

A `multihash::function` is a hash functor which operates on iterator pairs.

```cpp
auto multihash = multihash::function(code)(input.begin(), input.end());
```

### Multihash

A `multihash::multihash` combines the hash code and digest in a binary payload.

```cpp
auto code = multihash.code();
auto digest = multihash.digest();
```

## License

multihash is released under the [MIT License](LICENSE.txt).