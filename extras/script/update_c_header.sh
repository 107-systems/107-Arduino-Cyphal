#!/bin/sh

SCRIPT_DIR=$(dirname $(readlink -f "$0"))
HEADER_DIR="$SCRIPT_DIR/../../src/types"
NUNAVUT_DIR="$SCRIPT_DIR/../../src/nunavut"

cd /tmp
rm -rf public_regulated_data_types
git clone https://github.com/OpenCyphal/public_regulated_data_types

echo "Generating code..."
nnvg --target-language c \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --enable-serialization-asserts \
     --outdir public_regulated_data_types/uavcan-header \
     public_regulated_data_types/uavcan
nnvg --target-language c \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --enable-serialization-asserts \
     --lookup public_regulated_data_types/uavcan \
     --outdir public_regulated_data_types/reg-header \
     public_regulated_data_types/reg

echo "Copying code to destination"
cp -R public_regulated_data_types/uavcan-header/nunavut/* "$NUNAVUT_DIR"
cp -R public_regulated_data_types/uavcan-header/uavcan "$HEADER_DIR"
cp -R public_regulated_data_types/reg-header/reg "$HEADER_DIR"

echo "Fixing include paths"
cd $HEADER_DIR
find . -type f -exec sed -i 's/<reg/<types\/reg/g' {} +
find . -type f -exec sed -i 's/<uavcan/<types\/uavcan/g' {} +

echo "Fixing definition of NUNAVUT_ASSERT"
cd $NUNAVUT_DIR/support
sed -i -- 's/#define NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED/#define NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED\n\n#define NUNAVUT_ASSERT(expr) assert(expr)\n/g' serialization.h
