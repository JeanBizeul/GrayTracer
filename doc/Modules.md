# Modules
## What is a module
We call modules shared libraries that represents objects in the raytracer.
These objects can represent these things :
- [Primitives](Modules/Primitives.md): 3D objects.
- [Lights](Modules/Lights.md).
- [Materials](Modules/Materials.md).
- [Renderers](Renderers.md).

More modules may be added in the future but for now the rest of the program is shipped in with the code base.

All modules may be configured in a [scene configuration file](Configuration%20file.md), the list of each configurable parameters may be found in each module's documentation under the Modules folder.

## How to create a module ?
In order to add a module to the project, you implement a class based on an interface class described in each of the modules documentation page.

After this, you must add an entry under the [scripting documentation](Configuration%20file.md) on what argument your module may support compared to the minimum configuration.