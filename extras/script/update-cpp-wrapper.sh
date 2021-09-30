#!/bin/sh

pip install -U nunavut

SCRIPT_DIR=$(dirname $(readlink -f "$0"))
LIBRARY_ROOT_DIR="$SCRIPT_DIR/../.."
DSDL_SRC_DIR="$SCRIPT_DIR/../../.."

cd "$LIBRARY_ROOT_DIR"

nnvg --outdir src/wrappers/ \
     --templates extras/nunavut_templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem wrappers \
      "$DSDL_SRC_DIR/public_regulated_data_types/uavcan"

nnvg --outdir src/wrappers/ \
     --templates extras/nunavut_templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem wrappers \
       "$DSDL_SRC_DIR/public_regulated_data_types/reg"  \
     --lookup "$DSDL_SRC_DIR/public_regulated_data_types/uavcan"
