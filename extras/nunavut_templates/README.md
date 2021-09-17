# Usage

Executed from Repo root

```bash
nnvg --outdir src/wrappers/ \
     --templates extras/nunavut_templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem DSDLBaseTypes \
      dsdl_src/public_regulated_data_types/uavcan

nnvg --outdir src/wrappers/ \
     --templates extras/nunavut_templates \
     -e .hpp \
     --pp-max-emptylines 1 \
     --trim-blocks \
     --generate-namespace-types \
     --namespace-output-stem DSDLBaseTypes \
      dsdl_src/public_regulated_data_types/reg  \
     --lookup dsdl_src/public_regulated_data_types-master/uavcan
```
