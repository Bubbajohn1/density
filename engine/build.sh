set echo on

mkdir -p ../bin

cFilenames = $(find . -type f -name "*.c")

assembly = "engine"
compilerFlags = "-g -shared -fdeclspec -fPIC"

includeFlags = "-Isrc -I%VULKAN_SDK%/Include"
linkerFlags = "-lvulkan -lxcb -lx11-xcb -lxkbcommon -L%VULKAN_SDK%/Lib -L/usr/X11R6/lib"
defines = "-D_DEBUG -DEXPORT"

echo "Building $assembly..."
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags