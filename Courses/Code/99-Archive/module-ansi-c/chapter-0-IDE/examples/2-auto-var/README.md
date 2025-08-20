
A) Variation from the last example

https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

Use automatique variables.
Like "$@" and "$<" or "%: %"

"$@":
    Take the script output ( like a binary executable )

"$<":
    Take the first recipie ( like a main-source-file )

"direcotry/%.extention: direcotry/%.extention"
    Any file in the output directory have the same name
    than the currently iterate recipie in condition.


