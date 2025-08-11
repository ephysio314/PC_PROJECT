
A) Veriation from the last example

Use auto-macro.
Like "$@" and "$<" or "%: %"

"$@":
    Take the script output ( like a binary executable )

"$<":
    Take the first recipie ( like a main-source-file )

"direcotry/%.extention: direcotry/%.extention"
    Any file in the output directory have the same name
    than the currently iterate recipie in condition.


