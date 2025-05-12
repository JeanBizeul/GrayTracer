# Renderers

When loaded, must comminucate what level of illum  they support :

| 1   | Color on ambient and diffuse only       |
| --- | --------------------------------------- |
| 2   | Color on ambient, diffuse, and specular |
| 3   | Reflection: Ray trace                   |
| 4   | Transparency: Glass (ray trace)         |
| 5   | Reflection + Fresnel                    |
| 6   | Transparency: Refraction                |
| 7   | Transparency + Reflection               |
| 8   | Reflection using environment map        |
| 9   | Transparency + Reflection + Fresnel     |
