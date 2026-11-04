# Task 2: Creating bridge

### In this task, you are required to create a bridge to connect two container. (***not related to Task 1***)
![](../../assets/2025-06-11-00-04-36.png)

### 1. Create 2 containers using the following commands:

```bash
podman container run -d --rm --name box1 --network bridge --cap-add=NET_RAW busybox /bin/sh -c "while true; do sleep 3600; done"
```
```bash
podman container run -d --rm --name box2 --network bridge --cap-add=NET_RAW busybox /bin/sh -c "while true; do sleep 3600; done"
```

### 2. Create a network bridge:
```bash
podman network create box-bridge
```

### 3. Connecting two running containers to the network bridge:
```bash
podman network connect box-bridge box1
podman network connect box-bridge box2
```

### 4. You can use the following command to list docker networks:
```bash
podman network ls
```
<div class="warning">
    <strong>Note:</strong> You need to include the screenshot of the command output above in your report. <strong>(5 points)</strong>
</div>

![](../../assets/podma_network.png)

### 5. You can inspect more about the details of the `box-bridge` network:
```bash
podman network inspect box-bridge
```
<div class="warning">
    <strong>Note:</strong> You need to include the screenshot of the command output above in your report. Points WILL BE DEDUCTED if any output text get cropped out. <strong>(5 points)</strong>
</div>

![](../../assets/podman_network_box_bridge.png)

### 6. Log into `box1` and try to ping `box2`:
```bash
podman exec -it box1 sh
ping box2
```
<div class="warning">
    <strong>Note:</strong> You need to include the screenshot of the command output above in your report. <strong>(5 points)</strong>
</div>
