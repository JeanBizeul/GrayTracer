# Materials

Materials are used by the [Primitives](Primitives.md) to dictate the way a [Light](Lights.md) should interact with it.

A material factory is already provided. It will retrieve all .mtl files located in the assets/materials/ directory and attempt to parse them, building a map of all available materials.

## `.mtl` file format

The material files follow a format inspired by the Wavefront .mtl convention, with some adjustments:

```Bash
# Red        # Comments can be added with the '#' character
newmtl Red   # 'newmtl' marks the start of a new material definition
Kd 1.000000 0.000000 0.000000 # Diffuse color (RGB), color under direct light
Ka 1.000000 0.000000 0.000000 # Ambient color (RGB), color under global illumination

```
## Class definition

```Cpp
class Material {
public:
Material() = delete;
Material(const std::string &name, Math::Vec3 ambiantColor, Math::Vec3, diffuseColor);
~Material() = default;

std::string _name;
Math::Vec3 _ambiantColor;
Math::Vec3 _diffuseColor;
};
```
As you can see, the `RayTracer::Material` class is a simple data holder. You can treat it like a struct with a constructor.

## Usage

While building the scene, all materials loaded by the material factory are stored in the `FactoryContext` under the `"materials"` tag.

You can access them like this:
```Cpp
// Example from src/plugins/Factories/Primitives/Sphere/src/SphereFactory.cpp
[ ... ]

std::shared_ptr<RayTracer::FactoryContext> fcx; // FactoryContext ptr

// Retrieve the map of materials
std::unordered_map<std::string, RayTracer::Material> matMap =
	_fcx->get<std::unordered_map<std::string, RayTracer::Material>>
	("materials");

// Use the specified material to construct a sphere
std::string material = settings["material"];
return std::make_unique<RayTracer::Sphere>
	(position, rotation, matMap.at(material), scale);
```
