echo "Compiling $1"
cmake -DCMAKE_C_COMPILER=/opt/homebrew/opt/llvm@12/bin/clang -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm@12/bin/clang -DSOURCE_FILE:STRING=$1 -DCMAKE_BUILD_TYPE=Debug .
make