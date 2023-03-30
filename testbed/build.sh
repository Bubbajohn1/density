set echo on

mkdir -p ../bin

cFilenames = $(find . -type f -name "*.c")

assembly = "testbed"
compilerFlags = "-g -shared -fdeclspec -fPIC"

includeFlags = "-Isrc -I../engine/src/"
linkerFlags = "-L../bin/ -lengine -Wl,rpath,."
defines = "-D_DEBUG -DEXPORT"

echo "Building $assembly..."
echo clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags