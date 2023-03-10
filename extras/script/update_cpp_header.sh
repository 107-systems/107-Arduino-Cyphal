#!/bin/sh

SCRIPT_DIR=$(dirname $(readlink -f "$0"))
SRC_DIR="$SCRIPT_DIR/../../src"
HEADER_DIR="$SCRIPT_DIR/../../src/types"
NUNAVUT_DIR="$SCRIPT_DIR/../../src/nunavut"

cd /tmp
rm -rf public_regulated_data_types
git clone https://github.com/OpenCyphal/public_regulated_data_types

echo "nnvg version: "
nnvg --version
echo ""

echo "Generating code..."
nnvg --experimental-languages \
     --language-standard=c++17 \
     --target-language cpp \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --outdir public_regulated_data_types/uavcan-header \
     public_regulated_data_types/uavcan
nnvg --experimental-languages \
     --language-standard=c++17 \
     --target-language cpp \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --lookup public_regulated_data_types/uavcan \
     --outdir public_regulated_data_types/reg-header \
     public_regulated_data_types/reg

echo "Copying code to destination"
cp -R public_regulated_data_types/uavcan-header/nunavut/* "$NUNAVUT_DIR"
cp -R public_regulated_data_types/uavcan-header/uavcan "$HEADER_DIR"
cp -R public_regulated_data_types/reg-header/reg "$HEADER_DIR"

echo "Fixing include paths"
cd $HEADER_DIR
find . -type f -exec sed -i 's/"reg\//<types\/reg\//g' {} +
find . -type f -exec sed -i 's/"uavcan\//<types\/uavcan\//g' {} +
find . -type f -exec sed -i 's/"nunavut/<nunavut/g' {} +
find . -type f -exec sed -i 's/.hpp"/.hpp>/g' {} +

echo "Fixing definition of NUNAVUT_ASSERT"
cd $NUNAVUT_DIR/support
sed -i -- 's/#define NUNAVUT_SUPPORT_SERIALIZATION_HPP_INCLUDED/#define NUNAVUT_SUPPORT_SERIALIZATION_HPP_INCLUDED\n\n#include <cassert>\n\n#define NUNAVUT_ASSERT(expr) assert(expr)\n/g' serialization.hpp


echo "Auto-generate DSDL_Types.h.impl which contains a list of all generated files"
cd $SRC_DIR
touch DSDL_Types.h.impl
truncate -s 0 DSDL_Types.h.impl
for i in $(find ./types -type f -name "*.hpp" -printf "%P\n")
do
    printf "#include \"types/%s\" \n" $i >> DSDL_Types.h.impl
done
