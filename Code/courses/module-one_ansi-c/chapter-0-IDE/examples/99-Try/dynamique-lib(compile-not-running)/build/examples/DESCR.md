
Serie of source-files containing main-function to become executables.

B) Linux execution

a) Regular

~{
./path/app.exe
}~

b) Depand on dynamique library

~{
.PHONY: run
run: $(BIN_EXE)
	cd build/examples; export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../$(exe); ./$(exe)
}~

