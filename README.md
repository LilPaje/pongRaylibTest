# Silly Pong Clone

This is just a silly pong clone I made using Raylib for learning purpose (please don't judge my bad code).
If you want to try it out, just clone this repo and inside the origin folder you can run
```console
$ make
```

After that, go to bin/Debug and run the "pong" file.

Note: Inside the Makefile, the project is setted up to be in Debug mode. This projects is nothing crazy at all, but if you want some kind of optimization, just edit the "Makefile", on the 4th line, where the text is:
```c
  config=debug_x64
```
Change it to
```c
  config=release_x64
```
By doing that, a Release folder will be created on "bin/" and inside it will be the file to run this silly game (Again, It's my first time doing this... i'm sure that there are better ways to do this, i just don't know it how yet :D)

# License
Copyright (c) 2020-2025 Jeffery Myers

This software is provided "as-is", without any express or implied warranty. In no event 
will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim that you 
  wrote the original software. If you use this software in a product, an acknowledgment 
  in the product documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be misrepresented
  as being the original software.

  3. This notice may not be removed or altered from any source distribution.
