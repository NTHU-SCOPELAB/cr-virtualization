# Setup Environment

## Prequisite
We have provided the required files for this assignment. Please download them from [here](https://github.com/NTHU-SCOPELAB/cr-virtualization/releases/latest/download/hw2.zip).

The required files are as follows (included within the downloaded `hw2.zip`):
```
docker
  |-- server
  |     |-- Dockerfile
  |     |-- socket_server
  |     |-- socket_server_arm
  |
  |-- client
        |-- Dockerfile
        |-- socket_client.c

k8s
  |-- deployment.yaml
  |-- service.yaml
```

In addition, you must install the following programs on your computer:
- Docker: A tool that is used to automate the deployment of applications.
- Minikube: Local Kubernetes, focusing on making it easy to learn for Kubernetes.
- Kubectl: Command line tool for communicating with a control plane.

There are different installation processes dependending on your operating system. You must have ***root permissions*** in your system.
