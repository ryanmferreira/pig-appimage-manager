echo -e "Running premake...\n"
premake5 ninja

echo -e "Running ninja...\n"
ninja

echo -e "Running PIG...\n"

build/Debug/x86_64/PIG
