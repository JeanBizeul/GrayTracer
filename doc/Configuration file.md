# Configuration file

## Positions and rotation of objects

All positions and rotations in the configuration file must be written as `[x, y, z]`. Rotation is made around each axis. I.E.: If you want to rotate a object horizontally you must rotate it on the z axis.

## Objects

- ### Primitives

Primitives can either be created from [modules](Modules.md) with the corresponding name of the primitive (ex: a module implements a primitive named "cone"). Or created from a `.obj` file by giving the path to the `.obj` file in the __name__ property of the primitive.
The `material` property is a filepath to a given `.mlt` material file, it is optional.

> [!TIP]
> Primitive names are case insensitive

```c
scene:
{
    [...]
    primitives = (
        {
            name = "Cube";
            position = [ x, y, z ];
            rotation = [ x, y, z ];
            material = "material.mtl"; // Path to material file, optional
        },
        {
            name = "Monkey.obj";
            position = [ x, y, z ];
            rotation = [ x, y, z ];
            material = "material.mtl";
        }
    );
    [...]
};
```

- ### Lights

Lights follow the same principle as primitives, the default available light is "directional". The only exception is that lights cannot be imported via `.obj` files

```c
scene:
{
    [...]
    lights = (
        {
            name = "Directional";
            position = [ x, y, z ];
            rotation = [ x, y, z ];
            color = [ r, g, b ];
            range = 100.0; // Range of the light / power
        }
    );
    [...]
};
```

#### Ambient light

The ambient light is part of the whole scene it is a global illumination independent of any direction.

```c
scene:
{
    [...]
    ambient = [ r, g, b ];
    [...]
};
```

- ### Camera

A single camera is used in a scene to render it. It is possible to set it's FOV, position and rotation.

```c
scene:
{
    [...]
    camera:
    {
        position = [ x, y, z ];
        rotation = [ x, y, z ];
        fov = 1.0;
    };
    [...]
};
```

## Example

```c
scene:
{
    primitives = (
        {
            name = "Cube";
            position = [ x, y, z ];
            rotation = [ x, y, z ];
            material = "material.mtl"; // Path to material file, optional
        }
    );
    lights = (
        {
            name = "Directional";
            position = [ x, y, z ];
            rotation = [ x, y, z ];
            color = [ r, g, b ];
            range = 100.0; // Range of the light / power
        }
    );
    ambient = [ r, g, b ];
    camera:
    {
        position = [ x, y, z ];
        rotation = [ x, y, z ];
        fov = 1.0;
    };
};
```

> [!WARNING]
> If any value that is not mentioned in this documentation is found in the config you are trying to use with the raytracer the program will not work.
