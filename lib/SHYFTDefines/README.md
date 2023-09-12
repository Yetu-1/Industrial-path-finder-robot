# SHYFTDefines directory

This contains all (most) of the SHYFT-specific definitions that need to be used across multiple places.

This isn't generally a place for function/class definitions (although there are some equality operators for structs and such). This is mainly a "type-definition" directory; a single source of truth for SHYFT-specific variables, enums, structs, and global constants (including pin map).

The thought process behind this directory was basically:
* The interdependencies between the various "definition" files was getting exceedingly complex.
* Other "external" files should not have to:
  - worry about the `#include` order of these files
    - `#include` order had become a problem in the `DisplayFunctions.h` and `main.ino` files.
  - worry about which combinations of files are necessary to include the correct definitions.
* We should "encapsulate" the "shared definitions" section of our code into a single point of entry
* This point of entry will be `SHYFTDefines.h`, as it (sort of) has been previously

### How to use it

#### including/referencing the values within it
make sure to include the line: `#include "SHYFTDefines.h"`

#### Adding new constants/definitions
* If they are specific to one class and only used there (and/or in `main`), just put them in that class file
* If they fit into one of the categories of existing files (like `EnumDefinitions.h` or `PinMap.h`), add them to one of those files
  - If you run into a circular dependency, you may need to move new definitions into another file to resolve this
* If they are shared and conceptually of a "new category", then create a new file.
  - In this file, `#include` any files it's dependent on
  - In `SHYFTDefines.h`, make sure to `#include` this new file
  - In other files _within the `SHYFTDefines` dir_, `#include` this new file when needed
  - Outside of `SHYFTDefines`, do nothing (make sure `SHYFTDefines` is included wherever you need it)
