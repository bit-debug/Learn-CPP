echo "Compiling $1"
cmake -DSOURCE_FILE:STRING=$1 -DCMAKE_BUILD_TYPE=Debug .
make