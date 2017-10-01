set -e
gpp -C ./examples/aot_hello.hob > aot_hello.pp.hob
./hc ./aot_hello.pp.hob #generates a file out.ll in the directory this script is run
llc-3.7 -O0 -relocation-model=pic -cppgen=functions -filetype=asm out.ll #generates out.s , here there will be many unresolved symbols
gcc out.s libhobbes-pic.a -lm -lpthread -lstdc++ -lz `llvm-config-3.7 --libfiles` -ldl -lcurses -fPIC -o prog #compile asm with gcc and linkin the hobbes lib
# There could be a much smaller runtime library for this