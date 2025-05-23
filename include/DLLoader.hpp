/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include <dlfcn.h>

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

class DLLoaderError : public std::runtime_error {
 public:
    explicit DLLoaderError(const std::string &msg) : std::runtime_error(msg) {}
};

template <typename T>
class DLLoader {
 public:
    DLLoader(const DLLoader &) = delete;
    DLLoader &operator=(const DLLoader &) = delete;

    DLLoader(const std::string &libName, const std::string &entryPoint)
        : _libName(libName) {
        _handler = dlopen(_libName.c_str(), RTLD_LAZY);
        if (!_handler)
            throw DLLoaderError("Cannot load library " + _libName + ": " +
                                dlerror());
        _entryPoint = reinterpret_cast<std::unique_ptr<T> (*)(void)>(
            dlsym(_handler, entryPoint.c_str()));
        if (!_entryPoint)
            throw DLLoaderError("Could not find entry point in " + _libName +
                                ": " + dlerror());
    }

    ~DLLoader() {
        if (dlclose(_handler) != 0) {
            std::cerr << "Cannot unload " + _libName + ": ";
            std::cerr << dlerror() << std::endl;
        }
    }

    std::unique_ptr<T> getInstance() {
        return _entryPoint();
    }

 private:
    void *_handler;
    std::unique_ptr<T> (*_entryPoint)(void);
    const std::string _libName;
};

#endif  // DLLOADER_HPP_
