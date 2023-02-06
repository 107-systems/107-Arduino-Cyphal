<a href="https://opencyphal.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/opencyphal.svg" width="25%"></a>
### How-to generate C++ headers with [nunavut](https://github.com/OpenCyphal/nunavut)
Install Docker via `snap` or follow the official [instructions](https://docs.docker.com/engine/install/ubuntu/):
```bash
sudo snap install docker
```
**Note**: You may need to add your user to the `docker` group:
```bash
sudo usermod -a -G docker $USER
```
Generating the C++ header files using a Docker container:
```bash
cd extras/script
./build_docker.sh
./docker_codegen.sh
```
