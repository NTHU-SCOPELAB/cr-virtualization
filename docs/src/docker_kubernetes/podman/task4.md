# Task 4: Creating a Pod 

### In this task, you are required to create a Podman Pod to group two containers together, allowing them to share the same network namespace and communicate directly via localhost.

### 1. Create a Podman Pod and expose port 8888:

```bash
podman pod create --name test-pod -p 8888:8888
```

### 2. Start the server container inside the Pod:
```bash
podman run -d --pod test-pod --name test-server busybox sh -c "echo 'Hello from Pod Server!' > index.html && httpd -f -p 8888"
```

### 3. Start the client container inside the same Pod:
```bash
podman run -d --pod test-pod --name test-client busybox sleep 3600
```

### 4. Verify the localhost connection between the containers:
```bash
podman exec -it test-client wget -q -O - http://localhost:8888
```
<div class="warning">
    <strong>Note:</strong> You need to include the screenshot of the command output above in your report. <strong>(5 points)</strong>
</div>

