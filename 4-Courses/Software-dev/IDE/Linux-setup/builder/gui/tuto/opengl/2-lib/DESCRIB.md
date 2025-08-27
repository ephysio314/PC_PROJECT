
The features are from the "straigt" examples.

The directory "lib" contain libraries.
Each are fully encapsulate and independant from one another.

They could have dependancies
from the directory "deps".

deps could contain libraries
that are in lib.
But not in there "{name}-dev" version
but in the build version.
With a static-binary to link
and a description of the version.

The idea was that when are developped
those library build by the project from "lib".
Only those are to test and fix.
Because the one in "deps" must be stable
to be added.

In each library on "lib".
There is modules.
Those are all connected
from a share interface
that handle the logic
to call them accordingly
to there purpose
and in the good condition.

The libs have configure values,
that could have "mode" variables

The value come from an enum table
that was associate to the module.
Each function of this module
have a specifique version ( that could be share )
associate to a node-value of the enum table.

Also each modules are identified by a value of an enum table.



