
A) Methode

Implement in examples
with a main-file only.

Implementing what have been
implemented, tested, aprouve
from the first part. ( main-only )

Implement in the third part
extended version.

In thourth,
implement system of test
and scalability.

B) Architecture

a) data-flow

Test the structure:
- Configute
- Create
- Transform
- Process

Configure was an object
from a pack of data
that the user can get
to be pass in the argument of Create.

Create was the usage of the cofiguration
and current mode
to produce an object that can be use
as argument for the process.

Transform modify the state
of an object as it is after beeing created.
It is limited in what it can do.

Process was actualy the action to do.
It use the object from creat
and global data that the create
scope file encapsulate.

Meanning that the data-flow was like this:
	setup-config -> get-config -> create -> transform -> process

b) Modularity

Some feature could be handle in multipl way
with a sinificatif diferances in logic,
but could have the same interface.

Using enum, switch and a specifique function to call it.

The idea was to have mode to test multipl way
to inpremant one feature.

It can be multipl reason for that.
The two most important are maintenance and design-tradeof.

C) Feature

Creat shader, transform and draw it.



