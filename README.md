# CR Virtualization

This repository contains course materials for Container Runtime and Virtualization.

## Automated Releases

This repository includes a GitHub Action workflow that automatically creates releases containing the `hw2` folder contents.

### How it works

- **Trigger**: The workflow runs automatically on every push to the `main` or `master` branch
- **Archive Creation**: Creates `hw2.zip` containing all Docker and Kubernetes configuration files
- **Release Creation**: Generates a new GitHub release with a unique tag (format: `hw2-YYYYMMDD-HHMMSS-{commit-sha}`)
- **Asset Upload**: Uploads the `hw2.zip` file as a release asset

### What's included in releases

Each release contains a zip archive of the `hw2` folder with:
- Docker configuration files for server and client applications
- Kubernetes deployment and service configurations
- Socket server binaries and source code

### Accessing releases

You can find all releases on the [Releases page](../../releases) of this repository. Each release includes:
- Download link for `hw2.zip`
- Release notes with commit information
- Timestamp-based versioning for easy identification