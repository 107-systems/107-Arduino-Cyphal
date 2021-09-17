# Usage

```bash
nnvg --outdir out \
     --templates ../107-UAVCAN-Nunavut/templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem DSDLBaseType.ipp \
     ../public_regulated_data_types/uavcan

nnvg --outdir out \
     --templates ../107-UAVCAN-Nunavut/templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem DSDLBaseType.ipp \
     ../public_regulated_data_types/reg  \
     --lookup dsdl_src/public_regulated_data_types-master/uavcan
```
