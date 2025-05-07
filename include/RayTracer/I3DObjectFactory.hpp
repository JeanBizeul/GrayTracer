/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** I3DObjectFactory
*/

#ifndef I3DOBJECTFACTORY_HPP_
    #define I3DOBJECTFACTORY_HPP_
    #include <libconfig.h++>

namespace RayTracer {
template<typename T>
class I3DObjectFactory {
 public:
    ~I3DObjectFactory() = default;

    virtual T createObject<T>(libconfig::Config &config) = 0;
};
}  // namespace RayTracer

#endif /* !I3DOBJECTFACTORY_HPP_ */
