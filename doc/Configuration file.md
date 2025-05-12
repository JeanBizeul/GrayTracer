# Configuration file

## Positions and rotation of objects

All positions and rotations in the configuration file must be written as `[x, y, z]`. Rotation is made around each axis. I.E.: If you want to rotate a object horizontally you must rotate it on the z axis.

## Primitives

Primitives can either be created from [modules](Modules.md) with the corresponding name of the primitive (ex: a module implements a primitive named "cone"). Or created from a `.obj` file by giving the path to the `.obj` file in the __name__ property of the primitive.

> [!TIP]
> Primitive names are case insensitive

```c
scene:
{
    [...]
    primitives = (
        {
            name = "Cube";
            position = array[3] { x, y, z };
            rotation = array[3] { x, y, z };
            material = TODO;
        },
        {
            name = "Monkey.obj";
            position = array[3] { x, y, z };
            rotation = array[3] { x, y, z };
        }
    );
    [...]
};
```

## Lights

Lights follow the same principle as primitives, the default available light is "directional". The only exception is that lights cannot be imported via `.obj` files

```c
scene:
{
    [...]
    lights = (
        {
            name = "Directional";
            position = array[3] { x, y, z };
            rotation = array[3] { x, y, z };
        }
    );
    [...]
};
```

## Camera

A single camera is used in a scene to render it. It is possible to set it's FOV, position and rotation.

```c
scene:
{
    [...]
    camera:
    {
        position = array[3] { x, y, z };
        rotation = array[3] { x, y, z };
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
            position = array[3] { x, y, z };
            rotation = array[3] { x, y, z };
            material = TODO;
        }
    );
    lights = ();
    camera:
    {
        position = array[3] { x, y, z };
        rotation = array[3] { x, y, z };
        fov = 1.0;
    };
};
```

> [!WARNING]
> If any value that is not mentioned in this documentation is found in the config you are trying to use with the raytracer the program will not work.
