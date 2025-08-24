
~Version: 1-2-2

~State: inprouve

~Fail-status:
    V5
    Status: Commandes are refused by the Makefile that confuse with a file.
    Resolution: Call a variable "PATH" make fail any bash command.

~script: compile an executable from the main file

~Main: print a message

~Variation:

    V2
    Use argument of the script function
    to be use inside the commandes.

    V3
    Several function-label
    that each call a serie of commandes.

    V4
    Use variables to reuse
    or make easy to modify.

    V5
    Produce a setup required to build.

