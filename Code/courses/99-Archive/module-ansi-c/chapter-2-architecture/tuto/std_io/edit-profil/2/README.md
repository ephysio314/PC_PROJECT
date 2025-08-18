
VERSION 2

A) Goal

The user can enter the following data:
- He's first and second name.
- He's age.
- adress. ( adress label and number of street )
- postal code.
- A short text about them.
- email adress.
- Select he's favorit pet from a list.
- Way of transportation. ( multi-selection able )

Each should be input using a string.
Have there validity tested.

The evaluation to what should be ask next
will be done by iteration.
The logic should deduce what missing
after each successful input.

Meaning that they won't be asking staticaly
one after another as specifique process.

But that the state of beeing validated
and the order of requesting
should be evaluate after each successfull input
until there is no more unvalidated one.

When all have been validated,
we show the user the data.
He can validate the all.
Or can modity one specifique.
To do that he ask to modify
enter the identifier of the value,
and a new value.

The container that store the values
and there identifier will be immutable.

B) Version

a) Purpose

Implement an option that stop at a specifique character-value.
Turn the option to stop at a specifique character to true
and set it to a white-space.
Input a string.
Show it.

Also ignor a list.

b) Resume

Run a while-loop until the "valide" boolean was true.

Inside:
- Set a config of character to ignor. Here all the numbers.
- Set the config to stop at a white-space character.
- Output in the command-line to enter a sentence.
- Reqiest a string.
- If the result of the function checking if the buffer was "empty" was false, turn "valide" true. 
- Output the string from the buffer and he's calculate length.


