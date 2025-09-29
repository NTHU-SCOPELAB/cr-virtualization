# QEMU

### 0. Before starting, setup a bridge `br0` for QEMU to bind to: (will be cleaned up naturally after a reboot)
<img width="505" height="245" alt="image" src="https://github.com/user-attachments/assets/3c9ef3ae-8759-4bb0-bf62-1250ce20370d" />  


- Choose a subnet/IP that does not conflict with your usecase. For CIDR notation, see [here](https://en.wikipedia.org/wiki/Classless_Inter-Domain_Routing#CIDR_notation).
```bash
sudo ip link add br0 type bridge
sudo ip addr add 192.168.50.1/24 dev br0
sudo ip link set br0 up
```

- After running the command above, you can inspect your current network settings:
```bash
ip a
```

- Add a configuration file to enable qemu to automatically pick up your bridge configured above:
```bash
sudo su
mkdir -p /etc/qemu
echo "allow br0" >> /etc/qemu/bridge.conf
```

- For host to provide internet access to all instances attached to this bridge, issue the following command:
```bash
sudo sysctl -w net.ipv4.ip_forward=1
sudo iptables -A FORWARD -i br0 -o eth0 -j ACCEPT
sudo iptables -A FORWARD -i eth0 -o br0 -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
sudo iptables -t nat -A POSTROUTING -o eth0 -s 192.168.50.0/24 -j MASQUERADE
```
- Note: swap out `eth0` for your network interface that provides internet access, you can check it by issuing the following command:
```bash
ip address
```

### 1. First, create the disk image for `guest1`.
```bash
qemu-img create -f qcow2 guest1.qcow2 20G
```

### 2. Run `guest1` and complete the Ubuntu installation process.
```bash
sudo qemu-system-x86_64 -cpu host -enable-kvm -m 4G -smp 1 \
    -drive if=virtio,format=qcow2,file=guest1.qcow2 \
    -nic bridge,br=br0,model=virtio-net-pci,mac=52:54:00:40:C9:01 \
    -boot d -cdrom <your_ubuntu_img_file_path>.iso \
    -vnc :1,password=on -monitor stdio
```
- In qemu console, type the following command to change the vnc password to the one you know:
```bash
(qemu) change vnc password
```
- After changing the password to the one you know, use any VNC viewer (e.g. : RealVNC, vncviewer) connect to (Your host IP):5901 (e.g. : 192.168.7.102:5901 or 127.0.0.1:5901), and complete the installation process.
- After Ubuntu installation is complete, remove the `-boot d -cdrom <your_img_file_path>.iso` part from the above command and run `guest1` again.
- If you want to reach internet or other device on this guest instance, you may want to manually configure your IP under the same subnet. (e.g. `192.168.50.2`, subnet mask: `255.255.255.0`, gateway: `192.168.50.1`)

### 3. Repeat the same steps for `guest2`
```bash
qemu-img create -f qcow2 guest2.qcow2 20G
sudo qemu-system-x86_64 -cpu host -enable-kvm -m 4G -smp 1 \
    -drive if=virtio,format=qcow2,file=guest2.qcow2 \
    -nic bridge,br=br0,model=virtio-net-pci,mac=52:54:00:40:C9:02 \
    -boot d -cdrom <your_ubuntu_img_file_path>.iso \
    -vnc :1,password=on -monitor stdio
```
- In qemu console, type the following command to change the vnc password to the one you know:
```bash
(qemu) change vnc password
```
- Using any VNC viewer (e.g. : RealVNC, vncviewer) connect to (Your host IP):5902 (e.g. : 192.168.7.102:5902 or 127.0.0.1:5902), and complete the installation process.

- After Ubuntu installation is complete, remove the `-boot d -cdrom <your_img_file_path>.iso` part from the above command and run `guest2` again.
- If you want to reach internet or other device on this guest instance, you may want to manually configure your IP under the same subnet. (e.g. `192.168.50.3`, subnet mask: `255.255.255.0`, gateway: `192.168.50.1`)
