# Configuration file

## Example

```c
scene:
{
    primitives = [];
    lights = [];
    camera:
    {
        position = array[3] { x, y, z };
        rotation = array[3] { x, y, z };
        fov = 1.0;
    };
};
```

## Positions and rotation of objects

All positions and rotations in the configuration file must be written as `[x, y, z]`. Rotation is made around each axis. I.E.: If you want to rotate a object horizontally you must rotate it on the z axis.

## Primitives

Primitives can either be created from [modules](Modules.md)

## Lights

## Camera
